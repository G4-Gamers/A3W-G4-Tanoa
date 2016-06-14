/*
	@file Version: 0.1
	@file Name: statusBar.sqf
	@file Created: 21/4/2015
	@file Created By: Vishpala
*/

waitUntil {!(isNull (findDisplay 46))};
disableSerialization;

ZGO_StatusEnabled = true;

[] spawn
{
	uiSleep 2;
	
		_uid = getPlayerUID player;	

	while {true} do
	{
		uisleep 2;
		if !(ZGO_StatusEnabled) then
		{
			_rscLayer = "RscWastelandStatusBar" call BIS_fnc_rscLayer;
			_rscLayer cutText ["","PLAIN",1,false];
		}
		else
		{
			_rscLayer = "RscWastelandStatusBar" call BIS_fnc_rscLayer;
			_rscLayer cutRsc ["RscWastelandStatusBar","PLAIN",1,false];

			if(isNull ((uiNamespace getVariable "RscWastelandStatusBar")displayCtrl 55554)) then
			{
				diag_log "statusbar is null create";
				disableSerialization;
				_rscLayer = "RscWastelandStatusBar" call BIS_fnc_rscLayer;
				_rscLayer cutRsc ["RscWastelandStatusBar","PLAIN",1,false];
			};
		
			//initialize variables and set values
			_unit = _this select 0;
			_damage = round ((1 - (damage player)) * 100);




			_wallet = player getVariable ["cmoney",0] call fn_numbersText;
			_stamina = player getVariable ["bmoney",0] call fn_numbersText;
			//_energy = 100;
			//_energyPercent = 100;
			_pos = getPosATL player;
			_serverFPS = round diag_fps;
			//_respect = ExileClientPlayerScore;
			_dir = round (getDir (vehicle player));
			_grid = mapGridPosition  player; _xx = (format[_grid]) select  [0,3];
			_yy = (format[_grid]) select  [3,3];
			_time = (round(301-(serverTime)/60));  //edit the '240' value (60*4=240) to change the countdown timer if your server restarts are shorter or longer than 4 hour intervals
			_hours = (floor(_time/60));
			_minutes = (_time - (_hours * 60));

			switch(_minutes) do
			{
				case 9: {_minutes = "09"};
				case 8: {_minutes = "08"};
				case 7: {_minutes = "07"};
				case 6: {_minutes = "06"};
				case 5: {_minutes = "05"};
				case 4: {_minutes = "04"};
				case 3: {_minutes = "03"};
				case 2: {_minutes = "02"};
				case 1: {_minutes = "01"};
				case 0: {_minutes = "00"};
			};

			//display the information
			((uiNamespace getVariable "RscWastelandStatusBar")displayCtrl 55554) ctrlSetStructuredText
			parseText
			format
			["
			<t shadow='1' shadowColor='#000000'><img size='1.0'  shadowColor='#000000' image='client\icons\players.paa'/> %2</t>
			<t shadow='1' shadowColor='#000000'><img size='0.9'  shadowColor='#000000' image='client\icons\health.paa'/> %3%1</t> 
			<t shadow='1' shadowColor='#000000'><img size='0.9'  shadowColor='#000000' image='client\icons\money.paa'/> $%4</t> 
			<t shadow='1' shadowColor='#000000'><img size='0.9'  shadowColor='#000000' image='client\icons\atm.paa'/> %6</t>
			<t shadow='1' shadowColor='#000000'>FPS: %5</t>			
			<t shadow='1' shadowColor='#000000'><img size='0.9'  shadowColor='#000000' image='client\icons\compass.paa'/> %7</t> 
			<t shadow='1' shadowColor='#000000'><img size='1.0'  shadowColor='#000000' image='client\icons\stopwatch.paa'/>%8:%9</t>",
			
						"%", 
						count playableUnits,
						_damage,
						_wallet,
						_serverFPS,
						_stamina,
						_dir,
						_hours,
						_minutes
											
			];
		
		}; 
	};
};
