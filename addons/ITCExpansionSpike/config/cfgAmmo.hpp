class CfgAmmo {
	class M_Titan_AT;
	class tf47_itc_land_spikeLR: M_Titan_AT {
    irLock = 1;
    laserLock = 0;
    airLock = 0;
    timeToLive = 50;
    // Turn off arma crosshair-guidance
    manualControl = 0;
    
    caliber = 230;
    hit = 1000;         // default: 800
    indirectHit = 20;
    indirectHitRange = 2;
    // ACE uses these values
    //trackOversteer = 1;
    //trackLead = 0;

    initTime = 0;
    class ace_missileguidance {
      attackProfiles[] = {"itc_land_spike_guidance"};
      canVanillaLock = 0;
      defaultAttackProfile = "itc_land_spike_guidance";
      defaultSeekerLockMode = "";
      defaultSeekerType = "";
      enabled = 1;
      minDeflection = 0.00005;      // Minium flap deflection for guidance
      maxDeflection = 0.0025;       // Maximum flap deflection for guidance
      incDeflection = 0.00005;      // The incrmeent in which deflection adjusts.
      seekerAccuracy = 1;
      seekerAngle = 180;
      seekerLockModes[] = {"LOBL"};
      seekerMaxRange = 4000;
      seekerMinRange = 0;
      seekerTypes[] = {"Optic"};
      seekLastTargetPos = 1;
      useModeForAttackProfile = 0;
    };
  };
};
