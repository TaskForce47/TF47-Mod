/*
    File: fn_artillery_message.sqf
    Author: Ethan Johnson
    Date: 2020-05-05
    Last Update: 2020-06-12
    Public: No

    Description:
    Artillery message function which plays a message in side chat for the player

    Parameter(s):
    _type - Artillery type [STRING, defaults to ""]
    _id - ID/Group name [STRING, defaults to ""]
    _unit - Unit calling in the request [OBJECT, defaults to OBJNULL]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [] call vn_fnc_artillery_message;
*/

params [["_type","",[""]], ["_id","",[""]], ["_unit",objnull,[objnull]]];

if (isNull _unit || _type isEqualTo "") exitWith { false };

private _side = switch (side group _unit) do
{
        case east: {"east"};
        case independent: {"independent"};
        case west;
        default {"west"};
};
private _senders = [vn_artillery_speaker_west, vn_artillery_speaker_east, vn_artillery_speaker_independent];
private _sender = _senders#((_senders findif {side group _x isEqualTo side group _unit}) max 0);

if (_id isEqualTo "") then
{
        _sender = _unit;
}
else
{
        if !(_id isEqualTo "") then { group _sender setGroupId [_id]; };
};

private _message = format["vn_support_%1_%2",_side, _type];
if !(isClass(configFile >> "cfgradio" >> _message) || isClass(missionconfigFile >> "cfgradio" >> _message)) exitWith { diag_log [format["!!! CfgRadio class %1 does not exist !!!",_message]]; false };
[_sender, _message] remoteExec ["globalRadio",_unit];
true
