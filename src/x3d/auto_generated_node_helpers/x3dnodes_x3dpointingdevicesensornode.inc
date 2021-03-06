{ -*- buffer-read-only: t -*-

  Copyright 2015-2018 Michalis Kamburelis.

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

  strict private
    function GetDescription: string;
    procedure SetDescription(const Value: string);
  public
    { X3D field "description". } { }
    property Description: string read GetDescription write SetDescription;

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractPointingDeviceSensorNode ----------------------------------------------- }

function TAbstractPointingDeviceSensorNode.GetDescription: string;
begin
  Result := FdDescription.Value;
end;

procedure TAbstractPointingDeviceSensorNode.SetDescription(const Value: string);
begin
  FdDescription.Send(Value);
end;

{$endif read_implementation}
