#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F","rhsusf_c_weapons","rhsusf_main","ace_interaction","A3_Weapons_F_Tank_Launchers_MRAWS","UK3CB_BAF_Weapons_Ammo"};
        author = "TF47 Desty";
        VERSION_CONFIG;
    };
};

class CfgCloudlets {
	class Default;
	class WPCloud;
    
    class TF47_HC_EX3 : WPCloud {
		lifeTime = 120;
		lifeTimeVar = 1;
		coreDistance = 0;
		damageTime = 1;
		coreIntensity = 0.2;
		constantDistance = 1;
		blockAIVisibility = true;
		rubbing = 0.02;
		weight = 1.2777;
		volume = 1;
		
		color[] = {{0.95,1,0.95,0.9},{0.95,1,0.95,0.85},{0.95,1,0.95,0.87},{0.95,1,0.95,0.84}};
		size[] = {21,22,24,26,31,34,35,36};
	};
    
    class TF47_SmokeExplosion {
        class Explosion1 {
            intensity = 1;
            interval = 1;
            lifeTime = 76;
            position[] = {0, 0, 0};
            qualityLevel = -1;
            simulation = "particles";
            type = "TF47_HC_EX3";
        };
        
        class LightExp {
            intensity = 0.001;
            interval = 1;
            lifeTime = 1;
            position[] = {0, 0, 0};
            simulation = "light";
            type = "ExploLight";
        };
    };
};

#include "CfgWeapons.hpp"
#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "ACE_Arsenal_Stats.hpp"