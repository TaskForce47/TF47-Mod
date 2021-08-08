#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = 
        {
            "tf47_weap_maaws",
            "tf47_weap_raws_green",
            "tf47_weap_raws_olive",
            "tf47_weap_raws_sand"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F_Tank_Launchers_MRAWS","rhsusf_c_weapons","A3_Weapons_F_Tank","ace_frag"};
        author = "TF47 Desty";
        VERSION_CONFIG;
    };
};

class CfgCloudlets {
    class WPCloud;
    class WPTrails;
    
    class TF47_WP_Cloud : WPCloud {
        angle = 0;
        angleVar = 1;
        animationName = "";
        animationSpeed[] = {1000};
        animationSpeedCoef = 1;
        beforeDestroyScript = "";
        circleRadius = 0;
        circleVelocity[] = {0,0,0};
        color[] = {{1,1,1,0},{1,1,1,1},{1,1,1,0}};
        colorCoef[] = {1,1,1,1};
        colorVar[] = {0,0,0,0};
        interval = 0.06;
        lifeTime = 12;
        lifeTimeVar = 4;
        moveVelocity[] = {0,0.25,0};
        MoveVelocityVar[] = {0.25,0.25,0.25};
        MoveVelocityVarConst[] = {0,0,0};
        onTimerScript = "";
        particleFSFrameCount = 8;
        particleFSIndex = 12;
        particleFSLoop = 0;
        particleFSNtieth = 16;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleType = "Billboard";
        position[] = {0,0,0};
        positionVar[] = {4,3,4};
        positionVarConst[] = {0,0,0};
        randomDirectionIntensity = 0.04;
        randomDirectionIntensityVar = 0;
        randomDirectionPeriod = 1;
        randomDirectionPeriodVar = 0;
        rotationVelocity = 1;
        rotationVelocityVar = 20;
        rubbing = 0.1;
        size[] = {2,4,8,16,18,20,21,22};
        sizeCoef = 1;
        sizeVar = 0.3;
        timerPeriod = 1;
        volume = 7.9;
        weight = 10;
    };
    
    class TF47_WP_Trails : WPTrails {
        angle = 0;
        angleVar = 1;
        animationName = "";
        animationSpeed[] = {1000};
        animationSpeedCoef = 1;
        beforeDestroyScript = "";
        circleRadius = 0;
        circleVelocity[] = {0,0,0};
        color[] = {{1,1,1,1}};
        colorCoef[] = {1,1,1,1};
        colorVar[] = {0,0,0,0};
        interval = 0.01;
        lifeTime = 5;
        lifeTimeVar = 1;
        moveVelocity[] = {0,6,0};
        MoveVelocityVar[] = {10,5,10};
        MoveVelocityVarConst[] = {0,0,0};
        onTimerScript = "";
        particleEffects = "WPTrailEffectMain2";
        particleFSFrameCount = 2;
        particleFSIndex = 13;
        particleFSLoop = 0;
        particleFSNtieth = 16;
        particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
        particleType = "Billboard";
        position[] = {0,0,0};
        positionVar[] = {2,2,2};
        positionVarConst[] = {0,0,0};
        randomDirectionIntensity = 0;
        randomDirectionIntensityVar = 0;
        randomDirectionPeriod = 1;
        randomDirectionPeriodVar = 0;
        rotationVelocity = 0;
        rotationVelocityVar = 20;
        rubbing = 0.1;
        size[] = {0.5};
        sizeCoef = 1;
        sizeVar = 0;
        timerPeriod = 0.07;
        volume = 7.9;
        weight = 15;
    };
};

class TF47_SmokeExplosion {
    class Explosion {
        intensity = 1;
        interval = 1;
        lifeTime = 76;
        position[] = {0, 0, 0};
        qualityLevel = -1;
        simulation = "particles";
        type = "TF47_WP_Cloud";
    };
    
    class LightExp {
        intensity = 0.001;
        interval = 1;
        lifeTime = 1;
        position[] = {0, 0, 0};
        qualityLevel = -1;
        simulation = "light";
        type = "ExploLight";
    };
    
    class Trails {
        intensity = 1;
        interval = 1;
        lifeTime = 1;
        position[] = {0, 0, 0};
        qualityLevel = -1;
        simulation = "particles";
        type = "TF47_WP_Trails";
    };
};

class CfgFunctions 
{
   class TF47
   {
      class Airburst
      {
         file = "z\TF47\addons\LauncherRework\airburst";
         class initAirburst{postInit=1};
      };
   };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "ACE_Arsenal_Stats.hpp"