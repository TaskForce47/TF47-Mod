#include "\z\ace\addons\captives\script_component.hpp"
if (isDedicated) exitWith {};


gge_captives_var_isEscorting = false;
gge_captives_var_currentCaptive = objNull;
gge_captives_var_captiveOffset = [-0.2, 0.9, 0];

gge_captives_fnc_escortCaptiveHandler = {


    if (!gge_captives_var_isEscorting) then {
        if (player getVariable [QGVAR(isEscorting), false]) then {
            gge_captives_var_isEscorting = true;
            
            ["gge_captives_anim_holdhvt", true, true] call gge_core_fnc_playGesture;

            
            _captive = player getVariable [QGVAR(escortedUnit), objNull];
            gge_captives_var_currentCaptive = _captive;
            
            
            detach _captive;
            _captive attachTo [player, gge_captives_var_captiveOffset];
            _captive setDir 0;
            _captive setPos getPos player;
            
            
            _animChangedEHID = _captive getVariable [QGVAR(handcuffAnimEHID), -1];
            _captive removeEventHandler ["AnimChanged", _animChangedEHID];
            _captive setVariable [QGVAR(handcuffAnimEHID), -1];
            
            [_captive, animationState player] remoteExec ["switchMove", 0, true];
            [_captive, "gge_captives_anim_hvtdefault"] remoteExec ["playActionNow", 0, true];

            
        };
    } else {
    
        
        // Release captive if prone
        if (gge_core_var_stanceChanged) then {

            if (stance player == "PRONE") then {
                [player, gge_captives_var_currentCaptive, false] call ACE_captives_fnc_doEscortCaptive;
            };
        };
        
        
        if (!(player getVariable [QGVAR(isEscorting), false])) then {
            gge_captives_var_isEscorting = false;
            gge_captives_var_currentCaptive playMoveNow "ace_amovpercmstpscapwnondnon";
            [_captive, "gge_core_anim_clearAction"] remoteExec ["playActionNow", 0, true];
            gge_captives_var_currentCaptive = objNull;
            ["gge_core_anim_clearAction", true, true] call gge_core_fnc_playGesture;

            // If moving and release hostage, set hostage position to player position
            /*
            if ((vectorMagnitude (velocity player)) > 0) then {
                gge_captives_var_currentCaptive setPos (player modelToWorld gge_captives_var_captiveOffset);
            };
            */
            
        };
    };
    
    
    
};




// Add reloaded event handler so that we know when to reset the animation
player addEventHandler ["Reloaded", {
    params ["_unit", "_weapon", "_muzzle", "_newMagazine", "_oldMagazine"];
    
    if (gge_captives_var_isEscorting) then {
        ["gge_captives_anim_holdhvt", true, true] call gge_core_fnc_playGesture;
    };
    
}];





["GGE Captive Animation Handler Initialised..."] call gge_core_fnc_debugLog;

[gge_captives_fnc_escortCaptiveHandler]