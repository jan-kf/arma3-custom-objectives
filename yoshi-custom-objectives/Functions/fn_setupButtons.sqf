private _display = uiNamespace getVariable ["DefuseDialog", displayNull];
if (isNull _display) exitWith {};

// Retrieve the preset stored earlier
private _complexWireData = uiNamespace getVariable ["DefuseDialog_ComplexWires", []];
if (isNil "_complexWireData" || {_complexWireData isEqualTo []}) exitWith {};
private _simpleWireData = uiNamespace getVariable ["DefuseDialog_SimpleWires", []];
if (isNil "_simpleWireData" || {_simpleWireData isEqualTo []}) exitWith {};
private _extra_preset = uiNamespace getVariable ["DefuseDialog_ExtrasPreset", []];
if (isNil "_extra_preset" || {_extra_preset isEqualTo []}) exitWith {};

private _CWbuttonCount = _complexWireData select 0;
private _CWbuttonsData = _complexWireData select 1;

private _serialData = _extra_preset select 1;
private _ports = _extra_preset select 2;
private _batteries = _extra_preset select 3;
private _indicatorData = _extra_preset select 4;

private _isCWDone = [_complexWireData, _extra_preset] call YOSHI_CO_fnc_checkComplexWiresSolution;


for "_i" from 0 to (_CWbuttonCount-1) do {
    private _ctrl = _display displayCtrl (1600 + _i);
    private _ledCtrl = _display displayCtrl (1200 + _i);
    private _starCtrl = _display displayCtrl (1300 + _i);
    private _wireCtrl = _display displayCtrl (1400 + _i);
    if (!isNull _ctrl) then {
        if (_i < _CWbuttonCount) then {
            _ctrl ctrlShow true;
            private _data = _CWbuttonsData select _i;
            private _led = _data select 0;
            private _star = _data select 1;
            private _color = _data select 2;
            private _isCut = _data select 3;

            if (_led) then {
                _ledCtrl ctrlSetText "\yoshi-custom-objectives\UI\led_on_8x8.paa";
            };
            if (_star) then {
                _starCtrl ctrlSetText "\yoshi-custom-objectives\UI\star.paa";
            };
            if (!_isCut) then {
                if (_color == "Red") then {
                    _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireRed_vert.paa";
                };
                if (_color == "Blue") then {
                    _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireBlue_vert.paa";
                };
                if (_color == "White") then {
                    _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireWhite_vert.paa";
                };
                if (_color == "Red/Blue") then {
                    _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireRedBlue_vert.paa";
                };
                if (_color == "Blue/White") then {
                    _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireBlueWhite_vert.paa";
                };
                if (_color == "Red/White") then {
                    _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireRedWhite_vert.paa";
                };
            } else {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireNone_vert.paa";
            };
        } else {
            _ctrl ctrlShow false;
        };
    };
};

private _SWbuttonCount = _simpleWireData select 0;
private _SWbuttonsData = _simpleWireData select 1;

for "_i" from 0 to (_SWbuttonCount-1) do {
    private _ctrl = _display displayCtrl (4600 + _i);
    private _wireCtrl = _display displayCtrl (4400 + _i);
    if (!isNull _ctrl) then {
        if (_i < _SWbuttonCount) then {
            _ctrl ctrlShow true;
            private _data = _SWbuttonsData select _i;
            private _color = _data select 0;
            private _isCut = _data select 1;

            if (!_isCut) then {
                _wireCtrl ctrlSetText format["\yoshi-custom-objectives\UI\wire%1.paa", _color];
                if (_color == "None") then {
                    _ctrl ctrlShow false;
                };
            } else {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireNone.paa";
            };
        } else {
            _ctrl ctrlShow false;
        };
    };
};

private _portCount = count _ports;
for "_i" from 0 to (_portCount-1) do {
    private _portCtrl = _display displayCtrl (4500 + _i);
    if (!isNull _portCtrl) then {
        _portCtrl ctrlSetText (format ["\yoshi-custom-objectives\UI\%1.paa", _ports select _i]);
    };
};

private _batteryCount = count _batteries;
for "_i" from 0 to (_batteryCount-1) do {
    private _batteryCtrl = _display displayCtrl (4600 + _i);
    if (!isNull _batteryCtrl) then {
        _batteryCtrl ctrlSetText (format ["\yoshi-custom-objectives\UI\%1.paa", _batteries select _i]);
    };
};

private _serialCtrl = _display displayCtrl 4701;
private _serialNumber = _serialData select 0;
_serialCtrl ctrlSetText _serialNumber;

private _indicatorCtrl = _display displayCtrl 4702;
private _indicatorLightCtrl = _display displayCtrl 4700;
private _indicator = _indicatorData select 0;
private _indicatorLit = _indicatorData select 1;
_indicatorCtrl ctrlSetText _indicator;
if (_indicatorLit) then {
    _indicatorLightCtrl ctrlSetText "\yoshi-custom-objectives\UI\indicator_lit.paa";
};

if (_isCWDone) then {
    private _statusCtrl00 = _display displayCtrl 1000;
    _statusCtrl00 ctrlSetText "\yoshi-custom-objectives\UI\moduleDoneLightOn.paa";
};