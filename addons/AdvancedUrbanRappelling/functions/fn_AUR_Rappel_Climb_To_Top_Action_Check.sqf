params ["_player"];
if !(_player getVariable ["AUR_Is_Rappelling", false]) exitWith {false};
private _topRope = player getVariable ["AUR_Rappel_Rope_Top", nil];
if (isNil "_topRope") exitWith {false};
if (ropeLength _topRope > 1) exitWith {false};
true
