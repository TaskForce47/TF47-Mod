/*
    File: fn_artillery_radio.sqf
    Author: Ethan Johnson
    Date: 2020-05-13
    Last Update: 2020-06-12
    Public: No

    Description:
    Function to determine if the player has access to the artillery menu request

    Parameter(s):
    _unit - Unit attempting to call the request [OBJECT, defaults to PLAYER]

    Returns:
    If the player has a radio based on config settings [BOOL]

    Example(s):
    [player] call vn_fnc_artillery_radio
*/

params
[
        ["_unit",(call vn_fnc_player),[objnull]]
];

private _return = false;

while {count vn_artillery_availability < 5} do
{
        vn_artillery_availability pushBack false;
};

if (vn_artillery_availability#0 isEqualType 0) then
{
        {
                vn_artillery_availability set [_foreachindex, _x > 0];
        } foreach vn_artillery_availability;
};

// Always available
if (vn_artillery_availability#0) then
{
        _return = true;
};

// Radio backpacks array
if (!_return && {vn_artillery_availability#1}) then
{
        _return = backpack _unit in vn_artillery_radio_backpacks;
};

// Radio vehicles array
if (!_return && {vn_artillery_availability#2}) then
{
        _return = typeOf (vehicle _unit) in vn_artillery_radio_vehicles;
};

// Player types array
if (!_return && {vn_artillery_availability#3}) then
{
        _return = typeOf _unit in vn_artillery_player_types;
};

// Unit trait check
if (!_return && {vn_artillery_availability#4}) then
{
        private _trait = _unit getUnitTrait "vn_artillery";
        if !(isNil "_trait") then
        {
                _return = _trait;
        };
};

if (vn_artillery_unit_trait) then
{
        private _trait = _unit getUnitTrait "vn_artillery";
        if !(isNil "_trait") then
        {
                (_return && _trait)
        }
        else
        {
                false
        };
}
else
{
        _return
};
