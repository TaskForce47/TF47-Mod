params ["_player"];

// systemChat format ["Function: Rappel_Action, Params: %1", _this];

private _rappelPoint = [_player, "POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point;
if (count _rappelPoint > 0) then {
        _player setVariable ["AUR_Rappelling_Last_Started_Time", diag_tickTime];
        _player setVariable ["AUR_Rappelling_Last_Rappel_Point", _rappelPoint];
        private _ropeLength = [_player, 100] call TF47_fnc_AUR_Get_Needed_Ropelength;  // get needed rope legth

        if (AUR_ADVANCED_RAPPELING_ITEMS_NEEDED != 0) then {
                _ropeLength = [_player, _rappelPoint select 0, _rappelPoint select 1] call TF47_fnc_AUR_Get_Inventory_Ropelength;// try to get needed length with ropes from player's inventory                                         
        };

        [_player, _rappelPoint select 0, _rappelPoint select 1, _ropeLength] call TF47_fnc_AUR_Rappel;
} else {
        /*
        private _str = "Couldn't attach rope. Move closer to edge!";
        if (isLocalized "STR_COULD_NOT_ATTACH_ROPE") then {_str = format[localize "STR_COULD_NOT_ATTACH_ROPE"]};
        */
        private _str = format[localize "STR_COULD_NOT_ATTACH_ROPE"];
        [[_str, false], "TF47_fnc_AUR_Hint", _player] call TF47_fnc_AUR_RemoteExec;
};
