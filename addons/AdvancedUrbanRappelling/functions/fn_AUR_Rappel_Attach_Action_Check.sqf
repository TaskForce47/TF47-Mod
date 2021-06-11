params ["_player"];
if (_player getVariable ["AUR_Is_Rappelling", false]) exitWith {false};                                                                          // false, if player is rappelling
if (AUR_ADVANCED_RAPPELING_ITEMS_NEEDED == 2 && !("AUR_Rappel_Gear" in (items _player))) exitWith {false};        // false, if harness is needed for rappelling, and player has no harness in his inventory
if (vehicle _player != _player) exitWith {false};                                                                                                                        // false, if player is in some vehicle
private _rappelItems = (_player nearObjects 1.5) select {_x getVariable ["AUR_Rappel_Rope_Free", false]};        // get any object in 1,5 m radius around player, which has a 'rope free' flag set
if (count _rappelItems == 0) exitWith {false};                                                                                                                                // false, if no object is found, which is defined as rope anchor or end weight, and which has 'rope free' flag set
private ["_stats", "_item"];
{
        _stats = _x getVariable ["AUR_Rappel_Item_Stats", []];
        _item = _stats select 0;
        switch true do {
                case (count _stats == 0): {
                        deleteVehicle _x;
                };
                case (!(alive (_stats select 0)) || !(alive (_stats select 1))): {
                        deleteVehicle _x;
                };
        };
} forEach _rappelItems;
_rappelItems = (_player nearObjects 1.5) select {_x getVariable ["AUR_Rappel_Rope_Free", false]};                
if (count _rappelItems == 0) exitWith {false};
true
