//CUP Helicopter Slingload Config

// CUP_CH47F_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_CH47F_base")) then {
    // forward
    _statement = {[_target, _player, [0,-0.325188+1.9812,-3.02169]] call TF47_slingload_fnc_attachCargo};
    _position = [0,-0.325188+1.9812,-3.02169];
    _actionForward = ["TF47_slingload_attachCargoForward", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    // aft
    _statement = {[_target, _player, [0,-0.325188-1.9812,-3.02169]] call TF47_slingload_fnc_attachCargo};
    _position = [0,-0.325188-1.9812,-3.02169];
    _actionAft = ["TF47_slingload_attachCargoAft", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_CH47F_base", 0, [], _actionForward, true] call ace_interact_menu_fnc_addActionToClass;
    ["CUP_CH47F_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
    ["CUP_CH47F_base", 0, [], _actionAft, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_MH47E_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_MH47E_base")) then {
    // main
    _statement = {[_target, _player, [0,-0.084305,0.539414]] call TF47_slingload_fnc_attachCargo};
    _position = [0,-0.084305,0.539414];
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    // forward
    _statement = {[_target, _player, [0,2.22729,0.64529]] call TF47_slingload_fnc_attachCargo};
    _position = [0,2.22729,0.64529];
    _actionForward = ["TF47_slingload_attachCargoForward", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    // aft
    _statement = {[_target, _player, [0,-2.3959,0.433537]] call TF47_slingload_fnc_attachCargo};
    _position = [0,-2.3959,0.433537];
    _actionAft = ["TF47_slingload_attachCargoAft", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_MH47E_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
    ["CUP_MH47E_base", 0, [], _actionForward, true] call ace_interact_menu_fnc_addActionToClass;
    ["CUP_MH47E_base", 0, [], _actionAft, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_CH53E_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_CH53E_base")) then {
    // forward
    _statement = {[_target, _player, [0,1.524+4.30637,-4.25129]] call TF47_slingload_fnc_attachCargo};
    _position = [0,1.524+4.30637,-4.25129];
    _actionForward = ["TF47_slingload_attachCargoForward", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    // aft
    _statement = {[_target, _player, [0,-1.524+4.30637,-4.25129]] call TF47_slingload_fnc_attachCargo};
    _position = [0,-1.524+4.30637,-4.25129];
    _actionAft = ["TF47_slingload_attachCargoAft", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_CH53E_base", 0, [], _actionForward, true] call ace_interact_menu_fnc_addActionToClass;
    ["CUP_CH53E_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
    ["CUP_CH53E_base", 0, [], _actionAft, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_MH60S_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_MH60S_Base")) then {
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_MH60S_Base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_UH60_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_Uh60_Base")) then {
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_Uh60_Base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_MH6_Transport
if (isClass (configFile >> "CfgVehicles" >> "CUP_MH6_TRANSPORT")) then {    
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_MH6_TRANSPORT", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_Mi8_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_Mi8_base")) then {    
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_Mi8_base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_SA330_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_SA330_Base")) then {    
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_SA330_Base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

// CUP_Merlin_HC3_base
if (isClass (configFile >> "CfgVehicles" >> "CUP_Merlin_HC3_Base")) then {    
    _statement = TF47_slingload_fnc_attachCargo;
    _position = "slingload0";
    _action = ["TF47_slingload_attachCargoMain", _displayName, _icon, _statement, _condition, {}, [], _position, 5.0] call ace_interact_menu_fnc_createAction;
    ["CUP_Merlin_HC3_Base", 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
};
