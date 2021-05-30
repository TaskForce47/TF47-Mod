#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F","rhsusf_c_weapons","rhsusf_main","rhs_main","uk3cb_baf_weapons_Launchers","rhssaf_c_weapons","rhssaf_m_weapon_g36"};
        author = "TF47 -Sonic-, Desty, ra.Y";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"