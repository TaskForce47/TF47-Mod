#include "script_component.hpp"
#define OFFSET [0, 0, -2]
/*
Author: Ampers
PFH to show which seat the unit is looking at

* Arguments:
* 0: Unit <OBJECT>
*
* Return Value:
* -

* Example:
* [player] call TF47_rwyl_fnc_findSeat
*/

params ["_unit"];

// get vehicle
private _notInZeus = isNull curatorCamera;
private _currentVehicle = vehicle _unit;
private _isOnFoot = _currentVehicle == _unit;

private _fnc_nearestOnScreen = {
    params ["_reference", "_entities"];

    private _minDistance = 1000;
    private _indexClosest = -1;
    { // Get closest to center of screen
        if (0 < (count fullCrew [_x, "", true])) then {
            private _w2s = worldToScreen (getPos _x);
            private _distance = if (_w2s isEqualTo []) then {
                1000
            } else {
                _reference distance2D _w2s
            };
            if (_distance < _minDistance) then {
                _minDistance = _distance;
                _indexClosest = _forEachIndex;
            };
        };
    } forEach _entities;
    if (_indexClosest > -1) then {
        _entities # _indexClosest
    } else {
        objNull
    };
};

// check parentVehicle and nearEntities
TF47_rwyl_vehicle = if (_notInZeus) then {
    if (_isOnFoot) then {
        private _entities = ((_unit modelToWorld [0, 1.5, 0]) nearEntities ["AllVehicles", 1.5]);
        [[0.5,0.5], _entities] call _fnc_nearestOnScreen;
    } else {
        objNull
    }
} else {
    // In Zeus
    if (_isOnFoot) then {
        private _entities = (screenToWorld getMousePosition nearEntities ["AllVehicles", 10]) - [_unit];
        [getMousePosition, _entities] call _fnc_nearestOnScreen;
    } else {
        _currentVehicle
    };
};

// check view lineIntersectsSurfaces
if (isNull TF47_rwyl_vehicle) then {
    if _notInZeus then {
        private _start = AGLtoASL (_unit modelToWorldVisual (_unit selectionPosition "pilot"));
        private _end = (_start vectorAdd (getCameraViewDirection _unit vectorMultiply 3));
        private _objects = lineIntersectsSurfaces [_start, _end, _unit, _currentVehicle];
        private _vehicle = (_objects param [0, []]) param [2, objNull];
        TF47_rwyl_vehicle = [_currentVehicle, _vehicle] select (0 < (count fullCrew [_vehicle, "", true]));
    } else {
        private _start = AGLtoASL positionCameraToWorld [0, 0, 0];
        private _end = AGLtoASL screenToWorld getMousePosition;
        private _objects = lineIntersectsSurfaces [_start, _end, _unit];
        TF47_rwyl_vehicle = (_objects param [0, []]) param [2, objNull];
    };
};

// exit checks
if (isNull TF47_rwyl_vehicle) exitWith {}; // no vehicle

if (locked TF47_rwyl_vehicle in [2,3] && {_notInZeus}) exitWith { // locked
    hintSilent "Vehicle Locked";
    TF47_rwyl_vehicle = objNull;
};

private _fullCrew = fullCrew [TF47_rwyl_vehicle, "", true];
if (_fullCrew isEqualTo []) exitWith { // no seats
    TF47_rwyl_vehicle = objNull;
};

// get proxies
private _sn = TF47_rwyl_vehicle selectionNames "FireGeometry" select {
    private _proxy = toLower _x;
    private _proxyIndex = _proxy select [(_proxy find ".") + 1];
    // has non-zero selection position
    !((TF47_rwyl_vehicle selectionPosition _proxy) isEqualTo [0, 0, 0]) && {
    // ends with a number after a period
    ((parseNumber _proxyIndex > 0) || {_proxyIndex isEqualTo "0"}) && {
    // contains seat role
    (("cargo" in toLower _proxy) || {("gunner" in toLower _proxy) || {("driver" in toLower _proxy) ||
    {("commander" in toLower _proxy) || {("pilot" in toLower _proxy)}}}})}}
};
if (_sn isEqualTo []) exitWith {};

// hop vehicle filter for near proxies
private _hopVehicle = !_isOnFoot && {(_currentVehicle != TF47_rwyl_vehicle) && {_notInZeus}};
if (_hopVehicle) then {
    _sn = _sn select {
        (TF47_rwyl_vehicle selectionPosition _x) distance (TF47_rwyl_vehicle worldToModel getPos _unit) < 3
    };
};

// filter out blacklisted non-functional proxies
//_sn = _sn - getArray (configOf TF47_rwyl_vehicle >> "RWYL_proxyBlacklist");
_sn = _sn - (TF47_rwyl_vehicle getVariable ["RWYL_proxyBlacklist", []]);
{
    _sn pushBackUnique _x;
} forEach (TF47_rwyl_vehicle getVariable ["RWYL_proxyWhitelist", []]);


if (_sn isEqualTo []) exitWith { // no seat proxies found in selectionNames
    TF47_rwyl_vehicle = objNull;
    if (_hopVehicle) then { // if can't hop vehicle, run for current vehicle
        [_unit, true] call TF47_rwyl_fnc_findSeat;
    };
};

private _sp = _sn apply {TF47_rwyl_vehicle selectionPosition _x};
// adjust proxies offset from character position
private _proxyOffsets = (TF47_rwyl_vehicle getVariable ["RWYL_proxyOffsets", []]);
{
    if (_x in GVAR(offset_proxies) || {_x in _proxyOffsets}) then {
        _sp set [
            _forEachIndex,
            (_sp select _forEachIndex) vectorAdd OFFSET
        ];
    };
} forEach _sn;

TF47_rwyl_colour = ["IGUI", "TEXT_RGB"] call BIS_fnc_displayColorGet;
TF47_rwyl_colour_faded = [
    TF47_rwyl_colour select 0,
    TF47_rwyl_colour select 1,
    TF47_rwyl_colour select 2,
    (TF47_rwyl_colour select 3) / 2
];

TF47_rwyl_pfh_running = true;
[{
    params ["_args", "_pfID"];
    _args params ["_unit", "_sn", "_sp"];
    TF47_rwyl_proxy = nil;
    if (!TF47_rwyl_pfh_running) exitWith {
        [_pfID] call CBA_fnc_removePerFrameHandler;
    };

    private _reference = if (
        isNull curatorCamera && {
        isNil "ace_interact_menu_openedMenuType" || {ace_interact_menu_openedMenuType < 0}}
    ) then {
        [0.5,0.5]
    } else {
        getMousePosition
    };

    private _minDistance = 10000;
    private _indexClosest = -1;
    {
        private _w2s = worldToScreen (TF47_rwyl_vehicle modelToWorldVisual _x);
        private _distance = if (_w2s isEqualTo []) then {
            1000
        } else {
            _reference distance2D _w2s
        };
        if (_distance < _minDistance) then {
            _minDistance = _distance;
            _indexClosest = _forEachIndex;
        };
    } forEach _sp;

    // no seat proxies on screen
    if (_indexClosest == -1) exitWith {
        TF47_rwyl_vehicle = objNull;
    };

    TF47_rwyl_proxy = toLower (_sn # _indexClosest);

    // update crew get in/out in PFH
    private _fullCrew = fullCrew [TF47_rwyl_vehicle, "", true];
    //_x params ["_seatOccupant", "_seatRole", "_seatCargoIndex", "_seatTurretPath"];

    // get cargo index from proxy name
    private _cargoIndex = parseNumber (TF47_rwyl_proxy select [(TF47_rwyl_proxy find ".") + 1]);

    private _icon = "";
    private _text = "";

    // check seat type of proxy
    private _seatType = {
        if (_x in TF47_rwyl_proxy) exitWith {
            _x
        };
    } forEach ["cargo", "gunner", "driver", "commander", "pilot"];
    switch (_seatType) do {
        case "cargo": {
            private _vehicleConfig = configOf TF47_rwyl_vehicle;
            private _cargoIndexes = TF47_rwyl_vehicle getVariable ["RWYL_cargoProxyIndexes", []];
            if (_cargoIndexes isEqualTo []) then {
                _cargoIndexes = getArray (_vehicleConfig >> "cargoProxyIndexes");
            };
            private _indexOrPath = _cargoIndexes find _cargoIndex;
            if (_indexOrPath == -1) then {
                _indexOrPath = _cargoIndex - 1;
            };

            private _turretConfig = configOf TF47_rwyl_vehicle >> "Turrets";
            {
                if (_cargoIndex == (getNumber (_x >> "proxyIndex")) && {
                "CPCargo" isEqualTo (getText (_x >> "proxyType"))}) then {
                    _indexOrPath = [_forEachIndex];
                };
            } forEach (("true" configClasses (_turretConfig)));

            if (_indexOrPath isEqualType []) then {
                _text = "FFV " + str _cargoIndex;
                _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa";
                TF47_rwyl_isSeatTaken = alive (_fullCrew # (_fullCrew findIf {(_x # 3) isEqualTo _indexOrPath}) # 0);
                TF47_rwyl_isSeatLocked = TF47_rwyl_vehicle lockedTurret _indexOrPath;
            } else {
                _text = "Cargo " + str _cargoIndex;
                _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getincargo_ca.paa";
                private _crewIndex = _fullCrew findIf {(_x # 2) == _indexOrPath};
                TF47_rwyl_isSeatTaken = _crewIndex > 0 && {alive (_fullCrew # _crewIndex # 0)};
                TF47_rwyl_isSeatLocked = TF47_rwyl_vehicle lockedCargo _indexOrPath;
            };

        };
        case "gunner": {
            private _indexOrPath = [];
            private _turretConfig = configOf TF47_rwyl_vehicle >> "Turrets";
            {
                if (_cargoIndex == (getNumber (_x >> "proxyIndex")) && {
                "CPGunner" isEqualTo (getText (_x >> "proxyType"))}) then {
                    _text = getText (_x >> "gunnerName");
                    _indexOrPath = [_forEachIndex];
                };
            } forEach (("true" configClasses (_turretConfig)));

            if (_text isEqualTo "") then {
                _text = "Gunner " + str _cargoIndex;
            };
            _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa";
            TF47_rwyl_isSeatTaken = alive (_fullCrew # (_fullCrew findIf {(_x # 3) isEqualTo _indexOrPath}) # 0);
            TF47_rwyl_isSeatLocked = TF47_rwyl_vehicle lockedTurret _indexOrPath;
        };
        case "driver": {
            _text = "Driver";
            _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa";
            TF47_rwyl_isSeatTaken = alive driver TF47_rwyl_vehicle;
            TF47_rwyl_isSeatLocked = lockedDriver TF47_rwyl_vehicle;
        };
        case "commander": {
            _text = "Commander";
            _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getincommander_ca.paa";
            TF47_rwyl_isSeatTaken = alive commander TF47_rwyl_vehicle;
            private _indexOrPath = [];
            private _turretConfig = configOf TF47_rwyl_vehicle >> "Turrets";
            {
                if (_cargoIndex == (getNumber (_x >> "proxyIndex")) && {
                "CPGunner" isEqualTo (getText (_x >> "proxyType"))}) then {
                    _indexOrPath = [_forEachIndex];
                };
            } forEach (("true" configClasses (_turretConfig)));
            TF47_rwyl_isSeatLocked = TF47_rwyl_vehicle lockedTurret _indexOrPath;
        };
        case "pilot": {
            _text = "Pilot";
            _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa";
            TF47_rwyl_isSeatTaken = alive driver TF47_rwyl_vehicle;
            TF47_rwyl_isSeatLocked = lockedDriver TF47_rwyl_vehicle;
        };
    };

    if (TF47_rwyl_isSeatTaken) then {
        _icon = "\a3\ui_f\data\Map\MapControl\taskIconCanceled_ca.paa";
        _text = _text + " seat taken";
    };

    if (TF47_rwyl_isSeatLocked) then {
        _icon = "\a3\ui_f\data\Map\MapControl\taskIconCanceled_ca.paa";
        _text = _text + " seat locked";
    };

    drawIcon3D [_icon, TF47_rwyl_colour, TF47_rwyl_vehicle modelToWorldVisual (_sp select _indexClosest), 1, 1, 0, _text];

    if RWYL_ShowAllSeats then {
        {
            private _proxy = _x;
            if (_forEachIndex != _indexClosest) then {
                // get cargo index from proxy name
                private _cargoIndex = parseNumber (_proxy select [(_proxy find ".") + 1]);

                _icon = "";
                _text = "";

                // check seat type of proxy
                private _seatType = {
                    if (_x in _proxy) exitWith {
                        _x
                    };
                } forEach ["cargo", "gunner", "driver", "commander", "pilot"];
                switch (_seatType) do {
                    case "cargo": {
                        private _indexOrPath = _cargoIndex - 1;

                        private _turretConfig = configOf TF47_rwyl_vehicle >> "Turrets";
                        {
                            if (_cargoIndex == (getNumber (_x >> "proxyIndex")) && {
                            "CPCargo" isEqualTo (getText (_x >> "proxyType"))}) then {
                                _indexOrPath = [_forEachIndex];
                            };
                        } forEach (("true" configClasses (_turretConfig)));

                        if (_indexOrPath isEqualType []) then {
                            _text = "FFV " + str _cargoIndex;
                            _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa";
                        } else {
                            _text = "Cargo " + str _cargoIndex;
                            _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getincargo_ca.paa";
                        };

                    };
                    case "gunner": {
                        private _indexOrPath = [];
                        private _turretConfig = configOf TF47_rwyl_vehicle >> "Turrets";
                        {
                            if (_cargoIndex == (getNumber (_x >> "proxyIndex")) && {
                            "CPGunner" isEqualTo (getText (_x >> "proxyType"))}) then {
                                _text = getText (_x >> "gunnerName");
                                _indexOrPath = [_forEachIndex];
                            };
                        } forEach (("true" configClasses (_turretConfig)));

                        if (_text isEqualTo "") then {
                            _text = "Gunner " + str _cargoIndex;
                        };
                        _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa";
                    };
                    case "driver": {
                        _text = "Driver";
                        _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa";
                    };
                    case "commander": {
                        _text = "Commander";
                        _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getincommander_ca.paa";
                    };
                    case "pilot": {
                        _text = "Pilot";
                        _icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa";
                    };
                };

                drawIcon3D [_icon, TF47_rwyl_colour_faded, TF47_rwyl_vehicle modelToWorldVisual (_sp select _forEachIndex), 0.8, 0.8, 0, _text];
            };
        } forEach _sn;
    };

}, 0, [_unit, _sn, _sp]] call CBA_fnc_addPerFrameHandler;

/*
// draw proxies
v = ([[curatorSelected # 0 # 0, [vehicle player, cursorObject] select (vehicle player == player)] select isNull curatorCamera, (get3DENSelected "" # 0 # 0)] select is3DEN);
onEachFrame {
    {
        drawIcon3D ["\a3\missions_f_oldman\Systems\UI\CenterDot\Data\centerDot_ca.paa", [1,1,1,1], v modelToWorldVisual (v selectionPosition _x), 1, 1, 0, _x];
    } forEach (selectionNames v select {
        !((v selectionPosition _x) isEqualTo [0,0,0])
    });
};
*/
