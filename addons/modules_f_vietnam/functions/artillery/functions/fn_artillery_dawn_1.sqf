/*
    File: fn_artillery_dawn_1.sqf
    Author: Ethan Johnson
    Date: 2020-11-04
    Last Update: 2021-01-04
    Public: No

    Description:
    Spawns the illumination rounds for the scripted illumination artillery rounds

    Parameter(s):
    _position - Position which will be used to determine where the illumination [ARRAY]

    Returns:
    NOTHING

    Example(s):
    [[0,0,0]] call vn_fnc_artillery_dawn_1
*/

private _max_infi = 12;

if (isNil "vn_artillery_dawn_loops") then
{
   vn_artillery_dawn_loops = [];
};

private _handle = _this spawn
{
   params ["_position"];
   _position params ["_x_pos","_y_pos"];

   while {daytime >= 18 || daytime <= 6} do
   {
      // Fire
      private _height = 250;
      private _velocity = random[-1, -1.5, -2];
      private _divergence = 50;

      private _position = [_x_pos + random[-_divergence,0,_divergence], _y_pos + random[-_divergence,0,_divergence], _height];
      private _bomb = createVehicle ["vn_flare_plane_med_w_ammo", _position, [], 0, "CAN_COLLIDE"];
      _bomb setPosATL _position;
      _bomb setVectorDirAndUp [[0,0,-1],[0,1,0]];
      _bomb setVelocity [0, 0, _velocity];
      sleep 40;
   };
};

vn_artillery_dawn_loops pushBack _handle;
if (count vn_artillery_dawn_loops > _max_infi) then
{
   terminate (vn_artillery_dawn_loops#0);
};
