params ["_index"];

private _keypadData = uiNamespace getVariable ["DefuseDialog_Keypad", []];
if (isNil "_keypadData" || {_keypadData isEqualTo []}) exitWith {};

private _extra_preset = uiNamespace getVariable ["DefuseDialog_ExtrasPreset", []];
if (isNil "_extra_preset" || {_extra_preset isEqualTo []}) exitWith {};

private _object = _extra_preset select 0;

private _glyphs = _keypadData select 0;
private _answerGlyphs = _keypadData select 1;
private _responses = _keypadData select 2;

private _buttonCount = count _glyphs;

if (_index < 0 || {_index >= _buttonCount}) exitWith {};

private _glyph = _glyphs select _index;
private _answerGlyph = _answerGlyphs select (_answerGlyphs find _glyph);


_responses pushBack _glyph;


uiNamespace setVariable ["DefuseDialog_Keypad", _keypadData];
_object setVariable ["keypad", _keypadData, true];

private _display = uiNamespace getVariable ["DefuseDialog", displayNull];
if (isNull _display) exitWith {};

private _tile = _display displayCtrl (2400 + _index);
private _buttonCtrl = _display displayCtrl (2600 + _index);
_buttonCtrl ctrlShow false;

if (_glyph == _answerGlyph) then {
    _tile ctrlSetText "\yoshi-custom-objectives\UI\keypad_blank_success.paa";
    if (count _responses == _buttonCount) then {
        private _statusCtrl = _display displayCtrl 1001;
        _statusCtrl ctrlSetText "\yoshi-custom-objectives\UI\moduleDoneLightOn.paa";
        [_object, ["successBell", 100, 1]] remoteExec ["say3D"];
    };
} else {
    _tile ctrlSetText "\yoshi-custom-objectives\UI\keypad_blank_fail.paa";
    private _statusCtrl = _display displayCtrl 1001;
    _statusCtrl ctrlSetText "\yoshi-custom-objectives\UI\moduleDoneLightFail.paa";
    [_object] spawn {
        params ["_object"];

        [_object, ["chargingSound", 300, 1]] remoteExec ["say3D"];
        sleep 2;
        createVehicle ["Bomb_04_F", getPosATL _object, [], 0, "CAN_COLLIDE"];
    };
    private _defuseActionNumber = _object getVariable ["defuseActionNumber", -1];
    if (_defuseActionNumber != -1) then {
        _object removeAction _defuseActionNumber;
    };
};
