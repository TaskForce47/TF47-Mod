#include "TF47_AUR_MACROS.h"

params ["_player", "_length"];
if (AUR_GET_STATUS_HOLDING_ROPE(_player)) exitWith {false};
if !(_player call TF47_fnc_AUR_Has_Rope_Check) exitWith {false};

true