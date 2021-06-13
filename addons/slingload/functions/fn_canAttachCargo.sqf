#include "script_component.hpp"
/*
 * Author: Ampersand
 * Edit: TF47 Rampage
 * check if unit is able to adjust the length of the rope for the hook and less than 3 Loads are connected
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Unit <OBJECT>
 * 2: CargoHookName <STRING>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_hook, _unit, "TF47_slingload_cargoHookMain"] call TF47_slingload_fnc_canAttachCargo
 */
 
params ["_heli", "_player",["_cargoHookName", "TF47_slingload_cargoHookMain"]];

private _count = _heli getVariable [Format["%1%2",_cargoHookName,"_count"],0];
if (_count >= 3) exitwith {false};

if (typeOf _heli isEqualTo "TF47_slingload_apexFitting") exitWith { false };

!isNull (_player getVariable ["TF47_slingload_heldFitting", objNull])
&& {getNumber (configFile >> "CfgVehicles" >> typeOf _heli >> "slingLoadMaxCargoMass") > 0}
