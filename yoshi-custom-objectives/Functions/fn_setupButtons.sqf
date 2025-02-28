private _display = uiNamespace getVariable ["DefuseDialog", displayNull];
if (isNull _display) exitWith {};

// Retrieve the preset stored earlier
private _preset = uiNamespace getVariable ["DefuseDialog_Preset", []];
if (isNil "_preset" || {_preset isEqualTo []}) exitWith {};
private _buttonCount = _preset select 0;
private _buttonsData = _preset select 1;


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
            private _label = format [
                "LED:%1 STAR:%2 %3",
                if (_led) then {"ON"} else {"OFF"},
                if (_star) then {"YES"} else {"NO"},
                _color
            ];
            if (_led) then {
                _ledCtrl ctrlSetText "\yoshi-custom-objectives\UI\led_on_8x8.paa";
            };
            if (_star) then {
                _starCtrl ctrlSetText "\yoshi-custom-objectives\UI\star.paa";
            };

            if (_color == "Red") then {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireRed.paa";
            };
            if (_color == "Blue") then {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireBlue.paa";
            };
            if (_color == "White") then {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireWhite.paa";
            };
            if (_color == "Red/Blue") then {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireRedBlue.paa";
            };
            if (_color == "Blue/White") then {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireBlueWhite.paa";
            };
            if (_color == "Red/White") then {
                _wireCtrl ctrlSetText "\yoshi-custom-objectives\UI\wireRedWhite.paa";
            };
            _ctrl ctrlSetText _label;
        } else {
            _ctrl ctrlShow false;
        };
    };
};
