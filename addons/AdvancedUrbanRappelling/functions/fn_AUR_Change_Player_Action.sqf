// will be executed, if checking / unchecking 'Rope Actions Take Time' in CBA menu
params ["_player"];
private ["_actionID"];
if (!isNil {_player getVariable "AUR_Rappel_Action_actionID"}) then {
        _actionID = _player getVariable "AUR_Rappel_Action_actionID";
        _player removeAction _actionID;
};
private _str = "Rappel Self";
if (isLocalized "STR_AUR_RAPPEL_SELF") then {_str = format[localize "STR_AUR_RAPPEL_SELF"]};
if (AUR_ADVANCED_RAPPELING_NEW_ACTION) then {
        _actionID = [_player,
        _str,
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
        "[player] call TF47_fnc_AUR_Rappel_Action_Check",
        "[player] call TF47_fnc_AUR_Rappel_Action_Check",
        {},
        {},
        // {[player, vehicle player] spawn TF47_fnc_AUR_Rappel_Action;},
        {[player] spawn TF47_fnc_AUR_Rappel_Action;},
        {},
        nil,
        round AUR_ADVANCED_RAPPELING_NEW_ACTION_TIME,
        0,
        false,
        false] call BIS_fnc_holdActionAdd;
} else {
        _actionID = _player addAction [_str, { 
                // [player, vehicle player] call TF47_fnc_AUR_Rappel_Action;
                [player] call TF47_fnc_AUR_Rappel_Action;
        }, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Action_Check"];
};
_player setVariable ["AUR_Rappel_Action_actionID", _actionID, false];
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
if (!isNil {_player getVariable "AUR_Rappel_Attach_actionID"}) then {
        _actionID = _player getVariable "AUR_Rappel_Attach_actionID";
        _player removeAction _actionID;
};
_str = "Attach To Rappelling Rope";
if (isLocalized "STR_AUR_RAPPEL_ATTACH") then {_str = format[localize "STR_AUR_RAPPEL_ATTACH"]};
if (AUR_ADVANCED_RAPPELING_NEW_ACTION) then {
        _actionID = [_player,
        _str,
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
        "[player] call TF47_fnc_AUR_Rappel_Attach_Action_Check",
        "[player] call TF47_fnc_AUR_Rappel_Attach_Action_Check",
        {},
        {},
        {[player, vehicle player] spawn TF47_fnc_AUR_Rappel_Attach_Action;},
        {},
        nil,
        round AUR_ADVANCED_RAPPELING_NEW_ACTION_TIME,
        0,
        false,
        false] call BIS_fnc_holdActionAdd;
} else {
        _actionID = _player addAction [_str, { 
                [player] call TF47_fnc_AUR_Rappel_Attach_Action;
        }, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Rappel_Attach_Action_Check"];
};
_player setVariable ["AUR_Rappel_Attach_actionID", _actionID, false];
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
if (!isNil {_player getVariable "AUR_Detach_Rope_actionID"}) then {
        _actionID = _player getVariable "AUR_Detach_Rope_actionID";
        _player removeAction _actionID;
};
_str = "Detach Rope";
if (isLocalized "STR_AUR_DETACH_ROPE") then {_str = format[localize "STR_AUR_DETACH_ROPE"]};
if (AUR_ADVANCED_RAPPELING_NEW_ACTION) then {
        _actionID = [_player,
        _str,
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
        "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
        "[player] call TF47_fnc_AUR_Detach_Rope_Action_Check",
        "[player] call TF47_fnc_AUR_Detach_Rope_Action_Check",
        {},
        {},
        // {[player, vehicle player] spawn TF47_fnc_AUR_Detach_Rope_Action;},
        {[player] spawn TF47_fnc_AUR_Detach_Rope_Action;},
        {},
        nil,
        round AUR_ADVANCED_RAPPELING_NEW_ACTION_TIME,
        0,
        false,
        false] call BIS_fnc_holdActionAdd;
} else {
        _actionID = _player addAction [_str, { 
                [player] call TF47_fnc_AUR_Detach_Rope_Action;
        }, nil, 0, false, true, "", "[player] call TF47_fnc_AUR_Detach_Rope_Action_Check"];
};
_player setVariable ["AUR_Detach_Rope_actionID", _actionID, false];
