#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {};
        author = "TF47 Dragon, TF47 Desty, TF47 Sonic, TF47 Ray, TF47 Rampage";
        VERSION_CONFIG;
    };
};
        
class CfgFunctions 
{
    class TF47
    {
        class ClearBrush //just my test
        {
            file = "z\TF47\addons\main\functions";
            class clearBrush{};
            class canClearBrush{};
        };
    };
};

class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class ClearBrush {
                    displayName = "Clear Brush";
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

#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"
