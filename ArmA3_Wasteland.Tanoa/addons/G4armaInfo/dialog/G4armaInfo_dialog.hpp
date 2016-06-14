// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2015 G4arma.com *
// ******************************************************************************************
//	@file Name: G4armaInfo_dialog.hpp
//	@file Author: Lodac
//  @file Edited: fn_r3m3dy

#include "G4armaInfo_defines.hpp"
#define X_safezone 
#define RscHTML_sizeEx_H1 (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)
#define RscHTML_sizeEx_H2 (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)
#define RscHTML_sizeEx_P (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)
class G4armaInfoD
{
	idd = G4armaInfo_dialog; 
	movingEnable = 1; 
	enableSimulation = 1;
	enableDisplay = 1; 
	
	onLoad = ""; 

	class controls 
	{	
		class TAInfoBackground: RscText
		{
			idc = 10089;
			x = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "30 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.4};
		};
		class TAInfoTitle: RscText
		{
			idc = 10032;
			text = "G4 WastelandEvolved | Official Server";
			colorBackground[] = {0,0,0,1};
			x = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "30 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TAServerInfo: RscText
		{
			idc = G4armaInfo_Server_Info;
			type = CT_STRUCTURED_TEXT;
			size = 0.040;
			text = "";
			x = "18 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "12 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			
		};
		class TAGeneralInfoBackground: RscText
		{
			idc = G4armaInfo_General_Info_BG;
			type = CT_STRUCTURED_TEXT;
			size = 0.030;
			text = "Website: g4-gamers.com Forums: g4-gamers.com/forums/ Discord: discord.gg/0tOkw29tagosRghX";
			x = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "1.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "30 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.4};
			colorText[] = {1,1,1,1};
			colorLink[] = {0,0.34,0.59,1};
			colorLinkActive[] = {0,0.34,0.59,0.1};
		};
		class TARulesTiTleBackground: RscText
		{
			idc = G4armaInfo_Rules_Title_BG;
			text = "Rules and Terms of joining this server:";
			x = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.98,0.16,0.03,1};
		};
		class TARulesBackground: RscText
		{
			idc = G4armaInfo_Rules_BG;
			x = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			//colorBackground[] = {0.98,0.16,0.03,0.2};
		};
		class TAA3WBackground: RscText
		{
			idc = G4armaInfo_Content_A3W;
			type = CT_STRUCTURED_TEXT;
			size = 0.028;
			x = "15.1 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "2.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "14.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.2};
			text = "Welcome";
		};
		class TAStatsTiTleBackground: RscText
		{
			idc = G4armaInfo_Stats_Title_BG;
			text = "Gametracker and other info... ";
			x = "15.1 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "9.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "14.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.51,0.99,0.41,0.3};
		};
		class TANewsBackground: RscText
		{
			idc = G4armaInfo_News_BG;
			x = "0 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "9.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "10.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.4};
		};
		class TARulesText: RscHTML
		{	
			idc = G4armaInfo_Content_Rules;
			type = 9;
			shadow = 0;
			class H1
			{
				font = "PuristaMedium";
				fontBold = "PuristaLight";
				sizeEx = RscHTML_sizeEx_H1;
			};
			class H2: H1
			{
				sizeEx = RscHTML_sizeEx_H2;
				font = "PuristaLight";
			};
			class P: H1
			{
				sizeEx = RscHTML_sizeEx_P;
				fontBold = "PuristaLight";
			};
			colorBold[] = {0.6,0.6,0.6,1};
			colorLink[] = {0.69,0.75,0.5,1};
			colorLinkActive[] = {0.69,0.75,0.5,1};
			x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "3.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "14 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7.4 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TANewsText: RscHTML
		{	
			idc = G4armaInfo_Content_News;
			type = 9;
			shadow = 0;
			class H1
			{
				font = "PuristaMedium";
				fontBold = "PuristaLight";
				sizeEx = RscHTML_sizeEx_H1;
			};
			class H2: H1
			{
				sizeEx = RscHTML_sizeEx_H2;
				font = "PuristaLight";
			};
			class P: H1
			{
				sizeEx = RscHTML_sizeEx_P;
				fontBold = "PuristaLight";
			};
			colorBold[] = {0.6,0.6,0.6,1};
			colorLink[] = {0.69,0.75,0.5,1};
			colorLinkActive[] = {0.69,0.75,0.5,1};
			x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "9.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "14 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "10.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TAStatsText: RscHTML
		{	
			idc = G4armaInfo_Content_Stats;
			type = 9;
			shadow = 0;
			class H1
			{
					font = "PuristaMedium";
					fontBold = "PuristaLight";
					sizeEx = RscHTML_sizeEx_H1;
				};
			class H2: H1
			{
					sizeEx = RscHTML_sizeEx_H2;
					font = "PuristaLight";
				};
			class P: H1
			{
					sizeEx = RscHTML_sizeEx_P;
					fontBold = "PuristaLight";
				};
			colorBold[] = {0.6,0.6,0.6,1};
			colorLink[] = {0.69,0.75,0.5,1};
			colorLinkActive[] = {0.69,0.75,0.5,1};
			x = "15.2 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "10.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "14.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "9.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TAInfoCloseButton: w_RscButton
		{
			idc = -1;
			onButtonClick = "closeDialog 0";
			text = "AGREE to RULES and TERMS and CLOSE";
			sizeEx = 0.04;
			x = "8 * (((safezoneW / safezoneH) min 1.2) / 40)";
			y = "21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "15.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};