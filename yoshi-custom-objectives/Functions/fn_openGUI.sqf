params ["_target"];
// Retrieve the bomb preset from the object
private _cw_preset = _target getVariable ["complexWiresPreset", []];
if (isNil "_cw_preset" || {_cw_preset isEqualTo []}) exitWith {};

private _extra_preset = _target getVariable ["extrasPreset", []];
if (isNil "_extra_preset" || {_extra_preset isEqualTo []}) exitWith {};

// Store the preset in uiNamespace so the dialog can read it
uiNamespace setVariable ["DefuseDialog_ComplexWiresPreset", _cw_preset];
uiNamespace setVariable ["DefuseDialog_ExtrasPreset", _extra_preset];

// Open the dialog (if not already open)
if (!isNull (findDisplay 9999)) exitWith {};
createDialog "DefuseDialog";
