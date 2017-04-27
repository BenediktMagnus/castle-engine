{ -*- buffer-read-only: t -*-

  Copyright 2015-2017 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated node properties.

  Do not edit this file manually!
  To add new properties:
  - add them to the text files in nodes_specification/components/ ,
  - and regenerate include files by running
    nodes_specification/x3d-nodes-to-pascal/x3d-nodes-to-pascal.lpr .

  The documentation for properties should go to x3dnodes_documentation.txt . }

{$ifdef read_interface}

  private
    function GetAlphaFactor: Single;
    procedure SetAlphaFactor(const Value: Single);
    function GetAlphaTextureId: Integer;
    procedure SetAlphaTextureId(const Value: Integer);
    function GetAlphaTextureCoordinatesId: Integer;
    procedure SetAlphaTextureCoordinatesId(const Value: Integer);
    function GetAlphaTextureChannelMask: string;
    procedure SetAlphaTextureChannelMask(const Value: string);
    function GetAlphaTexture: TAbstractTextureNode;
    procedure SetAlphaTexture(const Value: TAbstractTextureNode);
    function GetAmbientFactor: TVector3Single;
    procedure SetAmbientFactor(const Value: TVector3Single);
    function GetAmbientTextureId: Integer;
    procedure SetAmbientTextureId(const Value: Integer);
    function GetAmbientTextureCoordinatesId: Integer;
    procedure SetAmbientTextureCoordinatesId(const Value: Integer);
    function GetAmbientTextureChannelMask: string;
    procedure SetAmbientTextureChannelMask(const Value: string);
    function GetAmbientTexture: TAbstractTextureNode;
    procedure SetAmbientTexture(const Value: TAbstractTextureNode);
    function GetDiffuseFactor: TVector3Single;
    procedure SetDiffuseFactor(const Value: TVector3Single);
    function GetDiffuseTextureId: Integer;
    procedure SetDiffuseTextureId(const Value: Integer);
    function GetDiffuseTextureCoordinatesId: Integer;
    procedure SetDiffuseTextureCoordinatesId(const Value: Integer);
    function GetDiffuseTextureChannelMask: string;
    procedure SetDiffuseTextureChannelMask(const Value: string);
    function GetDiffuseTexture: TAbstractTextureNode;
    procedure SetDiffuseTexture(const Value: TAbstractTextureNode);
    function GetDiffuseDisplacementTexture: TAbstractTextureNode;
    procedure SetDiffuseDisplacementTexture(const Value: TAbstractTextureNode);
    function GetDisplacementAxis: string;
    procedure SetDisplacementAxis(const Value: string);
    function GetDisplacementFactor: Single;
    procedure SetDisplacementFactor(const Value: Single);
    function GetDisplacementTextureId: Integer;
    procedure SetDisplacementTextureId(const Value: Integer);
    function GetDisplacementTextureCoordinatesId: Integer;
    procedure SetDisplacementTextureCoordinatesId(const Value: Integer);
    function GetDisplacementTexture: TAbstractTextureNode;
    procedure SetDisplacementTexture(const Value: TAbstractTextureNode);
    function GetEmissiveFactor: TVector3Single;
    procedure SetEmissiveFactor(const Value: TVector3Single);
    function GetEmissiveTextureId: Integer;
    procedure SetEmissiveTextureId(const Value: Integer);
    function GetEmissiveTextureCoordinatesId: Integer;
    procedure SetEmissiveTextureCoordinatesId(const Value: Integer);
    function GetEmissiveTextureChannelMask: string;
    procedure SetEmissiveTextureChannelMask(const Value: string);
    function GetEmissiveTexture: TAbstractTextureNode;
    procedure SetEmissiveTexture(const Value: TAbstractTextureNode);
    function GetEnvironmentFactor: TVector3Single;
    procedure SetEnvironmentFactor(const Value: TVector3Single);
    function GetEnvironmentTextureId: Integer;
    procedure SetEnvironmentTextureId(const Value: Integer);
    function GetEnvironmentTextureCoordinatesId: Integer;
    procedure SetEnvironmentTextureCoordinatesId(const Value: Integer);
    function GetEnvironmentTextureChannelMask: string;
    procedure SetEnvironmentTextureChannelMask(const Value: string);
    function GetEnvironmentTexture: TAbstractEnvironmentTextureNode;
    procedure SetEnvironmentTexture(const Value: TAbstractEnvironmentTextureNode);
    function GetMultiDiffuseAlphaTexture: TAbstractTextureNode;
    procedure SetMultiDiffuseAlphaTexture(const Value: TAbstractTextureNode);
    function GetMultiEmmisiveAmbientIntensityTexture: TAbstractTextureNode;
    procedure SetMultiEmmisiveAmbientIntensityTexture(const Value: TAbstractTextureNode);
    function GetMultiSpecularShininessTexture: TAbstractTextureNode;
    procedure SetMultiSpecularShininessTexture(const Value: TAbstractTextureNode);
    function GetMultiVisibilityTexture: TAbstractTextureNode;
    procedure SetMultiVisibilityTexture(const Value: TAbstractTextureNode);
    function GetNormalTextureId: Integer;
    procedure SetNormalTextureId(const Value: Integer);
    function GetNormalTextureCoordinatesId: Integer;
    procedure SetNormalTextureCoordinatesId(const Value: Integer);
    function GetNormalTextureChannelMask: string;
    procedure SetNormalTextureChannelMask(const Value: string);
    function GetNormalScale: TVector3Single;
    procedure SetNormalScale(const Value: TVector3Single);
    function GetNormalBias: TVector3Single;
    procedure SetNormalBias(const Value: TVector3Single);
    function GetNormalTexture: TAbstractTextureNode;
    procedure SetNormalTexture(const Value: TAbstractTextureNode);
    function GetReflectionFactor: TVector3Single;
    procedure SetReflectionFactor(const Value: TVector3Single);
    function GetReflectionTextureId: Integer;
    procedure SetReflectionTextureId(const Value: Integer);
    function GetReflectionTextureCoordinatesId: Integer;
    procedure SetReflectionTextureCoordinatesId(const Value: Integer);
    function GetReflectionTextureChannelMask: string;
    procedure SetReflectionTextureChannelMask(const Value: string);
    function GetReflectionTexture: TAbstractTextureNode;
    procedure SetReflectionTexture(const Value: TAbstractTextureNode);
    function GetShininessFactor: Single;
    procedure SetShininessFactor(const Value: Single);
    function GetShininessTextureId: Integer;
    procedure SetShininessTextureId(const Value: Integer);
    function GetShininessTextureCoordinatesId: Integer;
    procedure SetShininessTextureCoordinatesId(const Value: Integer);
    function GetShininessTextureChannelMask: string;
    procedure SetShininessTextureChannelMask(const Value: string);
    function GetShininessTexture: TAbstractTextureNode;
    procedure SetShininessTexture(const Value: TAbstractTextureNode);
    function GetSpecularFactor: TVector3Single;
    procedure SetSpecularFactor(const Value: TVector3Single);
    function GetSpecularTextureId: Integer;
    procedure SetSpecularTextureId(const Value: Integer);
    function GetSpecularTextureCoordinatesId: Integer;
    procedure SetSpecularTextureCoordinatesId(const Value: Integer);
    function GetSpecularTextureChannelMask: string;
    procedure SetSpecularTextureChannelMask(const Value: string);
    function GetSpecularTexture: TAbstractTextureNode;
    procedure SetSpecularTexture(const Value: TAbstractTextureNode);
    function GetTransmissionFactor: TVector3Single;
    procedure SetTransmissionFactor(const Value: TVector3Single);
    function GetTransmissionTextureId: Integer;
    procedure SetTransmissionTextureId(const Value: Integer);
    function GetTransmissionTextureCoordinatesId: Integer;
    procedure SetTransmissionTextureCoordinatesId(const Value: Integer);
    function GetTransmissionTextureChannelMask: string;
    procedure SetTransmissionTextureChannelMask(const Value: string);
    function GetTransmissionTexture: TAbstractTextureNode;
    procedure SetTransmissionTexture(const Value: TAbstractTextureNode);
    function GetTangentTextureCoordinatesId: Integer;
    procedure SetTangentTextureCoordinatesId(const Value: Integer);
    function GetBinormalTextureCoordinatesId: Integer;
    procedure SetBinormalTextureCoordinatesId(const Value: Integer);
    function GetInvertAlphaTexture: boolean;
    procedure SetInvertAlphaTexture(const Value: boolean);
    function GetRelativeIndexOfRefraction: Single;
    procedure SetRelativeIndexOfRefraction(const Value: Single);
    function GetFresnelBlend: Single;
    procedure SetFresnelBlend(const Value: Single);
  public
    property AlphaFactor: Single read GetAlphaFactor write SetAlphaFactor;
    property AlphaTextureId: Integer read GetAlphaTextureId write SetAlphaTextureId;
    property AlphaTextureCoordinatesId: Integer read GetAlphaTextureCoordinatesId write SetAlphaTextureCoordinatesId;
    property AlphaTextureChannelMask: string read GetAlphaTextureChannelMask write SetAlphaTextureChannelMask;
    property AlphaTexture: TAbstractTextureNode read GetAlphaTexture write SetAlphaTexture;
    property AmbientFactor: TVector3Single read GetAmbientFactor write SetAmbientFactor;
    property AmbientTextureId: Integer read GetAmbientTextureId write SetAmbientTextureId;
    property AmbientTextureCoordinatesId: Integer read GetAmbientTextureCoordinatesId write SetAmbientTextureCoordinatesId;
    property AmbientTextureChannelMask: string read GetAmbientTextureChannelMask write SetAmbientTextureChannelMask;
    property AmbientTexture: TAbstractTextureNode read GetAmbientTexture write SetAmbientTexture;
    property DiffuseFactor: TVector3Single read GetDiffuseFactor write SetDiffuseFactor;
    property DiffuseTextureId: Integer read GetDiffuseTextureId write SetDiffuseTextureId;
    property DiffuseTextureCoordinatesId: Integer read GetDiffuseTextureCoordinatesId write SetDiffuseTextureCoordinatesId;
    property DiffuseTextureChannelMask: string read GetDiffuseTextureChannelMask write SetDiffuseTextureChannelMask;
    property DiffuseTexture: TAbstractTextureNode read GetDiffuseTexture write SetDiffuseTexture;
    property DiffuseDisplacementTexture: TAbstractTextureNode read GetDiffuseDisplacementTexture write SetDiffuseDisplacementTexture;
    property DisplacementAxis: string read GetDisplacementAxis write SetDisplacementAxis;
    property DisplacementFactor: Single read GetDisplacementFactor write SetDisplacementFactor;
    property DisplacementTextureId: Integer read GetDisplacementTextureId write SetDisplacementTextureId;
    property DisplacementTextureCoordinatesId: Integer read GetDisplacementTextureCoordinatesId write SetDisplacementTextureCoordinatesId;
    property DisplacementTexture: TAbstractTextureNode read GetDisplacementTexture write SetDisplacementTexture;
    property EmissiveFactor: TVector3Single read GetEmissiveFactor write SetEmissiveFactor;
    property EmissiveTextureId: Integer read GetEmissiveTextureId write SetEmissiveTextureId;
    property EmissiveTextureCoordinatesId: Integer read GetEmissiveTextureCoordinatesId write SetEmissiveTextureCoordinatesId;
    property EmissiveTextureChannelMask: string read GetEmissiveTextureChannelMask write SetEmissiveTextureChannelMask;
    property EmissiveTexture: TAbstractTextureNode read GetEmissiveTexture write SetEmissiveTexture;
    property EnvironmentFactor: TVector3Single read GetEnvironmentFactor write SetEnvironmentFactor;
    property EnvironmentTextureId: Integer read GetEnvironmentTextureId write SetEnvironmentTextureId;
    property EnvironmentTextureCoordinatesId: Integer read GetEnvironmentTextureCoordinatesId write SetEnvironmentTextureCoordinatesId;
    property EnvironmentTextureChannelMask: string read GetEnvironmentTextureChannelMask write SetEnvironmentTextureChannelMask;
    property EnvironmentTexture: TAbstractEnvironmentTextureNode read GetEnvironmentTexture write SetEnvironmentTexture;
    property MultiDiffuseAlphaTexture: TAbstractTextureNode read GetMultiDiffuseAlphaTexture write SetMultiDiffuseAlphaTexture;
    property MultiEmmisiveAmbientIntensityTexture: TAbstractTextureNode read GetMultiEmmisiveAmbientIntensityTexture write SetMultiEmmisiveAmbientIntensityTexture;
    property MultiSpecularShininessTexture: TAbstractTextureNode read GetMultiSpecularShininessTexture write SetMultiSpecularShininessTexture;
    property MultiVisibilityTexture: TAbstractTextureNode read GetMultiVisibilityTexture write SetMultiVisibilityTexture;
    property NormalTextureId: Integer read GetNormalTextureId write SetNormalTextureId;
    property NormalTextureCoordinatesId: Integer read GetNormalTextureCoordinatesId write SetNormalTextureCoordinatesId;
    property NormalTextureChannelMask: string read GetNormalTextureChannelMask write SetNormalTextureChannelMask;
    property NormalScale: TVector3Single read GetNormalScale write SetNormalScale;
    property NormalBias: TVector3Single read GetNormalBias write SetNormalBias;
    property NormalTexture: TAbstractTextureNode read GetNormalTexture write SetNormalTexture;
    property ReflectionFactor: TVector3Single read GetReflectionFactor write SetReflectionFactor;
    property ReflectionTextureId: Integer read GetReflectionTextureId write SetReflectionTextureId;
    property ReflectionTextureCoordinatesId: Integer read GetReflectionTextureCoordinatesId write SetReflectionTextureCoordinatesId;
    property ReflectionTextureChannelMask: string read GetReflectionTextureChannelMask write SetReflectionTextureChannelMask;
    property ReflectionTexture: TAbstractTextureNode read GetReflectionTexture write SetReflectionTexture;
    property ShininessFactor: Single read GetShininessFactor write SetShininessFactor;
    property ShininessTextureId: Integer read GetShininessTextureId write SetShininessTextureId;
    property ShininessTextureCoordinatesId: Integer read GetShininessTextureCoordinatesId write SetShininessTextureCoordinatesId;
    property ShininessTextureChannelMask: string read GetShininessTextureChannelMask write SetShininessTextureChannelMask;
    property ShininessTexture: TAbstractTextureNode read GetShininessTexture write SetShininessTexture;
    property SpecularFactor: TVector3Single read GetSpecularFactor write SetSpecularFactor;
    property SpecularTextureId: Integer read GetSpecularTextureId write SetSpecularTextureId;
    property SpecularTextureCoordinatesId: Integer read GetSpecularTextureCoordinatesId write SetSpecularTextureCoordinatesId;
    property SpecularTextureChannelMask: string read GetSpecularTextureChannelMask write SetSpecularTextureChannelMask;
    property SpecularTexture: TAbstractTextureNode read GetSpecularTexture write SetSpecularTexture;
    property TransmissionFactor: TVector3Single read GetTransmissionFactor write SetTransmissionFactor;
    property TransmissionTextureId: Integer read GetTransmissionTextureId write SetTransmissionTextureId;
    property TransmissionTextureCoordinatesId: Integer read GetTransmissionTextureCoordinatesId write SetTransmissionTextureCoordinatesId;
    property TransmissionTextureChannelMask: string read GetTransmissionTextureChannelMask write SetTransmissionTextureChannelMask;
    property TransmissionTexture: TAbstractTextureNode read GetTransmissionTexture write SetTransmissionTexture;
    property TangentTextureCoordinatesId: Integer read GetTangentTextureCoordinatesId write SetTangentTextureCoordinatesId;
    property BinormalTextureCoordinatesId: Integer read GetBinormalTextureCoordinatesId write SetBinormalTextureCoordinatesId;
    property InvertAlphaTexture: boolean read GetInvertAlphaTexture write SetInvertAlphaTexture;
    property RelativeIndexOfRefraction: Single read GetRelativeIndexOfRefraction write SetRelativeIndexOfRefraction;
    property FresnelBlend: Single read GetFresnelBlend write SetFresnelBlend;

{$endif read_interface}

{$ifdef read_implementation}

{ TCommonSurfaceShaderNode ----------------------------------------------- }

function TCommonSurfaceShaderNode.GetAlphaFactor: Single;
begin
  Result := FdAlphaFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaFactor(const Value: Single);
begin
  FdAlphaFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTextureId: Integer;
begin
  Result := FdAlphaTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTextureId(const Value: Integer);
begin
  FdAlphaTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTextureCoordinatesId: Integer;
begin
  Result := FdAlphaTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTextureCoordinatesId(const Value: Integer);
begin
  FdAlphaTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTextureChannelMask: string;
begin
  Result := FdAlphaTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTextureChannelMask(const Value: string);
begin
  FdAlphaTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAlphaTexture: TAbstractTextureNode;
begin
  if FdAlphaTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdAlphaTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetAlphaTexture(const Value: TAbstractTextureNode);
begin
  FdAlphaTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientFactor: TVector3Single;
begin
  Result := FdAmbientFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientFactor(const Value: TVector3Single);
begin
  FdAmbientFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTextureId: Integer;
begin
  Result := FdAmbientTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTextureId(const Value: Integer);
begin
  FdAmbientTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTextureCoordinatesId: Integer;
begin
  Result := FdAmbientTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTextureCoordinatesId(const Value: Integer);
begin
  FdAmbientTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTextureChannelMask: string;
begin
  Result := FdAmbientTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTextureChannelMask(const Value: string);
begin
  FdAmbientTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetAmbientTexture: TAbstractTextureNode;
begin
  if FdAmbientTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdAmbientTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetAmbientTexture(const Value: TAbstractTextureNode);
begin
  FdAmbientTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseFactor: TVector3Single;
begin
  Result := FdDiffuseFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseFactor(const Value: TVector3Single);
begin
  FdDiffuseFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTextureId: Integer;
begin
  Result := FdDiffuseTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTextureId(const Value: Integer);
begin
  FdDiffuseTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTextureCoordinatesId: Integer;
begin
  Result := FdDiffuseTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTextureCoordinatesId(const Value: Integer);
begin
  FdDiffuseTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTextureChannelMask: string;
begin
  Result := FdDiffuseTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTextureChannelMask(const Value: string);
begin
  FdDiffuseTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseTexture: TAbstractTextureNode;
begin
  if FdDiffuseTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdDiffuseTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseTexture(const Value: TAbstractTextureNode);
begin
  FdDiffuseTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDiffuseDisplacementTexture: TAbstractTextureNode;
begin
  if FdDiffuseDisplacementTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdDiffuseDisplacementTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetDiffuseDisplacementTexture(const Value: TAbstractTextureNode);
begin
  FdDiffuseDisplacementTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementAxis: string;
begin
  Result := FdDisplacementAxis.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementAxis(const Value: string);
begin
  FdDisplacementAxis.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementFactor: Single;
begin
  Result := FdDisplacementFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementFactor(const Value: Single);
begin
  FdDisplacementFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementTextureId: Integer;
begin
  Result := FdDisplacementTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementTextureId(const Value: Integer);
begin
  FdDisplacementTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementTextureCoordinatesId: Integer;
begin
  Result := FdDisplacementTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementTextureCoordinatesId(const Value: Integer);
begin
  FdDisplacementTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetDisplacementTexture: TAbstractTextureNode;
begin
  if FdDisplacementTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdDisplacementTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetDisplacementTexture(const Value: TAbstractTextureNode);
begin
  FdDisplacementTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveFactor: TVector3Single;
begin
  Result := FdEmissiveFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveFactor(const Value: TVector3Single);
begin
  FdEmissiveFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTextureId: Integer;
begin
  Result := FdEmissiveTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTextureId(const Value: Integer);
begin
  FdEmissiveTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTextureCoordinatesId: Integer;
begin
  Result := FdEmissiveTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTextureCoordinatesId(const Value: Integer);
begin
  FdEmissiveTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTextureChannelMask: string;
begin
  Result := FdEmissiveTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTextureChannelMask(const Value: string);
begin
  FdEmissiveTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEmissiveTexture: TAbstractTextureNode;
begin
  if FdEmissiveTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdEmissiveTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetEmissiveTexture(const Value: TAbstractTextureNode);
begin
  FdEmissiveTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentFactor: TVector3Single;
begin
  Result := FdEnvironmentFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentFactor(const Value: TVector3Single);
begin
  FdEnvironmentFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTextureId: Integer;
begin
  Result := FdEnvironmentTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTextureId(const Value: Integer);
begin
  FdEnvironmentTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTextureCoordinatesId: Integer;
begin
  Result := FdEnvironmentTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTextureCoordinatesId(const Value: Integer);
begin
  FdEnvironmentTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTextureChannelMask: string;
begin
  Result := FdEnvironmentTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTextureChannelMask(const Value: string);
begin
  FdEnvironmentTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetEnvironmentTexture: TAbstractEnvironmentTextureNode;
begin
  if FdEnvironmentTexture.Value is TAbstractEnvironmentTextureNode then
    Result := TAbstractEnvironmentTextureNode(FdEnvironmentTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetEnvironmentTexture(const Value: TAbstractEnvironmentTextureNode);
begin
  FdEnvironmentTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiDiffuseAlphaTexture: TAbstractTextureNode;
begin
  if FdMultiDiffuseAlphaTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiDiffuseAlphaTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiDiffuseAlphaTexture(const Value: TAbstractTextureNode);
begin
  FdMultiDiffuseAlphaTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiEmmisiveAmbientIntensityTexture: TAbstractTextureNode;
begin
  if FdMultiEmmisiveAmbientIntensityTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiEmmisiveAmbientIntensityTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiEmmisiveAmbientIntensityTexture(const Value: TAbstractTextureNode);
begin
  FdMultiEmmisiveAmbientIntensityTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiSpecularShininessTexture: TAbstractTextureNode;
begin
  if FdMultiSpecularShininessTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiSpecularShininessTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiSpecularShininessTexture(const Value: TAbstractTextureNode);
begin
  FdMultiSpecularShininessTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetMultiVisibilityTexture: TAbstractTextureNode;
begin
  if FdMultiVisibilityTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdMultiVisibilityTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetMultiVisibilityTexture(const Value: TAbstractTextureNode);
begin
  FdMultiVisibilityTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTextureId: Integer;
begin
  Result := FdNormalTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalTextureId(const Value: Integer);
begin
  FdNormalTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTextureCoordinatesId: Integer;
begin
  Result := FdNormalTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalTextureCoordinatesId(const Value: Integer);
begin
  FdNormalTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTextureChannelMask: string;
begin
  Result := FdNormalTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalTextureChannelMask(const Value: string);
begin
  FdNormalTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalScale: TVector3Single;
begin
  Result := FdNormalScale.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalScale(const Value: TVector3Single);
begin
  FdNormalScale.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalBias: TVector3Single;
begin
  Result := FdNormalBias.Value;
end;

procedure TCommonSurfaceShaderNode.SetNormalBias(const Value: TVector3Single);
begin
  FdNormalBias.Send(Value);
end;

function TCommonSurfaceShaderNode.GetNormalTexture: TAbstractTextureNode;
begin
  if FdNormalTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdNormalTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetNormalTexture(const Value: TAbstractTextureNode);
begin
  FdNormalTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionFactor: TVector3Single;
begin
  Result := FdReflectionFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionFactor(const Value: TVector3Single);
begin
  FdReflectionFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTextureId: Integer;
begin
  Result := FdReflectionTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTextureId(const Value: Integer);
begin
  FdReflectionTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTextureCoordinatesId: Integer;
begin
  Result := FdReflectionTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTextureCoordinatesId(const Value: Integer);
begin
  FdReflectionTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTextureChannelMask: string;
begin
  Result := FdReflectionTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTextureChannelMask(const Value: string);
begin
  FdReflectionTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetReflectionTexture: TAbstractTextureNode;
begin
  if FdReflectionTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdReflectionTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetReflectionTexture(const Value: TAbstractTextureNode);
begin
  FdReflectionTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessFactor: Single;
begin
  Result := FdShininessFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessFactor(const Value: Single);
begin
  FdShininessFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTextureId: Integer;
begin
  Result := FdShininessTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessTextureId(const Value: Integer);
begin
  FdShininessTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTextureCoordinatesId: Integer;
begin
  Result := FdShininessTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessTextureCoordinatesId(const Value: Integer);
begin
  FdShininessTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTextureChannelMask: string;
begin
  Result := FdShininessTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetShininessTextureChannelMask(const Value: string);
begin
  FdShininessTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetShininessTexture: TAbstractTextureNode;
begin
  if FdShininessTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdShininessTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetShininessTexture(const Value: TAbstractTextureNode);
begin
  FdShininessTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularFactor: TVector3Single;
begin
  Result := FdSpecularFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularFactor(const Value: TVector3Single);
begin
  FdSpecularFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTextureId: Integer;
begin
  Result := FdSpecularTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTextureId(const Value: Integer);
begin
  FdSpecularTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTextureCoordinatesId: Integer;
begin
  Result := FdSpecularTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTextureCoordinatesId(const Value: Integer);
begin
  FdSpecularTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTextureChannelMask: string;
begin
  Result := FdSpecularTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTextureChannelMask(const Value: string);
begin
  FdSpecularTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetSpecularTexture: TAbstractTextureNode;
begin
  if FdSpecularTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdSpecularTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetSpecularTexture(const Value: TAbstractTextureNode);
begin
  FdSpecularTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionFactor: TVector3Single;
begin
  Result := FdTransmissionFactor.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionFactor(const Value: TVector3Single);
begin
  FdTransmissionFactor.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTextureId: Integer;
begin
  Result := FdTransmissionTextureId.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTextureId(const Value: Integer);
begin
  FdTransmissionTextureId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTextureCoordinatesId: Integer;
begin
  Result := FdTransmissionTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTextureCoordinatesId(const Value: Integer);
begin
  FdTransmissionTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTextureChannelMask: string;
begin
  Result := FdTransmissionTextureChannelMask.Value;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTextureChannelMask(const Value: string);
begin
  FdTransmissionTextureChannelMask.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTransmissionTexture: TAbstractTextureNode;
begin
  if FdTransmissionTexture.Value is TAbstractTextureNode then
    Result := TAbstractTextureNode(FdTransmissionTexture.Value)
  else
    Result := nil;
end;

procedure TCommonSurfaceShaderNode.SetTransmissionTexture(const Value: TAbstractTextureNode);
begin
  FdTransmissionTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetTangentTextureCoordinatesId: Integer;
begin
  Result := FdTangentTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetTangentTextureCoordinatesId(const Value: Integer);
begin
  FdTangentTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetBinormalTextureCoordinatesId: Integer;
begin
  Result := FdBinormalTextureCoordinatesId.Value;
end;

procedure TCommonSurfaceShaderNode.SetBinormalTextureCoordinatesId(const Value: Integer);
begin
  FdBinormalTextureCoordinatesId.Send(Value);
end;

function TCommonSurfaceShaderNode.GetInvertAlphaTexture: boolean;
begin
  Result := FdInvertAlphaTexture.Value;
end;

procedure TCommonSurfaceShaderNode.SetInvertAlphaTexture(const Value: boolean);
begin
  FdInvertAlphaTexture.Send(Value);
end;

function TCommonSurfaceShaderNode.GetRelativeIndexOfRefraction: Single;
begin
  Result := FdRelativeIndexOfRefraction.Value;
end;

procedure TCommonSurfaceShaderNode.SetRelativeIndexOfRefraction(const Value: Single);
begin
  FdRelativeIndexOfRefraction.Send(Value);
end;

function TCommonSurfaceShaderNode.GetFresnelBlend: Single;
begin
  Result := FdFresnelBlend.Value;
end;

procedure TCommonSurfaceShaderNode.SetFresnelBlend(const Value: Single);
begin
  FdFresnelBlend.Send(Value);
end;

{$endif read_implementation}