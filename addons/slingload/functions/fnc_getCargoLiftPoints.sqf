#include "script_component.hpp"
/*
 * Author: Ampersand
 * Get lift points for cargo
 *
 * Arguments:
 * 0: Cargo <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * ExTF47le:
 * [_cargo] call TF47_slingload_fnc_getCargoLiftPoints
 */

params ["_cargo"];

// vanilla config
(getArray (configFile >> "CfgVehicles" >> typeOf _cargo >> "slingLoadCargoMemoryPoints")) apply {_cargo selectionPosition _x};
