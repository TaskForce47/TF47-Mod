#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        name = COMPONENT;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"A3_Weapons_F","rhssaf_c_weapons","rhssaf_m_weapon_g36"};
        author = "TF47 ra.Y";
        VERSION_CONFIG;
    };
};

class CfgMagazines {
    //base class
    class 30Rnd_556x45_Stanag;


    class rhssaf_30rnd_556x45_EPR_G36: 30Rnd_556x45_Stanag {
        mass =  0.9;
    };
    
    class rhssaf_30rnd_556x45_MDIM_G36: 30Rnd_556x45_Stanag {
        mass =  0.9;
    };
    
    class rhssaf_30rnd_556x45_SOST_G36: 30Rnd_556x45_Stanag {
        mass =  0.9;
    };
    
    class rhssaf_30rnd_556x45_SPR_G36: 30Rnd_556x45_Stanag {
        mass =  0.9;
    };
    
    class rhssaf_30rnd_556x45_TDIM_G36: 30Rnd_556x45_Stanag {
        mass =  0.9;
    };
    
    class rhssaf_30rnd_556x45_Tracers_G36: 30Rnd_556x45_Stanag {
        mass =  0.9;
    };
};
