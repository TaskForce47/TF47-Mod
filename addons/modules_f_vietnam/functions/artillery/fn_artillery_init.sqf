/*
    File: fn_artillery_init.sqf
    Author: Ethan Johnson
    Date: 2020-05-02
    Last Update: 2020-06-12
    Public: No

    Description:
    Init function for artillery module

    Parameter(s):
    NONE

    Returns:
    NONE

    Example(s):
    call vn_fnc_artillery_init
*/

if isServer then
{
        missionNamespace setVariable
        [
                "vn_artillery_config",
                (
                        [configFile >> "vn_artillery_settings",missionConfigFile >> "vn_artillery_settings"]
                        select
                        (isClass (missionConfigFile >> "vn_artillery_settings"))
                ),
                true
        ];

        private _object_west = (createGroup west) createUnit ["Logic", [0,0,0], [], 0, "CAN_COLLIDE"];
        private _object_east = (createGroup east) createUnit ["Logic", [0,0,0], [], 0, "CAN_COLLIDE"];
        private _object_independent = (createGroup independent) createUnit ["Logic", [0,0,0], [], 0, "CAN_COLLIDE"];
        missionNamespace setVariable ["vn_artillery_speaker_west", _object_west, true];
        missionNamespace setVariable ["vn_artillery_speaker_east", _object_east, true];
        missionNamespace setVariable ["vn_artillery_speaker_independent", _object_independent, true];
        missionNamespace setVariable ["vn_artillery_score_variable", getText(vn_artillery_config >> "cost_variable"), true];
        missionNamespace setVariable ["vn_artillery_availability", getArray(vn_artillery_config >> "availability"), true];
        missionNamespace setVariable ["vn_artillery_unit_trait", (getNumber(vn_artillery_config >> "unit_trait_required") > 0), true];
        missionNamespace setVariable ["vn_artillery_radio_backpacks", getArray(vn_artillery_config >> "radio_backpacks"), true];
        missionNamespace setVariable ["vn_artillery_radio_vehicles", getArray(vn_artillery_config >> "radio_vehicles"), true];
        missionNamespace setVariable ["vn_artillery_player_types", getArray(vn_artillery_config >> "player_types"), true];
        missionNamespace setVariable ["vn_artillery_danger_distance", getNumber(vn_artillery_config >> "danger_distance"), true];
};

private _score = missionNamespace getVariable [vn_artillery_score_variable,0];
if !(_score isEqualType 0) then
{
        private _message = "!!! VN Bombardment - Score variable is not type number. Assign a number variable or remove 'cost_variable' line from vn_bombardment_settings config !!!";
        [_message] call bis_fnc_error;
        diag_log _message;
};

private _aircraft_array = [];
private _artillery_array = [];
private _resupply_array = [];
private _transport_array = [];
private _artillery = "true" configClasses (vn_artillery_config >> "artillery");
private _aircraft = "true" configClasses (vn_artillery_config >> "aircraft");
private _resupply = "true" configClasses (vn_artillery_config >> "resupply");
private _transport = "true" configClasses (vn_artillery_config >> "transport");
{
        private _array_holder = [getText(_x >> "displayname")];
        private _callsign_array = [];
        {
                private _callsign = _x;
                private _name = getText (_callsign >> "displayname");
                private _icon = getText (_callsign >> "icon");
                private _description = getText (_callsign >> "description");
                private _ammo = getArray (_callsign >> "ammo");
                private _divergence = getNumber (_callsign >> "divergence");
                private _allow_double = getNumber (_callsign >> "allow_double");
                private _count = getNumber (_callsign >> "count");
                private _cooldown = getNumber (_callsign >> "cooldown");
                private _tickets = getNumber (_callsign >> "tickets");
                private _cost = getNumber (_callsign >> "cost");
                private _illumination = getNumber (_callsign >> "illumination");
                private _magazine = getArray (_callsign >> "magazines");
                private _function = getText (_callsign >> "function");
                private _condition = getText (_callsign >> "condition");
                private _origin = getArray (_callsign >> "origin");
                private _speed = getNumber (_callsign >> "speed");
                if (_tickets <= 0) then { _tickets = 9999; };
                if (_condition == "") then { _condition = "true"; };

                _callsign_array pushBack [_callsign, _name, _description, _icon, _ammo, _allow_double, _divergence, _count, _cooldown, _tickets, _cost, _illumination, _magazine, _function, _condition, _origin, _speed];
        } foreach ("true" configClasses _x);
        _array_holder pushBack _callsign_array;
        _artillery_array pushBack _array_holder;
} foreach _artillery;

{
        private _array_holder = [getText(_x >> "displayname")];
        private _callsign_array = [];
        {
                private _callsign = _x;
                private _name = getText (_callsign >> "displayname");
                private _icon = getText (_callsign >> "icon");
                private _description = getText (_callsign >> "description");
                private _vehicleclass = getText (_callsign >> "vehicleclass");
                private _allow_double = getNumber (_callsign >> "allow_double");
                private _cooldown = getNumber (_callsign >> "cooldown");
                private _tickets = getNumber (_callsign >> "tickets");
                private _cost = getNumber (_callsign >> "cost");
                private _illumination = getNumber (_callsign >> "illumination");
                private _magazine = getArray (_callsign >> "magazines");
                private _function = getText (_callsign >> "function");
                private _condition = getText (_callsign >> "condition");
                private _divergence = getNumber (_callsign >> "divergence");
                private _artillery = getNumber (_callsign >> "artillery");
                if (_tickets <= 0) then { _tickets = 9999; };
                if (_condition == "") then { _condition = "true"; };
                if (_divergence == 0) then { _divergence = 50; };

                _callsign_array pushBack [_callsign, _name, _description, _icon, _vehicleclass, _allow_double, _divergence, 1, _cooldown, _tickets, _cost, _illumination, _magazine, _function, _condition, nil, nil, _artillery];
        } foreach ("true" configClasses _x);
        _array_holder pushBack _callsign_array;
        _aircraft_array pushBack _array_holder;
} foreach _aircraft;

{
        private _array_holder = [getText(_x >> "displayname")];
        private _callsign_array = [];
        {
                private _callsign = _x;
                private _name = getText (_callsign >> "displayname");
                private _icon = getText (_callsign >> "icon");
                private _description = getText (_callsign >> "description");
                private _vehicleclass = getText (_callsign >> "vehicleclass");
                private _containerclass = getText (_callsign >> "containerclass");
                private _items = getArray (_callsign >> "items");
                private _cooldown = getNumber (_callsign >> "cooldown");
                private _tickets = getNumber (_callsign >> "tickets");
                private _cost = getNumber (_callsign >> "cost");
                private _condition = getText (_callsign >> "condition");
                if (_tickets <= 0) then { _tickets = 9999; };
                if (_condition == "") then { _condition = "true"; };

                _callsign_array pushBack [_callsign, _name, _description, _icon, _vehicleclass, _containerclass, _items, _cooldown, _tickets, _cost, _condition];
        } foreach ("true" configClasses _x);
        _array_holder pushBack _callsign_array;
        _resupply_array pushBack _array_holder;
} foreach _resupply;

{
        private _array_holder = [getText(_x >> "displayname")];
        private _callsign_array = [];
        {
                private _callsign = _x;
                private _name = getText (_callsign >> "displayname");
                private _icon = getText (_callsign >> "icon");
                private _description = getText (_callsign >> "description");
                private _vehicleclass = getText (_callsign >> "vehicleclass");
                private _cooldown = getNumber (_callsign >> "cooldown");
                private _tickets = getNumber (_callsign >> "tickets");
                private _cost = getNumber (_callsign >> "cost");
                private _condition = getText (_callsign >> "condition");
                if (_tickets <= 0) then { _tickets = 9999; };
                if (_condition == "") then { _condition = "true"; };

                _callsign_array pushBack [_callsign, _name, _description, _icon, _vehicleclass, _cooldown, _tickets, _cost, _condition];
        } foreach ("true" configClasses _x);
        _array_holder pushBack _callsign_array;
        _transport_array pushBack _array_holder;
} foreach _transport;
missionNamespace setVariable ["vn_artillery_config_array",[_aircraft_array, _resupply_array, _artillery_array, _transport_array]];
