#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F","rhsusf_c_weapons","rhsusf_main","rhs_main", "uk3cb_baf_weapons_Launchers"};
        author = "TF47 -Sonic- & Desty";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"