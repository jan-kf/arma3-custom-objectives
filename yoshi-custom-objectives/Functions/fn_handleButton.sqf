params ["_index"];

private _complexWireData = uiNamespace getVariable ["DefuseDialog_ComplexWires", []];
if (isNil "_complexWireData" || {_complexWireData isEqualTo []}) exitWith {};
private _extra_preset = uiNamespace getVariable ["DefuseDialog_ExtrasPreset", []];
if (isNil "_extra_preset" || {_extra_preset isEqualTo []}) exitWith {};

private _lastDigitIsEven = (_extra_preset select 1) select 1;
private _hasParallelPort = "port_parallel" in (_extra_preset select 2);
private _has2OrMoreBatteries = count (_extra_preset select 3) >= 2;

private _object = _extra_preset select 0;

private _buttonCount = _complexWireData select 0;
private _buttonsData = _complexWireData select 1;
if (_index < 0 || {_index >= _buttonCount}) exitWith {};

private _data = _buttonsData select _index;
_data set [3, true]; // Simulate a cut wire
uiNamespace setVariable ["DefuseDialog_ComplexWires", _complexWireData];
_object setVariable ["complexWires", _complexWireData, true];

private _correct = [_data, _lastDigitIsEven, _hasParallelPort, _has2OrMoreBatteries] call YOSHI_CO_CHECK_WIRE;

private _isDone = [_complexWireData, _extra_preset] call YOSHI_CO_fnc_checkComplexWiresSolution;

private _display = uiNamespace getVariable ["DefuseDialog", displayNull];
if (isNull _display) exitWith {};

if (_isDone) then {
    private _statusCtrl = _display displayCtrl 1000;
    _statusCtrl ctrlSetText "\yoshi-custom-objectives\UI\moduleDoneLightOn.paa";
};
private _wireCtrl = _display displayCtrl (1400 + _index);
_wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireNone_vert.paa";

if (!_correct) then {
    createVehicle ["Bomb_04_F", getPosATL _object, [], 0, "CAN_COLLIDE"];
    deleteVehicle _object;
};


hint format [
    "Was that right?: %1",
    _correct
];
