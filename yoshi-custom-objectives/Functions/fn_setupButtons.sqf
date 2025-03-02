private _display = uiNamespace getVariable ["DefuseDialog", displayNull];
if (isNull _display) exitWith {};

// Retrieve the preset stored earlier
private _cw_preset = uiNamespace getVariable ["DefuseDialog_ComplexWiresPreset", []];
if (isNil "_cw_preset" || {_cw_preset isEqualTo []}) exitWith {};
private _extra_preset = uiNamespace getVariable ["DefuseDialog_ExtrasPreset", []];
if (isNil "_extra_preset" || {_extra_preset isEqualTo []}) exitWith {};

private _buttonCount = _cw_preset select 0;
private _buttonsData = _cw_preset select 1;
private _ports = _extra_preset select 0;
private _batteries = _extra_preset select 1;


for "_i" from 0 to (_buttonCount-1) do {
    private _ctrl = _display displayCtrl (1600 + _i);
    private _ledCtrl = _display displayCtrl (1200 + _i);
    private _starCtrl = _display displayCtrl (1300 + _i);
    private _wireCtrl = _display displayCtrl (1400 + _i);
    if (!isNull _ctrl) then {
        if (_i < _buttonCount) then {
            _ctrl ctrlShow true;
            private _data = _buttonsData select _i;
            private _led = _data select 0;
            private _star = _data select 1;
            private _color = _data select 2;
            // private _label = format [
            //     "LED:%1 STAR:%2 %3",
            //     if (_led) then {"ON"} else {"OFF"},
            //     if (_star) then {"YES"} else {"NO"},
            //     _color
            // ];
            if (_led) then {
                _ledCtrl ctrlSetText "\yoshi-custom-objectives\UI\led_on_8x8.paa";
            };
            if (_star) then {
                _starCtrl ctrlSetText "\yoshi-custom-objectives\UI\star.paa";
            };

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
            // _ctrl ctrlSetText _label;
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
