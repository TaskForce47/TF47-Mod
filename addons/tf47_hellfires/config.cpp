#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_missileguidance","ace_hellfire","ace_compat_rhs_usf3","rhsusf_airweapons","rhsusf_c_airweapons"};
        author = "TF47 Desty, TF47 -Sonic-";
        VERSION_CONFIG;
    };
};


#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgMagazineWells.hpp"
#include "CfgWeapons.hpp"