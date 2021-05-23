#include "script_component.hpp"
/*
 * Author: Ampersand
 * Rig cargo with hooks, ropes, and fitting. Have player ACE carry fitting.
 *
 * Arguments:
 * 0: Cargo <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * ExTF47le:
 * [_cargo, _unit] call TF47_slingload_fnc_removeRigging
 */

params ["_cargo", "_player"];

private _ropes = _cargo getVariable ["TF47_slingload_ropes4Cargo", []];

private _apexFitting = ropeAttachedTo _cargo;
_ropes apply {ropeDestroy _x};
if (_apexFitting isKindOf "TF47_slingload_apexFitting") then {
    deleteVehicle _apexFitting;
};
private _wreckDummy = _cargo getVariable [QGVAR(wreckDummy), objNull];
if !(isNull _wreckDummy) then {
    detach _cargo;
    [_wreckDummy, _unit] call FUNC(removeRigging);
    deleteVehicle _wreckDummy;
    _cargo setVariable [QGVAR(wreckDummy), objNull, true];
};

_cargo setVariable ["TF47_slingload_liftPoints", [], true];
_cargo setVariable ["TF47_slingload_ropes4Cargo", [], true];

true
