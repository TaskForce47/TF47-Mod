/*
        FILE: fn_module_artillery.sqf
        DATE: 18-05-2020
        AUTHOR: Ethan Johnson

        DESCRIPTION:
                Setup function for the artillery module system
        PARAMETERS:
      (0): OBJECT - Logic object
      (1): ARRAY - Array of units
      (2): BOOL - Logic activated
        RETURNS:
                NONE
*/

params
[
        ["_logic",objNull,[objNull]],
        ["_units",[],[[]]],
        ["_activated",true,[true]]
];
if (_activated && {isNil "vn_artillery_module"}) then
{
        missionNamespace setVariable ["vn_artillery_module",_logic];
        call VN_fnc_artillery_init;
        [] spawn
        {
                // Wait until the player object is ready and not null
                waitUntil{player == player};
                
                call VN_fnc_artillery_actions;
        };
};
