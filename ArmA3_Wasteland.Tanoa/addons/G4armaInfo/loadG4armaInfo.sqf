// ******************************************************************************************
// * This project is licensed under the GNU Affero GPL v3. Copyright © 2015 A3Wasteland.com *
// ******************************************************************************************
//	@file Name: loadG4armaInfo.sqf
//	@file Author: Lodac
//  @file Edited: fn_r3m3dy

#include "dialog\G4armaInfo_defines.hpp"


//private ["_display", "_map", "_mission", "_player", "_newsOnline", "_newsOffline", "_ctrlHTML", "_htmlLoaded"];

disableSerialization;

_uid = getPlayerUID player;

createDialog "G4armaInfoD";

_display = (findDisplay G4armaInfo_dialog);

_serverInfoText = _display displayCtrl G4armaInfo_Server_Info;
_serverInfoString = format ["<t color='#A0FFFFFF'>A3Wasteland v1.2b #%1 %2</t>", call A3W_extDB_ServerID, worldName];
_serverInfoText ctrlSetStructuredText parseText _serverInfoString;

_generalInfoText = _display displayCtrl G4armaInfo_General_Info_BG;
_generalInfoString = "Website: <t color='#0091CD'><a href='http://g4-gamers.com/'> G4 WastelandEvolved </a></t> Forums: <t color='#0091CD'><a href='http://g4-gamers.com/forums/'> G4 Forums </a></t> Discord Voice: <t color='#0091CD'><a href='https://discord.gg/0tOkw29tagrgP04S'> Voice Server </a></t>";
_generalInfoText ctrlSetStructuredText parseText _generalInfoString;


_rulesOnline = "";
_rulesOffline = "addons\G4armaInfo\rules.html";
_newsOnline = "";
_newsOffline = "addons\G4armaInfo\news.html";
_statsOnline = "" ;
_statsOffline = "addons\G4armaInfo\stats.html";


//Load the correct HTML into the control
_ctrlHTML = _display displayCtrl G4armaInfo_Content_Rules;
_ctrlHTML htmlLoad _rulesOnline;
_htmlLoaded = ctrlHTMLLoaded _ctrlHTML;
if (!_htmlLoaded) then 
{
	_ctrlHTML htmlLoad _rulesOffline;
};
_ctrlHTML = _display displayCtrl G4armaInfo_Content_News;
_ctrlHTML htmlLoad _newsOnline;
_htmlLoaded = ctrlHTMLLoaded _ctrlHTML;
if (!_htmlLoaded) then 
{
	_ctrlHTML htmlLoad _newsOffline;
};
_ctrlHTML = _display displayCtrl G4armaInfo_Content_Stats;
_ctrlHTML htmlLoad _statsOnline;
_htmlLoaded = ctrlHTMLLoaded _ctrlHTML;
if (!_htmlLoaded) then 
{
	_ctrlHTML htmlLoad _statsOffline;
};

_control = _display displayCtrl G4armaInfo_Content_A3W;
private ["_teamrules", "_teamicon", "_teamcol"];

switch (playerSide) do {
	case BLUFOR: {
		_teamrules = "STR_WL_YouAreInTeam";
		_teamicon = "client\icons\igui_side_blufor_ca.paa";
		_teamcol = "#0066ff";
	};
	case OPFOR: {
		_teamrules = "STR_WL_YouAreInTeam";
		_teamicon = "client\icons\igui_side_opfor_ca.paa";
		_teamcol = "#ff1111";
	};
	case INDEPENDENT: {
		_teamrules = "STR_WL_YouAreInFFA";
		_teamicon = "client\icons\igui_side_indep_ca.paa";
		_teamcol = "#00ff00";
	};
	case sideEnemy: {
		_teamrules = "STR_WL_YouAreInFFA";
		_teamicon = "client\icons\igui_side_indep_ca.paa";
		_teamcol = "#00ff00";
	};
};

_message = format ["<t shadow=""1"">%1<br/>%2<br/>%3<br/></t>",
	//localize "STR_WL_WelcomeToWasteland",
	//localize "STR_WL_MapMoreInfo",
	format [localize _teamrules,
		_teamicon,
		_teamcol,
		localize format ["STR_WL_Gen_Team%1", str playerSide],
		localize format ["STR_WL_Gen_Team%1_2", str playerSide]
	]
];

_control ctrlSetStructuredText (parseText _message);
