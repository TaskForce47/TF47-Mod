#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = "Ride Where You Look";
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.0.1;
        requiredAddons[] = {"cba_common"};
        author = "Ampersand";
        authors[] = {"Ampersand"};
        authorUrl = "https://github.com/ampersand38/rwyl";
    };
};

class CfgFunctions 
{
    class TF47
    {
        class RideWhereYouLook
        {
            file = "z\TF47\addons\rwyl\functions";
            class findSeat{};
            class moveSeat{};
            class moveSeatLocal{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
