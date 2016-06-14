// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2014 A3Wasteland.com *
// ******************************************************************************************
#include "player_sys.sqf"
#define COLOR_TRANSPARENT { 0, 0, 0, 0 }

class playerSettings {

	idd = playersys_DIALOG;
	movingEnable = true;
	enableSimulation = true;
	onLoad = "[] execVM 'client\systems\playerMenu\item_list.sqf'";

	class controlsBackground {

		class Tablet: w_RscPicture
		{
			idc = -1;
			text = "panel\infopanel.paa";
			x = -0.00;
		 	y = -0.15;
			w = 1;
			h = 1.28;
		};
		
		/*class MainBG : IGUIBack {
			idc = -1;
			colorText[] = {1, 1, 1, 1};
			colorBackground[] = {0,0,0,0.6};

			moving = true;
			x = 0.0; y = 0.1;
			w = .745; h = 0.65;
		};

		class TopBar: IGUIBack
		{
			idc = -1;
			colorText[] = {1, 1, 1, 1};
			colorBackground[] = {A3W_UICOLOR_R, A3W_UICOLOR_G, A3W_UICOLOR_B, 0.8};

			x = 0;
			y = 0.1;
			w = 0.745;
			h = 0.05;
		};

		class MainTitle : w_RscText {
			idc = -1;
			text = "Player Inventory";
			sizeEx = 0.04;
			shadow = 2;
			x = 0.260; y = 0.1;
			w = 0.3; h = 0.05;
		};

		class waterIcon : w_RscPicture {
			idc = -1;
			text = "client\icons\water.paa";
			x = 0.022; y = 0.2;
			w = 0.04 / (4/3); h = 0.04;
		};

		class foodIcon : w_RscPicture {
			idc = -1;
			text = "client\icons\food.paa";
			x = 0.022; y = 0.26;
			w = 0.04 / (4/3); h = 0.04;
		};

		class moneyIcon : w_RscPicture {
			idc = -1;
			text = "client\icons\money.paa";
			x = 0.022; y = 0.32;
			w = 0.04 / (4/3); h = 0.04;
		};
		
		class serverLogo : w_RscPicture {
			idc = -1;
			text = "mapconfig\logo.paa";
			x = 0.225; y = 0.20;
			w = 0.32 / (4/3); h = 0.32;
		};

		class waterText : w_RscText {
			idc = water_text;
			text = "";
			sizeEx = 0.03;
			x = 0.06; y = 0.193;
			w = 0.3; h = 0.05;
		};

		class foodText : w_RscText {
			idc = food_text;
			sizeEx = 0.03;
			text = "";
			x = 0.06; y = 0.254;
			w = 0.3; h = 0.05;
		};

		class moneyText : w_RscText {
			idc = money_text;
			text = "";
			sizeEx = 0.03;
			x = 0.06; y = 0.313;
			w = 0.3; h = 0.05;
		};

		class distanceText : w_RscText {
			idc = view_range_text;
			text = "View range:";
			sizeEx = 0.025;
			x = 0.03; y = 0.40;
			w = 0.3; h = 0.02;
		};*/

		class uptimeText : w_RscText {
			idc = uptime_text;
			text = "";
			sizeEx = 0.030;
			x = 0.52; y = 0.69;
			w = 0.225; h = 0.03;
		};
	};

	class controls {

		class itemList : w_Rsclist {
			idc = item_list;
			x = 0.5125; y = 0.228; //[0.5125,0.228,0.2455,0.3455]
			w = 0.2455; h = 0.3455;
		};

		class DropButton : w_RscButton {
			idc = -1;
			text = "Drop";
			onButtonClick = "[1] execVM 'client\systems\playerMenu\itemfnc.sqf'"; //[0.647954,0.616,0.1,0.13]
			x = 0.647954; y = 0.616;
			w = 0.1; h = 0.13;
		};

		class UseButton : w_RscButton {
			idc = -1;
			text = "Use";
			onButtonClick = "[0] execVM 'client\systems\playerMenu\itemfnc.sqf'"; //[0.522538,0.616,0.1,0.13]
			x = 0.522538; y = 0.616;
			w = 0.1; h = 0.13;
		};

		class moneyInput: w_RscCombo {
			idc = money_value;
			x = 0.77; y = 0.4; //[0.77,0.4,0.116,0.03]
			w = 0.116; h = 0.03;
		};

		class DropcButton : w_RscButton {
			idc = -1;
			text = "Drop $";
			onButtonClick = "[] execVM 'client\systems\playerMenu\dropMoney.sqf'"; //[0.776629,0.44708,0.1,0.13]
			x = 0.776629; y = 0.44708;
			w = 0.1; h = 0.13;
		};

		class CloseButton : w_RscButton {
			idc = close_button;
			text = "Close";
			colorText[] = {1, 1, 1, 1};
			colorBackground[] = {1, 0, 0, 1};
			onButtonClick = "[] execVM 'client\systems\playerMenu\closePlayerMenu.sqf'"; //[0.7625,0.608,0.1,0.127273]
			x = 0.776669; y = 0.616; //[0.776669,0.616,0.1,0.13]
			w = 0.1; h = 0.13;
		};

		class GroupsButton : w_RscButton {
			idc = groupButton;
			text = "Group";
			onButtonClick = "[] execVM 'client\systems\groups\loadGroupManagement.sqf'"; //[0.135,0.228,0.1,0.13]
			x = 0.125; y = 0.236;
			w = 0.1; h = 0.13;
		};

		class btnDistanceNear : w_RscButton {
			idc = -1;
			text = "Near";
			onButtonClick = "setViewDistance 1000;"; //[0.125,0.616,0.1,0.13]
			x = 0.125; y = 0.616;
			w = 0.1; h = 0.13;
		};

		class btnDistanceMedium : w_RscButton {
			idc = -1;
			text = "Med";
			onButtonClick = "setViewDistance 1500;"; //[0.2275,0.612,0.1,0.127273]
			x = 0.2425; y = 0.616;
			w = 0.1; h = 0.13;
		};

		class btnDistanceFar : w_RscButton {
			idc = -1;
			text = "Far";
			onButtonClick = "setViewDistance 2200;"; //[0.361023,0.616,0.1,0.13]
			x = 0.361023; y = 0.616;
			w = 0.1; h = 0.13;
		};

/*		class btnDistanceCustom : w_RscButton {
			idc = -1;
			text = "Custom";
			onButtonClick = "[] execVM 'addons\VIP\organized_arsenal.sqf'";
			x = 0.158; y = 0.57;
			w = 0.125; h = 0.033 * safezoneH;
		};
*/
		class btnDistanceEffects : w_RscButton {
			idc = -1;
			text = "Effects";
			onButtonClick = "[] execVM 'addons\disableEnvironment\disableEnvironment.sqf'"; //[0.2725,0.496,0.2,0.06]
			x = 0.2725; y = 0.490;
			w = 0.2; h = 0.06; // * safezoneH;
		};


			class G4armaInfoButton : w_RscButton {
			idc = -1;
			text = "G4 Info";
			onButtonClick = "[] execVM 'addons\G4armaInfo\loadG4armaInfo.sqf'"; //[0.135,0.416,0.1,0.13]
			x = 0.125; y = 0.424;
			w = 0.1; h = 0.13;
		};
	};
};
