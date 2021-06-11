params ["_unit"];

// Check, if a unit has 'rappel action' available

//if (AUR_ADVANCED_RAPPELING_ITEMS_NEEDED == 1 && !([_unit] call TF47_fnc_AUR_Rappel_Rope_Check)) exitWith {false};// use when CBA Setting
//if (AUR_ADVANCED_RAPPELING_ITEMS_NEEDED == 2 && (!("AUR_Rappel_Gear" in (items _unit)) || !([_unit] call TF47_fnc_AUR_Rappel_Rope_Check))) exitWith {false};

if (_unit getVariable ["AUR_Is_Rappelling", false]) exitWith {false};
if (vehicle _unit != _unit) exitWith {false};

//if (([_unit] call TF47_fnc_AUR_Get_Unit_Height_Above_Ground) < AUR_Minimal_Rappel_Height) exitWith {false};

if !([_unit, "FAST_EXISTS_CHECK"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point) exitWith {false};
if (count ([_unit, "POSITION"] call TF47_fnc_AUR_Find_Nearby_Rappel_Point) == 0) exitWith {false};

// diag_log formatText ["%1%2%3%4%5", time, "s  (AUR_Rappel_Action_Check) _this: ", _this, ", _unit: ", _unit];

true
