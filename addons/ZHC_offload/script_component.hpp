#define COMPONENT offload
#define COMPONENT_BEAUTIFIED Offload
#include "\t\zhc\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_OFFLOAD
	#define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_OFFLOAD
	#define DEBUG_SETTINGS DEBUG_SETTINGS_OFFLOAD
#endif

#include "\t\zhc\addons\main\script_macros.hpp"

#define DEFAULT_DELAY_CYCLE 20
#define DEFAULT_DELAY_CHECK 5
#define DEFAULT_DELAY_PER 15
#define DEFAULT_DELAY_EMERG 5
#define DEFAULT_DELAY_REBAL 30
#define BLACKLIST_UAV "UAV", "UAV_AI_base_F", "B_UAV_AI", "O_UAV_AI", "I_UAV_AI"
#define BLACKLIST_NAMES "BIS_SUPP_HQ_"

#define ICON_TRANSPARENCY 0.9

#define COLOR_SERVER 255/255, 54/255, 0/255
#define COLOR_HEADLESS 100/255, 200/255, 36/255
#define COLOR_ZEUS 0/255, 15/255, 255/255
#define COLOR_UNTRANSFERRED 247/255, 211/255, 12/255
#define COLOR_LOCAL 255/255, 4/255, 179/255
