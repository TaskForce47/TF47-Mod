// CBA Settings [ADDON: gge_canting]:

////// GGE_CANTING BINDS ///////
[
	"GGE Canting",
    "gge_canting_var_toggleCantMode", 
	["Toggle Aiming Mode", "Change between canted aiming and regular aiming (NOTE: Only has an effect if pressed while player is aiming)"], 
	{ }, 
	{ [] spawn gge_canting_fnc_toggleCantMode; }, 
	[46, [false, false, false]]
] call CBA_fnc_addKeybind;

////// GGE_CANTING SETTINGS ///////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ADS TOGGLE MODE
[
    "gge_canting_var_toggleADSMode", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Toggle ADS Mode (Check 'Optics' binding!)", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "GGE Canting", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    false // data for this setting: [min, max, default, number of shown trailing decimals]
] call CBA_fnc_addSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ENABLE CROSSHAIR DURING DAYLIGHT
[
    "gge_canting_var_crosshairMode", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Enable Crosshair when canting weapon without NVGs", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "GGE Canting", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true // data for this setting: [min, max, default, number of shown trailing decimals]
] call CBA_fnc_addSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CROSSHAIR COLOUR
[
    "gge_canting_var_crosshairColour", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "COLOR", // setting type
    "Crosshair colour", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "GGE Canting", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [1,1,1,1] // data for this setting: [min, max, default, number of shown trailing decimals]
] call CBA_fnc_addSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ENABLE GUNLIGHT WHEN CANTING
[
    "gge_canting_var_enableGunLight", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Enable weapon light when canting", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "GGE Canting", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true // data for this setting: [min, max, default, number of shown trailing decimals]
] call CBA_fnc_addSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DISABLE LASER TOGGLE MODE
[
    "gge_canting_var_disableLaser", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Disable weapon laser when no longer canting weapon", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "GGE Canting", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true // data for this setting: [min, max, default, number of shown trailing decimals]
] call CBA_fnc_addSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////