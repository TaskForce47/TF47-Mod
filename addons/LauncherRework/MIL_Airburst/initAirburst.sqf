MIL_AirburstAmmo = _this;

MIL_fnc_addAirburstToPlayer = compileFinal preprocessFileLineNumbers "MIL_airburst\addAirburstToPlayer.sqf";
MIL_fnc_airburst = compileFinal preprocessFileLineNumbers "MIL_airburst\airburst.sqf";
MIL_fnc_fuseSetting_updater = compileFinal preprocessFileLineNumbers "MIL_airburst\fuseSetting_updater.sqf";

waitUntil {({!isNil _x} count ["MIL_fnc_addAirburstToPlayer","MIL_fnc_airburst","MIL_fnc_fuseSetting_updater"]) == 3};

nul = [] spawn MIL_fnc_addAirburstToPlayer;