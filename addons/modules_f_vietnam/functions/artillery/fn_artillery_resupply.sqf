/*
    File: fn_artillery_resupply.sqf
    Author: Ethan Johnson
    Date: 2020-05-04
    Last Update: 2020-06-12
    Public: No

    Description:
    Server side script for resupply call from a player

    Parameter(s):
    _params - Combo box index array [ARRAY]
    _start_pos - Starting position [ARRAY]
    _end_pos - Ending position [ARRAY]
    _unit - The unit calling in the request [OBJECT]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [parameter] call vn_fnc_artillery_resupply
*/

params ["_params", "_start_pos", "_end_pos", "_unit", "_vn_artillery_choice"];
_params params ["_ammo_index", "_callsign_index", "_amount_index"];

private _speakers = [vn_artillery_speaker_west, vn_artillery_speaker_east, vn_artillery_speaker_independent];
private _speaker = _speakers#((_speakers findif {side group _x isEqualTo side group _unit}) max 0);

(vn_artillery_config_array#_vn_artillery_choice#_ammo_index#1#_callsign_index) params ["_callsign", "_name", "_description", "_icon", "_vehicleclass", "_containerclass", "_items", "_cooldown", "_tickets", "_cost", "_condition"];

["015", "", _unit] call vn_fnc_artillery_message;

private _prefix = format ["vn_resupply_%1", _name];
private _time = [time,serverTime] select isMultiplayer;

(missionNamespace getVariable [format ["%1_%2", _prefix, "cooldown"], [0,0]]) params [["_cooldown_config_time",0,[0]],["_cooldown_time",0,[0]]];
(missionNamespace getVariable [format ["%1_%2", _prefix, "tickets"], _tickets]) params [["_tickets",9999,[0]]];

if (_tickets <= 0 || _cooldown_time >= _time) exitWith
{
        ["003", "Covey", _unit] call vn_fnc_artillery_message;
};

["001", "Covey", _unit] call vn_fnc_artillery_message;

[_cost] remoteExec ["vn_fnc_artillery_score_set",_unit];

// Aircraft always come from the module's location
private _distance = _start_pos distance2d vn_artillery_module;
private _speed = 150; // 150m/s
private _setup_time = 45;
private _wait_time = (_distance/_speed) + _setup_time;

missionNamespace setVariable [format ["%1_%2", _prefix, "cooldown"], [_cooldown, _time + _wait_time + (_cooldown*(_amount_index+1))], true];
missionNamespace setVariable [format ["%1_%2", _prefix, "tickets"], _tickets - 1, true];

vn_artillery_loop_params = [_start_pos, _end_pos, _unit, _vehicleclass, _containerclass, _items];
[
        "itemAdd",
        [
                str random 10000,
                {
                        vn_artillery_loop_params params ["_start_pos", "_end_pos", "_unit", "_vehicleclass", "_containerclass", "_items"];

                        _start_pos set [2, 100];
                        _end_pos set [2, 100];

                        private _dir = _start_pos getDir _end_pos;

                        private _spawn_position = _start_pos getPos [3000, _dir - 180];
                        private _end_position = _start_pos getPos [3000, _dir];

                        _spawn_position set [2, 300];

                        private _vehicle_info = [_spawn_position, _dir, _vehicleclass, civilian] call BIS_fnc_spawnVehicle;
                        _vehicle_info params ["_vehicle","_vehicle_crew","_vehicle_group"];
                        _vehicle setPosATL _spawn_position;

                        _vehicle setVariable ['vn_cargo_class', _containerclass];
                        _vehicle setVariable ['vn_cargo_items', _items];
                        _vehicle setVariable ['vn_cargo_unit', _unit];

                        _vehicle disableAi "TARGET";
                        _vehicle disableAi "AUTOTARGET";
                        _vehicle setCaptive true;
                        _vehicle_group allowFleeing 0;

                        _vehicle flyInHeight 300;

                        private _waypoint_drop = _vehicle_group addWaypoint [_start_pos, 0];
                        _waypoint_drop setWaypointType "MOVE";
                        _waypoint_drop setWaypointBehaviour "CARELESS";
                        _waypoint_drop setWaypointCombatMode "BLUE";
                        _waypoint_drop setWaypointSpeed "FULL";
                        _waypoint_drop setWaypointStatements
                        [
                                "true",
                                "
                                private _vehicle = vehicle this;
                                if (local _vehicle) then
                                {
                                        private _position = getPosATL _vehicle;
                                        private _spawn_position = [_position#0, _position#1, (_position#2) - 8];
                                        private _containerclass = _vehicle getVariable ['vn_cargo_class',''];
                                        private _container = createVehicle [_containerclass, _spawn_position, [], 0, 'CAN_COLLIDE'];
                                        private _parachutue = createVehicle ['B_Parachute_02_F', _spawn_position, [], 0, 'CAN_COLLIDE'];
                                        _container attachTo [_parachutue];
                                        _parachutue setVectorUp [0, 0, 1];

                                        clearItemCargo _container;
                                        clearMagazineCargo _container;
                                        clearWeaponCargo _container;
                                        clearBackpackCargo _container;

                                        private _items = _vehicle getVariable ['vn_cargo_items', []];
                                        for '_i' from 0 to (count _items)-1 step 2 do
                                        {
                                                private _item = _items#_i;
                                                private _count = _items#(_i+1);

                                                switch true do
                                                {
                                                        case (isClass (configFile >> 'CfgWeapons' >> _item)):
                                                        {
                                                                _container addWeaponCargoGlobal [_item, _count];
                                                        };
                                                        case (isClass (configFile >> 'CfgMagazines' >> _item)):
                                                        {
                                                                _container addMagazineCargoGlobal [_item, _count];
                                                        };
                                                        case (isClass (configFile >> 'CfgVehicles' >> _item)):
                                                        {
                                                                _container addBackpackCargoGlobal [_item, _count];
                                                        };
                                                        case (_item isKindOf 'ItemCore'):
                                                        {
                                                                _container addItemCargoGlobal [_item, _count];
                                                        };
                                                        default { false };
                                                };
                                        };


                                        [_vehicle] spawn
                                        {
                                                sleep 4;
                                                private _unit = (_this#0) getVariable ['vn_cargo_unit',objnull];
                                                ['014', 'Covey', _unit] call vn_fnc_artillery_message;
                                        };

                                        (group this) setCurrentWaypoint [(group this), 1];
                                };
                                "
                        ];

                        private _waypoint_end = _vehicle_group addWaypoint [_end_position, 1];
                        _waypoint_end setWaypointType "MOVE";
                        _waypoint_end setWaypointBehaviour "CARELESS";
                        _waypoint_end setWaypointCombatMode "BLUE";
                        _waypoint_end setWaypointSpeed "NORMAL";
                        _waypoint_end setWaypointCompletionRadius 100;
                        _waypoint_end setWaypointStatements
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
                },
                _wait_time,
                "seconds",
                { true },
                { false },
                true
        ]
] call BIS_fnc_loop;
