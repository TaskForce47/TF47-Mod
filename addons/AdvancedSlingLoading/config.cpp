class CfgPatches {
   class AdvancedSlingLoading {
      units[]            = {
         "AdvancedSlingLoading"
      };
      requiredVersion      = 1;
      requiredAddons[]   = {
         "A3_Modules_F"
      };
   };
};
class CfgNetworkMessages {
   class AdvancedSlingLoadingRemoteExecClient {
      module         = "AdvancedSlingLoading";
      parameters[]   = {
         "ARRAY",
         "STRING",
         "OBJECT",
         "BOOL"
      };
   };
   class AdvancedSlingLoadingRemoteExecServer {
      module         = "AdvancedSlingLoading";
      parameters[]   = {
         "ARRAY",
         "STRING",
         "BOOL"
      };
   };
};
class CfgFunctions {
   class SA {
      class AdvancedSlingLoading {
         file = "\AdvancedSlingLoading\functions";
         class advancedSlingLoadingInit {
            preInit = 1;
         };
      };
   };
};
class Extended_PreInit_EventHandlers {
   class SA {
      init = "call compile preprocessFileLineNumbers '\AdvancedSlingLoading\scripts\XEH_preInit.sqf'"; // CBA_a3 integration
   };
};
class Extended_PostInit_EventHandlers {
   class SA {
      init = "call compile preprocessFileLineNumbers '\AdvancedSlingLoading\scripts\XEH_postInit.sqf'"; // CBA key binding integration
   };
};