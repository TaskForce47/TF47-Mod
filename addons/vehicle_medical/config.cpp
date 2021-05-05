#include "config_macros.hpp"

class CfgPatches {
    class ADDON
    {
        name = QUOTE(ADDON_NAME);
        author = "M3ales";
        url = "https://github.com/M3ales/MIRA_Vehicle_Medical";
        requiredAddons[] = {"ace_interact_menu", "ace_medical"};
        units[] = {};
        weapons[] = {};
    };
};

class CfgFunctions {
    class ADDON {
        class VehicleMedical {
            tag = QUOTE(ADDON);
            requiredAddons[] = {"ace_interact_menu",  "ace_medical"};
            file = QUOTE(z\TF47\addons\ADDON\functions);
            class buildUnstablePassengerActions {};
            class buildUnstableActions {};
            class isBleeding {};
            class isCardiacArrest {};
            class isUnconscious {};
            class buildStablePassengerActions {};
            class buildStableActions {};
            class getOpenWounds {};
            class getStitchableWounds {};
            class needsBandage {};
            class openMedicalMenu {};
        };
    };
};

#include "CfgVehicles.hpp"