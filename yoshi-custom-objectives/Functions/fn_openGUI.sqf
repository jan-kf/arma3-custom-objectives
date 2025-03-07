params ["_target"];
// Retrieve the bomb preset from the object
private _complexWireData = _target getVariable ["complexWires", []];
if (isNil "_complexWireData" || {_complexWireData isEqualTo []}) exitWith {};

private _simpleWireData = _target getVariable ["simpleWires", []];
if (isNil "_simpleWireData" || {_simpleWireData isEqualTo []}) exitWith {};

private _extra_preset = _target getVariable ["extrasPreset", []];
if (isNil "_extra_preset" || {_extra_preset isEqualTo []}) exitWith {};

// Store the preset in uiNamespace so the dialog can read it
uiNamespace setVariable ["DefuseDialog_ComplexWires", _complexWireData];
uiNamespace setVariable ["DefuseDialog_SimpleWires", _simpleWireData];
uiNamespace setVariable ["DefuseDialog_ExtrasPreset", _extra_preset];

// Open the dialog (if not already open)
if (!isNull (findDisplay 9999)) exitWith {};
createDialog "DefuseDialog";
