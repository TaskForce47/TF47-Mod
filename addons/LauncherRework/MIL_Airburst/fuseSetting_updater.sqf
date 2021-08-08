waitUntil {!isNull (findDisplay 10846)};

disableSerialization;

private ["_display"];

_display = uiNamespace getVariable "MIL_fuseSetting_HE";

[_display] spawn {
    disableSerialization;
    params ["_display"];
    if ((player getVariable ["FuseSetting","0"]) != "0") then {
        (_display displayCtrl 101) ctrlSetText (player getVariable ["FuseSetting","0"]);
    };
    ctrlSetFocus (_display displayCtrl 101);
};

MIL_displayEH_id = _display displayAddEventHandler ["KeyDown",{
    private ["_key","_display","_fuse"];
    _key = _this select 1;
    _display = uiNamespace getVariable "MIL_fuseSetting_HE";
    switch (_key) do {
        case 1: {
            //Escape
            _display displayRemoveEventHandler ["KeyDown",MIL_displayEH_id];
            closeDialog 0;
        };
        case 14: {
            //Backspace
            ctrlSetText [101,""];
        };
        case 28;//Enter
        case 156: {
            //Enter
            _display displayRemoveEventHandler ["KeyDown",MIL_displayEH_id];
            player setVariable ["FuseSetting",(ctrlText 101),false];
            
            if ((parseNumber (ctrlText 101)) < 40) then {
                hint "Fuse set: Impact.";
                } else {
                hint format["Fuse set: %1",(ctrlText 101) + "m."];
            };            
            
            closeDialog 0;
        };
        case 211: {
            //Delete
            ctrlSetText [101,""];
        };
    };
    true
}];

publicVariable "MIL_displayEH_id";