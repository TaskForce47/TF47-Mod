#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "TF47_slingload_apexFitting",
            "TF47_slingload_wreckDummy"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_interaction"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class Slingload
        {
            file = "z\TF47\addons\slingload\functions";
            class adjustRigging{};
            class canAdjustRigging{};
            class attachCargo{};
            class canAttachCargo{};
            class cancelPlacement{};
            class canReleaseCargo{};
            class canRemoveRigging{};
            class canRigCargo{};
            class canRigCargoAuto{};
            class canRigCargoManual{};
            class getCargoLiftPoints{};
            class handleScrollWheel{};
            class pickUpFitting{};
            class releaseCargo{};
            class removeRigging{};
            class rigCargo{};
            class rigCargoAuto{};
            class rigCargoManual{};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
