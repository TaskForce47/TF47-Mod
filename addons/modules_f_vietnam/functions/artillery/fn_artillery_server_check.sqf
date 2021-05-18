/*
    File: fn_artillery_server_check.sqf
    Author: Ethan Johnson
    Date: 2020-05-04
    Last Update: 2020-06-12
    Public: No

    Description:
    Server side check for the artillery request, makes sure the request isn't in a safezone or near a respawn point

    Parameter(s):
    _params - Combo box index array [ARRAY]
    _start_pos - Starting position [ARRAY]
    _end_pos - Ending position [ARRAY]
    _unit - The unit calling in the request [OBJECT]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [parameter] call vn_fnc_myFunction
*/

params ["_params", "_start_pos", "_end_pos", "_unit", "_vn_artillery_choice"];
_params params ["_ammo_index", "_callsign_index", "_amount_index"];

// Gather data
private _map_markers = [[],[],[]];
{
        private _marker = tolower _x;
        switch true do
        {
                case (_marker find "respawn_" >= 0):
                {
                        (_map_markers#0) pushBack _marker;
                };
                case (_marker find "safezone_" >= 0):
                {
                        (_map_markers#1) pushBack _marker;
                };
                case (_marker find "fsb_" isEqualTo 0):
                {
                        (_map_markers#2) pushBack _marker;
                };
        };
} foreach allMapMarkers;
private _speakers = [vn_artillery_speaker_west, vn_artillery_speaker_east, vn_artillery_speaker_independent];
private _speaker = _speakers#((_speakers findif {side group _x isEqualTo side group _unit}) max 0);

(vn_artillery_config_array#_vn_artillery_choice#_ammo_index#1#_callsign_index) params ["_callsign", "_name", "_description", "_icon", "_ammo", "_allow_double", "_divergence", "_count", "_cooldown", "_tickets", "_cost", "_illumination", "_magazine", "_function", "_condition", ["_origin", [], [[]]], ["_speed", 75, [75]]];
private _is_artillery = _vn_artillery_choice == 2;

if !_is_artillery then
{
   if (_illumination > 0) then
        {
                ["032", "", _unit] call vn_fnc_artillery_message;
        }
        else
        {
                ["001", "", _unit] call vn_fnc_artillery_message;
        };
}
else
{
        if (_illumination > 0) then
        {
                ["025", "", _unit] call vn_fnc_artillery_message;
        }
        else
        {
                ["015", "", _unit] call vn_fnc_artillery_message;
        };
};

private _blacklisted_area = false;

if _is_artillery then
{
        // Artillery
        private _count = 1;
        if (_ammo isEqualType []) then
        {
                _count = count _ammo;
        };
        if (_amount_index > 0) then { _count = _count*2; };

        for "_i" from 1 to (_count max 2) do
        {
                if !_blacklisted_area then
                {
                        private _x_pos = linearConversion [1, _count, _i, (_start_pos#0), (_end_pos#0)];
                        private _y_pos = linearConversion [1, _count, _i, (_start_pos#1), (_end_pos#1)];

                        _blacklisted_area = ((_map_markers#0) findif {(getMarkerPos _x) distance2d [_x_pos,_y_pos,0] <= (vn_artillery_danger_distance + _divergence + ((getMarkerSize _x)#0 max ((getMarkerSize _x)#1)))} > -1);
                        if !_blacklisted_area then
                        {
                                _blacklisted_area = ((_map_markers#1) findif {(getMarkerPos _x) distance2d [_x_pos,_y_pos,0] <= (vn_artillery_danger_distance + _divergence + ((getMarkerSize _x)#0 max ((getMarkerSize _x)#1)))} > -1);
                        };
                };
        };
}
else
{
        // Vehicles
        _blacklisted_area = ((_map_markers#0) findif {(getMarkerPos _x) distance2d _start_pos <= (vn_artillery_danger_distance + ((getMarkerSize _x)#0 max ((getMarkerSize _x)#1)))} > -1);
        if !_blacklisted_area then
        {
                _blacklisted_area = ((_map_markers#1) findif {(getMarkerPos _x) distance2d _start_pos <= (vn_artillery_danger_distance + ((getMarkerSize _x)#0 max ((getMarkerSize _x)#1)))} > -1);
        };
};

// Check for blacklisted area - illumination ignores blacklisted areas
if (_blacklisted_area && {_illumination <= 0}) exitWith
{
        if _is_artillery then
        {
                ["018", "Savage Seven", _unit] call vn_fnc_artillery_message;
        }
        else
        {
                ["004", "Covey", _unit] call vn_fnc_artillery_message;
        };
};

private _prefix = format ["vn_artillery_%1", _name];
private _time = [time,serverTime] select isMultiplayer;

(missionNamespace getVariable [format ["%1_%2", _prefix, "cooldown"], [0,0]]) params [["_cooldown_config_time",0,[0]],["_cooldown_time",0,[0]]];
(missionNamespace getVariable [format ["%1_%2", _prefix, "tickets"], _tickets]) params [["_tickets",9999,[0]]];

if (_tickets <= 0 || _cooldown_time >= _time) exitWith
{
        if _is_artillery then
        {
                ["017", "Savage Seven", _unit] call vn_fnc_artillery_message;
        }
        else
        {
                ["003", "Covey", _unit] call vn_fnc_artillery_message;
        };
};

if !_is_artillery then
{
        ["002", "Covey", _unit] call vn_fnc_artillery_message;
   if (_illumination >= 1) then
        {
                ["033", "", _unit] call vn_fnc_artillery_message;
        }
   else
   {
      if (_ammo isKindOf "Plane") then
           {
                   if (_amount_index > 0) then
                   {
                           ["010", "", _unit] call vn_fnc_artillery_message;
                   }
                   else
                   {
                           ["006", "", _unit] call vn_fnc_artillery_message;
                   };
           }
           else
           {
                   if (_ammo isKindOf "Helicopter") then
                   {
                           if (_amount_index > 0) then
                           {
                                   ["012", "", _unit] call vn_fnc_artillery_message;
                           }
                           else
                           {
                                   ["008", "", _unit] call vn_fnc_artillery_message;
                           };
                   }
         else
         {
            [selectRandom ["008", "006"], "", _unit] call vn_fnc_artillery_message;
         };
           };

   };
}
else
{
        if (_illumination == 0) then
        {
                ["016", "Savage Seven", _unit] call vn_fnc_artillery_message;
        };
};

[_cost*(_amount_index+1)] remoteExec ["vn_fnc_artillery_score_set",_unit];


private _wait_time = if _is_artillery then
{
   // Get a list of markers and find the closest one
   private _markers = [(_map_markers#2) + [vn_artillery_module], [_start_pos], { _input0 distance2d (if (_x isEqualType "") then {getMarkerPos _x} else {_x}) }, "ASCEND"] call BIS_fnc_sortBy;
   _origin = if ((_markers#0) isEqualType "") then {getMarkerPos (_markers#0)} else {getPosASL (_markers#0)};
   private _distance = _start_pos distance2d ([vn_artillery_module, _origin] select ((count _origin) >= 2));
        private _speed = [115, _speed] select (_speed != 0); // 115m/s
        private _setup_time = 20;
        (_distance/_speed) + _setup_time
}
else
{
        // Aircraft always come from the module's location
        private _distance = _start_pos distance2d ([vn_artillery_module, _origin] select ((count _origin) >= 2));
        private _speed = [180, _speed] select (_speed != 0); // 180m/s
        private _setup_time = 35;
        (_distance/_speed) + _setup_time
};

missionNamespace setVariable [format ["%1_%2", _prefix, "cooldown"], [_cooldown, _time + _wait_time + (_cooldown*(_amount_index+1))], true];
missionNamespace setVariable [format ["%1_%2", _prefix, "tickets"], _tickets - 1, true];

vn_artillery_loop_params = [_start_pos, _end_pos, _unit, _params, _vn_artillery_choice];
[
        "itemAdd",
        [
                str random 10000,
                {
                        vn_artillery_loop_params spawn vn_fnc_artillery_bombard;
                },
                _wait_time,
                "seconds",
                { true },
                { false },
                true
        ]
] call BIS_fnc_loop;

[missionNamespace, "vn_artillery_called", [_unit, _is_artillery, _amount_index > 0, (vn_artillery_config_array#_vn_artillery_choice#_ammo_index#1#_callsign_index)]] remoteExecCall ["BIS_fnc_callScriptedEventHandler", 0];

if _is_artillery then
{
        [_wait_time, _unit, _params] spawn
        {
                _this params ["_wait_time", "_unit", "_params"];
                sleep (_wait_time*0.8);
                ["028", "Savage Seven", _unit] call vn_fnc_artillery_message;
        };

        if (_illumination > 0) then
        {
                [_unit] spawn
                {
                        private _unit = (_this#0);
                        ["026", "Savage Seven", _unit] call vn_fnc_artillery_message;
                        sleep 1;
                        ["027", "", _unit] call vn_fnc_artillery_message;
                };
        }
        else
        {
                if (_amount_index > 0) then
                {
                        [_unit] spawn
                        {
                                private _unit = (_this#0);
                                ["022", "", _unit] call vn_fnc_artillery_message;
                                sleep 1;
                                ["023", "Savage Seven", _unit] call vn_fnc_artillery_message;
                                sleep 1;
                                ["024", "", _unit] call vn_fnc_artillery_message;
                        };
                }
                else
                {
                        [_unit] spawn
                        {
                                private _unit = (_this#0);
                                ["019", "", _unit] call vn_fnc_artillery_message;
                                sleep 1;
                                ["020", "Savage Seven", _unit] call vn_fnc_artillery_message;
                                sleep 1;
                                ["021", "", _unit] call vn_fnc_artillery_message;
                        };
                };
        };
}
else
{
        [_unit] spawn
        {
                private _unit = (_this#0);
                sleep 12;
                ["005", "Covey", _unit] call vn_fnc_artillery_message;
        };
};
