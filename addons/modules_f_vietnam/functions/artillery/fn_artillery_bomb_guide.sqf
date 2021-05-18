/*
    File: fn_artillery_bomb_guide.sqf
    Author: Ethan Johnson
    Date: 2021-01-15
    Last Update: 2021-01-15
    Public: No

    Description:
    Guides a bomb through velocity transformation so it always hits the target

    Parameter(s):
    _projectile - Projectile object [OBJECT, defaults to OBJNULL]
    _target - Target object [OBJECT, defaults to OBJNULL]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [bomb, player] call vn_fnc_artillery_bomb_guide
*/
params
[
   ["_projectile", objnull,[objnull]],
   ["_target", objnull,[objnull]]
];

if (isNull _projectile || isNull _target) exitWith {false};
if !(local _projectile) exitWith {false};

private _projectile_type = typeOf _projectile;
private _projectile_pos = getPosASL _projectile;
private _target_pos = getPosASL _target;
private _velocity = velocity _projectile;
private _dir = vectorDir _projectile;
private _up = vectorUp _projectile;
private _distance = _projectile distance _target;

private _time = time;
private _total = time + 5;

private _id = str random 999999;
[
   _id,
   "onEachFrame",
   {
      _this params ["_projectile","_projectile_pos","_target_pos","_velocity","_dir","_up","_time","_total","_id"];
      _projectile setVelocityTransformation
      [
         _projectile_pos,
         _target_pos,
         _velocity,
         _velocity,
         _dir,
         _dir,
         _up,
         _up,
         linearConversion [_time, _total, time, 0, 1]
      ];
      if (isNull _projectile || time > _total) then
      {
         [_id, "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
      };
   },
   [
      _projectile,
      _projectile_pos,
      _target_pos,
      _velocity,
      _dir,
      _up,
      _time,
      _total,
      _id
   ]
] call BIS_fnc_addStackedEventHandler;
true
