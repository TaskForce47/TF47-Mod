/*
does this work?
*/
params ["_player"];
private _aiUnits = [_player] call TF47_fnc_AUR_Get_AI_Units_Ready_To_Rappel;
if (count _aiUnits == 0) exitWith {};// leave, if player does not any AI units ready for rappelling
private _rappelPoint = _player getVariable ["AUR_Rappelling_Last_Rappel_Point", []];
if ([_player] call TF47_fnc_AUR_Rappel_Action_Check) then {
        _rappelPoint = [_player, "POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point;        
};
private _index = 0;
private _allRappelPoints = _rappelPoint select 2;

if (count _rappelPoint > 0) then {
        {
                if (!(_x getVariable ["AUR_Is_Rappelling", false])) then {
                        private _ropeLength = [_x, 100] call TF47_fnc_AUR_Get_Needed_Ropelength;// get needed rope length
                        if (AUR_ADVANCED_RAPPELING_ITEMS_NEEDED != 0) then {
                                _ropeLength = [_x, _allRappelPoints select (_index mod 3), _rappelPoint select 1] call TF47_fnc_AUR_Get_Inventory_Ropelength;        // try to get needed length with ropes from unit's inventory                                         
                        };
                        [_x, _allRappelPoints select (_index mod 3), _rappelPoint select 1, _ropeLength] spawn TF47_fnc_AUR_Rappel;
                        sleep 5;
                };
                _index = _index + 1;
        } forEach (_aiUnits);
};
