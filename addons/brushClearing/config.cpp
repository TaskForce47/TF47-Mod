class CfgPatches {
    class brushClearing {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.6;
        requiredAddons[] = {"ace_trenches"};
        version = 2.0.0;
        versionStr = 2.0.0;
        versionAr[] = {2, 0, 0};
        author = "TF47 Desty";
    };
};


#include "CfgFunctions.hpp"


class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class ClearBrush {
                    displayName = "Clear Grass / Bush";
                    condition = "[_player] call TF47_fnc_canClearBrush";
                    //wait a frame to handle "Do When releasing action menu key" option
                    statement = "[{[] call TF47_fnc_clearBrush},[]] call CBA_fnc_execNextFrame";
                    exceptions[] = {};
                    showDisabled = 0;
                    //icon = QPATHTOF(UI\icon_sandbag_ca.paa);
                };
            };
        };
    };
};
