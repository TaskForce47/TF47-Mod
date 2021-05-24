#include "script_component.hpp"
/*
 * Author: Ampersand
 * check if unit is able to rig cargo for sling load
 *
 * Arguments:
 * 0: Cargo <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * example:
 * [_cargo, _unit] call TF47_slingload_fnc_canRigCargo
 */

params ["_cargo", "_unit"];

if !("TF47_slingload_CargoSling" in (_unit call ace_common_fnc_uniqueItems)) exitWith {false};

if ((typeOf _cargo) isEqualTo "TF47_slingload_apexFitting") exitWith {false};
if GVAR(pfeh_running) exitWith {false};

if (_cargo getVariable ["TF47_slingload_isRiggingEnabled", false]) exitWith {true};
if !(getArray (configFile >> "CfgVehicles" >> typeOf _cargo >> "slingLoadCargoMemoryPoints") isEqualTo []) exitWith {true};

_cargo isKindOf "LandVehicle" || {_cargo isKindOf "Air" || {_cargo isKindOf "Ship"}}
