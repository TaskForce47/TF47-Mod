params ["_unit","_id"];

_unit = player;

_index = _unit addEventHandler [
    "Fired",
    {
        if ((_this select 5) in MIL_AirburstAmmo) then {
            nul = [_this select 0,_this select 6] spawn MIL_fnc_airburst;
        };
    }
];

if (isClass(configFile >> "CfgPatches" >> "ace_main")) then {

    if (!(isNil "MIL_HE_Airburst_ACE3Action")) exitWith {};
    
    MIL_HE_Airburst_ACE3Action = [
        "MIL_HE_Airburst",
        "HE Fuse Setting",
        "MIL_Airburst\pics\MIL_Explosion.paa",
        {CreateDialog "MIL_fuseSetting_HE"},
        {
            ((currentMagazine _target) in MIL_AirburstAmmo) &&
            (currentMagazine _target) in MIL_AirburstAmmo
        }
    ] call ace_interact_menu_fnc_createAction;

    [
        player,
        1,
        ["ACE_SelfActions"],
        MIL_HE_Airburst_ACE3Action
    ] call ace_interact_menu_fnc_addActionToObject;

    } else {

    _id = _unit addAction [
        "<t color='#88B985'>HE Fuse Setting</t>",
        {CreateDialog "MIL_fuseSetting_HE"},
        [],
        10,
        true,
        true,
        "",
        "(currentMagazine _target) in MIL_AirburstAmmo"
    ];
};