gge_core_fnc_checkForADSChange = {

    // Reset ADS changed state on this frame as it has been used for all other functions by this point
    if (gge_core_var_ADSChanged) then {
        gge_core_var_ADSChanged = false;
    };
    
    _cameraViewChanged = !(cameraView isEqualTo gge_core_var_lastFrameCameraView);
    gge_core_var_ADSChanged = _cameraViewChanged && (vehicle player == player);
    
    // reset last frame camera view
    if (gge_core_var_ADSChanged && (vehicle player == player)) then {gge_core_var_lastFrameCameraView = cameraView};
    

};

["GGE ADS State Change Detection System Initialised..."] call gge_core_fnc_debugLog;

// Return the function to be added to the main loop
[gge_core_fnc_checkForADSChange]