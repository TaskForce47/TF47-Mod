//3CB Helicopter Slingload Config

// BAF_Merlin_base
if (isClass (configFile >> "CfgVehicles" >> "UK3CB_BAF_Merlin_Base")) then {
    //Cargo Hook
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["UK3CB_BAF_Merlin_Base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

// BAF_Wildcat_base
if (isClass (configFile >> "CfgVehicles" >> "UK3CB_BAF_Wildcat_Base")) then {
    //Cargo Hook
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["UK3CB_BAF_Wildcat_AH1_TRN_8A", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
    ["UK3CB_BAF_Wildcat_HMA2_TRN_8A", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};
