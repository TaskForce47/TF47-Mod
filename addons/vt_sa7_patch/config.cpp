#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"weapons_v_f_vietnam_c","sounds_f_vietnam_c"};
        author = "TF47 Dragon";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
