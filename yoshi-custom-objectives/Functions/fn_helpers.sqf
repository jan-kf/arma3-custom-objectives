YOSHI_CO_isRed = {
	params ["_color"];
	_color in ["Red", "Red/Blue", "Red/White"]
};
YOSHI_CO_isBlue = {
	params ["_color"];
	_color in ["Blue", "Red/Blue", "Blue/White"]
};

YOSHI_CO_CHECK_COMPLEX_WIRE = {
	params ["_wire", "_lastDigitIsEven", "_hasParallelPort", "_has2OrMoreBatteries"];
	private _led = _wire select 0;
	private _star = _wire select 1;
	private _color = _wire select 2;
	private _isCut = _wire select 3;

	private _wireHasBlue = _color call YOSHI_CO_isBlue;
	private _wireHasRed = _color call YOSHI_CO_isRed;

	private _solved = true;

	if (_wireHasBlue && _wireHasRed) then {
		// Both Red and Blue
		if (!_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo _lastDigitIsEven);
		};
		if (_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo _hasParallelPort);
		};
		if (!_star && _led) then {
			_solved = _solved && (_isCut isEqualTo _lastDigitIsEven);
		};
		if (_star && _led) then {
			_solved = _solved && (_isCut isEqualTo false);
		};
	};
	if (_wireHasBlue && !_wireHasRed) then {
		// Only Blue
		if (!_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo _lastDigitIsEven);
		};
		if (_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo false);
		};
		if (!_star && _led) then {
			_solved = _solved && (_isCut isEqualTo _hasParallelPort);
		};
		if (_star && _led) then {
			_solved = _solved && (_isCut isEqualTo _hasParallelPort);
		};
	};
	if (!_wireHasBlue && _wireHasRed) then {
		// Only Red
		if (!_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo _lastDigitIsEven);
		};
		if (_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo true);
		};
		if (!_star && _led) then {
			_solved = _solved && (_isCut isEqualTo _has2OrMoreBatteries);
		};
		if (_star && _led) then {
			_solved = _solved && (_isCut isEqualTo _has2OrMoreBatteries);
		};
	};
	if (!_wireHasBlue && !_wireHasRed) then {
		// Only White
		if (!_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo true);
		};
		if (_star && !_led) then {
			_solved = _solved && (_isCut isEqualTo true);
		};
		if (!_star && _led) then {
			_solved = _solved && (_isCut isEqualTo false);
		};
		if (_star && _led) then {
			_solved = _solved && (_isCut isEqualTo _has2OrMoreBatteries);
		};
	};

	_solved
};