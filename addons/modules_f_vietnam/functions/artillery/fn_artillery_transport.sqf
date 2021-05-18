/*
    File: fn_artillery_transport.sqf
    Author: Ethan Johnson
    Date: 2020-05-04
    Last Update: 2020-06-12
    Public: No

    Description:
    Server side script for transport call from a player.

    Parameter(s):
    _params - Combo box index array [ARRAY]
    _start_pos - Starting position [ARRAY]
    _end_pos - Ending position [ARRAY]
    _unit - The unit calling in the request [OBJECT]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [parameter] call vn_fnc_artillery_transport
*/

params ["_params", "_start_pos", "_end_pos", "_unit", "_vn_artillery_choice"];
_params params ["_ammo_index", "_callsign_index", "_amount_index"];

private _speakers = [vn_artillery_speaker_west, vn_artillery_speaker_east, vn_artillery_speaker_independent];
private _speaker = _speakers#((_speakers findif {side group _x isEqualTo side group _unit}) max 0);

(vn_artillery_config_array#_vn_artillery_choice#_ammo_index#1#_callsign_index) params ["_callsign", "_name", "_description", "_icon", "_vehicleclass", "_cooldown", "_tickets", "_cost", "_condition"];

["001", "", _unit] call vn_fnc_artillery_message;

private _prefix = format ["vn_transport_%1", _name];
private _time = [time,serverTime] select isMultiplayer;

(missionNamespace getVariable [format ["%1_%2", _prefix, "cooldown"], [0,0]]) params [["_cooldown_config_time",0,[0]],["_cooldown_time",0,[0]]];
(missionNamespace getVariable [format ["%1_%2", _prefix, "tickets"], _tickets]) params [["_tickets",9999,[0]]];

if (_tickets <= 0 || _cooldown_time >= _time) exitWith
{
        ["003", "Covey", _unit] call vn_fnc_artillery_message;
};

["005", "Covey", _unit] call vn_fnc_artillery_message;

[_cost] remoteExec ["vn_fnc_artillery_score_set",_unit];

// Aircraft always come from the module's location
private _distance = _start_pos distance2d vn_artillery_module;
private _speed = 150; // 150m/s
private _setup_time = 45;
private _wait_time = (_distance/_speed) + _setup_time;

missionNamespace setVariable [format ["%1_%2", _prefix, "cooldown"], [_cooldown, _time + _wait_time + (_cooldown*(_amount_index+1))], true];
missionNamespace setVariable [format ["%1_%2", _prefix, "tickets"], _tickets - 1, true];

vn_artillery_loop_params = [_start_pos, _end_pos, _unit, _vehicleclass];
[
        "itemAdd",
        [
                str random 10000,
                {
                        [] spawn
                        {
                                vn_artillery_loop_params params ["_start_pos", "_end_pos", "_unit", "_vehicleclass"];

                                _start_pos set [2, 0];
                                _end_pos set [2, 0];

                                private _dir = _start_pos getDir _end_pos;
                                private _spawn_position = _start_pos getPos [3000, _dir - 180];
                                private _end_position = _start_pos getPos [3000, _dir];

                                _spawn_position set [2, 100];
                                _end_position set [2, 100];

                                private _vehicle_info = [_spawn_position, _dir, _vehicleclass, side _unit] call BIS_fnc_spawnVehicle;
                                _vehicle_info params ["_vehicle","_vehicle_crew","_vehicle_group"];
                                _vehicle setPosATL _spawn_position;

                                _vehicle lockDriver true;
                                _vehicle disableAi "TARGET";
                                _vehicle disableAi "AUTOTARGET";
                                _vehicle setCaptive true;
                                _vehicle_group allowFleeing 0;

                                _vehicle flyInHeight 100;

                                private _safe_start = _start_pos findEmptyPosition [0, 100, _vehicleclass];
                                if (count _safe_start <= 0) then
                                {
                                        _safe_start = +_start_pos;
                                };
                                private _start_land_position = createVehicle ["Land_HelipadEmpty_F", _safe_start, [], 0, "CAN_COLLIDE"];

                                private _waypoint_first_landing = _vehicle_group addWaypoint [_safe_start, 0];
                                _waypoint_first_landing setWaypointType "MOVE";
                                _waypoint_first_landing setWaypointBehaviour "CARELESS";
                                _waypoint_first_landing setWaypointCombatMode "BLUE";
                                _waypoint_first_landing setWaypointSpeed "NORMAL";
                                _waypoint_first_landing setWaypointCompletionRadius 50;
                                _waypoint_first_landing setWaypointStatements
                                [
                                        "true",
                                        "
                                        private _vehicle = vehicle this;
                                        if (local _vehicle) then
                                        {
                                                _vehicle land 'GET IN';
                                        };
                                        "
                                ];

                                [
                                        _vehicle addAction
                                        [
                                                localize "STR_VN_ARTILLERY_TRANSPORT_START",
                                                {
                                                        params ["_target", "_caller", "_actionId", "_arguments"];
                                                        _target setVariable ['vn_transport_takeoff_ready', true, true];
                                                },
                                                nil,
                                                -50,
                                                true,
                                                true,
                                                "",
                                                "!(_target getVariable ['vn_transport_takeoff_ready',false]) && {((fullCrew _target) findif {_this == (_x#0)}) > -1}",
                                                50,
                                                false,
                                                "",
                                                ""
                                        ]
                                ] remoteExec ["addAction", 0, _vehicle];

                                private _timeout = time + 300;
                                waitUntil { (_vehicle getVariable ["vn_transport_takeoff_ready",false]) || !alive _vehicle || !alive (driver _vehicle) || time >= _timeout };

                                if (alive _vehicle && {alive (driver _vehicle)}) then
                                {
                                        _vehicle setVariable ['vn_transport_change_lz', true, true];

                                        [
                                                _vehicle,
                                                [
                                                        localize "STR_VN_ARTILLERY_TRANSPORT_CHANGE_LZ",
                                                        {
                                                                params ["_target", "_caller", "_actionId", "_arguments"];

                                                                private _end_landing = _target getVariable ['vn_transport_landing_waypoint_helipad', objnull];
                                                                if (!isNull _end_landing) then
                                                                {
                                                                        hint localize "STR_VN_ARTILLERY_TRANSPORT_CHANGE_LZ_HINT";
                                                                        vn_transport_params = [_target, _end_landing];

                                                                        private _evh_id = addMissionEventHandler ["MapSingleClick",
                                                                        {
                                                                                params ["_units", "_pos", "_alt", "_shift"];
                                                                                vn_transport_params params ["_target", "_end_landing"];

                                                                                _pos set [2, 0];

                                                                                [group _target, 2] setWaypointPosition [_pos, 0];
                                                                                _end_landing setPosATL _pos;

                                                                                hint format[localize "STR_VN_ARTILLERY_TRANSPORT_CHANGE_LZ_HINT_FORMAT", mapGridPosition _pos];

                                                                                openMap false;
                                                                                vn_transport_params = nil;
                                                                                removeMissionEventHandler ["MapSingleClick", (uiNamespace getVariable ["vn_transport_map_evh", -1])];
                                                                        }];
                                                                        uiNamespace setVariable ["vn_transport_map_evh", _evh_id];

                                                                        openMap true;
                                                                        true
                                                                };
                                                        },
                                                        nil,
                                                        -49,
                                                        true,
                                                        true,
                                                        "",
                                                        "_target getVariable ['vn_transport_change_lz',false] && {((fullCrew _target) findif {_this == (_x#0)}) > -1}",
                                                        50,
                                                        false,
                                                        "",
                                                        ""
                                                ]
                                        ] remoteExec ["addAction", 0, _vehicle];

                                        _vehicle land 'NONE';

                                        private _end_land_position = createVehicle ["Land_HelipadEmpty_F", _end_pos, [], 0, "CAN_COLLIDE"];
                                        private _waypoint_second_landing = _vehicle_group addWaypoint [_end_pos, 1];
                                        _waypoint_second_landing setWaypointType "MOVE";
                                        _waypoint_second_landing setWaypointBehaviour "CARELESS";
                                        _waypoint_second_landing setWaypointCombatMode "BLUE";
                                        _waypoint_second_landing setWaypointSpeed "NORMAL";
                                        _waypoint_second_landing setWaypointCompletionRadius 50;
                                        _waypoint_second_landing setWaypointStatements
                                        [
                                                "true",
                                                "
                                                private _vehicle = vehicle this;
                                                if (local _vehicle) then
                                                {
                                                        _vehicle setVariable ['vn_transport_change_lz', false, true];
                                                        _vehicle land 'GET OUT';
                                                };
                                                "
                                        ];

                                        _vehicle setVariable ['vn_transport_landing_waypoint', _waypoint_second_landing, true];
                                        _vehicle setVariable ['vn_transport_landing_waypoint_helipad', _end_land_position, true];

                                        waitUntil { ((_vehicle distance _end_land_position <= 50) && { ((getPos _vehicle)#2) <= 1 }) || !alive _vehicle || !alive (driver _vehicle) };

                                        {
                                                private _unit = (_x#0);
                                                if (isPlayer _unit) then
                                                {
                                                        moveOut _unit;
                                                };
                                        } foreach (fullCrew _vehicle);

                                        sleep 1;

                                        waitUntil { ((fullCrew _vehicle) findif {isPlayer (_x#0)}) == -1 || !alive _vehicle || !alive (driver _vehicle) };

                                        _vehicle land 'NONE';

                                        private _waypoint_second_landing = _vehicle_group addWaypoint [_spawn_position, 1];
                                        _waypoint_second_landing setWaypointType "MOVE";
                                        _waypoint_second_landing setWaypointBehaviour "CARELESS";
                                        _waypoint_second_landing setWaypointCombatMode "BLUE";
                                        _waypoint_second_landing setWaypointSpeed "NORMAL";
                                        _waypoint_second_landing setWaypointCompletionRadius 100;
                                        _waypoint_second_landing setWaypointStatements
                                        [
                                                "true",
                                                "
                                                private _group = group this;
                                                if (local _group) then
                                                {
                                                        private _vehicle = vehicle this;
                                                        { _vehicle deleteVehicleCrew _x } forEach crew _vehicle;
                                                        deleteVehicle _vehicle;
                                                        { deleteVehicle _x } forEach units _group;
                                                        deleteGroup _group;
                                                }
                                                "
                                        ];
                                };
                        };
                },
                _wait_time,
                "seconds",
                { true },
                { false },
                true
        ]
] call BIS_fnc_loop;
