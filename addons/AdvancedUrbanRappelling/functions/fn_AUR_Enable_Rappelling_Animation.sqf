params ["_unit", ["_globalExec", false]];
if (local _unit && _globalExec) exitWith {};
if (local _unit && !_globalExec) then {
        [[_unit], "AUR_Enable_Rappelling_Animation_Global"] call TF47_fnc_AUR_RemoteExecServer;
};
if (_unit != player) then {
        _unit enableSimulation false;
};
if (call TF47_fnc_AUR_Has_Addon_Animations_Installed) then {                
        if ([_unit] call TF47_fnc_AUR_Current_Weapon_Type_Selected == "HANDGUN") then {
                if (local _unit) then {
                        _unit switchMove "AUR_01_Idle_Pistol";
                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Idle_Pistol_No_Actions", true];
                } else {
                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Idle_Pistol_No_Actions"];
                };
        } else {
                if (local _unit) then {
                        _unit switchMove "AUR_01_Idle";
                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Idle_No_Actions", true];
                } else {
                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Idle_No_Actions"];
                };
        };
        if !(local _unit) then {                // Temp work around to avoid seeing other player as standin
                _unit switchMove "AUR_01_Idle_No_Actions";
                sleep 1;
                _unit switchMove "AUR_01_Idle_No_Actions";
                sleep 1;
                _unit switchMove "AUR_01_Idle_No_Actions";
                sleep 1;
                _unit switchMove "AUR_01_Idle_No_Actions";
        };
} else {
        if (local _unit) then {
                _unit switchMove "HubSittingChairC_idle1";
                _unit setVariable ["AUR_Animation_Move", "HubSittingChairC_idle1", true];
        } else {
                _unit setVariable ["AUR_Animation_Move", "HubSittingChairC_idle1"];
        };
};
private _animationEventHandler = -1;
if (local _unit) then {
        _animationEventHandler = _unit addEventHandler ["AnimChanged", {
                params ["_unit", "_animation"];
                if (call TF47_fnc_AUR_Has_Addon_Animations_Installed) then {
                        if ((toLower _animation) find "aur_" < 0) then {
                                if ([_unit] call TF47_fnc_AUR_Current_Weapon_Type_Selected == "HANDGUN") then {
                                        _unit switchMove "AUR_01_Aim_Pistol";
                                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Aim_Pistol_No_Actions", true];
                                } else {
                                        _unit switchMove "AUR_01_Aim";
                                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Aim_No_Actions", true];
                                };
                        } else {
                                if (toLower _animation == "aur_01_aim") then {
                                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Aim_No_Actions", true];
                                };
                                if (toLower _animation == "aur_01_idle") then {
                                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Idle_No_Actions", true];
                                };
                                if (toLower _animation == "aur_01_aim_pistol") then {
                                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Aim_Pistol_No_Actions", true];
                                };
                                if (toLower _animation == "aur_01_idle_pistol") then {
                                        _unit setVariable ["AUR_Animation_Move", "AUR_01_Idle_Pistol_No_Actions", true];
                                };
                        };
                } else {
                        _unit switchMove "HubSittingChairC_idle1";
                        _unit setVariable ["AUR_Animation_Move", "HubSittingChairC_idle1", true];
                };
        }];
};

if (!local _unit) then {
        [_unit] spawn {
                params ["_unit"];
                while {_unit getVariable ["AUR_Is_Rappelling", false]} do {
                        private _currentState = toLower animationState _unit;
                        private _newState = toLower (_unit getVariable ["AUR_Animation_Move", ""]);
                        if !(call TF47_fnc_AUR_Has_Addon_Animations_Installed) then {
                                _newState = "HubSittingChairC_idle1";
                        };
                        if (_currentState != _newState) then {
                                _unit switchMove _newState;
                                _unit switchGesture "";
                                sleep 1;
                                _unit switchMove _newState;
                                _unit switchGesture "";
                        };
                        sleep 0.1;
                };                        
        };
};

waitUntil {!(_unit getVariable ["AUR_Is_Rappelling", false])};

if (_animationEventHandler != -1) then {
        _unit removeEventHandler ["AnimChanged", _animationEventHandler];
};

_unit switchMove "";
_unit enableSimulation true;
