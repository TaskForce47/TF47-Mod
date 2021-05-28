#include "script_component.hpp"

params [["_newState", true]];

if (_newState) then {
     showHUD GVAR(vanillaHUD);
} else {
     GVAR(vanillaHUD) = shownHUD;
     showHUD [false,false,false,false,false,false,false,false];
};
