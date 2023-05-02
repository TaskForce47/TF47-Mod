params [["_execFunctions", false]];
// If !_execFunctions then we just want to return the functions, not execute them.

gschs_var_perFrameStateChangeHandlers = [];
gschs_var_UIFrameStateChangeHandlers = [];



// STATE CHANGE HANDLER FUNCTIONS
gschs_fnc_addStateChangeHandler = {
	params["_boolToCheck", "_codeToExecute", ["_executeInUIEnvironment", false]];
	
	_state = missionNamespace getVariable [_boolToCheck, nil];
	_stateExists = !(isNil _boolToCheck);
	_lastFrameState = _state; 
	
	if (typeName _codeToExecute != "ARRAY") then {
		_codeToExecute = [_codeToExecute];
	};
	
	_SCHValues = [_boolToCheck, _codeToExecute, _lastFrameState, _executeInUIEnvironment];
	
	[
		// IF STATE DOES NOT EXIST
		systemChat ("GSCHS ERROR: STATE: " + _boolToCheck + " DOES NOT EXIST IN MISSION NAMESPACE!"),
		// IF STATE DOES EXIST, ADD IT TO LIST OF STATECHANGEHANDLERS
		[_SCHValues] call gschs_fnc_appendStateChangeHandler
	] select (_stateExists);
	
};

gschs_fnc_appendStateChangeHandler = {
	params["_sch"];
	
	_handlerAdded = false;
	_stateCheckIndex = 0;
	
	_checkArray = [gschs_var_perFrameStateChangeHandlers, gschs_var_UIFrameStateChangeHandlers] select (_sch select 3);
	
	// Check if a handler for this state already exists
	while {(!_handlerAdded) && (_stateCheckIndex < (count _checkArray))} do {
		
		_compareStateHandler = _checkArray select _stateCheckIndex;
		_compareState = _compareStateHandler select 0;
		_functions = (_sch select 1);
		
		// If stateHandler exists already, add this handlers functions to it. (Don't double up)
		if (_compareState == (_sch select 0)) then {
			// Append all functions to existing handler
			{
				(_compareStateHandler select 1) append [_x];
			} foreach _functions;
			
			_handlerAdded = true;
		};
		
		_stateCheckIndex = 	_stateCheckIndex + 1;
	};
	
	if (!_handlerAdded) then {
		_checkArray append [_sch];
	};
};

gschs_fnc_updateStateChangeHandler = {
	params ["_stateName", "_newLastFrameState", "_UIEnvironment"];
	if (isNil (missionNamespace getVariable ["_stateName", nil])) exitWith { systemChat "GSCHS ERROR: CANNOT UPDATE AN SCH THAT DOES NOT ALREADY EXIST!"; };
	
	_checkArray = [gschs_var_perFrameStateChangeHandlers, gschs_var_UIFrameStateChangeHandlers] select (_UIEnvironment);
	
	_stateChangeHandler = (_checkArray select {(_x select 0) == _stateName}) select 0;
	_stateChangeHandler set [2, _newLastFrameState];
	
};

gschs_fnc_processStateChangeHandler = {
	params ["_sch"];
	_stateName = _sch select 0;
	_state = missionNamespace getVariable [_stateName, nil];
	
	_functionsToExecute = _sch select 1;
	_lastFrameState = _sch select 2;
	_UIEnvironment = _sch select 3;

	_stateChanged = (str _state) != (str _lastFrameState);
		
	if (_stateChanged) then {
		_args = [missionNamespace getVariable _stateName, _UIEnvironment];
		// Call functions on state change
		{
			_args call _x;
		} foreach _functionsToExecute;
		
		// update lastFrameState
		[_stateName, _state, _UIEnvironment] call gschs_fnc_updateStateChangeHandler;
	};
};


gschs_fnc_evaluatePerFrameStateChangeHandlers = {
	{
		[_x] call gschs_fnc_processStateChangeHandler;
	} foreach gschs_var_perFrameStateChangeHandlers;
};

gschs_fnc_evaluateUIFrameStateChangeHandlers = {
	{
		[_x] call gschs_fnc_processStateChangeHandler;
	} foreach gschs_var_UIFrameStateChangeHandlers;
};


if (_execFunctions) then {
	addMissionEventHandler ["Draw3D", {call gschs_fnc_evaluateUIFrameStateChangeHandlers}];

	_handle = [gschs_fnc_evaluatePerFrameStateChangeHandlers, 0] call CBA_fnc_addPerFrameHandler;
};



// Return the functions
[gschs_fnc_evaluateUIFrameStateChangeHandlers, gschs_fnc_evaluatePerFrameStateChangeHandlers]




