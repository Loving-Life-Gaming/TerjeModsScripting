// LLG Medicine - pharmacy labels for TerjeMedicine.
//
// This config touches no item classes. It only registers the addon and its
// script module, exactly the shape of Bohemia's DayZ sample mod. The labels
// are in Scripts/4_World/LLGMedicineLabels.c.

class CfgPatches
{
	class LLGMedicine
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"TerjeCore",
			"TerjeMedicine"
		};
	};
};

class CfgMods
{
	class LLGMedicine
	{
		dir = "LLGMedicine";
		name = "LLG Medicine";
		credits = "Loving Life Gaming";
		action = "http://www.lovinglifegaming.com";
		author = "iam";
		version = "3.0.0";
		type = "mod";
		extra = 0;
		picture = "";
		hideName = 0;
		hidePicture = 1;
		dependencies[] = {"Core", "Game", "World", "Mission"};

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"LLGMedicine/Scripts/4_World"};
			};
		};
	};
};
