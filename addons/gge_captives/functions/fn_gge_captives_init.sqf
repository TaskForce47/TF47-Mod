#include "\z\ace\addons\captives\script_component.hpp"
if (isDedicated) exitWith {};


gge_captives_var_isEscorting = false;
gge_captives_var_currentCaptive = objNull;
gge_captives_var_captiveOffset = [-0.2, 0.9, 0];


PX_fnc_splitReplace = {
    params["_str", "_find", "_replace"];    
    private _result = ([" "+_str+" ", _find, true] call BIS_fnc_splitString) joinString _replace;    
    _result select [1, (count _result)-2];
};

gge_captives_fnc_grabCaptive = {
    if (!gge_core_var_isReloading) then {
        _holdAnim = "gge_captives_anim_holdhvt";
        
        if ((currentWeapon player) == (handgunWeapon player)) then {
            _holdAnim = "gge_captives_anim_holdhvtpistol";
        };
        
        
        
        [_holdAnim, true, true] call gge_core_fnc_playGesture;
        
    };
};

gge_captives_fnc_escortCaptiveHandler = {

    if (gge_captives_var_isEscorting && gge_core_var_weaponChanged) then {
        _pstRfl = ["pst", "rfl"];
        _animState = configName (configFile >> getText (configFile >> "CfgVehicles" >> typeOf player >> "moves") >> "States" >> (animationState player));;

        if (currentWeapon player == handgunWeapon player) then {
            _animState = [_animState, "rfl", "pst"] call PX_fnc_splitReplace;
        };
        if (currentWeapon player == primaryWeapon player) then {
            _animState = [_animState, "pst", "rfl"] call PX_fnc_splitReplace;
        };
        
        [player, ""] remoteExec ["switchMove", 0, false];
        [player, _animState] remoteExec ["switchMove", 0, false];
        
        call gge_captives_fnc_grabCaptive;
    }; 

    if (!gge_captives_var_isEscorting) then {
        if (player getVariable [QGVAR(isEscorting), false]) then {
            gge_captives_var_isEscorting = true;
            
            call gge_captives_fnc_grabCaptive;
            
            _captive = player getVariable [QGVAR(escortedUnit), objNull];
            gge_captives_var_currentCaptive = _captive;
            
            
            detach _captive;
            _captive attachTo [player, gge_captives_var_captiveOffset];
            _captive setDir 0;
            _captive setPos getPos player;
            
            
            _animChangedEHID = _captive getVariable [QGVAR(handcuffAnimEHID), -1];
            _captive removeEventHandler ["AnimChanged", _animChangedEHID];
            _captive setVariable [QGVAR(handcuffAnimEHID), -1];
            
            [_captive, animationState player] remoteExec ["switchMove", 0, false];            
            [_captive, "gge_captives_anim_hvtdefault"] remoteExec ["playActionNow", 0, true];

            
        };
    } else {
        
        // Reset anim if just finished reloading
        if (gge_core_var_finishedReload) then {
            call gge_captives_fnc_grabCaptive;
            //["gge_captives_anim_holdhvt", true, true] call gge_core_fnc_playGesture;
        };
    
                
        // Release captive if prone
        if (gge_core_var_stanceChanged) then {

            if (stance player == "PRONE") then {
                [player, gge_captives_var_currentCaptive, false] call ACE_captives_fnc_doEscortCaptive;
            };
        };    
        
        
        if (!(player getVariable [QGVAR(isEscorting), false])) then {
            gge_captives_var_isEscorting = false;
            _releaseCaptiveStance = ["ace_amovpercmstpscapwnondnon", "ace_amovpercmstpscapwnondnon"] select (stance player == "ERECT");
            [gge_captives_var_currentCaptive, _releaseCaptiveStance] remoteExec ["switchMove", 0, true];
            [gge_captives_var_currentCaptive, "gge_core_anim_clearAction"] remoteExec ["playActionNow", 0, true];
            gge_captives_var_currentCaptive = objNull;
            ["gge_core_anim_clearAction", true, true] call gge_core_fnc_playGesture;

            // If moving and release hostage, set hostage position to player position
            if ((vectorMagnitude (velocity player)) > 0) then {
                gge_captives_var_currentCaptive setPos (player modelToWorld gge_captives_var_captiveOffset);
            };
            
        };
    };
    
    
    if ((gge_captives_var_currentCaptive != objNull) && (alive gge_captives_var_currentCaptive)) then {
        [gge_captives_var_currentCaptive, animationState player] remoteExec ["playMoveNow", 0];
        if (stance _player == "PRONE") then {
            player setUnitPos "MIDDLE";
            call gge_captives_fnc_grabCaptive;
        };
    };
    
};


["GGE Captive Animation Handler Initialised..."] call gge_core_fnc_debugLog;

[gge_captives_fnc_escortCaptiveHandler]