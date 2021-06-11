params ["_unit", "_rappelPoint", "_rappelDirection"];
private _unitStartPosition = getPosASL _unit;
_unitStartPosition = _rappelPoint vectorAdd (_rappelDirection vectorMultiply 2);// start player rappelling 2m out from the rappel point                
_unitStartPosition set [2, getPosASL _unit select 2];
_unitStartPosition
