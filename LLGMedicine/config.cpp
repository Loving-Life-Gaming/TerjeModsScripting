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
	// them. Declaring a different parent here would re-parent the class and
	// silently drop everything TerjeMedicine set on it.
	class Inventory_Base;
	class Container_Base;
	class Edible_Base;
	class SodaCan_ColorBase;
	class TerjePillsBase: Edible_Base;
	class TerjeAmpouleBase: Inventory_Base;
	class TerjeInjectorBase: Inventory_Base;
	class TerjeSalveBase: Inventory_Base;
	class TerjeEnergyDrink: SodaCan_ColorBase;

	// Each override sets llgPharmacyLabel=1, which routes that item's tooltip
	// through the label renderer in Scripts/4_World/LLGMedicineLabels.c.

	//--------------------------------------------------------------
	// PILLS AND CAPSULES
	//--------------------------------------------------------------

	class TerjePillsAnalgin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ANALGIN (METAMIZOLE) 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR MILD TO MODERATE PAIN.<br/><color rgba='150,155,160,255'>NOTE: Short acting. Wears off quickly under stress.</color>";
	};

	class TerjePillsNimesulid: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NIMESULIDE 100 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR PAIN AND SWELLING.<br/><color rgba='240,173,78,255'>CAUTION: Take with food. May irritate the stomach.</color>";
	};

	class TerjePillsParacetamol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PARACETAMOL 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR PAIN, FEVER AND EARLY COLD SYMPTOMS.<br/><color rgba='240,173,78,255'>CAUTION: Liver damage occurs above the labelled dose.</color>";
	};

	class TerjePillsIbuprofen: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IBUPROFEN 400 MG · ORAL CAPSULE</color><br/>TAKE 1 CAPSULE BY MOUTH FOR PAIN AND CHEST INFECTION.<br/><color rgba='240,173,78,255'>CAUTION: Take with food. May irritate the stomach.</color>";
	};

	class TerjePillsNurofen: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NUROFEN (IBUPROFEN LYSINE) 512 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR FEVER AND CHEST INFECTION.<br/><color rgba='240,173,78,255'>WARNING: Fast acting and easy to overdose. One tablet per dose.</color>";
	};

	class TerjePillsAmoxiclav: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMOXICILLIN / CLAVULANATE 875 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR RESPIRATORY INFECTION.<br/><color rgba='240,173,78,255'>WARNING: Full-strength antibiotic. Space doses well apart.</color>";
	};

	class TerjePillsPiperacylin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PIPERACILLIN 500 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR RESPIRATORY INFECTION.<br/><color rgba='240,173,78,255'>CAUTION: Finish the course. Never double a missed dose.</color>";
	};

	class TerjePillsAmibaktam: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMIBACTAM 250 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH AT THE FIRST SIGN OF A COLD.<br/><color rgba='150,155,160,255'>NOTE: Weak and very short acting. Not for pneumonia.</color>";
	};

	class TerjePillsPolisorb: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POLYSORB (SILICON DIOXIDE) 3 G · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR NAUSEA AND MILD FOOD POISONING.<br/><color rgba='150,155,160,255'>NOTE: Drink plenty of water with each dose.</color>";
	};

	class TerjePillsFtalazol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PHTHALYLSULFATHIAZOLE 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH FOR PERSISTENT FOOD POISONING.<br/><color rgba='240,173,78,255'>CAUTION: Long acting. Wait before taking another.</color>";
	};

	class TerjePillsMesalazin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MESALAZINE 800 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR SEVERE FOOD POISONING.<br/><color rgba='240,173,78,255'>CAUTION: Do not combine with other gut medication.</color>";
	};

	class TerjePillsNoopept: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NOOPEPT 10 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR HEADACHE AND CONCUSSION.<br/><color rgba='240,173,78,255'>CAUTION: May cause irritability and disturbed sleep.</color>";
	};

	class TerjePillsVikasol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VIKASOL (VITAMIN K3) 15 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH TO SLOW BLOOD LOSS.<br/><color rgba='150,155,160,255'>NOTE: Does not replace a bandage or tourniquet.</color>";
	};

	class TerjePillsIrovit: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IROVIT (FERROUS SULFATE) 325 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH TO REBUILD LOST BLOOD.<br/><color rgba='240,173,78,255'>CAUTION: May cause nausea. Take with food.</color>";
	};

	class TerjePillsMagnesiumSulfate: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MAGNESIUM SULFATE 500 MG · ORAL CAPSULE</color><br/>TAKE 1 CAPSULE BY MOUTH TO REBUILD LOST BLOOD.<br/><color rgba='240,173,78,255'>CAUTION: May cause flushing and light-headedness.</color>";
	};

	class TerjePillsAdepress: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ADEPRESS (PAROXETINE) 20 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH TO STEADY MOOD AND NERVES.<br/><color rgba='150,155,160,255'>NOTE: May cause drowsiness. Do not take with alcohol.</color>";
	};

	class TerjePillsAgteminol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AGTEMINOL 25 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH TO CALM NERVES.<br/><color rgba='150,155,160,255'>NOTE: May cause mild drowsiness.</color>";
	};

	class TerjePillsVenlafaxine: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VENLAFAXINE 75 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH TO STEADY MOOD.<br/><color rgba='240,173,78,255'>CAUTION: Do not stop suddenly after repeated use.</color>";
	};

	class TerjePillsRombiopental: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ROMBIOPENTAL 100 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH BEFORE ENTERING CONTAMINATED AIR.<br/><color rgba='150,155,160,255'>NOTE: Protective window is under one minute.</color>";
	};

	class TerjePillsB190: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>INDRALIN (B-190) 150 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH BEFORE ENTERING A RADIATION ZONE.<br/><color rgba='240,173,78,255'>CAUTION: Preventive only. Does nothing once exposed.</color>";
	};

	class TerjePillsPotassiumIodide: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POTASSIUM IODIDE 130 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH BEFORE ENTERING A RADIATION ZONE.<br/><color rgba='150,155,160,255'>NOTE: Protects the thyroid only. Short duration.</color>";
	};

	class TerjePillsHexacyanoferrate: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FERRIC HEXACYANOFERRATE 500 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH AFTER RADIOACTIVE CONTAMINATION.<br/><color rgba='240,173,78,255'>CAUTION: Binds fallout in the gut. Not a cure.</color>";
	};

	class TerjePillsMexamine: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MEXAMINE 50 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH IMMEDIATELY BEFORE HEAVY RADIATION EXPOSURE.<br/><color rgba='240,173,78,255'>WARNING: Very strong and very brief. High overdose risk.</color>";
	};

	class TerjePillsIversan: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IVERSAN 12 MG · ORAL TABLET · CONTROLLED POISON</color><br/>UNLICENSED FORMULATION. NOT FIT FOR HUMAN USE.<br/><color rgba='217,83,79,255'>WARNING: Swallowing causes severe poisoning.</color>";
	};

	class TerjePillsArsenic: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ARSENIC TRIOXIDE 200 MG · ORAL TABLET · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT SWALLOW.<br/><color rgba='217,83,79,255'>DANGER: Poison. Causes fatal organ failure.</color>";
	};

	class TerjePillsPotassiumCyanide: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POTASSIUM CYANIDE 300 MG · ORAL TABLET · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT SWALLOW.<br/><color rgba='217,83,79,255'>DANGER: Poison. Death follows within seconds.</color>";
	};


	//--------------------------------------------------------------
	// VANILLA PILLS RE-LABELLED BY TERJE MEDICINE
	//--------------------------------------------------------------

	class PainkillerTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CODEINE PHOSPHATE 30 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH FOR PAIN.<br/><color rgba='150,155,160,255'>NOTE: May cause drowsiness. Habit forming.</color>";
	};

	class TetracyclineAntibiotics: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>TETRACYCLINE 250 MG · ORAL CAPSULE · RX ONLY</color><br/>TAKE 1 CAPSULE BY MOUTH FOR INFECTION.<br/><color rgba='240,173,78,255'>CAUTION: Avoid dairy. Finish the course.</color>";
	};

	class CharcoalTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ACTIVATED CHARCOAL 500 MG · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH AFTER SWALLOWING SPOILED FOOD.<br/><color rgba='150,155,160,255'>Works only on recent poisoning.</color>";
	};

	class ChelatingTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CHELATION TABLETS (DMSA) 200 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR HEAVY-METAL OR CHEMICAL POISONING.<br/><color rgba='240,173,78,255'>WARNING: Strong binder. Depletes minerals with repeat use.</color>";
	};

	class VitaminBottle: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MULTIVITAMIN COMPLEX · ORAL TABLET</color><br/>TAKE 1 TABLET BY MOUTH DAILY TO SUPPORT IMMUNITY.<br/><color rgba='150,155,160,255'>Dietary supplement. Not a medicine.</color>";
	};

	class PurificationTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>WATER PURIFICATION TABLETS 8.5 MG · ORAL TABLET</color><br/>ADD 1 TABLET TO ONE LITRE OF WATER AND WAIT 30 MINUTES.<br/><color rgba='150,155,160,255'>NOTE: For water treatment only. Do not swallow dry.</color>";
	};


	//--------------------------------------------------------------
	// AMPOULES (REQUIRE A STERILE SYRINGE)
	//--------------------------------------------------------------

	class TerjeAmpouleAlcohol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MEDICAL ALCOHOL 96% · INJECTION AMPOULE</color><br/>FOR CLEANING WOUNDS AND INSTRUMENTS. EXTERNAL USE ONLY.<br/><color rgba='217,83,79,255'>DANGER: Never inject. Injection is fatal.</color>";
	};

	class TerjeAmpouleAmoxivan: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMOXIVAN (AMOXICILLIN) 1 G · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR CHEST INFECTION.<br/><color rgba='240,173,78,255'>CAUTION: Full-strength antibiotic. Space doses apart.</color>";
	};

	class TerjeAmpouleKetarol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>KETAROL (KETOROLAC) 30 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR INFECTION ACCOMPANIED BY PAIN.<br/><color rgba='240,173,78,255'>WARNING: Long acting. Do not stack with other painkillers.</color>";
	};

	class TerjeAmpouleFlemoclav: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FLEMOCLAV 1.2 G · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE INFECTION AND SEPSIS.<br/><color rgba='240,173,78,255'>WARNING: Maximum-strength antibiotic. Clinical use.</color>";
	};

	class TerjeAmpouleImipenem: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IMIPENEM 500 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE INFECTION AND SEPSIS.<br/><color rgba='240,173,78,255'>WARNING: Last-line antibiotic. Reserve for sepsis.</color>";
	};

	class TerjeAmpouleNovacaine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NOVOCAINE (PROCAINE) 2% · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR MODERATE PAIN.<br/><color rgba='240,173,78,255'>CAUTION: May cause numbness and light-headedness.</color>";
	};

	class TerjeAmpouleMorphine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MORPHINE SULFATE 10 MG/ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE PAIN.<br/><color rgba='240,173,78,255'>WARNING: Slows breathing. Habit forming.</color>";
	};

	class TerjeAmpouleGexobarbital: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>HEXOBARBITAL 500 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE PAIN WITH SEDATION.<br/><color rgba='240,173,78,255'>WARNING: Heavy sedation. Never combine with alcohol.</color>";
	};

	class TerjeAmpouleKetamin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>KETAMINE 500 MG / 10 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE PAIN WHEN NOTHING ELSE WORKS.<br/><color rgba='240,173,78,255'>CAUTION: Causes dissociation and confusion.</color>";
	};

	class TerjeAmpouleMetoclopramid: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>METOCLOPRAMIDE 10 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE NAUSEA AND VOMITING.<br/><color rgba='240,173,78,255'>CAUTION: May cause restlessness and muscle stiffness.</color>";
	};

	class TerjeAmpouleHeptral: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>HEPTRAL (ADEMETIONINE) 400 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR LIVER DAMAGE CAUSED BY POISONING.<br/><color rgba='240,173,78,255'>WARNING: Maximum strength. Space doses widely.</color>";
	};

	class TerjeAmpouleNeirox: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NEIROX 250 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR CONCUSSION AND HEAD INJURY.<br/><color rgba='240,173,78,255'>WARNING: Cerebral stimulant. Do not redose quickly.</color>";
	};

	class TerjeAmpouleErythropoetin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ERYTHROPOIETIN 4000 IU · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT TO REBUILD BLOOD OVER TIME.<br/><color rgba='240,173,78,255'>CAUTION: Slow acting. Thickens the blood if overused.</color>";
	};

	class TerjeAmpouleAdrenalin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ADRENALINE (EPINEPHRINE) 1 MG/ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT TO FIGHT SHOCK AND RESTORE ALERTNESS.<br/><color rgba='240,173,78,255'>CAUTION: Raises heart rate sharply. Emergency use only.</color>";
	};

	class TerjeAmpouleMetralindole: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>METRALINDOLE 25 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT TO STEADY MOOD AND NERVES.<br/><color rgba='150,155,160,255'>NOTE: Mild sedation. Very low overdose risk.</color>";
	};

	class TerjeAmpouleActaparoxetine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ACTAPAROXETINE 40 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR SEVERE ANXIETY AND PANIC.<br/><color rgba='240,173,78,255'>CAUTION: May cause drowsiness for several minutes.</color>";
	};

	class TerjeAmpouleAmitriptyline: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMITRIPTYLINE 50 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR A SEVERE MENTAL BREAKDOWN.<br/><color rgba='240,173,78,255'>WARNING: Heavy sedation. Do not drive after use.</color>";
	};

	class TerjeAmpouleVaxicam: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VAXICAM INFLUENZA VACCINE 0.5 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT BEFORE EXPOSURE TO PREVENT COLD AND PNEUMONIA.<br/><color rgba='240,173,78,255'>WARNING: Preventive only. Does nothing once ill.</color>";
	};

	class TerjeAmpouleZerivax: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ZERIVAX Z-VIRUS VACCINE 0.5 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT BEFORE EXPOSURE TO PREVENT Z-VIRUS INFECTION.<br/><color rgba='217,83,79,255'>WARNING: Preventive only. Severe reaction risk.</color>";
	};

	class TerjeAmpouleRabivax: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RABIVAX RABIES VACCINE 1 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT BEFORE EXPOSURE TO PREVENT RABIES.<br/><color rgba='217,83,79,255'>WARNING: Preventive only. Useless once symptoms begin.</color>";
	};

	class TerjeAmpouleRabinoline: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RABINOLINE ANTISERUM 5 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER AN ANIMAL BITE TO TREAT RABIES.<br/><color rgba='240,173,78,255'>WARNING: Give early. Serum reaction possible.</color>";
	};

	class TerjeAmpouleRifampicyne: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RIFAMPICIN 600 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT FOR ADVANCED RABIES.<br/><color rgba='217,83,79,255'>WARNING: Maximum strength. Very high overdose risk.</color>";
	};

	class TerjeAmpouleZivirol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ZIVIROL Z-ANTIDOTE 10 ML · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT IMMEDIATELY AFTER Z-VIRUS INFECTION.<br/><color rgba='217,83,79,255'>DANGER: Costs blood and health. One dose only.</color>";
	};

	class TerjeAmpouleNeirocetal: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NEIROCETAL 200 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER BREATHING TOXIC OR CHEMICAL AGENTS.<br/><color rgba='217,83,79,255'>WARNING: Narrow safety margin. One dose only.</color>";
	};

	class TerjeAmpoulePentacin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PENTACIN (CA-DTPA) 250 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER HEAVY RADIOACTIVE CONTAMINATION.<br/><color rgba='240,173,78,255'>WARNING: Strips minerals from the body. Limit doses.</color>";
	};

	class TerjeAmpouleCarboxyme: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CARBOXYME 300 MG · INJECTION AMPOULE · RX ONLY</color><br/>DRAW WITH A STERILE SYRINGE AND INJECT AFTER PROLONGED RADIATION EXPOSURE.<br/><color rgba='240,173,78,255'>WARNING: Long acting. Limit repeat doses.</color>";
	};

	class TerjeAmpouleBeladonna: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>BELLADONNA EXTRACT 1 ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='217,83,79,255'>DANGER: Poison. Causes delirium and collapse.</color>";
	};

	class TerjeAmpouleStrychnine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>STRYCHNINE 5 MG/ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='217,83,79,255'>DANGER: Poison. Causes violent convulsions.</color>";
	};

	class TerjeAmpouleKonyin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>KONYIN (CONIINE) 2 ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='217,83,79,255'>DANGER: Poison. Causes paralysis and unconsciousness.</color>";
	};

	class TerjeAmpouleArsenic: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ARSENIC TRIOXIDE 10 MG/ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='217,83,79,255'>DANGER: Poison. Fatal multi-organ failure.</color>";
	};

	class TerjeAmpoulePotassiumCyanide: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>POTASSIUM CYANIDE 300 MG/ML · INJECTION AMPOULE · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT INJECT.<br/><color rgba='217,83,79,255'>DANGER: Poison. Death follows within seconds.</color>";
	};


	//--------------------------------------------------------------
	// AUTO-INJECTORS
	//--------------------------------------------------------------

	class TerjeInjectorPromidol: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PROMIDOL 40 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE PAIN.<br/><color rgba='240,173,78,255'>CAUTION: Strong opioid. Habit forming.</color>";
	};

	class TerjeInjectorPropital: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PROPITAL 100 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR PAIN AND RAPID WOUND RECOVERY.<br/><color rgba='240,173,78,255'>WARNING: Combat stimulant. Habit forming.</color>";
	};

	class TerjeInjectorReanimatal: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>REANIMATAL 200 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH TO REVIVE A COLLAPSING CASUALTY.<br/><color rgba='217,83,79,255'>WARNING: Buys minutes only. Very high overdose risk.</color>";
	};

	class TerjeInjectorAmoxiclav: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMOXICILLIN / CLAVULANATE 1.2 G · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE INFECTION AND SEPSIS.<br/><color rgba='240,173,78,255'>WARNING: Longest-acting antibiotic carried. Do not stack.</color>";
	};

	class TerjeInjectorTopoizomeraza: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>TOPOISOMERASE 400 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE INFECTION AND SEPSIS.<br/><color rgba='240,173,78,255'>WARNING: Broad spectrum. Reserve for sepsis.</color>";
	};

	class TerjeInjectorNeirox: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NEIROX 250 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR CONCUSSION AND HEAD INJURY.<br/><color rgba='240,173,78,255'>CAUTION: Cerebral stimulant. May cause jitters.</color>";
	};

	class TerjeInjectorErytromixelin: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ERYTROMIXELIN 5 ML · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH TO STOP HEAVY BLEEDING AND REBUILD BLOOD.<br/><color rgba='240,173,78,255'>CAUTION: Does not replace a bandage or tourniquet.</color>";
	};

	class TerjeInjectorErythropoietin: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ERYTHROPOIETIN 4000 IU · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH TO REBUILD BLOOD OVER TIME.<br/><color rgba='240,173,78,255'>CAUTION: Slow acting. Thickens the blood if overused.</color>";
	};

	class TerjeInjectorStomaproxidal: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>STOMAPROXIDAL 250 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE POISONING AND VOMITING.<br/><color rgba='240,173,78,255'>WARNING: Maximum strength. One dose per incident.</color>";
	};

	class TerjeInjectorRabinucoline: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>RABINUCOLINE ANTISERUM 5 ML · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH AFTER AN ANIMAL BITE TO TREAT RABIES.<br/><color rgba='217,83,79,255'>WARNING: Maximum strength. Very high overdose risk.</color>";
	};

	class TerjeInjectorAmfitalicyne: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AMFITALICYNE 60 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR A SEVERE MENTAL BREAKDOWN.<br/><color rgba='240,173,78,255'>WARNING: Psychotropic. Heavy sedation possible.</color>";
	};

	class TerjeInjectorZivirol: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ZIVIROL Z-ANTIDOTE 10 ML · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH IMMEDIATELY AFTER Z-VIRUS INFECTION.<br/><color rgba='217,83,79,255'>DANGER: Costs blood and health. One dose only.</color>";
	};

	class TerjeInjectorNovichek: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NOVICHEK NERVE AGENT · SINGLE-USE AUTO-INJECTOR · CONTROLLED POISON</color><br/>NOT A MEDICINE. DO NOT USE.<br/><color rgba='217,83,79,255'>DANGER: Military nerve agent. Exposure is fatal.</color>";
	};


	//--------------------------------------------------------------
	// VANILLA INJECTORS RE-LABELLED BY TERJE MEDICINE
	//--------------------------------------------------------------

	class Morphine: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MORPHINE 10 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH FOR SEVERE PAIN.<br/><color rgba='240,173,78,255'>WARNING: Slows breathing. Habit forming.</color>";
	};

	class Epinephrine: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>EPINEPHRINE 0.3 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH TO REVERSE SHOCK AND RESTORE ALERTNESS.<br/><color rgba='240,173,78,255'>WARNING: Raises heart rate sharply. One dose per episode.</color>";
	};

	class AntiChemInjector: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>NBC ANTIDOTE (ATROPINE / PRALIDOXIME) · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH IMMEDIATELY AFTER CHEMICAL OR NERVE AGENT EXPOSURE.<br/><color rgba='217,83,79,255'>WARNING: Military issue. Very high overdose risk.</color>";
	};

	class TerjeAntiradInjector: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>ANTI-RADIATION AGENT · SINGLE-USE AUTO-INJECTOR · RX ONLY</color><br/>PRESS FIRMLY AGAINST THE OUTER THIGH AFTER RADIATION EXPOSURE.<br/><color rgba='240,173,78,255'>CAUTION: One dose per exposure. Not a cure for burns.</color>";
	};


	//--------------------------------------------------------------
	// TOPICAL OINTMENTS
	//--------------------------------------------------------------

	class TerjeSalveViprosal: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>VIPROSAL (CAMPHOR / TURPENTINE) 30 G · TOPICAL OINTMENT, TUBE</color><br/>APPLY A THIN LAYER TO BRUISING AND RUB IN GENTLY.<br/><color rgba='150,155,160,255'>External use only. Longest acting of the three.</color>";
	};

	class TerjeSalveCapsicum: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>CAPSICUM OINTMENT 30 G · TOPICAL OINTMENT, TUBE</color><br/>APPLY A THIN LAYER TO BRUISING.<br/><color rgba='150,155,160,255'>External use only. Burns on broken skin.</color>";
	};

	class TerjeSalveFinalgon: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FINALGON (NONIVAMIDE) 20 G · TOPICAL OINTMENT, TUBE</color><br/>APPLY A SMALL AMOUNT TO BRUISING.<br/><color rgba='150,155,160,255'>External use only. Fast, short acting, strong burn.</color>";
	};


	//--------------------------------------------------------------
	// ENERGY DRINKS
	//--------------------------------------------------------------

	class TerjeDrinkYaguar: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>YAGUAR ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION. STRONGEST FORMULA STOCKED.<br/><color rgba='150,155,160,255'>NOTE: Very high caffeine. Not a substitute for sleep.</color>";
	};

	class TerjeDrinkMadBull: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>MADBULL ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION AND STAY AWAKE.<br/><color rgba='150,155,160,255'>NOTE: High caffeine. Not a substitute for sleep.</color>";
	};

	class TerjeDrink6Energy: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>6ENERGY ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION AND STAY AWAKE.<br/><color rgba='150,155,160,255'>NOTE: High caffeine. Not a substitute for sleep.</color>";
	};

	class TerjeDrinkGang: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>GANG ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO FIGHT EXHAUSTION.<br/><color rgba='150,155,160,255'>NOTE: Moderate caffeine. Not a substitute for sleep.</color>";
	};

	class TerjeDrinkPrayboy: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>PRAYBOY ENERGY DRINK · 500 ML CAN</color><br/>DRINK TO TAKE THE EDGE OFF TIREDNESS.<br/><color rgba='150,155,160,255'>Mild formula. Not a substitute for sleep.</color>";
	};


	//--------------------------------------------------------------
	// MEDICAL SUPPLIES (BASE CLASSES - ALL COLOUR VARIANTS INHERIT)
	//--------------------------------------------------------------

	class TerjeSurgicalTool_ColorBase: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>SURGICAL INSTRUMENT SET · TRAY, REUSABLE</color><br/>USE TO REMOVE FRAGMENTS AND CLOSE DEEP WOUNDS.<br/><color rgba='150,155,160,255'>NOTE: Sterilise before every use.</color>";
	};

	class TerjeSurgicalKit: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>FIELD SURGICAL KIT · SEALED POUCH, MULTI-USE</color><br/>USE TO REMOVE FRAGMENTS AND CLOSE DEEP WOUNDS.<br/><color rgba='150,155,160,255'>NOTE: Contents are single-use. Discard when spent.</color>";
	};

	class TerjeFirstAidKitIndividualBase: Container_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>IFAK · INDIVIDUAL FIRST AID KIT · SEALED POUCH, MULTI-USE</color><br/>USE TO TREAT YOUR OWN WOUNDS IN THE FIELD.<br/><color rgba='150,155,160,255'>NOTE: Refill after use. Contents are consumed.</color>";
	};

	class TerjeFirstAidKitAdvancedBase: Container_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="<color rgba='222,226,230,255'>AFAK · ADVANCED FIRST AID KIT · SEALED POUCH, MULTI-USE</color><br/>USE TO TREAT SERIOUS WOUNDS IN THE FIELD.<br/><color rgba='150,155,160,255'>NOTE: Refill after use. Contents are consumed.</color>";
	};
};