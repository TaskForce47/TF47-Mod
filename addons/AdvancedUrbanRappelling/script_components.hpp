#define COMPONENT AUR
#define COMPONENT_BEAUTIFIED AdvancedUrbanRappeling

#include "\z\TF47\addons\main\script_mod.hpp"

// #define DRAW_FASTROPE_INFO
// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_AUR
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_AUR
    #define DEBUG_SETTINGS DEBUG_SETTINGS_AUR
#endif

#include "\z\TF47\addons\main\script_macros.hpp"
//#include "script_xeh.hpp"

#define AUR_DEFAULT_ROPE_LENGTH 60

//Does this even work?

// ropes and their lengths defined as valid rappel ropes [name of rope item, length in m]
#define AUR_Rappellng_Ropes  [["AUR_Rappel_Rope_10", 10],["ACE_rope12",12],["ACE_rope15", 15],["ACE_rope18", 18],["AUR_Rappel_Rope_20", 20],["ACE_rope27", 27],["AUR_Rappel_Rope_30", 30],["ACE_rope36",36],["AUR_Rappel_Rope_50", 50],["AUR_Rappel_Rope_70", 70]]

#define AUR_ADVANCED_RAPPELING_ITEMS_NEEDED 0   // CBA not installed / used security
#define AUR_ADVANCED_RAPPELING_ROPES_HANDLING 0 // CBA not installed / used security
#define AUR_ADVANCED_RAPPELING_VELOCITY 1       // CBA not installed / used security
#define AUR_ADVANCED_RAPPELING_NEW_ACTION false // CBA not installed / used security
#define AUR_ADVANCED_RAPPELING_NEW_ACTION_TIME 3// CBA not installed / used security
#define AUR_AI_RAPPEL_CHECK_INTERVAL 2          // interval in seconds between AI rappel checks. Performance increases with higher values, but will cause a 'lag' on appearing / disappearing player action menu entry.
#define AUR_Minimal_Rappel_Height 4             // minimal height in meters, a unit has to be above ground, for rappel action to be available
