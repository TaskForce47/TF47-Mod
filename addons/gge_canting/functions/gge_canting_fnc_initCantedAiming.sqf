gge_canting_var_cantMode = false;
gge_canting_var_aiming = false;
gge_canting_var_cantingAim = false;
gge_canting_var_rmbHeld = false;
gge_canting_var_toggleADSMode = false;
gge_canting_var_crosshairMode = true;
gge_canting_var_drawCrosshair = false;
gge_canting_var_crosshairColour = [1,1,1,1];
gge_canting_var_enableGunLight = true;
gge_canting_var_disableLaser = true;


// compile animation functions
gge_canting_fnc_cantAim = compile preprocessFileLineNumbers "gge_canting\functions\gge_canting_fnc_cantAim.sqf";
gge_canting_fnc_decantAim = compile preprocessFileLineNumbers "gge_canting\functions\gge_canting_fnc_decantAim.sqf";


// Initialise input
waituntil {!isnull (finddisplay 46)};
gge_canting_fnc_initInput = call compile preprocessFileLineNumbers "gge_canting\functions\gge_canting_fnc_inputInitialiser.sqf";


// Initialise canting animation situations handler
gge_canting_fnc_animationHandler = compile preprocessFileLineNumbers "gge_canting\functions\gge_canting_fnc_animationHandler.sqf";



// Handle crosshair drawing
addMissionEventHandler ["Draw3D", { 

    gge_canting_var_drawCrosshair = gge_canting_var_cantingAim && (currentVisionMode player != 1) && gge_canting_var_crosshairMode;

    if (gge_canting_var_drawCrosshair) then { 
        _begW = player modelToWorldVisual (player selectionPosition "righthand");
        _endW = (_begW vectorAdd (player weaponDirection currentWeapon player vectorMultiply 99999999)); 
        drawIcon3D ["\A3\ui_f\data\igui\cfg\weaponcursors\arifle_gs.paa", gge_canting_var_crosshairColour, _endW, 2, 2, 0, "", 1, 0.05, "TahomaB"]; 
    };
}];


gge_canting_fnc_toggleCantMode = {
    if (gge_canting_var_rmbHeld or (gge_canting_var_toggleADSMode && gge_canting_var_aiming)) then {
    
    
        _ads = cameraOn == player && cameraView == "Gunner";
        if (_ads) then {
            gge_canting_var_cantMode = true;
            call gge_canting_fnc_cantAim;
        } else {
            call gge_canting_fnc_decantAim;
            gge_canting_var_cantMode = false;
        };
        
    };
};

// Initialise CBA controls
gge_canting_fnc_CBAInputInitialiser = call compile preprocessFileLineNumbers "gge_canting\functions\gge_canting_fnc_CBAInputInitialiser.sqf";






["GGE Canting components and systems succesfully initialised!"] call gge_core_fnc_debugLog;

// Return function for main loop execution
[gge_canting_fnc_animationHandler]

