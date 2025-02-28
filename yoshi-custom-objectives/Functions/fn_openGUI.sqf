params ["_target"];
// Retrieve the bomb preset from the object
private _preset = _target getVariable ["bombPreset", []];
if (isNil "_preset" || {_preset isEqualTo []}) exitWith {};

// Store the preset in uiNamespace so the dialog can read it
uiNamespace setVariable ["DefuseDialog_Preset", _preset];

// Open the dialog (if not already open)
if (!isNull (findDisplay 9999)) exitWith {};
createDialog "DefuseDialog";
