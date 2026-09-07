// MedicineLabels - pill-bottle style item descriptions for TerjeMedicine.
// Overrides descriptionShort on every TerjeMedicine tablet, ampoule, injector and salve
// (plus the vanilla medical items TerjeMedicine repurposes) with a short label that
// says what the drug is, what it treats, how strong it is, how long it lasts,
// how toxic it is, and a flavour expiration date.
//
// Values are taken from TerjeMedicine's own config.cpp files (Pills, Ampouls,
// Injectors, Salves, FixVanilla). Regenerate with the script described in README.md
// if TerjeMedicine changes its numbers.

class CfgPatches
{
	class MedicineLabels
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Medical",
			"TerjeCore",
			"TerjeMedicine",
			"TerjeMedicine_Pills",
			"TerjeMedicine_Ampouls",
			"TerjeMedicine_Injectors",
			"TerjeMedicine_Salves",
			"TerjeMedicine_FixVanilla"
		};
	};
};

class CfgMods
{
	class MedicineLabels
	{
		dir = "MedicineLabels";
		action = "https://github.com/Loving-Life-Gaming/TerjeModsScripting";
		hideName = 0;
		hidePicture = 0;
		name = "Medicine Labels";
		credits = "Loving Life Gaming";
		version = "1.0.0";
		author = "Loving Life Gaming";
		dependencies[] = {"World"};
		extra = 0;
		type = "mod";

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"MedicineLabels/Scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class Edible_Base;
	class Inventory_Base;
	class TerjePillsBase;
	class TerjeAmpouleBase;
	class TerjeInjectorBase;
	class TerjeSalveBase;

	// Base classes: flag every child so the script keeps the label visible
	// even when the player has the Pill/Ampoule/Injector Recognition perk.
	class TerjePillsBase
	{
		medicineLabel=1;
	};
	class TerjeAmpouleBase
	{
		medicineLabel=1;
	};
	class TerjeInjectorBase
	{
		medicineLabel=1;
	};
	class TerjeSalveBase
	{
		medicineLabel=1;
	};

	// ---------------- TABLETS ----------------
	class CharcoalTablets: Edible_Base
	{
		descriptionShort="#STR_MEDLBL_CHARCOALTABLETS";
		medicineLabel=1;
	};
	class ChelatingTablets: Edible_Base
	{
		descriptionShort="#STR_MEDLBL_CHELATINGTABLETS";
		medicineLabel=1;
	};
	class PainkillerTablets: Edible_Base
	{
		descriptionShort="#STR_MEDLBL_PAINKILLERTABLETS";
		medicineLabel=1;
	};
	class TetracyclineAntibiotics: Edible_Base
	{
		descriptionShort="#STR_MEDLBL_TETRACYCLINEANTIBIOTICS";
		medicineLabel=1;
	};
	class VitaminBottle: Edible_Base
	{
		descriptionShort="#STR_MEDLBL_VITAMINBOTTLE";
		medicineLabel=1;
	};
	class TerjePillsAnalgin: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSANALGIN";
		medicineLabel=1;
	};
	class TerjePillsNimesulid: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSNIMESULID";
		medicineLabel=1;
	};
	class TerjePillsParacetamol: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSPARACETAMOL";
		medicineLabel=1;
	};
	class TerjePillsIbuprofen: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSIBUPROFEN";
		medicineLabel=1;
	};
	class TerjePillsNurofen: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSNUROFEN";
		medicineLabel=1;
	};
	class TerjePillsNoopept: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSNOOPEPT";
		medicineLabel=1;
	};
	class TerjePillsAmibaktam: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSAMIBAKTAM";
		medicineLabel=1;
	};
	class TerjePillsAmoxiclav: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSAMOXICLAV";
		medicineLabel=1;
	};
	class TerjePillsPiperacylin: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSPIPERACYLIN";
		medicineLabel=1;
	};
	class TerjePillsPolisorb: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSPOLISORB";
		medicineLabel=1;
	};
	class TerjePillsFtalazol: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSFTALAZOL";
		medicineLabel=1;
	};
	class TerjePillsMesalazin: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSMESALAZIN";
		medicineLabel=1;
	};
	class TerjePillsVikasol: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSVIKASOL";
		medicineLabel=1;
	};
	class TerjePillsIrovit: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSIROVIT";
		medicineLabel=1;
	};
	class TerjePillsMagnesiumSulfate: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSMAGNESIUMSULFATE";
		medicineLabel=1;
	};
	class TerjePillsAdepress: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSADEPRESS";
		medicineLabel=1;
	};
	class TerjePillsAgteminol: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSAGTEMINOL";
		medicineLabel=1;
	};
	class TerjePillsVenlafaxine: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSVENLAFAXINE";
		medicineLabel=1;
	};
	class TerjePillsB190: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSB190";
		medicineLabel=1;
	};
	class TerjePillsPotassiumIodide: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSPOTASSIUMIODIDE";
		medicineLabel=1;
	};
	class TerjePillsHexacyanoferrate: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSHEXACYANOFERRATE";
		medicineLabel=1;
	};
	class TerjePillsMexamine: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSMEXAMINE";
		medicineLabel=1;
	};
	class TerjePillsRombiopental: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSROMBIOPENTAL";
		medicineLabel=1;
	};
	class TerjePillsPotassiumCyanide: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSPOTASSIUMCYANIDE";
		medicineLabel=1;
	};
	class TerjePillsArsenic: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSARSENIC";
		medicineLabel=1;
	};
	class TerjePillsIversan: TerjePillsBase
	{
		descriptionShort="#STR_MEDLBL_TERJEPILLSIVERSAN";
		medicineLabel=1;
	};

	// ---------------- AMPOULES ----------------
	class TerjeAmpouleAlcohol: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEALCOHOL";
		medicineLabel=1;
	};
	class TerjeAmpouleAmoxivan: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEAMOXIVAN";
		medicineLabel=1;
	};
	class TerjeAmpouleKetarol: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEKETAROL";
		medicineLabel=1;
	};
	class TerjeAmpouleFlemoclav: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEFLEMOCLAV";
		medicineLabel=1;
	};
	class TerjeAmpouleImipenem: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEIMIPENEM";
		medicineLabel=1;
	};
	class TerjeAmpouleNovacaine: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULENOVACAINE";
		medicineLabel=1;
	};
	class TerjeAmpouleMorphine: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEMORPHINE";
		medicineLabel=1;
	};
	class TerjeAmpouleGexobarbital: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEGEXOBARBITAL";
		medicineLabel=1;
	};
	class TerjeAmpouleKetamin: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEKETAMIN";
		medicineLabel=1;
	};
	class TerjeAmpouleMetoclopramid: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEMETOCLOPRAMID";
		medicineLabel=1;
	};
	class TerjeAmpouleHeptral: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEHEPTRAL";
		medicineLabel=1;
	};
	class TerjeAmpouleNeirox: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULENEIROX";
		medicineLabel=1;
	};
	class TerjeAmpouleErythropoetin: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEERYTHROPOETIN";
		medicineLabel=1;
	};
	class TerjeAmpouleAdrenalin: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEADRENALIN";
		medicineLabel=1;
	};
	class TerjeAmpoulePentacin: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEPENTACIN";
		medicineLabel=1;
	};
	class TerjeAmpouleCarboxyme: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULECARBOXYME";
		medicineLabel=1;
	};
	class TerjeAmpouleMetralindole: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEMETRALINDOLE";
		medicineLabel=1;
	};
	class TerjeAmpouleActaparoxetine: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEACTAPAROXETINE";
		medicineLabel=1;
	};
	class TerjeAmpouleAmitriptyline: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEAMITRIPTYLINE";
		medicineLabel=1;
	};
	class TerjeAmpouleVaxicam: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEVAXICAM";
		medicineLabel=1;
	};
	class TerjeAmpouleZerivax: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEZERIVAX";
		medicineLabel=1;
	};
	class TerjeAmpouleRabivax: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULERABIVAX";
		medicineLabel=1;
	};
	class TerjeAmpouleRabinoline: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULERABINOLINE";
		medicineLabel=1;
	};
	class TerjeAmpouleRifampicyne: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULERIFAMPICYNE";
		medicineLabel=1;
	};
	class TerjeAmpouleNeirocetal: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULENEIROCETAL";
		medicineLabel=1;
	};
	class TerjeAmpouleZivirol: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEZIVIROL";
		medicineLabel=1;
	};
	class TerjeAmpoulePotassiumCyanide: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEPOTASSIUMCYANIDE";
		medicineLabel=1;
	};
	class TerjeAmpouleArsenic: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEARSENIC";
		medicineLabel=1;
	};
	class TerjeAmpouleBeladonna: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEBELADONNA";
		medicineLabel=1;
	};
	class TerjeAmpouleStrychnine: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULESTRYCHNINE";
		medicineLabel=1;
	};
	class TerjeAmpouleKonyin: TerjeAmpouleBase
	{
		descriptionShort="#STR_MEDLBL_TERJEAMPOULEKONYIN";
		medicineLabel=1;
	};

	// ---------------- INJECTORS ----------------
	class Epinephrine: Inventory_Base
	{
		descriptionShort="#STR_MEDLBL_EPINEPHRINE";
		medicineLabel=1;
	};
	class Morphine: Inventory_Base
	{
		descriptionShort="#STR_MEDLBL_MORPHINE";
		medicineLabel=1;
	};
	class AntiChemInjector: Inventory_Base
	{
		descriptionShort="#STR_MEDLBL_ANTICHEMINJECTOR";
		medicineLabel=1;
	};
	class TerjeInjectorZivirol: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORZIVIROL";
		medicineLabel=1;
	};
	class TerjeInjectorAmoxiclav: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORAMOXICLAV";
		medicineLabel=1;
	};
	class TerjeInjectorTopoizomeraza: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORTOPOIZOMERAZA";
		medicineLabel=1;
	};
	class TerjeInjectorNeirox: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORNEIROX";
		medicineLabel=1;
	};
	class TerjeInjectorErythropoietin: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORERYTHROPOIETIN";
		medicineLabel=1;
	};
	class TerjeInjectorErytromixelin: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORERYTROMIXELIN";
		medicineLabel=1;
	};
	class TerjeInjectorPromidol: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORPROMIDOL";
		medicineLabel=1;
	};
	class TerjeInjectorPropital: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORPROPITAL";
		medicineLabel=1;
	};
	class TerjeInjectorReanimatal: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORREANIMATAL";
		medicineLabel=1;
	};
	class TerjeInjectorStomaproxidal: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORSTOMAPROXIDAL";
		medicineLabel=1;
	};
	class TerjeInjectorRabinucoline: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORRABINUCOLINE";
		medicineLabel=1;
	};
	class TerjeInjectorAmfitalicyne: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORAMFITALICYNE";
		medicineLabel=1;
	};
	class TerjeInjectorNovichek: TerjeInjectorBase
	{
		descriptionShort="#STR_MEDLBL_TERJEINJECTORNOVICHEK";
		medicineLabel=1;
	};

	// ---------------- SALVES ----------------
	class TerjeSalveFinalgon: TerjeSalveBase
	{
		descriptionShort="#STR_MEDLBL_TERJESALVEFINALGON";
		medicineLabel=1;
	};
	class TerjeSalveCapsicum: TerjeSalveBase
	{
		descriptionShort="#STR_MEDLBL_TERJESALVECAPSICUM";
		medicineLabel=1;
	};
	class TerjeSalveViprosal: TerjeSalveBase
	{
		descriptionShort="#STR_MEDLBL_TERJESALVEVIPROSAL";
		medicineLabel=1;
	};
};
