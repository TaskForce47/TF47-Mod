params ["_player"];
private _future = _player getVariable "AUR_Rappel_AI_mutex";
if (time < _future) exitWith {
        _player getVariable "AUR_Rappel_AI_mutex_last_check";
};
_player setVariable ["AUR_Rappel_AI_mutex", time + AUR_AI_RAPPEL_CHECK_INTERVAL];
if (leader _player != _player) exitWith {
        _player setVariable ["AUR_Rappel_AI_mutex_last_check", false];
        false
};
private _hasAiUnits = false;
{
        if (!isPlayer _x) exitWith {_hasAiUnits = true};
} forEach units _player;
if (!_hasAiUnits) exitWith {
        _player setVariable ["AUR_Rappel_AI_mutex_last_check", false];
        false
};
if ((count ([_player] call TF47_fnc_AUR_Get_AI_Units_Ready_To_Rappel)) == 0) exitWith {
        _player setVariable ["AUR_Rappel_AI_mutex_last_check", false];
        false
};
_player setVariable ["AUR_Rappel_AI_mutex_last_check", true];
true
