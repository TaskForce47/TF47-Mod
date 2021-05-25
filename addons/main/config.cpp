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
      class Dummy //just my dummy test for the function Viewer
      {
         tag = "TF47";
         requiredAddons[] = {postInit=1};
      };
   };
};
#include "CfgEventHandlers.hpp"
#include "CfgModuleCategories.hpp"