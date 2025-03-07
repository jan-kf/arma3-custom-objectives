params ["_CW_Data", "_extraData"];

private _wireData = _CW_Data select 1;
private _lastDigitIsEven = (_extraData select 1) select 1;
private _hasParallelPort = "port_parallel" in (_extraData select 2);
private _has2OrMoreBatteries = count (_extraData select 3) >= 2;

private _solved = true;

{
	_solved = _solved && [_x, _lastDigitIsEven, _hasParallelPort, _has2OrMoreBatteries] call YOSHI_CO_CHECK_COMPLEX_WIRE;
} forEach _wireData;

_solved