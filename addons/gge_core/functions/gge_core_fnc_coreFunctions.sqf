
gge_core_fnc_playGesture = {
    params ["_gesture", ["_playWhileSprinting", true], ["_jip", false]];
    
    if (!gge_core_var_isReloading) then {
        _playAnim = !(gge_core_var_isSprinting && !_playWhileSprinting);
        
        if (_playAnim) then {
            [player, _gesture] remoteExec ["playActionNow", 0, _jip];
            if (gge_core_var_debugMode) then {systemChat ('GESTURE "' + (str _gesture) + '" PLAYED!');};
            gge_core_var_gestureJustPlayed = true;
        };
        
        
        
    };
    
};



// Core functions have been loaded succesfully
["GGE Core functions succesfully initialised!"] call gge_core_fnc_debugLog;