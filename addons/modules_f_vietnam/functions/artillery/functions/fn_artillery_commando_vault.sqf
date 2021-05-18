/*
    File: fn_artillery_commando_vault.sqf
    Author: Ethan Johnson
    Date: 2020-07-10
    Last Update: 2021-01-04
    Public: No

    Description:
    Runs the commando vault function.

    Parameter(s):
    _position - Position at which to spawn the bomb [ARRAY, defaults to []]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [[0,0,0]] call vn_fnc_artillery_commando_vault
*/


params [["_position",[],[]], ["_unit",objnull,[objNull]]];

["011", "Covey", _unit] call vn_fnc_artillery_message;

[_position, 1500] call vn_fnc_bomb_blu82;

[_unit] spawn
{
   params [["_unit",objnull,[objNull]]];
   sleep 10;
   ["014", "Covey", _unit] call vn_fnc_artillery_message;
};
true
