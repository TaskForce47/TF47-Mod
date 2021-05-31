#include "script_components.hpp"
class CfgPatches
{
        class TF47_AdvancedUrbanRappelling
        {
                units[] = {"TF47_AdvancedUrbanRappelling"};
                requiredVersion = 1.0;
                requiredAddons[] = {"A3_Modules_F","cba_main"};
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
