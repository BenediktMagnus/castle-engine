{
  Copyright 2003-2017 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Utilities specifically for VRML/X3D cameras.
  @seealso(CastleCameras For our general classes and utilities
    for camera handling.) }
unit X3DCameraUtils;

{$I castleconf.inc}

interface

uses CastleUtils, CastleVectors, CastleBoxes, X3DNodes;

type
  { Version of VRML/X3D camera definition. }
  TX3DCameraVersion = (cvVrml1_Inventor, cvVrml2_X3d);

const
  { Standard camera settings given by VRML/X3D specifications.
    @groupBegin }
  DefaultX3DCameraPosition: array [TX3DCameraVersion] of TVector3 =
    ( (Data: (0, 0, 1)),
      (Data: (0, 0, 10))
    );
  DefaultX3DCameraDirection: TVector3 = (Data: (0, 0, -1));
  DefaultX3DCameraUp: TVector3 = (Data: (0, 1, 0));
  DefaultX3DGravityUp: TVector3 = (Data: (0, 1, 0));
  { @groupEnd }

{ Construct string with VRML/X3D node defining camera with given
  properties. }
function MakeCameraStr(const Version: TX3DCameraVersion;
  const Xml: boolean;
  const Position, Direction, Up, GravityUp: TVector3): string;

{ Construct TX3DNode defining camera with given properties.

  Overloaded version with ViewpointNode parameter returns
  the TAbstractViewpointNode descendant that is (somewhere within)
  the returned node. }
function MakeCameraNode(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const Position, Direction, Up, GravityUp: TVector3): TAbstractChildNode;
function MakeCameraNode(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const Position, Direction, Up, GravityUp: TVector3;
  out ViewpointNode: TAbstractViewpointNode): TAbstractChildNode;

{ Make camera node (like MakeCameraNode) that makes the whole box
  nicely visible (like CameraViewpointForWholeScene). }
function CameraNodeForWholeScene(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const Box: TBox3D;
  const WantedDirection, WantedUp: Integer;
  const WantedDirectionPositive, WantedUpPositive: boolean): TAbstractChildNode;

function MakeCameraNavNode(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const NavigationType: string;
  const WalkSpeed, VisibilityLimit: Single; const AvatarSize: TVector3;
  const Headlight: boolean): TNavigationInfoNode;

implementation

uses SysUtils, CastleCameras;

function MakeCameraStr(const Version: TX3DCameraVersion;
  const Xml: boolean;
  const Position, Direction, Up, GravityUp: TVector3): string;
const
  Comment: array [boolean] of string = (
    '# Generated by %s.' +nl+
    '# Use view3dscene "Console -> Print Current Camera..." to generate VRML/X3D code like below.' +nl+
    '# Camera settings "encoded" in the VRML/X3D declaration below :' +nl+
    '#   direction %s' +nl+
    '#   up %s' +nl+
    '#   gravityUp %s' +nl,

    '<!-- Generated by %s.' +nl+
    '  Use view3dscene "Console -> Print Current Camera..." to generate VRML/X3D code like below.' +nl+
    '  Camera settings "encoded" in the X3D declaration below :' +nl+
    '    direction %s' +nl+
    '    up %s' +nl+
    '    gravityUp %s -->' +nl);

  UntransformedViewpoint: array [TX3DCameraVersion, boolean] of string = (
    ('PerspectiveCamera {' +nl+
     '  position %s' +nl+
     '  orientation %s' +nl+
     '}',

     '<PerspectiveCamera' +nl+
     '  position="%s"' +nl+
     '  orientation="%s"' +nl+
     '/>'),

    ('Viewpoint {' +nl+
     '  position %s' +nl+
     '  orientation %s' +nl+
     '}',

     '<Viewpoint' +nl+
     '  position="%s"' +nl+
     '  orientation="%s"' +nl+
     '/>')
  );
  TransformedViewpoint: array [TX3DCameraVersion, boolean] of string = (
    ('Separator {' +nl+
     '  Transform {' +nl+
     '    translation %s' +nl+
     '    rotation %s %s' +nl+
     '  }' +nl+
     '  PerspectiveCamera {' +nl+
     '    position 0 0 0 # camera position is expressed by translation' +nl+
     '    orientation %s' +nl+
     '  }' +nl+
     '}',

     '<Separator>' +nl+
     '  <Transform' +nl+
     '    translation="%s"' +nl+
     '    rotation="%s %s"' +nl+
     '  />' +nl+
     '  <!-- the camera position is already expressed by the translation above -->' +nl+
     '  <PerspectiveCamera' +nl+
     '    position="0 0 0"' +nl+
     '    orientation="%s"' +nl+
     '  />' +nl+
     '</Separator>'),

    ('Transform {' +nl+
     '  translation %s' +nl+
     '  rotation %s %s' +nl+
     '  children Viewpoint {' +nl+
     '    position 0 0 0 # camera position is expressed by translation' +nl+
     '    orientation %s' +nl+
     '  }' +nl+
     '}',

     '<Transform' +nl+
     '  translation="%s"' +nl+
     '  rotation="%s %s">' +nl+
     '  <!-- the camera position is already expressed by the translation above -->' +nl+
     '  <Viewpoint' +nl+
     '    position="0 0 0"' +nl+
     '    orientation="%s"' +nl+
     '  />' +nl+
     '</Transform>')
  );

var
  RotationVectorForGravity: TVector3;
  AngleForGravity: Single;
  { Workarounding FPC 3.1.1 internal error 200211262 in x3dcamerautils.pas }
  S1, S2, S3, S4: string;
begin
  Result := Format(Comment[Xml], [ApplicationName,
    Direction.ToRawString,
    Up.ToRawString,
    GravityUp.ToRawString ]);

  RotationVectorForGravity := TVector3.CrossProduct(DefaultX3DGravityUp, GravityUp);
  if RotationVectorForGravity.IsZero then
  begin
    { Then GravityUp is parallel to DefaultX3DGravityUp, which means that it's
      just the same. So we can use untranslated Viewpoint node. }
    S1 := Position.ToRawString;
    S2 := OrientationFromDirectionUp(Direction, Up).ToRawString;
    Result := Result + Format(UntransformedViewpoint[Version, Xml], [S1, S2]);
  end else
  begin
    { Then we must transform Viewpoint node, in such way that
      DefaultX3DGravityUp affected by this transformation will give
      desired GravityUp. }
    AngleForGravity := AngleRadBetweenVectors(DefaultX3DGravityUp, GravityUp);
    S1 := Position.ToRawString;
    S2 := RotationVectorForGravity.ToRawString;
    S3 := Format('%g', [AngleForGravity]);
    { We want such that
        1. standard VRML/X3D dir/up vectors
        2. rotated by orientation
        3. rotated around RotationVectorForGravity
      will give Camera.Direction/Up.
      OrientationFromDirectionUp will calculate the orientation needed to
      achieve given up/dir vectors. So I have to pass there
      MatrixWalker.Direction/Up *already rotated negatively
      around RotationVectorForGravity*. }
    S4 := OrientationFromDirectionUp(
            RotatePointAroundAxisRad(-AngleForGravity, Direction, RotationVectorForGravity),
            RotatePointAroundAxisRad(-AngleForGravity, Up       , RotationVectorForGravity)
          ).ToRawString;
    Result := Result + Format(TransformedViewpoint[Version, Xml], [S1, S2, S3, S4]);
  end;
end;

function MakeCameraNode(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const Position, Direction, Up, GravityUp: TVector3;
  out ViewpointNode: TAbstractViewpointNode): TAbstractChildNode;
var
  RotationVectorForGravity: TVector3;
  AngleForGravity: Single;
  Separator: TSeparatorNode_1;
  Transform_1: TTransformNode_1;
  Transform_2: TTransformNode;
  Rotation, Orientation: TVector4;
begin
  RotationVectorForGravity := TVector3.CrossProduct(DefaultX3DGravityUp, GravityUp);
  if RotationVectorForGravity.IsZero then
  begin
    { Then GravityUp is parallel to DefaultX3DGravityUp, which means that it's
      just the same. So we can use untranslated Viewpoint node. }
    case Version of
      cvVrml1_Inventor: ViewpointNode := TPerspectiveCameraNode_1.Create('', BaseUrl);
      cvVrml2_X3d     : ViewpointNode := TViewpointNode.Create('', BaseUrl);
      else raise EInternalError.Create('MakeCameraNode Version incorrect');
    end;
    ViewpointNode.Position := Position;
    ViewpointNode.Orientation := OrientationFromDirectionUp(Direction, Up);
    Result := ViewpointNode;
  end else
  begin
    { Then we must transform Viewpoint node, in such way that
      DefaultX3DGravityUp affected by this transformation will give
      desired GravityUp. }
    AngleForGravity := AngleRadBetweenVectors(DefaultX3DGravityUp, GravityUp);
    Rotation := Vector4(RotationVectorForGravity, AngleForGravity);
    { I want
      1. standard VRML/X3D dir/up vectors
      2. rotated by orientation
      3. rotated around RotationVectorForGravity
      will give MatrixWalker.Direction/Up.
      OrientationFromDirectionUp will calculate the orientation needed to
      achieve given up/dir vectors. So I have to pass there
      MatrixWalker.Direction/Up *already rotated negatively
      around RotationVectorForGravity*. }
    Orientation := OrientationFromDirectionUp(
      RotatePointAroundAxisRad(-AngleForGravity, Direction, RotationVectorForGravity),
      RotatePointAroundAxisRad(-AngleForGravity, Up       , RotationVectorForGravity));
    case Version of
      cvVrml1_Inventor:
        begin
          Transform_1 := TTransformNode_1.Create('', BaseUrl);
          Transform_1.FdTranslation.Value := Position;
          Transform_1.FdRotation.Value := Rotation;

          ViewpointNode := TPerspectiveCameraNode_1.Create('', BaseUrl);
          ViewpointNode.Position := TVector3.Zero;
          ViewpointNode.Orientation := Orientation;

          Separator := TSeparatorNode_1.Create('', BaseUrl);
          Separator.VRML1ChildAdd(Transform_1);
          Separator.VRML1ChildAdd(ViewpointNode);

          Result := Separator;
        end;

      cvVrml2_X3d:
        begin
          Transform_2 := TTransformNode.Create('', BaseUrl);
          Transform_2.Translation := Position;
          Transform_2.Rotation := Rotation;

          ViewpointNode := TViewpointNode.Create('', BaseUrl);
          ViewpointNode.Position := TVector3.Zero;
          ViewpointNode.Orientation := Orientation;

          Transform_2.AddChildren(ViewpointNode);

          Result := Transform_2;
        end;
      else raise EInternalError.Create('MakeCameraNode Version incorrect');
    end;
  end;
end;

function MakeCameraNode(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const Position, Direction, Up, GravityUp: TVector3): TAbstractChildNode;
var
  ViewpointNode: TAbstractViewpointNode;
begin
  Result := MakeCameraNode(Version, BaseUrl, Position, Direction, Up, GravityUp,
    ViewpointNode { we ignore the returned ViewpointNode });
end;

function CameraNodeForWholeScene(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const Box: TBox3D;
  const WantedDirection, WantedUp: Integer;
  const WantedDirectionPositive, WantedUpPositive: boolean): TAbstractChildNode;
var
  Position, Direction, Up, GravityUp: TVector3;
begin
  CameraViewpointForWholeScene(Box, WantedDirection, WantedUp,
    WantedDirectionPositive, WantedUpPositive, Position, Direction, Up, GravityUp);
  Result := MakeCameraNode(Version, BaseUrl,
    Position, Direction, Up, GravityUp);
end;

function MakeCameraNavNode(const Version: TX3DCameraVersion;
  const BaseUrl: string;
  const NavigationType: string;
  const WalkSpeed, VisibilityLimit: Single; const AvatarSize: TVector3;
  const Headlight: boolean): TNavigationInfoNode;
var
  NavigationNode: TNavigationInfoNode;
begin
  case Version of
    cvVrml2_X3d     : NavigationNode := TNavigationInfoNode.Create('', BaseUrl);
    else raise EInternalError.Create('MakeCameraNavNode Version incorrect');
  end;
  NavigationNode.FdType.Items.Clear;
  NavigationNode.FdType.Items.Add(NavigationType);
  NavigationNode.FdAvatarSize.Items.Clear;
  NavigationNode.FdAvatarSize.Items.AddRange(AvatarSize.Data);
  NavigationNode.FdHeadlight.Value := Headlight;
  NavigationNode.FdSpeed.Value := WalkSpeed;
  NavigationNode.FdVisibilityLimit.Value := VisibilityLimit;
  Result := NavigationNode;
end;

end.
