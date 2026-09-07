// LLG Medicine - pharmacy-label overrides for TerjeMedicine.
//
// This addon changes nothing but item text. Every class below re-opens an
// existing TerjeMedicine or vanilla class and sets `descriptionShort` only,
// so balance values (levels, timers, overdose increments) stay wherever
// TerjeMedicine puts them and keep working after an upstream update.
//
// Each label is written out in full on the class it belongs to. To reword one,
// edit the string in place - the text you read here is the text the game shows.

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
			"TerjeMedicine",
			"TerjeMedicine_Pills",
			"TerjeMedicine_Ampouls",
			"TerjeMedicine_Injectors",
			"TerjeMedicine_Salves",
			"TerjeMedicine_Drinks",
			"TerjeMedicine_Tools",
			"TerjeMedicine_FirstAidKit",
			"TerjeMedicine_FixVanilla"
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
		version = "2.0.0";
		type = "mod";
		extra = 0;
		hideName = 0;
		hidePicture = 0;
		dependencies[] = {"Game", "World", "Mission"};

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

class CfgVehicles
{
	// Upstream classes are forward declared so the overrides below merge into
	// them. A forward declaration must NOT carry a base class: "class X: Y;"
	// is a syntax error in DayZ configs ("';' encountered instead of '{'").
	// The real parent comes from TerjeMedicine, which loads first.
	class Inventory_Base;
	class Container_Base;
	class Edible_Base;
	class SodaCan_ColorBase;
	class TerjePillsBase;
	class TerjeAmpouleBase;
	class TerjeInjectorBase;
	class TerjeSalveBase;
	class TerjeEnergyDrink;

	// Each override sets llgPharmacyLabel=1, which routes that item's tooltip
	// through the label renderer in Scripts/4_World/LLGMedicineLabels.c.

	//--------------------------------------------------------------
	// PILLS AND CAPSULES
	//--------------------------------------------------------------

	class TerjePillsAnalgin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ANALGIN (METAMIZOLE) 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR MILD TO MODERATE PAIN.<br/><color rgba='150,155,160,255'>PAIN L1 for 8 min 20 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.15 (Low Risk). Short acting. Wears off quickly under stress.</color><br/><color rgba='150,155,160,255'>LOT 1329D · EXP 2029-06-13</color>";
	};

	class TerjePillsNimesulid: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NIMESULIDE 100 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR PAIN.<br/><color rgba='150,155,160,255'>PAIN L1 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.25 (Moderate Risk). Take with food. May irritate the stomach.</color><br/><color rgba='150,155,160,255'>LOT 1458Y · EXP 2031-12-12</color>";
	};

	class TerjePillsParacetamol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PARACETAMOL 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR PAIN AND EARLY COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>PAIN L1 for 3 min 20 sec · COLD/PNEUMONIA L1 for 2 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.45 (Moderate Risk). Liver damage occurs above the labelled dose.</color><br/><color rgba='150,155,160,255'>LOT 8820N · EXP 2031-08-24</color>";
	};

	class TerjePillsIbuprofen: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IBUPROFEN 400 MG · ORAL CAPSULE</color><br/>TAKE 1 CAPSULE BY MOUTH FOR PAIN AND COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>PAIN L1 for 10 min · COLD/PNEUMONIA L2 for 5 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.35 (Moderate Risk). Take with food. May irritate the stomach.</color><br/><color rgba='150,155,160,255'>LOT 3699P · EXP 2030-04-06</color>";
	};

	class TerjePillsNurofen: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NUROFEN (IBUPROFEN LYSINE) 512 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>PAIN L1 for 5 min 50 sec · COLD/PNEUMONIA L2 for 5 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.52 (High Risk). Fast acting. One tablet per dose, no stacking.</color><br/><color rgba='150,155,160,255'>LOT 8743W · EXP 2030-04-28</color>";
	};

	class TerjePillsAmoxiclav: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMOXICLAV 875 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L2 for 20 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.75 (High Risk). Full-strength antibiotic. Space doses well apart.</color><br/><color rgba='150,155,160,255'>LOT 5429G · EXP 2029-09-22</color>";
	};

	class TerjePillsPiperacylin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PIPERACILLIN 500 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L2 for 18 min 20 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.45 (Moderate Risk). Finish the course. Never double a missed dose.</color><br/><color rgba='150,155,160,255'>LOT 7511J · EXP 2030-10-12</color>";
	};

	class TerjePillsAmibaktam: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMIBACTAM 250 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH AT THE FIRST SIGN OF COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L1 for 1 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.05 (Low Risk). Weak and very short acting. Not for pneumonia.</color><br/><color rgba='150,155,160,255'>LOT 6376J · EXP 2029-09-09</color>";
	};

	class TerjePillsPolisorb: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POLYSORB (SILICON DIOXIDE) 3 G · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR MILD FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L1 for 5 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.05 (Low Risk). Drink plenty of water with each dose.</color><br/><color rgba='150,155,160,255'>LOT 1043E · EXP 2031-12-02</color>";
	};

	class TerjePillsFtalazol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PHTHALAZOLE 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR PERSISTENT FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L1 for 20 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.25 (Moderate Risk). Long acting. Wait before taking another.</color><br/><color rgba='150,155,160,255'>LOT 6977Z · EXP 2029-11-20</color>";
	};

	class TerjePillsMesalazin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MESALAZINE 800 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR SEVERE FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L2 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.35 (Moderate Risk). Do not combine with other gut medication.</color><br/><color rgba='150,155,160,255'>LOT 2618G · EXP 2031-05-17</color>";
	};

	class TerjePillsNoopept: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NOOPEPT 10 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR PAIN AND CONCUSSION.<br/><color rgba='150,155,160,255'>PAIN L1 for 6 min 20 sec · CONCUSSION for 6 min 20 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.35 (Moderate Risk). May cause irritability and disturbed sleep.</color><br/><color rgba='150,155,160,255'>LOT 4463B · EXP 2029-07-06</color>";
	};

	class TerjePillsVikasol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VIKASOL (VITAMIN K3) 15 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH TO SLOW THE BLEEDING RATE.<br/><color rgba='150,155,160,255'>BLEEDING RATE L1 for 5 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.15 (Low Risk). Does not replace a bandage or tourniquet.</color><br/><color rgba='150,155,160,255'>LOT 8235Y · EXP 2029-01-02</color>";
	};

	class TerjePillsIrovit: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IROVIT (FERROUS SULFATE) 325 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR BLOOD REGENERATION.<br/><color rgba='150,155,160,255'>BLOOD REGEN L1 for 2 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). May cause nausea. Take with food.</color><br/><color rgba='150,155,160,255'>LOT 5389E · EXP 2028-03-11</color>";
	};

	class TerjePillsMagnesiumSulfate: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MAGNESIUM SULFATE 500 MG · ORAL CAPSULE</color><br/>TAKE 1 CAPSULE BY MOUTH FOR BLOOD REGENERATION.<br/><color rgba='150,155,160,255'>BLOOD REGEN L2.5 for 2 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). May cause flushing and light-headedness.</color><br/><color rgba='150,155,160,255'>LOT 7573A · EXP 2028-12-02</color>";
	};

	class TerjePillsAdepress: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ADEPRESS (PAROXETINE) 20 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH FOR MENTAL HEALTH.<br/><color rgba='150,155,160,255'>MENTAL HEALTH L1 for 2 min 30 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.2 (Moderate Risk). May cause drowsiness. Do not take with alcohol.</color><br/><color rgba='150,155,160,255'>LOT 6095W · EXP 2028-09-21</color>";
	};

	class TerjePillsAgteminol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AGTEMINOL 25 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR MENTAL HEALTH.<br/><color rgba='150,155,160,255'>MENTAL HEALTH L1 for 2 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.2 (Moderate Risk). May cause mild drowsiness.</color><br/><color rgba='150,155,160,255'>LOT 5234J · EXP 2029-01-25</color>";
	};

	class TerjePillsVenlafaxine: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VENLAFAXINE 75 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR MENTAL HEALTH.<br/><color rgba='150,155,160,255'>MENTAL HEALTH L1 for 4 min 10 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). Do not stop suddenly after repeated use.</color><br/><color rgba='150,155,160,255'>LOT 1944D · EXP 2030-12-01</color>";
	};

	class TerjePillsRombiopental: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ROMBIOPENTAL 100 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH BEFORE CHEMICAL EXPOSURE.<br/><color rgba='150,155,160,255'>CHEMICAL POISONING L1 for 30 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.15 (Low Risk). Protective window is under one minute.</color><br/><color rgba='150,155,160,255'>LOT 6782T · EXP 2031-08-23</color>";
	};

	class TerjePillsB190: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>TABLETS B190 150 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH BEFORE ENTERING A RADIATION ZONE.<br/><color rgba='150,155,160,255'>RADIATION L1 for 2 min 20 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). Preventive only. Does nothing once exposed.</color><br/><color rgba='150,155,160,255'>LOT 8945R · EXP 2030-11-18</color>";
	};

	class TerjePillsPotassiumIodide: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POTASSIUM IODIDE 130 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH BEFORE ENTERING A RADIATION ZONE.<br/><color rgba='150,155,160,255'>RADIATION L1 for 1 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.2 (Moderate Risk). Protects the thyroid only. Short duration.</color><br/><color rgba='150,155,160,255'>LOT 8669J · EXP 2028-05-14</color>";
	};

	class TerjePillsHexacyanoferrate: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FERRIC HEXACYANOFERRATE 500 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH AFTER RADIOACTIVE CONTAMINATION.<br/><color rgba='150,155,160,255'>RADIATION L1 for 2 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). Binds fallout in the gut. Not a cure.</color><br/><color rgba='150,155,160,255'>LOT 7939J · EXP 2029-10-22</color>";
	};

	class TerjePillsMexamine: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MEXAMINE 50 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH IMMEDIATELY BEFORE HEAVY RADIATION EXPOSURE.<br/><color rgba='150,155,160,255'>RADIATION L2 for 25 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.75 (High Risk). Very strong and very brief. Time it to the exposure.</color><br/><color rgba='150,155,160,255'>LOT 8091W · EXP 2030-06-17</color>";
	};

	class TerjePillsIversan: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IVERSAN 12 MG · ORAL TABLET · CONTROLLED POISON</color><br/>UNLICENSED FORMULATION. NOT FIT FOR HUMAN USE.<br/><color rgba='150,155,160,255'>CAUSES FOOD POISONING</color><br/><color rgba='217,83,79,255'>OVERDOSE 0.5 (High Risk). Swallowing causes severe poisoning.</color><br/><color rgba='150,155,160,255'>LOT 1800L · EXP 2028-06-07</color>";
	};

	class TerjePillsArsenic: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ARSENIC TRIOXIDE 200 MG · ORAL TABLET · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT SWALLOW.<br/><color rgba='150,155,160,255'>CAUSES FOOD POISONING</color><br/><color rgba='217,83,79,255'>OVERDOSE 2.5 (Lethal Risk). Poison. Causes fatal organ failure.</color><br/><color rgba='150,155,160,255'>LOT 7955N · EXP 2030-10-05</color>";
	};

	class TerjePillsPotassiumCyanide: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POTASSIUM CYANIDE 300 MG · ORAL TABLET · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT SWALLOW.<br/><color rgba='150,155,160,255'>CAUSES FOOD POISONING</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.5 (Severe Risk). Poison. Death follows within seconds.</color><br/><color rgba='150,155,160,255'>LOT 5827Z · EXP 2030-11-17</color>";
	};


	//--------------------------------------------------------------
	// VANILLA PILLS RE-LABELLED BY TERJE MEDICINE
	//--------------------------------------------------------------

	class PainkillerTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CODEINE 30 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH FOR PAIN.<br/><color rgba='150,155,160,255'>PAIN L1 for 5 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.2 (Moderate Risk). May cause drowsiness. Habit forming.</color><br/><color rgba='150,155,160,255'>LOT 4254D · EXP 2029-08-14</color>";
	};

	class TetracyclineAntibiotics: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>TETRACYCLINE 250 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH FOR COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L1 for 5 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.45 (Moderate Risk). Avoid dairy. Finish the course.</color><br/><color rgba='150,155,160,255'>LOT 4537D · EXP 2029-05-09</color>";
	};

	class CharcoalTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CHARCOAL 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L1 for 5 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.01 (Low Risk). Works only on recent poisoning.</color><br/><color rgba='150,155,160,255'>LOT 5433X · EXP 2030-08-05</color>";
	};

	class ChelatingTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CHELATION TABLETS (DMSA) 200 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR SEVERE FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L2 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.6 (High Risk). Strong binder. Depletes minerals with repeat use.</color><br/><color rgba='150,155,160,255'>LOT 1810W · EXP 2029-04-20</color>";
	};

	class VitaminBottle: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MULTIVITAMIN COMPLEX · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH DAILY TO SUPPORT IMMUNITY.<br/><color rgba='150,155,160,255'>IMMUNITY for 2 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.01 (Low Risk). Dietary supplement. Not a medicine.</color><br/><color rgba='150,155,160,255'>LOT 2283H · EXP 2029-02-09</color>";
	};

	class PurificationTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>WATER PURIFICATION TABLETS 8.5 MG · ORAL TABLET</color><br/>ADD 1 TABLET TO ONE LITRE OF WATER AND WAIT 30 MINUTES.<br/><color rgba='150,155,160,255'>TREATS WATER. NO EFFECT WHEN SWALLOWED.</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). For water treatment only. Do not swallow dry.</color><br/><color rgba='150,155,160,255'>LOT 3645J · EXP 2028-02-27</color>";
	};


	//--------------------------------------------------------------
	// AMPOULES (REQUIRE A STERILE SYRINGE)
	//--------------------------------------------------------------

	class TerjeAmpouleAlcohol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MEDICAL ALCOHOL 96% · INJECTION AMPOULE</color><br/>FOR CLEANING WOUNDS AND INSTRUMENTS. EXTERNAL USE ONLY.<br/><color rgba='150,155,160,255'>DISINFECTS WOUNDS AND SYRINGES. NOT FOR INJECTION.</color><br/><color rgba='217,83,79,255'>OVERDOSE 4.0 (Lethal Risk). Never inject. Injection is fatal.</color><br/><color rgba='150,155,160,255'>LOT 2286Z · EXP 2028-03-24</color>";
	};

	class TerjeAmpouleAmoxivan: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMOXIVAN (AMOXICILLIN) 1 G · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L2 for 15 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). Full-strength antibiotic. Space doses apart.</color><br/><color rgba='150,155,160,255'>LOT 5183W · EXP 2026-09-19</color>";
	};

	class TerjeAmpouleKetarol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>KETAROL (KETOROLAC) 30 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR COLD/PNEUMONIA WITH PAIN.<br/><color rgba='150,155,160,255'>PAIN L1 for 20 min · COLD/PNEUMONIA L2 for 20 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.5 (High Risk). Long acting. Do not stack with other painkillers.</color><br/><color rgba='150,155,160,255'>LOT 9647A · EXP 2026-04-15</color>";
	};

	class TerjeAmpouleFlemoclav: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FLEMOCLAVE 1.2 G · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR COLD/PNEUMONIA AND SEPSIS.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L3 for 20 min · SEPSIS for 20 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.8 (High Risk). Maximum-strength antibiotic. Clinical use.</color><br/><color rgba='150,155,160,255'>LOT 4837B · EXP 2027-05-15</color>";
	};

	class TerjeAmpouleImipenem: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IMIPENEM 500 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR COLD/PNEUMONIA AND SEPSIS.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L3 for 15 min · SEPSIS for 15 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.7 (High Risk). Last-line antibiotic. Reserve for sepsis.</color><br/><color rgba='150,155,160,255'>LOT 9632J · EXP 2027-07-17</color>";
	};

	class TerjeAmpouleNovacaine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NOVACAINE 2% · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR MODERATE PAIN.<br/><color rgba='150,155,160,255'>PAIN L2 for 20 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.4 (Moderate Risk). May cause numbness and light-headedness.</color><br/><color rgba='150,155,160,255'>LOT 9150N · EXP 2028-06-26</color>";
	};

	class TerjeAmpouleMorphine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MORPHINOCIN 10 MG/ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE PAIN.<br/><color rgba='150,155,160,255'>PAIN L3 for 14 min 10 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.52 (High Risk). Slows breathing. Habit forming.</color><br/><color rgba='150,155,160,255'>LOT 6578A · EXP 2026-06-15</color>";
	};

	class TerjeAmpouleGexobarbital: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>HEXOBARBITAL 500 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE PAIN WITH SEDATION.<br/><color rgba='150,155,160,255'>PAIN L3 for 15 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.65 (High Risk). Heavy sedation. Never combine with alcohol.</color><br/><color rgba='150,155,160,255'>LOT 3130X · EXP 2028-03-23</color>";
	};

	class TerjeAmpouleKetamin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>KETAMINE 500 MG / 10 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE PAIN WHEN NOTHING ELSE WORKS.<br/><color rgba='150,155,160,255'>PAIN L3 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.45 (Moderate Risk). Causes dissociation and confusion.</color><br/><color rgba='150,155,160,255'>LOT 9480L · EXP 2028-02-13</color>";
	};

	class TerjeAmpouleMetoclopramid: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>METOCLOPRAMID 10 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L2 for 20 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.4 (Moderate Risk). May cause restlessness and muscle stiffness.</color><br/><color rgba='150,155,160,255'>LOT 7337R · EXP 2026-10-02</color>";
	};

	class TerjeAmpouleHeptral: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>HEPTRAL (ADEMETIONINE) 400 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L3 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.6 (High Risk). Maximum strength. Space doses widely.</color><br/><color rgba='150,155,160,255'>LOT 3585L · EXP 2028-01-23</color>";
	};

	class TerjeAmpouleNeirox: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NEIROX 250 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR CONCUSSION.<br/><color rgba='150,155,160,255'>CONCUSSION for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.6 (High Risk). Cerebral stimulant. Do not redose quickly.</color><br/><color rgba='150,155,160,255'>LOT 6352W · EXP 2026-03-02</color>";
	};

	class TerjeAmpouleErythropoetin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ERYTHROPOIETIN 4000 IU · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR BLOOD REGENERATION.<br/><color rgba='150,155,160,255'>BLOOD REGEN L1 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.4 (Moderate Risk). Slow acting. Thickens the blood if overused.</color><br/><color rgba='150,155,160,255'>LOT 7102R · EXP 2026-12-21</color>";
	};

	class TerjeAmpouleAdrenalin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ADRENALINE (EPINEPHRINE) 1 MG/ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT TO FIGHT SHOCK AND RESTORE ALERTNESS.<br/><color rgba='150,155,160,255'>ADRENALINE for 3 min 40 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). Raises heart rate sharply. Emergency use only.</color><br/><color rgba='150,155,160,255'>LOT 9721G · EXP 2028-03-17</color>";
	};

	class TerjeAmpouleMetralindole: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>METRALINDOLE 25 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR MENTAL HEALTH.<br/><color rgba='150,155,160,255'>MENTAL HEALTH L2 for 5 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.1 (Low Risk). Mild sedation. The gentlest of the mood agents.</color><br/><color rgba='150,155,160,255'>LOT 5428L · EXP 2026-03-13</color>";
	};

	class TerjeAmpouleActaparoxetine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ACTAPAROXETINE 40 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR MENTAL HEALTH.<br/><color rgba='150,155,160,255'>MENTAL HEALTH L2 for 6 min 40 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.4 (Moderate Risk). May cause drowsiness for several minutes.</color><br/><color rgba='150,155,160,255'>LOT 9385C · EXP 2028-02-27</color>";
	};

	class TerjeAmpouleAmitriptyline: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMITRIPTYLINE 50 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE MENTAL HEALTH LOSS.<br/><color rgba='150,155,160,255'>MENTAL HEALTH L3 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.5 (High Risk). Heavy sedation. Do not drive after use.</color><br/><color rgba='150,155,160,255'>LOT 5649X · EXP 2027-12-15</color>";
	};

	class TerjeAmpouleVaxicam: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VAXICAM INFLUENZA VACCINE 0.5 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT BEFORE EXPOSURE TO PREVENT COLD/PNEUMONIA.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA IMMUNITY for 4 hr</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.8 (High Risk). Preventive only. Does nothing once ill.</color><br/><color rgba='150,155,160,255'>LOT 4654V · EXP 2027-10-27</color>";
	};

	class TerjeAmpouleZerivax: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ZERIVAX Z-VIRUS VACCINE 0.5 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT BEFORE EXPOSURE TO PREVENT ZOMBIE VIRUS.<br/><color rgba='150,155,160,255'>ZOMBIE VIRUS IMMUNITY for 2 hr</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.5 (Severe Risk). Preventive only. Severe reaction risk.</color><br/><color rgba='150,155,160,255'>LOT 9933W · EXP 2027-03-04</color>";
	};

	class TerjeAmpouleRabivax: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RABIVAX RABIES VACCINE 1 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT BEFORE EXPOSURE TO PREVENT RABIES.<br/><color rgba='150,155,160,255'>RABIES IMMUNITY for 4 hr</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.3 (Severe Risk). Preventive only. Useless once symptoms begin.</color><br/><color rgba='150,155,160,255'>LOT 5990Z · EXP 2028-12-22</color>";
	};

	class TerjeAmpouleRabinoline: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RABINOLINE ANTISERUM 5 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER AN ANIMAL BITE TO TREAT RABIES.<br/><color rgba='150,155,160,255'>RABIES L2 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.8 (High Risk). Give early. Serum reaction possible.</color><br/><color rgba='150,155,160,255'>LOT 1369V · EXP 2028-08-25</color>";
	};

	class TerjeAmpouleRifampicyne: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RIFAMPICIN 600 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR ADVANCED RABIES.<br/><color rgba='150,155,160,255'>RABIES L3 for 5 min</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.35 (Severe Risk). Maximum strength. Give once, then wait it out.</color><br/><color rgba='150,155,160,255'>LOT 6485W · EXP 2026-08-11</color>";
	};

	class TerjeAmpouleZivirol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ZIVIROL EXPERIMENTAL ANTIDOTE 10 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT IMMEDIATELY AFTER ZOMBIE VIRUS INFECTION.<br/><color rgba='150,155,160,255'>ZOMBIE VIRUS for 16 min 40 sec · HEALTH -25 · BLOOD -15 · SHOCK -100</color><br/><color rgba='217,83,79,255'>OVERDOSE 2.35 (Lethal Risk). Costs blood and health. One dose only.</color><br/><color rgba='150,155,160,255'>LOT 7977P · EXP 2028-02-22</color>";
	};

	class TerjeAmpouleNeirocetal: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NEUROCETAL 200 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER CHEMICAL POISONING.<br/><color rgba='150,155,160,255'>CHEMICAL POISONING L2 for 8 min 20 sec</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.25 (Severe Risk). Narrow safety margin. One dose only.</color><br/><color rgba='150,155,160,255'>LOT 8367J · EXP 2028-12-04</color>";
	};

	class TerjeAmpoulePentacin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PENTACIN (CA-DTPA) 250 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER HEAVY RADIOACTIVE CONTAMINATION.<br/><color rgba='150,155,160,255'>RADIATION L2 for 6 min 40 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.5 (High Risk). Strips minerals from the body. Limit doses.</color><br/><color rgba='150,155,160,255'>LOT 9981V · EXP 2027-09-13</color>";
	};

	class TerjeAmpouleCarboxyme: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CARBOXYME 300 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER PROLONGED RADIATION EXPOSURE.<br/><color rgba='150,155,160,255'>RADIATION L2 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.6 (High Risk). Long acting. Limit repeat doses.</color><br/><color rgba='150,155,160,255'>LOT 6097X · EXP 2026-12-22</color>";
	};

	class TerjeAmpouleBeladonna: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>BELLADONNA EXTRACT 1 ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='150,155,160,255'>CAUSES PAIN · CAUSES CONCUSSION</color><br/><color rgba='217,83,79,255'>OVERDOSE 3.8 (Lethal Risk). Poison. Causes delirium and collapse.</color><br/><color rgba='150,155,160,255'>LOT 8965J · EXP 2027-01-27</color>";
	};

	class TerjeAmpouleStrychnine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>STRYCHNINE 5 MG/ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='150,155,160,255'>CAUSES CONCUSSION · BLOOD -1000 · WATER -5000</color><br/><color rgba='217,83,79,255'>OVERDOSE 3.2 (Lethal Risk). Poison. Causes violent convulsions.</color><br/><color rgba='150,155,160,255'>LOT 2913H · EXP 2027-12-24</color>";
	};

	class TerjeAmpouleKonyin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>KONYIN (CONIINE) 2 ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='150,155,160,255'>SEDATION +100 for 5 min</color><br/><color rgba='217,83,79,255'>OVERDOSE 3.0 (Lethal Risk). Poison. Causes paralysis and unconsciousness.</color><br/><color rgba='150,155,160,255'>LOT 4693V · EXP 2028-11-09</color>";
	};

	class TerjeAmpouleArsenic: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ARSENIC TRIOXIDE 10 MG/ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='150,155,160,255'>HEALTH -50</color><br/><color rgba='217,83,79,255'>OVERDOSE 5.0 (Lethal Risk). Poison. Fatal multi-organ failure.</color><br/><color rgba='150,155,160,255'>LOT 7094D · EXP 2028-08-07</color>";
	};

	class TerjeAmpoulePotassiumCyanide: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POTASSIUM CYANIDE 300 MG/ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='150,155,160,255'>WATER -5000 · ENERGY -5000</color><br/><color rgba='217,83,79,255'>OVERDOSE 5.0 (Lethal Risk). Poison. Death follows within seconds.</color><br/><color rgba='150,155,160,255'>LOT 1198Y · EXP 2027-07-03</color>";
	};


	//--------------------------------------------------------------
	// AUTO-INJECTORS
	//--------------------------------------------------------------

	class TerjeInjectorPromidol: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PROMIDOL 40 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE PAIN.<br/><color rgba='150,155,160,255'>PAIN L3 for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.45 (Moderate Risk). Strong opioid. Habit forming.</color><br/><color rgba='150,155,160,255'>LOT 9534S · EXP 2029-03-22</color>";
	};

	class TerjeInjectorPropital: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PROPITAL 100 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR PAIN AND RAPID WOUND RECOVERY.<br/><color rgba='150,155,160,255'>PAIN L2 for 3 min · HEALTH REGEN for 45 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.75 (High Risk). Combat stimulant. Habit forming.</color><br/><color rgba='150,155,160,255'>LOT 5203C · EXP 2028-04-05</color>";
	};

	class TerjeInjectorReanimatal: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>REANIMATAL 200 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH TO REVIVE A COLLAPSING CASUALTY.<br/><color rgba='150,155,160,255'>PAIN L3 for 4 min · HEALTH REGEN for 3 min · SHOCK -75</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.5 (Severe Risk). Buys minutes only, and takes a heavy toll to do it.</color><br/><color rgba='150,155,160,255'>LOT 8365K · EXP 2029-05-12</color>";
	};

	class TerjeInjectorAmoxiclav: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMOXICLAV 1.2 G · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR COLD/PNEUMONIA AND SEPSIS.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L3 for 30 min · SEPSIS for 5 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.6 (High Risk). Longest-acting antibiotic carried. Do not stack.</color><br/><color rgba='150,155,160,255'>LOT 7193X · EXP 2027-08-23</color>";
	};

	class TerjeInjectorTopoizomeraza: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>TOPOISOMERASE 400 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR COLD/PNEUMONIA AND SEPSIS.<br/><color rgba='150,155,160,255'>COLD/PNEUMONIA L3 for 15 min · SEPSIS for 10 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.65 (High Risk). Broad spectrum. Reserve for sepsis.</color><br/><color rgba='150,155,160,255'>LOT 8495N · EXP 2027-08-07</color>";
	};

	class TerjeInjectorNeirox: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NEIROX 250 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR CONCUSSION.<br/><color rgba='150,155,160,255'>CONCUSSION for 8 min 20 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.3 (Moderate Risk). Cerebral stimulant. May cause jitters.</color><br/><color rgba='150,155,160,255'>LOT 1012J · EXP 2027-01-08</color>";
	};

	class TerjeInjectorErytromixelin: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ERYTROMIXELIN 5 ML · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH TO SLOW THE BLEEDING RATE AND REBUILD BLOOD.<br/><color rgba='150,155,160,255'>BLEEDING RATE L3 for 5 min · BLOOD REGEN L2 for 2 min 30 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.32 (Moderate Risk). Does not replace a bandage or tourniquet.</color><br/><color rgba='150,155,160,255'>LOT 6761S · EXP 2028-07-22</color>";
	};

	class TerjeInjectorErythropoietin: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ERYTHROPOIETIN 4000 IU · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR BLOOD REGENERATION.<br/><color rgba='150,155,160,255'>BLOOD REGEN L1 for 15 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.4 (Moderate Risk). Slow acting. Thickens the blood if overused.</color><br/><color rgba='150,155,160,255'>LOT 7164G · EXP 2029-07-18</color>";
	};

	class TerjeInjectorStomaproxidal: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>STOMAPROXIDAL 250 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE FOOD POISONING.<br/><color rgba='150,155,160,255'>FOOD POISONING L3 for 15 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.68 (High Risk). Maximum strength. One dose per incident.</color><br/><color rgba='150,155,160,255'>LOT 5737S · EXP 2027-09-18</color>";
	};

	class TerjeInjectorRabinucoline: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RABINUCOLINE ANTISERUM 5 ML · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH AFTER AN ANIMAL BITE TO TREAT RABIES.<br/><color rgba='150,155,160,255'>RABIES L3 for 15 min</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.46 (Severe Risk). Maximum strength. Give once and monitor.</color><br/><color rgba='150,155,160,255'>LOT 5032F · EXP 2027-07-26</color>";
	};

	class TerjeInjectorAmfitalicyne: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMFITALICYNE 60 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE MENTAL HEALTH LOSS.<br/><color rgba='150,155,160,255'>MENTAL HEALTH L3 for 8 min 40 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.6 (High Risk). Psychotropic. Heavy sedation possible.</color><br/><color rgba='150,155,160,255'>LOT 8396V · EXP 2028-09-28</color>";
	};

	class TerjeInjectorZivirol: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ZIVIROL EXPERIMENTAL ANTIDOTE 10 ML · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH IMMEDIATELY AFTER ZOMBIE VIRUS INFECTION.<br/><color rgba='150,155,160,255'>ZOMBIE VIRUS for 20 min · HEALTH -20 · BLOOD -10 · SHOCK -100</color><br/><color rgba='217,83,79,255'>OVERDOSE 2.5 (Lethal Risk). Costs blood and health. One dose only.</color><br/><color rgba='150,155,160,255'>LOT 9612D · EXP 2029-12-07</color>";
	};

	class TerjeInjectorNovichek: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NOVICHEK NERVE AGENT · SINGLE-USE AUTO-INJECTOR · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT USE.<br/><color rgba='150,155,160,255'>SHOCK -100</color><br/><color rgba='217,83,79,255'>OVERDOSE 5.0 (Lethal Risk). Military nerve agent. Exposure is fatal.</color><br/><color rgba='150,155,160,255'>LOT 3419V · EXP 2029-11-01</color>";
	};


	//--------------------------------------------------------------
	// VANILLA INJECTORS RE-LABELLED BY TERJE MEDICINE
	//--------------------------------------------------------------

	class Morphine: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MORPHINE 10 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE PAIN.<br/><color rgba='150,155,160,255'>PAIN L3 for 5 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.75 (High Risk). Slows breathing. Habit forming.</color><br/><color rgba='150,155,160,255'>LOT 1721G · EXP 2027-01-27</color>";
	};

	class Epinephrine: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>EPINEPHRINE 0.3 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH TO REVERSE SHOCK AND RESTORE ALERTNESS.<br/><color rgba='150,155,160,255'>ADRENALINE for 12 min</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.55 (High Risk). Raises heart rate sharply. One dose per episode.</color><br/><color rgba='150,155,160,255'>LOT 2174W · EXP 2028-02-21</color>";
	};

	class AntiChemInjector: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NBC ANTIDOTE (ATROPINE / PRALIDOXIME) · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH IMMEDIATELY AFTER CHEMICAL POISONING.<br/><color rgba='150,155,160,255'>CHEMICAL POISONING L3 for 3 min</color><br/><color rgba='217,83,79,255'>OVERDOSE 1.1 (Severe Risk). Military issue. One dose per exposure, never two.</color><br/><color rgba='150,155,160,255'>LOT 1356Y · EXP 2029-03-07</color>";
	};

	class TerjeAntiradInjector: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ANTI-RADIATION AGENT · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH AFTER RADIATION EXPOSURE.<br/><color rgba='150,155,160,255'>RADIATION. VALUES SET BY SERVER CONFIG.</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.0 (None). One dose per exposure. Not a cure for burns.</color><br/><color rgba='150,155,160,255'>LOT 5297V · EXP 2028-11-27</color>";
	};


	//--------------------------------------------------------------
	// TOPICAL OINTMENTS
	//--------------------------------------------------------------

	class TerjeSalveViprosal: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VIPROSAL (CAMPHOR / TURPENTINE) 30 G · TOPICAL OINTMENT, TUBE</color><br/>APPLY A THIN LAYER TO BRUISING AND RUB IN GENTLY.<br/><color rgba='150,155,160,255'>HEMATOMA L1 for 10 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). External use only. Longest acting of the three.</color><br/><color rgba='150,155,160,255'>LOT 5665A · EXP 2030-09-11</color>";
	};

	class TerjeSalveCapsicum: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CAPSICUM OINTMENT 30 G · TOPICAL OINTMENT, TUBE</color><br/>APPLY A THIN LAYER TO BRUISING.<br/><color rgba='150,155,160,255'>HEMATOMA L1 for 6 min 40 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). External use only. Burns on broken skin.</color><br/><color rgba='150,155,160,255'>LOT 2590K · EXP 2027-01-23</color>";
	};

	class TerjeSalveFinalgon: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FINALGON (NONIVAMIDE) 20 G · TOPICAL OINTMENT, TUBE</color><br/>APPLY A SMALL AMOUNT TO BRUISING.<br/><color rgba='150,155,160,255'>HEMATOMA L1 for 5 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). External use only. Fast, short acting, strong burn.</color><br/><color rgba='150,155,160,255'>LOT 1179P · EXP 2027-02-23</color>";
	};


	//--------------------------------------------------------------
	// ENERGY DRINKS
	//--------------------------------------------------------------

	class TerjeDrinkYaguar: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>YAGUAR® ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION. STRONGEST FORMULA STOCKED.<br/><color rgba='150,155,160,255'>WAKEFULNESS +10 for 1 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). Very high caffeine. Not a substitute for sleep.</color><br/><color rgba='150,155,160,255'>LOT 2842H · BEST BY 2030-03-23</color>";
	};

	class TerjeDrinkMadBull: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MADBULL® ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION AND STAY AWAKE.<br/><color rgba='150,155,160,255'>WAKEFULNESS +8 for 1 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). High caffeine. Not a substitute for sleep.</color><br/><color rgba='150,155,160,255'>LOT 5434P · BEST BY 2031-03-05</color>";
	};

	class TerjeDrink6Energy: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>6-HOUR ENERGY® · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION AND STAY AWAKE.<br/><color rgba='150,155,160,255'>WAKEFULNESS +8 for 1 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). High caffeine. Not a substitute for sleep.</color><br/><color rgba='150,155,160,255'>LOT 3856V · BEST BY 2030-05-18</color>";
	};

	class TerjeDrinkGang: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>GANG® ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION.<br/><color rgba='150,155,160,255'>WAKEFULNESS +6 for 1 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). Moderate caffeine. Not a substitute for sleep.</color><br/><color rgba='150,155,160,255'>LOT 5376E · BEST BY 2029-10-20</color>";
	};

	class TerjeDrinkPrayboy: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PRAYBOY® ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO TAKE THE EDGE OFF TIREDNESS.<br/><color rgba='150,155,160,255'>WAKEFULNESS +4 for 1 sec</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). Mild formula. Not a substitute for sleep.</color><br/><color rgba='150,155,160,255'>LOT 8324Y · BEST BY 2030-06-09</color>";
	};


	//--------------------------------------------------------------
	// MEDICAL SUPPLIES (BASE CLASSES - ALL COLOUR VARIANTS INHERIT)
	//--------------------------------------------------------------

	class TerjeSurgicalTool_ColorBase: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MEDICAL BOWL WITH INSTRUMENT · TRAY, REUSABLE</color><br/>USE TO REMOVE FRAGMENTS AND CLOSE DEEP WOUNDS.<br/><color rgba='150,155,160,255'>WOUND SURGERY. VALUES SET BY SERVER CONFIG.</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). Sterilise before every use.</color><br/><color rgba='150,155,160,255'>LOT 9752C · STERILE UNTIL 2030-01-16</color>";
	};

	class TerjeSurgicalKit: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FIELD SURGICAL KIT · SEALED POUCH, MULTI-USE</color><br/>USE TO REMOVE FRAGMENTS AND CLOSE DEEP WOUNDS.<br/><color rgba='150,155,160,255'>WOUND SURGERY. VALUES SET BY SERVER CONFIG.</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). Contents are single-use. Discard when spent.</color><br/><color rgba='150,155,160,255'>LOT 4680A · STERILE UNTIL 2031-12-26</color>";
	};

	class TerjeFirstAidKitIndividualBase: Container_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>INDIVIDUAL FIRST AID KIT (IFAK) · SEALED POUCH, MULTI-USE</color><br/>USE TO TREAT YOUR OWN WOUNDS IN THE FIELD.<br/><color rgba='150,155,160,255'>WOUND TREATMENT. VALUES SET BY SERVER CONFIG.</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). Refill after use. Contents are consumed.</color><br/><color rgba='150,155,160,255'>LOT 8321X · STERILE UNTIL 2031-07-22</color>";
	};

	class TerjeFirstAidKitAdvancedBase: Container_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ADVANCED FIRST AID KIT (AFAK) · SEALED POUCH, MULTI-USE</color><br/>USE TO TREAT SERIOUS WOUNDS IN THE FIELD.<br/><color rgba='150,155,160,255'>BLEEDING RATE L3 for 1 min</color><br/><color rgba='150,155,160,255'>OVERDOSE 0.0 (None). Refill after use. Contents are consumed.</color><br/><color rgba='150,155,160,255'>LOT 9842J · STERILE UNTIL 2031-03-06</color>";
	};
};