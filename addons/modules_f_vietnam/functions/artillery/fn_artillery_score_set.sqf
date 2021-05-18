/*
    File: fn_artillery_score_set.sqf
    Author: Ethan Johnson
    Date: 2020-05-13
    Last Update: 2020-06-12
    Public: No

    Description:
    Sets the score variable +/- the cost that is passed through to the function

    Parameter(s):
    _cost - Cost of the request [NUMBER]

    Returns:
    Function reached the end [BOOL]

    Example(s):
    [parameter] call vn_fnc_artillery_score_set
*/

params ["_cost"];
private _score_variable = missionNamespace getVariable ["vn_artillery_score_variable",""];
private _score_pass = true;
if !(_score_variable isEqualTo "") then
{
        private _score = missionNamespace getVariable [_score_variable, 0];
        // Lets try not to break their scoring system.
        _score = (_score - _cost) max 0;
        missionNamespace setVariable [_score_variable, _score];
};
true
