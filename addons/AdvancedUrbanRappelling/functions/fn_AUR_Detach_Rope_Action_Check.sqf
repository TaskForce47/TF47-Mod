params ["_player"];
if (_player getVariable ["AUR_Is_Rappelling", false]) exitWith {false};
if (AUR_ADVANCED_RAPPELING_ROPES_HANDLING != 2) exitWith {false};
if (vehicle _player != _player) exitWith {false};                
_rappelItems = (_player nearObjects 1.5) select {_x getVariable ["AUR_Rappel_Rope_Free", false]};                
if (count _rappelItems == 0) exitWith {false};
{
        private _stats = _x getVariable ["AUR_Rappel_Item_Stats", []];
        private _item = _stats select 0;
        switch true do {
                case (count _stats == 0): {deleteVehicle _x};
                case (!(alive (_stats select 0)) || !(alive (_stats select 1))): {deleteVehicle _x};
                case (_x isKindOf "Land_Can_V2_F"): {
                        private _rappelDevice = ropeAttachedTo _x;
                        if !(_rappelDevice isKindOf "AUR_RopeSmallWeight") then {deleteVehicle _x};
                };
                case (_item isKindOf "Land_Can_V2_F"): {
                        private _rappelDevice = ropeAttachedTo _item;
                        if !(_rappelDevice isKindOf "AUR_RopeSmallWeight") then {deleteVehicle _x};
                };
        };
} forEach _rappelItems;
_rappelItems = (_player nearObjects 1.5) select {_x getVariable ["AUR_Rappel_Rope_Free", false]};                
if (count _rappelItems == 0) exitWith {false};
true
