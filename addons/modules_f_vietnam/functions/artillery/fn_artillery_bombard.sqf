/*
    File: fn_artillery_bombard.sqf
    Author: Ethan Johnson
    Date: 2020-04-14
    Last Update: 2020-06-12
    Public: No

    Description:
    Main bombard function

    Parameter(s):
    _start_pos - Starting position [ARRAY]
    _end_pos - Ending position [ARRAY]
    _unit - Unit who called in the request [OBJECT]
    _params - Params array which contains the index's for the selected values [ARRAY]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [[0,0,0],[0,100,0],man1,[0,0],"Aero 1-3"] call vn_fnc_artillery_bombard
*/

params ["_start_pos", "_end_pos", "_unit", "_params", "_vn_artillery_choice"];
_params params ["_ammo_index", "_callsign_index", "_amount_index"];

_start_pos set [2,0];
_end_pos set [2,0];

(vn_artillery_config_array#_vn_artillery_choice#_ammo_index#1#_callsign_index) params ["_callsign", "_name", "_description", "_icon", "_ammo", "_allow_double", "_divergence", "_count", "_cooldown", "_tickets", "_cost", "_illumination", "_magazine", "_function", "_condition"];
private _is_artillery = _vn_artillery_choice == 2;

[missionNamespace, "vn_artillery_fired", [_unit, _is_artillery, _amount_index > 0, (vn_artillery_config_array#_vn_artillery_choice#_ammo_index#1#_callsign_index)]] remoteExecCall ["BIS_fnc_callScriptedEventHandler", 0];

if _is_artillery then
{
        // Artillery
        private _count_org = 1;
        if (_ammo isEqualType []) then
        {
                _count_org = count _ammo;
        };
        private _count_ammo = _count_org;
        if (_amount_index > 0) then { _count_ammo = _count_ammo*2; };

   ["029", "Savage Seven", _unit] call vn_fnc_artillery_message;

        for "_i" from 1 to _count_ammo do
        {
                private _x_pos = linearConversion [1, _count_ammo, _i, (_start_pos#0), (_end_pos#0)];
                private _y_pos = linearConversion [1, _count_ammo, _i, (_start_pos#1), (_end_pos#1)];

                // If function is defined, run fucntion rather then spawning any explosives
                if !(_function isEqualTo "") then
                {
                        [[_x_pos,_y_pos,0], _unit] call (missionNamespace getVariable [_function, {true}]);
                }
                else
                {
                        private _index = (_i-1)%_count_org;
                        private _ammo_class = (_ammo#_index);
                        for "_y" from 1 to _count do
                        {
                                private _height = 1500;
                                private _velocity = random[-1, -150, -300];
                                private _sleep = 0.5;
                                if (_illumination > 0) then
                                {
                                        _height = 250;
                                        _velocity = random[-1, -1.5, -2];
                                        _sleep = 40;
                                };
                                private _position = [_x_pos + random[-_divergence,0,_divergence], _y_pos + random[-_divergence,0,_divergence], _height];
                                private _bomb = createVehicle [_ammo_class, _position, [], 0, "CAN_COLLIDE"];
                                _bomb setPosATL _position;
                                _bomb setVectorDirAndUp [[0,0,-1],[0,1,0]];
                                _bomb setVelocity [0, 0, _velocity];
                                sleep _sleep;
                        };
                };
                sleep 10;
        };
      // Let the function handle the audio
      if (_function isEqualTo "") then
      {
         ["030", "", _unit] call vn_fnc_artillery_message;
              [_unit] spawn
              {
                      _this params ["_unit"];
                      sleep 8;
                      ["031", "Savage Seven", _unit] call vn_fnc_artillery_message;
              };
      };
}
else
{
        if (_ammo isKindOf "Plane") then
        {
                if (_amount_index > 0) then
                {
                        ["011", "Covey", _unit] call vn_fnc_artillery_message;
                }
                else
                {
                        ["007", "Covey", _unit] call vn_fnc_artillery_message;
                };
        }
        else
        {
                if (_ammo isKindOf "Helicopter") then
                {
                        if (_amount_index > 0) then
                        {
                                ["013", "Covey", _unit] call vn_fnc_artillery_message;
                        }
                        else
                        {
                                ["009", "Covey", _unit] call vn_fnc_artillery_message;
                        };
                };
        };

        for "_i" from 0 to _amount_index do
        {
                // If function is defined, run fucntion rather then spawning any explosives
                if !(_function isEqualTo "") then
                {
                        [_start_pos, _unit, _end_pos] call (missionNamespace getVariable [_function, {true}]);
                }
                else
                {
                        private _plane_config = configfile >> "cfgvehicles" >> _ammo;
                        if !(isclass _plane_config) exitwith { diag_log ["!!! Vehicle class '%1' not found !!!",_ammo]; };

                        switch true do
                        {
                                case (_ammo isKindOf "Plane"):
                                {
                                        [_i, _plane_config, _ammo, _start_pos, _end_pos, _amount_index, _magazine, _unit, _illumination] spawn vn_fnc_artillery_plane;
                                };
                                case (_ammo isKindOf "Helicopter"):
                                {
                                        [_i, _plane_config, _ammo, _start_pos, _end_pos, _amount_index, _magazine, _unit, _illumination] spawn vn_fnc_artillery_heli;
                                };
                                default
                                {
                                        diag_log ["!!! Vehicle class '%1' must be either type 'Plane' or 'Helicopter' !!!",_ammo];
                                };
                        };
                };
                sleep 9;
        };
};
true
