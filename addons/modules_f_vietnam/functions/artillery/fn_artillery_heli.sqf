/*
    File: fn_artillery_heli.sqf
    Author: Ethan Johnson
    Date: 2020-06-25
    Last Update: 2021-01-04
    Public: No

    Description:
    Spawns a helicopter with predetermined settings from the artillery module GUI

    Parameter(s):
    _i - Index of this heli's run [NUMBER]
    _planeCfg - Heli config [CONFIG]
    _vehicle_class - Plane classname [STRING]
    _start_pos - Start position for the run  [ARRAY]
    _end_pos - End position for the run [ARRAY]
    _amount_index - Number of total runs [NUMBER]
    _magazine - Array of magazines which will be fired from the vehicle [ARRAY]
    _unit - Unit that called the artillery [OBJECT]
    _illumination - Is the artillery run an illumination run [BOOL]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [0, configfile >> "cfgvehicles" >> "aircraft_class", "aircraft_class", [0,0,0], [100,100,0], 0, ["rockets"], player, false] call vn_fnc_artillery_heli
*/
params ["_i", "_planeCfg", "_vehicle_class", "_start_pos", "_end_pos", "_amount_index", "_magazine", "_unit", "_illumination"];

private _posATL = _start_pos;
private _pos = +_posATL;
_pos set [2,(_pos select 2) + getterrainheightasl _pos];
private _dir = _start_pos getDir _end_pos;

private _dis = 3000;
private _alt = 1000;
private _pitch = atan (_alt / _dis);
private _speed = 300 / 3.6;
private _duration = ([0,0] distance [_dis,_alt]) / _speed;

//--- Create plane
private _planePos = [_pos,_dis,_dir + 180] call bis_fnc_relpos;
_planePos set [2,(_pos select 2) + _alt];
private _planeSide = (getnumber (_planeCfg >> "side")) call bis_fnc_sideType;
private _planeArray = [_planePos,_dir,_vehicle_class,_planeSide] call bis_fnc_spawnVehicle;
private _plane = _planeArray select 0;
_plane setposasl _planePos;
_plane move ([_pos,_dis,_dir] call bis_fnc_relpos);
_plane disableai "move";
_plane disableai "target";
_plane disableai "autotarget";
_plane setcombatmode "blue";

private _vectorDir = [_planePos,_pos] call bis_fnc_vectorFromXtoY;
private _velocity = [_vectorDir,_speed] call bis_fnc_vectorMultiply;
_plane setvectordir _vectorDir;
[_plane,-90 + atan (_dis / _alt),0] call bis_fnc_setpitchbank;
private _vectorUp = vectorup _plane;

private _turret = allTurrets _plane;
{
        private _weapons = _plane weaponsTurret _x;
        {
                private _weapon = _x;
                if (_magazine findif {_x == _weapon} <= -1) then
                {
                        _plane removeWeapon _weapon;
                };
        } foreach _weapons;
} foreach _turret;
{
        if (_foreachindex < count _magazine && {(_magazine#_foreachindex) != ""}) then
        {
                if (isClass (configfile >> "CfgMagazines" >> (_magazine#_foreachindex))) then
                {
                        _plane setPylonLoadout [_foreachindex + 1, _magazine#_foreachindex, true];
                }
                else
                {
                        _plane setPylonLoadout [_foreachindex + 1, "", true];
                };
        }
        else
        {
                _plane setPylonLoadout [_foreachindex + 1, "", true];
        };
} forEach getPylonMagazines _plane;
{
        // Passed through weapons will be added along with ammo
        if (isClass (configfile >> "cfgWeapons" >> _x)) then
        {
                private _turrets = allTurrets _plane;
                if (count _turrets > 0) then
                {
                        _plane addWeaponTurret [_x, _turrets#0];
                        private _ammo = getArray (configfile >> "cfgWeapons" >> _x >> "magazines");
                        if (count _ammo > 0) then
                        {
                                _plane addMagazineTurret [_ammo#0,_turrets#0];
                        };
                };
        };
} foreach _magazine;

private _target = createVehicle ["Land_HelipadEmpty_F", _start_pos, [], 0, "CAN_COLLIDE"];

//--- Approach
private _fire = [] spawn {waituntil {false}};
private _fireNull = true;
private _time = time;
waituntil
{
        private _fireProgress = _plane getvariable ["fireProgress",0];

        //--- Set the plane approach vector
        _plane setVelocityTransformation
        [
                _planePos, [_pos select 0,_pos select 1,(_pos select 2) + _fireProgress * 12],
                _velocity, _velocity,
                _vectorDir,_vectorDir,
                _vectorUp, _vectorUp,
                (time - _time) / _duration
        ];
        _plane setvelocity velocity _plane;

   _plane addEventHandler ["Fired",
   {
      params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];

      private _type = (_weapon call bis_fnc_itemType)#1;
      if (["bomblauncher","grenadelauncher"] findif {_x == _type} > -1) then
      {
         [_projectile, _unit getVariable ["vn_target", objnull]] spawn vn_fnc_artillery_bomb_guide;
      };
   }];
   _plane setVariable ["vn_target", _target];

        //--- Fire! - Do not fire if illumination mission
        if ((getposasl _plane) distance _pos < 1000 && {_fireNull}) then
        {
                _fireNull = false;
                terminate _fire;
                _fire = [_plane, _target, _illumination] spawn
                {
                        params ["_plane", "_target", "_illumination"];
                        private _duration = 3;
                        private _time = time + _duration;
                        waituntil
                        {
            if (_illumination <= 0) then
            {
               {
                                           private _weapon = getText (configFile >> "CfgMagazines" >> _x >> "pylonWeapon");
                                           private _type = (_weapon call bis_fnc_itemType)#1;
                                           if (["bomblauncher","rocketlauncher","grenadelauncher","machinegun","cannon"] findif {_x == _type} > -1) then
                                           {
                                                   // Non-aimed weapons use BIS_fnc_fire
                                                   [_plane, _weapon] call BIS_fnc_fire;
                                           }
                                           else
                                           {
                                                   // Aimed weapons use fireAtTarget
                                                   _plane fireAtTarget [_target, _weapon];
                                           };
                                   } foreach getPylonMagazines _plane;

                                   private _turret = allTurrets _plane;
                                   {
                                           private _turret = _x;
                                           private _weapons = _plane weaponsTurret _turret;
                                           {
                                                   _plane selectWeaponTurret [_x, _turret];
                                                   private _type = (_x call bis_fnc_itemType)#1;
                                                   if (["bomblauncher","rocketlauncher","grenadelauncher","machinegun","cannon"] findif {_x == _type} > -1) then
                                                   {
                                                           // Non-aimed weapons use BIS_fnc_fire
                                                           [_plane, _x, _turret] call BIS_fnc_fire;
                                                   }
                                                   else
                                                   {
                                                           // Aimed weapons use fireAtTarget
                                                           _plane fireAtTarget [_target, _x];
                                                   };
                                           } foreach _weapons;
                                   } foreach _turret;

                                   _plane setvariable ["fireProgress",(1 - ((_time - time) / _duration)) max 0 min 1];
            };
                                sleep 0.1;
                                time > _time || isnull _plane //--- Shoot only for specific period or only one bomb
                        };
         // Illumination does not fire weapons just spawns flares
         if (_illumination > 0) then
         {
                 [_plane] spawn
                 {
                         params ["_plane"];
                         private _time = time + 8;
                         waituntil {time > _time};
               for "_i" from 0 to 3 do
               {
                  private _flare = createVehicle ["vn_flare_plane_med_w_ammo", getPosATL _plane, [], 0, "CAN_COLLIDE"];
                            _flare setVelocity [0, 0, -25];
                  sleep 1;
               };
                 };
         };
                        sleep 1;
                };
        };
        sleep 0.01;
        scriptdone _fire || isnull _plane
};
_plane setvelocity velocity _plane;
_plane flyinheight _alt;

deleteVehicle _target;

if (_i isEqualTo _amount_index) then
{
        ["014", "Covey", _unit] call vn_fnc_artillery_message;
};

_plane flyinheight 200;
_plane enableai "move";
(driver _plane) doMove (_plane getPos [_dis*2,direction _plane]);

waituntil {_plane distance _pos > _dis || !alive _plane};

//--- Delete plane
if (alive _plane) then
{
        private _group = group _plane;
        private _crew = crew _plane;
        deletevehicle _plane;
        {deletevehicle _x} foreach _crew;
        deletegroup _group;
};
