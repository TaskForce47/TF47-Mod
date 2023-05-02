gsas_var_currentStagedAnim = nil;
gsas_var_currentAnimStage = nil;
gsas_var_playingStagedAnim = false;
gsas_var_stagedAnimCompletionCode = nil;



gsas_fnc_playStagedAnimation = {
    params ["_animStages", "_codeToTriggerWhenComplete"];    
    // Stages format = [animation name, stage length, animation being played?, animation stage completed?, code to execute on completion]
    
    gsas_var_playingStagedAnim = true;
    // set current anim to this
    gsas_var_currentStagedAnim = _animStages;
    // Set current stage of anim to first stage
    gsas_var_currentAnimStage = gsas_var_currentStagedAnim select 0;
    // update code to be executed when all anim stages are finished
    gsas_var_stagedAnimCompletionCode = _codeToTriggerWhenComplete;
    

};

gsas_fnc_playAnimStage = {
    params ["_animStage"];

    // 0 - animation
    _anim = _animStage select 0;
    // 1 - stage length 
    _length = _animStage select 1;
    if (_length < 0) then {
        _length = getNumber (configFile >> "CfgGesturesMale" >> "States" >> _anim >> "speed");
        _length = 1/_length;
    };
    // 2 - stage being played now
    _beingPlayed = _animStage select 2;
    // 3 - stage completed
    _completed = _animStage select 3;
    // 4 - code to execute on completion (not really used in this function)
    _code = _animStage select 4;
    
        
    // Begin timer
    [_length, false] call BIS_fnc_countDown;
    
    // Play animation
    [_anim] call gge_core_fnc_playGesture;
    
    // set current anim stage
    gsas_var_currentAnimStage = _animStage;
    
    // Set playing var in current animstage to true
    gsas_var_currentAnimStage set [2, true];
    
};

gsas_fnc_endAnimStage = {
    // Current anim stage completed, find next stage
    // mark this stage as completed
    gsas_var_currentAnimStage set [2, false];
    gsas_var_currentAnimStage set [3, true];
    
    _codeToExecute = gsas_var_currentAnimStage select 4;
    
    // If there is any code to execute at the end of this stage, do it now
    if (!isNil "_codeToExecute") then {
        
        call _codeToExecute;
        
    };
};

gsas_fnc_finishStagedAnim = {
    // There are no more stages to play, the animation is over!
    // Reset the timer.
    [-1] call BIS_fnc_countDown;
    // If we have code to call on animation completion, call it now.
    if (!isNil "gsas_var_stagedAnimCompletionCode") then {
        call gsas_var_stagedAnimCompletionCode;
    };
    
    // reset staged anim global variables
    gsas_var_currentStagedAnim = nil;
    gsas_var_currentAnimStage = nil;
    gsas_var_playingStagedAnim = false;

};

gsas_fnc_handleStagedAnim = {
    if (gsas_var_playingStagedAnim && (!isNil "gsas_var_currentStagedAnim")) then {
        if (!isNil "gsas_var_currentAnimStage") then {
            _animBeingPlayed = gsas_var_currentAnimStage select 2;
            if (!_animBeingPlayed) then {
                //  if we have just transitioned to this stage, play it
                [gsas_var_currentAnimStage] call gsas_fnc_playAnimStage;
            } else {
                _timerFinished = !([true] call BIS_fnc_countDown);
                if (_timerFinished) then {
                
                    call gsas_fnc_endAnimStage;
                
                    // get all stages not marked as complete
                    _remainingStages = gsas_var_currentStagedAnim select {!(_x select 3)};
                    
                    if ((count _remainingStages) > 0) then {
                        // We have found another stage to play, so play it.
                        _stageToPlay = _remainingStages select 0; 
                        [_stageToPlay] call gsas_fnc_playAnimStage;
                        
                    } else {
                        
                        call gsas_fnc_finishStagedAnim;
                        
                    };
                        
                };
            };
            
            _animCompleted = gsas_var_currentAnimStage select 3;
        };
    };
};



// Staged anim handler functions have been loaded succesfully
["GGE Core Staged Animation Handler succesfully initialised!"] call gge_core_fnc_debugLog;


// return anim handler for main loop
_handle = [gsas_fnc_handleStagedAnim, 0] call CBA_fnc_addPerFrameHandler;
//[gsas_fnc_handleStagedAnim]