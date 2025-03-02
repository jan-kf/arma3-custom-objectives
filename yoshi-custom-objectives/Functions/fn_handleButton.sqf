params ["_index"];

private _preset = uiNamespace getVariable ["DefuseDialog_ComplexWiresPreset", []];
if (isNil "_preset" || {_preset isEqualTo []}) exitWith {};

private _buttonCount = _preset select 0;
private _buttonsData = _preset select 1;
if (_index < 0 || {_index >= _buttonCount}) exitWith {};

private _data = _buttonsData select _index;
private _led   = _data select 0;
private _star  = _data select 1;
private _color = _data select 2;

closeDialog 0;
hint format [
    "LED: %1\nStar: %2\nColor: %3",
    if (_led) then {"ON"} else {"OFF"},
    if (_star) then {"YES"} else {"NO"},
    _color
];
