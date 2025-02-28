#define GUI_GRID_X (safeZoneX + 0.1)
#define GUI_GRID_Y (safeZoneY + 0.1)
#define GUI_GRID_W (safeZoneW / 40)
#define GUI_GRID_H (safeZoneH / 25)

class RscText;
class RscButton;
class RscPictureKeepAspect;
class WireButton: RscButton
{
    colorDisabled[] = {0,0,0,0};
    colorBackground[] = {0,0,0,0};
    colorBackgroundDisabled[] = {0,0,0,0};
    colorBackgroundActive[] = {0,0,0,0};
    colorFocused[] = {0,0,0,0};
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0,0,0,0};
};

class DefuseDialog
{
    idd = 9999;
    movingEnable = false;
    onLoad = "uiNamespace setVariable ['DefuseDialog', _this select 0]; [] spawn YOSHI_CO_fnc_setupButtons;";
    class controlsBackground {
        class Background: RscPictureKeepAspect {
            idc = -1;
            x = 13.5 * GUI_GRID_W + GUI_GRID_X;
            y = 3 * GUI_GRID_H + GUI_GRID_Y;
            w = 12 * GUI_GRID_W;
            h = 12 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\complexWiresModuleBackground.paa";
            colorBackground[] = {0, 0, 0, 0.7}; // Dark transparent background
        };
    };

    class controls
    {
        // class RscText_1000: RscText
        // {
        //     idc = 1000;
        //     text = "Complex Wires"; //--- ToDo: Localize;
        //     x = 14 * GUI_GRID_W + GUI_GRID_X;
        //     y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
        //     w = 11 * GUI_GRID_W;
        //     h = 2 * GUI_GRID_H;
        //     colorBackground[] = {0,0,0,0};
        //     sizeEx = 2 * GUI_GRID_H;
        // };

        class StatusIndicator: RscPictureKeepAspect
        {
            idc = 1000;
            x = 22.5 * GUI_GRID_W + GUI_GRID_X;
            y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\moduleDoneLightOff.paa";
        };

        class RscButton_1600: WireButton
        {
            idc = 1600;
            x = 15 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "";
            action = "[0] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1601: WireButton
        {
            idc = 1601;
            x = 16 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "";
            action = "[1] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1602: WireButton
        {
            idc = 1602;
            x = 17 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "";
            action = "[2] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1603: WireButton
        {
            idc = 1603;
            x = 18 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "";
            action = "[3] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1604: WireButton
        {
            idc = 1604;
            x = 19 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "";
            action = "[4] call YOSHI_CO_fnc_handleButton;";
        };
        class RscButton_1605: WireButton
        {
            idc = 1605;
            x = 20 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "";
            action = "[5] call YOSHI_CO_fnc_handleButton;";
        };

        class RscButton_1400: RscPictureKeepAspect
        {
            idc = 1400;
            x = 15 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1401: RscPictureKeepAspect
        {
            idc = 1401;
            x = 16 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1402: RscPictureKeepAspect
        {
            idc = 1402;
            x = 17 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1403: RscPictureKeepAspect
        {
            idc = 1403;
            x = 18 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1404: RscPictureKeepAspect
        {
            idc = 1404;
            x = 19 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };
        class RscButton_1405: RscPictureKeepAspect
        {
            idc = 1405;
            x = 20 * GUI_GRID_W + GUI_GRID_X;
            y = 5 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 8 * GUI_GRID_H;
            text = "\yoshi-custom-objectives\UI\wireNone_vert.paa";
        };


        class RscPicture_1200: RscPictureKeepAspect 
        {
            idc = 1200;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = 15 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1201: RscPictureKeepAspect 
        {
            idc = 1201;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = 16 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1202: RscPictureKeepAspect 
        {
            idc = 1202;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = 17 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1203: RscPictureKeepAspect 
        {
            idc = 1203;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = 18 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1204: RscPictureKeepAspect 
        {
            idc = 1204;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = 19 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1205: RscPictureKeepAspect 
        {
            idc = 1205;
            text = "\yoshi-custom-objectives\UI\led_off_8x8.paa";
            x = 20 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };

        class RscPicture_1300: RscPictureKeepAspect 
        {
            idc = 1300;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = 15 * GUI_GRID_W + GUI_GRID_X;
            y = 13 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1301: RscPictureKeepAspect 
        {
            idc = 1301;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = 16 * GUI_GRID_W + GUI_GRID_X;
            y = 13 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1302: RscPictureKeepAspect 
        {
            idc = 1302;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = 17 * GUI_GRID_W + GUI_GRID_X;
            y = 13 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1303: RscPictureKeepAspect 
        {
            idc = 1303;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = 18 * GUI_GRID_W + GUI_GRID_X;
            y = 13 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1304: RscPictureKeepAspect 
        {
            idc = 1304;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = 19 * GUI_GRID_W + GUI_GRID_X;
            y = 13 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscPicture_1305: RscPictureKeepAspect 
        {
            idc = 1305;
            text = "\yoshi-custom-objectives\UI\noStar.paa";
            x = 20 * GUI_GRID_W + GUI_GRID_X;
            y = 13 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
    };

    
};


