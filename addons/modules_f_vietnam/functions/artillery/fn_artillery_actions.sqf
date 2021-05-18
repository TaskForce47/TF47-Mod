/*
    File: fn_artillery_actions.sqf
    Author: Ethan Johnson
    Date: 2020-06-27
    Last Update: 2020-06-27
    Public: No

    Description:
    Adds radio action to players and the respawn eventhandler to add actions when they respawn.

    Parameter(s):
    NONE

    Returns:
    Action added to player passed [BOOL]

    Example(s):
    [] call vn_fnc_artillery_actions
*/


private _radio_action = "count (missionNamespace getVariable ['vn_artillery_config_array',[]]) > 0 && {call vn_fnc_artillery_radio}";

private _id = player addAction
[
        localize "STR_VN_ARTILLERY_ACTION_NAME",
        {
                [] spawn
                {
                        sleep 0.1;
                        ["init"] call vn_fnc_artillery_menu;
                };
        },
        nil,
        -99,
        false,
        true,
        "",
        _radio_action
];
player setVariable ["vn_artillery_module_action_id", _id];

private _vn_respawn = player getVariable ["vn_artillery_event_respawn",-1];
if (_vn_respawn <= -1) then
{
        private _return = player addEventHandler ["Respawn",
        {
           params ["_unit", "_corpse"];
                _corpse removeAction (_corpse getVariable ["vn_artillery_module_action_id", -1]);
                call vn_fnc_artillery_actions;
        }];
        player setVariable ["vn_artillery_event_respawn",_return];
};
(player getVariable ["vn_artillery_event_respawn",-1] > -1)
