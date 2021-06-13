#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main"};
        author = "TF47 Desty";
        VERSION_CONFIG;
    };
};

class CfgFunctions 
{
    class TF47
    {
        class COMPONENT
		{
            file = "z\TF47\addons\EnhancedNVGs\functions";
            class getVisionMode{};
            class getNvgEffect{};
            class setNvgEffect{};
		};
    };
};       

class Extended_PostInit_EventHandlers
{
	class COMPONENT
	{
		init="call compile preprocessFileLineNumbers 'z\TF47\addons\EnhancedNVGs\XEH_postInit.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class COMPONENT
	{
		init="call compile preprocessFileLineNumbers 'z\TF47\addons\EnhancedNVGs\XEH_preInit.sqf'";
	};
};
