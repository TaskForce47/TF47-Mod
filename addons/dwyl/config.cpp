#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = "Dismount Where You Look";
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.0.1;
        requiredAddons[] = {"cba_common"};
        author = "Ampersand";
        authors[] = {"Ampersand"};
        authorUrl = "https://github.com/ampersand38/dwyl";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class DismountWhereYouLook
        {
            file = "z\TF47\addons\dwyl\functions";
            class exit{};
            class findLookedAt{};
            class getExits{};
            class showExits{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
