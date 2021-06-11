#include "script_components.hpp"
class CfgPatches
{
        class TF47_AdvancedUrbanRappelling
        {
                author = "duda123, TF47 Rampage";
                name = "Advanced Urban Rappelling";
                url = "https://github.com/sethduda/AdvancedUrbanRappelling";
                units[] = {"AUR_AdvancedUrbanRappelling","AUR_RopeSmallWeight"};
                requiredVersion = 1;
                requiredAddons[] = {"A3_Modules_F","cba_main"};
                weapons[] = {"AUR_Rappel_Gear","AUR_Rappel_Rope_10","AUR_Rappel_Rope_20","AUR_Rappel_Rope_30","AUR_Rappel_Rope_50","AUR_Rappel_Rope_70"};
        };
};
class CfgNetworkMessages
{
        class AdvancedUrbanRappellingRemoteExecClient
        {
                module = "AdvancedUrbanRappelling";
                parameters[] = {"ARRAY","STRING","OBJECT","BOOL"};
        };
        class AdvancedUrbanRappellingRemoteExecServer
        {
                module = "AdvancedUrbanRappelling";
                parameters[] = {"ARRAY","STRING","BOOL"};
        };
};
class CfgFunctions
{

#include "functions\functions.h"

};
#include "CfgEventHandlers.hpp"

#include "cfgWeapons.hpp"
#include "cfgAnimations.hpp"

class CfgSounds
{
        class AUR_Rappel_Loop
        {
                name = "AUR_Rappel_Loop";
                sound[] = {"\z\TF47\addons\AdvancedUrbanRappelling\sounds\AUR_Rappel_Loop.ogg", db+5, 1};
                titles[] = {0,""};
        };
        class AUR_Rappel_Start
        {
                name = "AUR_Rappel_Start";
                sound[] = {"\z\TF47\addons\AdvancedUrbanRappelling\sounds\AUR_Rappel_Start.ogg", db+10, 1};
                titles[] = {0,""};
        };
        class AUR_Rappel_End
        {
                name = "AUR_Rappel_End";
                sound[] = {"\z\TF47\addons\AdvancedUrbanRappelling\sounds\AUR_Rappel_End.ogg", db+10, 1};
                titles[] = {0,""};
        };
        class GVAR(Rope) {
                name = "ACE_Fastroping_Rope";
                sound[] = {QUOTE(PATHTOF(data\sounds\fastroping_rope.ogg)), 10, 1.0};
                titles[] = {};
        };
        class GVAR(Thud) {
                name = "ACE_Fastroping_Thud";
                sound[] = {QUOTE(PATHTOF(data\sounds\fastroping_thud.ogg)), 10, 1.0};
                titles[] = {};
    };
};

class CfgVehicles
{
        class Land_Camping_Light_F;
        class AUR_RopeSmallWeight: Land_Camping_Light_F
        {
                scope = 2;
                displayname = "Rope weight";
                model = "\z\TF47\addons\AdvancedUrbanRappelling\assets\AUR_weightSmall";
        };
};

