//Vanilla Helicopter Slingload Config

// Huron
_statement = {[_target, _player, [0,3.6,-2.5]] call TF47_slingload_fnc_attachCargo};
_position = [0,3.6,-2.5];
private _actionForward = ["TF47_slingload_attachCargoForward", _displayName, _icon, _statement, _condition, {}, _cargoHookNameForward, _position, 5.0] call ace_interact_menu_fnc_createAction;
_statement = {[_target, _player, [0,-3.6,-2.7]] call TF47_slingload_fnc_attachCargo};
_position = [0,-3.6,-2.7];
private _actionAft = ["TF47_slingload_attachCargoAft", _displayName, _icon, _statement, _condition, {}, _cargoHookNameAft, _position, 5.0] call ace_interact_menu_fnc_createAction;
["Heli_Transport_03_base_F", 0, [], _actionForward, true] call ace_interact_menu_fnc_addActionToClass;
["Heli_Transport_03_unarmed_base_F", 0, [], _actionForward, true] call ace_interact_menu_fnc_addActionToClass;
["Heli_Transport_03_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
["Heli_Transport_03_unarmed_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
["Heli_Transport_03_base_F", 0, [], _actionAft, true] call ace_interact_menu_fnc_addActionToClass;
["Heli_Transport_03_unarmed_base_F", 0, [], _actionAft, true] call ace_interact_menu_fnc_addActionToClass;

//Ghosthawk
["Heli_Transport_01_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
// Mohawk
["Heli_Transport_02_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
// Taru
["Heli_Transport_04_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;

//Pawnee
["Heli_Light_01_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
//Kasatka
["Heli_Light_02_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
//Wildcat
["Heli_light_03_base_F", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;

#include "SOGPF.sqf"
#include "RHS.sqf"
#include "CUP.sqf"
#include "3CB.sqf"
