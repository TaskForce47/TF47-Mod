////// GGE_CORE SETTINGS ///////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DEBUG MODE TOGGLE
[
    "gge_core_var_debugMode", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    "Enable Debug Mode", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "Goobin's Gameplay Enhancements Core", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    false // data for this setting: [min, max, default, number of shown trailing decimals]
] call CBA_fnc_addSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

["GGE Core CBA Settings succesfully initialised!"] call gge_core_fnc_debugLog;
