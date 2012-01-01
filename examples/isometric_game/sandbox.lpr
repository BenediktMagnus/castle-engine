program SandBox;

{$apptype GUI}

uses SysUtils, GL, GLU, GLExt, CastleWindow, SandBoxMap, CastleFilesUtils,
  WindowModes, SandBoxPlayer, CastleStringUtils, Math, CastleUtils,
  CastleGLUtils, SandBoxGame, KeysMouse, CastleMessages, GLImages;

var
  Window: TCastleWindowDemo;
  Player: TPlayer;
  Quit: boolean;
  ViewMoveX, ViewMoveY: Single;
  ViewFollowsPlayer: boolean = true;

procedure LoadMap;
begin
  Map := TMap.CreateFromFile(ProgramDataPath + 'maps' + PathDelim + '1.map');
  Player := TPlayer.Create;
  Player.Teleport(Map.PlayerStartX, Map.PlayerStartY, dirSouth);
end;

procedure Draw(Window: TCastleWindowBase);
var
  RealViewMoveX, RealViewMoveY: Integer;

  procedure DrawImageOnTile(X, Y: Cardinal; ImageList: TGLuint;
    const SpecialMoveX: Integer = 0;
    const SpecialMoveY: Integer = 0);
  var
    PosX, PosY: Integer;
  begin
    PosX := X * BaseWidth;
    if Odd(Y) then
      PosX += BaseWidth div 2;
    PosX += RealViewMoveX + SpecialMoveX;
    PosY := Y * (BaseHeight div 2);
    PosY += RealViewMoveY + SpecialMoveY;

    if (PosX >= 0) and (PosY >= 0) then
    begin
      glRasterPos2i(PosX, PosY);
    end else
    begin
      { Instead of glRasterPos2i(PosX, PosY) we use following trick from
        [http://www.opengl.org/resources/features/KilgardTechniques/oglpitfall/].
        We don't use this trick always --- possibly normal glRasterPos2i may
        be a little faster when it's enough. }
      glRasterPos2i(0, 0);
      glBitmap(0, 0, 0, 0, PosX, PosY, nil);
    end;

    glCallList(ImageList);
  end;

var
  X, Y: Cardinal;
  MapTile: TMapTile;
  BaseFitX, BaseFitY: Cardinal;
  X1, X2, Y1, Y2: Integer;
begin
  glClear(GL_COLOR_BUFFER_BIT);
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_GREATER, 0.5);

  BaseFitX := Ceil(ScreenWidth / BaseWidth) + 1;
  BaseFitY := Ceil(2 * ScreenHeight / BaseHeight) + 1;

  if ViewFollowsPlayer then
  begin
    { Ignore ViewMoveX/Y, calculate RealView such that the player
      is in the middle. }
    RealViewMoveX := Player.XPixel;
    RealViewMoveY := Player.YPixel;
    if Player.Moving then
    begin
      RealViewMoveX -= Round(Player.MovingSmallMoveX);
      RealViewMoveY -= Round(Player.MovingSmallMoveY);
    end;
  end else
  begin
    RealViewMoveX := Round(ViewMoveX);
    RealViewMoveY := Round(ViewMoveY);
  end;

  { First: this is what would be seen if RealViewMoveX/Y is zero. }
  X1 := -1;
  X2 := Integer(BaseFitX) - 2;
  Y1 := -1;
  Y2 := Integer(BaseFitY) - 2;
  { Now translate taking RealViewMoveX/Y into account. }
  X1 -= Ceil(RealViewMoveX / BaseWidth);
  X2 -= Floor(RealViewMoveX / BaseWidth);
  Y1 -= Ceil(2 * RealViewMoveY / BaseHeight);
  Y2 -= Floor(2 * RealViewMoveY / BaseHeight);
  { Eventually correct to be inside 0..Map.Width/Height - 1 range }
  Clamp(X1, 0, Map.Width - 1);
  Clamp(X2, 0, Map.Width - 1);
  Clamp(Y1, 0, Map.Height - 1);
  Clamp(Y2, 0, Map.Height - 1);

  for X := X1 to X2 do
    for Y := Y1 to Y2 do
    begin
      MapTile := Map.Items[X, Y];
      DrawImageOnTile(X, Y, MapTile.BaseTile.GLList);
    end;

  { TODO: shitty code, should draw only the part that fits within the window.
    We should auto-check width/height of bonus tile, to know when to draw it.
    Even better, we should record this on the map --- which tile is visible
    where. }
  for Y := Map.Height - 1 downto 0 do
  begin
    { The order of drawing is important. Player must be drawn
      on top of some objects and below some others. }
    if Y = Player.Y then
    begin
      if Player.Moving then
        DrawImageOnTile(Player.X, Player.Y, Player.GLList[Player.Direction],
          Round(Player.MovingSmallMoveX),
          Round(Player.MovingSmallMoveY)) else
        DrawImageOnTile(Player.X, Player.Y, Player.GLList[Player.Direction]);
    end;

    for X := 0 to Map.Width - 1 do
    begin
      MapTile := Map.Items[X, Y];
      if MapTile.BonusTile <> nil then
        DrawImageOnTile(X, Y, MapTile.BonusTile.GLList);
    end;
  end;

  glDisable(GL_ALPHA_TEST);

  { Tests: middle lines:
  VerticalGLLine(Window.Width / 2, 0, Window.Height);
  HorizontalGLLine(0, Window.Width, Window.Height / 2); }
end;

procedure KeyDown(Window: TCastleWindowBase; key: TKey; c: char);
var
  NewViewMoveX, NewViewMoveY: Integer;

  procedure EditBaseTile;
  var
    BaseTile: TBaseTile;
    C: Char;
  begin
    C := MessageChar(Window, 'Enter the character code of new base tile, ' +
      'or Escape to cancel', AllChars - [#0], '', taMiddle);
    if C <> CharEscape then
    begin
      BaseTile := Map.BaseTiles[C];
      if BaseTile = nil then
        MessageOK(Window, Format('The character "%s" is not a code ' +
          'for any base tile', [C]), taMiddle) else
      Map.Items[Player.X, Player.Y].BaseTile := BaseTile;
    end;
  end;

  procedure EditBonusTile;
  var
    BonusTile: TBonusTile;
    C: Char;
  begin
    C := MessageChar(Window, 'Enter the character code of new bonus tile, ' +
      'or "_" to clear or Escape to cancel', AllChars - [#0], '', taMiddle);
    if C <> CharEscape then
    begin
      if C = '_' then
        Map.Items[Player.X, Player.Y].BonusTile := nil else
      begin
        BonusTile := Map.BonusTiles[C];
        if BonusTile = nil then
          MessageOK(Window, Format('The character "%s" is not a code ' +
            'for any bonus tile', [C]), taMiddle) else
        Map.Items[Player.X, Player.Y].BonusTile := BonusTile;
      end;
    end;
  end;

  procedure ShowFieldInfo;

    function TileDescr(Tile: TTile): string;
    begin
      if Tile = nil then
        Result := '<none>' else
        Result := Format('"%s" (filename "%s")',
          [Tile.CharCode, Tile.RelativeFileName]);
    end;

  begin
    MessageOK(Window, Format(
      'Position: %d, %d' +nl+
      'Base tile: %s' +nl+
      'Bonus tile: %s',
      [ Player.X, Player.Y,
        TileDescr(Map.Items[Player.X, Player.Y].BaseTile),
        TileDescr(Map.Items[Player.X, Player.Y].BonusTile) ]), taLeft);
  end;

var
  FileName: string;
begin
  case C of
    'f': begin
           ViewFollowsPlayer := not ViewFollowsPlayer;
           if not ViewFollowsPlayer then
           begin
             { Set ViewMoveX/Y initial values such that the player is still
               in the middle. This is less confusing for user. }
             ViewMoveToCenterPosition(Player.X, Player.Y,
               NewViewMoveX, NewViewMoveY);
             ViewMoveX := NewViewMoveX;
             ViewMoveY := NewViewMoveY;
           end;
         end;
    'e': EditBaseTile;
    'E': EditBonusTile;
    's': begin
           FileName := 'new';
           if MessageInputQuery(Window, 'Save map as name' +
             ' (don''t specify here initial path and .map extension)',
             FileName, taLeft) then
           Map.SaveToFile(ProgramDataPath + 'maps' + PathDelim +
             FileName + '.map');
         end;
    'i': ShowFieldInfo;
    CharEscape: Quit := true;
  end;
end;

procedure Idle(Window: TCastleWindowBase);
const
  ViewMoveChangeSpeed = 10.0 * 50.0;
begin
  if not ViewFollowsPlayer then
  begin
    if Window.Pressed[K_Up]    then ViewMoveY -= ViewMoveChangeSpeed * Window.Fps.IdleSpeed;
    if Window.Pressed[K_Down]  then ViewMoveY += ViewMoveChangeSpeed * Window.Fps.IdleSpeed;
    if Window.Pressed[K_Right] then ViewMoveX -= ViewMoveChangeSpeed * Window.Fps.IdleSpeed;
    if Window.Pressed[K_Left]  then ViewMoveX += ViewMoveChangeSpeed * Window.Fps.IdleSpeed;
  end else
  begin
    { At first I placed the commands below in KeyDown, as they work
      like KeyDown: non-continuously. However, thanks to smooth scrolling
      of the screen, user is easily fooled and thinks that they work
      continuously. So he keeps pressing them. So we should check them
      here. }
    if Window.Pressed[K_Up]    then Player.Move(dirNorth);
    if Window.Pressed[K_Down]  then Player.Move(dirSouth);
    if Window.Pressed[K_Left]  then Player.Move(dirWest);
    if Window.Pressed[K_Right] then Player.Move(dirEast);

    if Window.Pressed[K_Numpad_7] then Player.Move(dirNorthWest);
    if Window.Pressed[K_Numpad_9] then Player.Move(dirNorthEast);
    if Window.Pressed[K_Numpad_1] then Player.Move(dirSouthWest);
    if Window.Pressed[K_Numpad_3] then Player.Move(dirSouthEast);
    if Window.Pressed[K_Numpad_4] then Player.Move(dirWest);
    if Window.Pressed[K_Numpad_6] then Player.Move(dirEast);
    if Window.Pressed[K_Numpad_2] then Player.Move(dirSouth);
    if Window.Pressed[K_Numpad_8] then Player.Move(dirNorth);
  end;

  GameTime += Window.Fps.IdleSpeed;

  Player.Idle;
end;

procedure MouseDown(Window: TCastleWindowBase; Button: TMouseButton);
begin
  { Nothing for now. }
end;

procedure Game;
var
  SavedMode: TGLMode;
begin
  SavedMode := TGLMode.CreateReset(Window, 0, true, @Draw, @Resize2D, nil);
  try
    Window.AutoRedisplay := true;
    Window.OnKeyDown := @KeyDown;
    Window.OnMouseDown := @MouseDown;
    Window.OnIdle := @Idle;

    Quit := false;
    repeat
      if not Application.ProcessMessage(true, true) then Quit := true;
    until Quit;

  finally FreeAndNil(SavedMode); end;
end;

begin
  Window := TCastleWindowDemo.Create(Application);

  Window.Caption := 'The Sandbox';
  Window.ResizeAllowed := raOnlyAtOpen;
  Window.OnResize := @Resize2D;
  Window.SetDemoOptions(K_F11, CharEscape, true);

  Window.Open;
  ScreenWidth := Window.Width;
  ScreenHeight := Window.Height;

  LoadMap;
  Game;

  FreeAndNil(Player);
  FreeAndNil(Map);
end.
