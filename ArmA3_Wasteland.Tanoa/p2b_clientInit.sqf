/* 
* File:		p2b_clientInit.sqf
* Author: 	Player2 - Player2DZ@gmail.com
* Date: 	2016-01-21
*/


/*---------------------------------------------------------------------------
IMPORTANT README:

THIS FILE GOES IN THE MISSION FILE AND SHOULD RUN CLIENT-SIDE ONLY.

NOT ON THE SERVER.

YOU MUST ADD THIS FILE TO YOUR MISSION THEN START IT LIKE THIS FROM YOUR INIT.SQF:

	call compile preprocessFileLineNumbers "p2b_clientInit.sqf";
---------------------------------------------------------------------------*/
//client debug RPT output setting
p2b_debug = true;
p2b_logPrefix = "P2B";

//debug
if (p2b_debug) then { diag_log(format["%1: Running p2b_clientInit", p2b_logPrefix]); };

//Make sure this runs client side only
if (hasInterface && !isServer) exitWith {

	//Create function for client messages
	p2b_clientMessage = {
		params[
			["_msgTitle","No Title Found"],
			["_msgText","No Text Found"],
			["_titleCol","#FF3300"],
			["_msgCol","#FFFFFF"]
		];

		//Set defaults
		private["_titleText","_mainText"];
		_titleText = "No Title Found";
		_mainText  = "No Message Found";

		//Create hint message to player using supplied params
		_titleText = format["<t color='%1' size='1.5' align='center'>%2</t>",	_titleCol,	_msgTitle];
		_mainText  = format["<t color='%1' size='1.0' align='center'>%2</t>",	_msgCol,	_msgText];

		//Display hint message
		hintSilent parseText format[
			"%1<br/>%2",
			_titleText,
			_mainText
		];

		//Give player chat message about it
		systemChat(format["%1: %2", _msgTitle, _msgText]);
	};

	//Create function for client cash change & message
	p2b_clientCash = {
		params[["_cashAmount", 0], ["_msg", "None found."]];

		//Set defaults
		private["_player","_mycash","_add","_txt"];
		_player = player;
		_mycash = 0;
		_add    = true;
		_txt = "transferred into";

		//Get current cash
		_mycash = _player getVariable ["cmoney", 0];

		//Wait a moment to get current cash properly
		sleep 0.1;

		//Get text and addition/subtraction and set number
		if (_cashAmount > 0) then {
			_add = true;
		} else {
			_add = false;
			_cashAmount = abs _cashAmount; //convert from negative number to positive number
		};

		//Add/Subtract
		if (_add) then {
			_mycash = _mycash + _cashAmount;
			_txt = "transferred into";
		} else {
			_mycash = _mycash - _cashAmount;
			_txt = "transferred out of";
		};

		//Set var on player to their updated cash
		_player setVariable ["cmoney", _mycash, true];

		//Display chat message
		systemChat(format["Assasination Cash Transfer: $%1 has been %2 your account. Reason: %3", _cashAmount, _txt, _msg]);

		//debug
		if (p2b_debug) then { diag_log(format["%1: p2b_netMsg cash updated to %2.", p2b_logPrefix, _mycash]); };
	};


	//Add client side network pubvar receiver for server send message
	"p2b_netMsg" addPublicVariableEventHandler {
		//debug
		if (p2b_debug) then { diag_log(format["%1: p2b_netMsg recieved: %2", p2b_logPrefix, (_this select 1)]); };
		//spawn function
		(_this select 1) spawn p2b_clientMessage;
	};

	//Add client side network pubvar receiver for server change cash
	"p2b_netCash" addPublicVariableEventHandler {
		//debug
		if (p2b_debug) then { diag_log(format["%1: p2b_netCash recieved: %2", p2b_logPrefix, (_this select 1)]); };
		//spawn function
		(_this select 1) spawn p2b_clientCash;
	};

	//debug
	if (p2b_debug) then { diag_log(format["%1: p2b_netMsg client function and net receiver added.", p2b_logPrefix]); };
};

//debug
if (p2b_debug) then { diag_log(format["%1: ERROR - p2b_clientInit - RUNNING ON SERVER INSTEAD OF CLIENT.", p2b_logPrefix]); };
