// S.O.G. Prarie Fire Helicopter Slingload Config

//UH-1B & C
if (isClass (configFile >> "CfgVehicles" >> "vn_air_uh1c_base")) then { 
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["vn_air_uh1c_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};
//UH-1D
if (isClass (configFile >> "CfgVehicles" >> "vn_air_uh1d_base")) then {
    _statement = {[_target, _player, [-0.0864563,1.22266,-2.39804]] call TF47_slingload_fnc_attachCargo};
    _position = [-0.0864563,1.22266,-2.39804]; //modeled Cargo Hook
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["vn_air_uh1d_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};
//CH-34D
if (isClass (configFile >> "CfgVehicles" >> "vn_air_ch34_01_base")) then { 
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["vn_air_ch34_01_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};
