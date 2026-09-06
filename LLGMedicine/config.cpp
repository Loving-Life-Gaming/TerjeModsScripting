// LLG Medicine - pharmacy-label overrides for TerjeMedicine.
//
// This addon changes nothing but item text. Every class below re-opens an
// existing TerjeMedicine or vanilla class and sets `descriptionShort` only,
// so balance values (levels, timers, overdose increments) stay wherever
// TerjeMedicine puts them and keep working after an upstream update.
//
// Label text lives in stringtable.csv, not here. Edit that file to reword a
// label or to translate one; no config change is needed.

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
		descriptionShort="#STR_LLGMED_PILL_ANALGIN_DESC";
	};

	class TerjePillsNimesulid: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_NIMESULID_DESC";
	};

	class TerjePillsParacetamol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_PARACETAMOL_DESC";
	};

	class TerjePillsIbuprofen: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_IBUPROFEN_DESC";
	};

	class TerjePillsNurofen: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_NUROFEN_DESC";
	};

	class TerjePillsAmoxiclav: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_AMOXICLAV_DESC";
	};

	class TerjePillsPiperacylin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_PIPERACYLIN_DESC";
	};

	class TerjePillsAmibaktam: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_AMIBAKTAM_DESC";
	};

	class TerjePillsPolisorb: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_POLISORB_DESC";
	};

	class TerjePillsFtalazol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_FTALAZOL_DESC";
	};

	class TerjePillsMesalazin: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_MESALAZIN_DESC";
	};

	class TerjePillsNoopept: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_NOOPEPT_DESC";
	};

	class TerjePillsVikasol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_VIKASOL_DESC";
	};

	class TerjePillsIrovit: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_IROVIT_DESC";
	};

	class TerjePillsMagnesiumSulfate: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_MAGNESIUMSULFATE_DESC";
	};

	class TerjePillsAdepress: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_ADEPRESS_DESC";
	};

	class TerjePillsAgteminol: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_AGTEMINOL_DESC";
	};

	class TerjePillsVenlafaxine: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_VENLAFAXINE_DESC";
	};

	class TerjePillsRombiopental: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_ROMBIOPENTAL_DESC";
	};

	class TerjePillsB190: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_B190_DESC";
	};

	class TerjePillsPotassiumIodide: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_POTASSIUMIODIDE_DESC";
	};

	class TerjePillsHexacyanoferrate: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_HEXACYANOFERRATE_DESC";
	};

	class TerjePillsMexamine: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_MEXAMINE_DESC";
	};

	class TerjePillsIversan: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_IVERSAN_DESC";
	};

	class TerjePillsArsenic: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_ARSENIC_DESC";
	};

	class TerjePillsPotassiumCyanide: TerjePillsBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PILL_POTASSIUMCYANIDE_DESC";
	};


	//--------------------------------------------------------------
	// VANILLA PILLS RE-LABELLED BY TERJE MEDICINE
	//--------------------------------------------------------------

	class PainkillerTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PAINKILLERTABLETS_DESC";
	};

	class TetracyclineAntibiotics: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_TETRACYCLINEANTIBIOTICS_DESC";
	};

	class CharcoalTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_CHARCOALTABLETS_DESC";
	};

	class ChelatingTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_CHELATINGTABLETS_DESC";
	};

	class VitaminBottle: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_VITAMINBOTTLE_DESC";
	};

	class PurificationTablets: Edible_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_PURIFICATIONTABLETS_DESC";
	};


	//--------------------------------------------------------------
	// AMPOULES (REQUIRE A STERILE SYRINGE)
	//--------------------------------------------------------------

	class TerjeAmpouleAlcohol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_ALCOHOL_DESC";
	};

	class TerjeAmpouleAmoxivan: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_AMOXIVAN_DESC";
	};

	class TerjeAmpouleKetarol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_KETAROL_DESC";
	};

	class TerjeAmpouleFlemoclav: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_FLEMOCLAV_DESC";
	};

	class TerjeAmpouleImipenem: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_IMIPENEM_DESC";
	};

	class TerjeAmpouleNovacaine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_NOVACAINE_DESC";
	};

	class TerjeAmpouleMorphine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_MORPHINE_DESC";
	};

	class TerjeAmpouleGexobarbital: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_GEXOBARBITAL_DESC";
	};

	class TerjeAmpouleKetamin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_KETAMIN_DESC";
	};

	class TerjeAmpouleMetoclopramid: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_METOCLOPRAMID_DESC";
	};

	class TerjeAmpouleHeptral: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_HEPTRAL_DESC";
	};

	class TerjeAmpouleNeirox: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_NEIROX_DESC";
	};

	class TerjeAmpouleErythropoetin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_ERYTHROPOETIN_DESC";
	};

	class TerjeAmpouleAdrenalin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_ADRENALIN_DESC";
	};

	class TerjeAmpouleMetralindole: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_METRALINDOLE_DESC";
	};

	class TerjeAmpouleActaparoxetine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_ACTAPAROXETINE_DESC";
	};

	class TerjeAmpouleAmitriptyline: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_AMITRIPTYLINE_DESC";
	};

	class TerjeAmpouleVaxicam: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_VAXICAM_DESC";
	};

	class TerjeAmpouleZerivax: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_ZERIVAX_DESC";
	};

	class TerjeAmpouleRabivax: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_RABIVAX_DESC";
	};

	class TerjeAmpouleRabinoline: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_RABINOLINE_DESC";
	};

	class TerjeAmpouleRifampicyne: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_RIFAMPICYNE_DESC";
	};

	class TerjeAmpouleZivirol: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_ZIVIROL_DESC";
	};

	class TerjeAmpouleNeirocetal: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_NEIROCETAL_DESC";
	};

	class TerjeAmpoulePentacin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_PENTACIN_DESC";
	};

	class TerjeAmpouleCarboxyme: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_CARBOXYME_DESC";
	};

	class TerjeAmpouleBeladonna: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_BELADONNA_DESC";
	};

	class TerjeAmpouleStrychnine: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_STRYCHNINE_DESC";
	};

	class TerjeAmpouleKonyin: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_KONYIN_DESC";
	};

	class TerjeAmpouleArsenic: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_ARSENIC_DESC";
	};

	class TerjeAmpoulePotassiumCyanide: TerjeAmpouleBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_AMP_POTASSIUMCYANIDE_DESC";
	};


	//--------------------------------------------------------------
	// AUTO-INJECTORS
	//--------------------------------------------------------------

	class TerjeInjectorPromidol: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_PROMIDOL_DESC";
	};

	class TerjeInjectorPropital: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_PROPITAL_DESC";
	};

	class TerjeInjectorReanimatal: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_REANIMATAL_DESC";
	};

	class TerjeInjectorAmoxiclav: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_AMOXICLAV_DESC";
	};

	class TerjeInjectorTopoizomeraza: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_TOPOIZOMERAZA_DESC";
	};

	class TerjeInjectorNeirox: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_NEIROX_DESC";
	};

	class TerjeInjectorErytromixelin: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_ERYTROMIXELIN_DESC";
	};

	class TerjeInjectorErythropoietin: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_ERYTHROPOIETIN_DESC";
	};

	class TerjeInjectorStomaproxidal: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_STOMAPROXIDAL_DESC";
	};

	class TerjeInjectorRabinucoline: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_RABINUCOLINE_DESC";
	};

	class TerjeInjectorAmfitalicyne: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_AMFITALICYNE_DESC";
	};

	class TerjeInjectorZivirol: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_ZIVIROL_DESC";
	};

	class TerjeInjectorNovichek: TerjeInjectorBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_NOVICHEK_DESC";
	};


	//--------------------------------------------------------------
	// VANILLA INJECTORS RE-LABELLED BY TERJE MEDICINE
	//--------------------------------------------------------------

	class Morphine: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_MORPHINE_DESC";
	};

	class Epinephrine: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_EPINEPHRINE_DESC";
	};

	class AntiChemInjector: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_ANTICHEMINJECTOR_DESC";
	};

	class TerjeAntiradInjector: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_INJ_ANTIRAD_DESC";
	};


	//--------------------------------------------------------------
	// TOPICAL OINTMENTS
	//--------------------------------------------------------------

	class TerjeSalveViprosal: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_SALVE_VIPROSAL_DESC";
	};

	class TerjeSalveCapsicum: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_SALVE_CAPSICUM_DESC";
	};

	class TerjeSalveFinalgon: TerjeSalveBase
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_SALVE_FINALGON_DESC";
	};


	//--------------------------------------------------------------
	// ENERGY DRINKS
	//--------------------------------------------------------------

	class TerjeDrinkYaguar: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_DRINK_YAGUAR_DESC";
	};

	class TerjeDrinkMadBull: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_DRINK_MADBULL_DESC";
	};

	class TerjeDrink6Energy: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_DRINK_6ENERGY_DESC";
	};

	class TerjeDrinkGang: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_DRINK_GANG_DESC";
	};

	class TerjeDrinkPrayboy: TerjeEnergyDrink
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_DRINK_PRAYBOY_DESC";
	};


	//--------------------------------------------------------------
	// MEDICAL SUPPLIES (BASE CLASSES - ALL COLOUR VARIANTS INHERIT)
	//--------------------------------------------------------------

	class TerjeSurgicalTool_ColorBase: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_KIT_SURGTOOL_DESC";
	};

	class TerjeSurgicalKit: Inventory_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_KIT_SURGICAL_DESC";
	};

	class TerjeFirstAidKitIndividualBase: Container_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_KIT_IFAK_DESC";
	};

	class TerjeFirstAidKitAdvancedBase: Container_Base
	{
		llgPharmacyLabel=1;
		descriptionShort="#STR_LLGMED_KIT_AFAK_DESC";
	};
};