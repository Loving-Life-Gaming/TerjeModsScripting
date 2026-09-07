# Generates MedicineLabels/config.cpp and MedicineLabels/stringtable.csv
# from one data table so the two never drift apart.
import csv, io, os

OUT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")

def dur(sec):
    if sec < 60: return f"{sec} sec"
    if sec < 3600:
        m = sec / 60
        return f"{int(m)} min" if m == int(m) else f"~{round(m)} min"
    h = sec / 3600
    return f"{int(h)} h" if h == int(h) else f"~{h:.1f} h"

def tox(v, extra=""):
    if v <= 0.1: t = f"Low toxicity ({v} per dose)."
    elif v <= 0.3: t = f"Low toxicity ({v} per dose). Safe if spaced out."
    elif v <= 0.6: t = f"Moderate toxicity ({v} per dose). Do not stack doses."
    elif v <= 1.0: t = f"High toxicity ({v} per dose). Repeat doses risk overdose."
    elif v <= 2.0: t = f"Very high toxicity ({v} per dose). One dose can trigger overdose symptoms."
    else: t = f"DANGER: toxicity {v} per dose. Overdose is near certain."
    return (t + " " + extra).strip()

# Packaging blurbs
PILL = "10 tablets. Swallow one at a time."
AMP  = "Glass ampoule, 5 doses. Draw with a sterile syringe and inject."
INJ  = "Auto-injector, single dose. Press against skin. No syringe needed."
SALV = "Tube of ointment, 5 applications. Rub on bruised skin."

def label(title, pack, kind, use, lasts, warn, exp):
    return "<br/>".join([
        f"{title}",
        f"{pack}",
        f"What: {kind}",
        f"Use: {use}",
        f"Lasts: {lasts}",
        f"Warning: {warn}",
        f"EXP {exp}",
    ])

PILLCAP = " per tablet, stacks up to 30 min max"
DOSECAP = " per dose, stacks up to 30 min max"

# (class, parent, key, title, pack, kind, use, lasts, warn, exp)
ITEMS = []
def add(cls, parent, title, pack, kind, use, lasts, warn, exp):
    key = "STR_MEDLBL_" + cls.upper()
    ITEMS.append((cls, parent, key, label(title, pack, kind, use, lasts, warn, exp)))

# ---------------- TABLETS ----------------
add("CharcoalTablets","Edible_Base","ACTIVATED CHARCOAL",PILL,"Absorbent antipoison, strength 1 of 3.",
    "early food poisoning from bad food or dirty water.",dur(300)+PILLCAP,tox(0.01),"06/2020")
add("ChelatingTablets","Edible_Base","CHELATING TABLETS",PILL,"Chelating antipoison, strength 2 of 3.",
    "moderate food poisoning, heavy metal poisoning.",dur(600)+PILLCAP,tox(0.6),"02/2019")
add("PainkillerTablets","Edible_Base","CODEINE",PILL,"Painkiller, strength 1 of 3.",
    "mild pain from bruises and small wounds.",dur(300)+PILLCAP,tox(0.2),"09/2021")
add("TetracyclineAntibiotics","Edible_Base","TETRACYCLINE",PILL,"Antibiotic, strength 1 of 3.",
    "early cold. Will not stop pneumonia.",dur(300)+PILLCAP,tox(0.45),"12/2018")
add("VitaminBottle","Edible_Base","MULTIVITAMIN",PILL,"Immune booster.",
    "raising immunity so you catch fewer infections.",dur(120)+PILLCAP,tox(0.01),"08/2022")

add("TerjePillsAnalgin","TerjePillsBase","ANALGIN",PILL,"Painkiller, strength 1 of 3.",
    "mild pain from bruises and small wounds.",dur(500)+PILLCAP,tox(0.15),"11/2021")
add("TerjePillsNimesulid","TerjePillsBase","NIMESULIDE",PILL,"Painkiller, strength 1 of 3.",
    "mild pain. Longest lasting of the weak painkillers.",dur(600)+PILLCAP,tox(0.25),"04/2020")
add("TerjePillsParacetamol","TerjePillsBase","PARACETAMOL",PILL,"Painkiller strength 1 of 3 plus antibiotic strength 1 of 3.",
    "mild pain and early cold at the same time.",dur(200)+" pain, "+dur(120)+" antibiotic, per tablet",tox(0.45),"07/2019")
add("TerjePillsIbuprofen","TerjePillsBase","IBUPROFEN",PILL,"Painkiller strength 1 of 3 plus antibiotic strength 2 of 3.",
    "mild pain and cold up to pneumonia.",dur(600)+" pain, "+dur(300)+" antibiotic, per tablet",tox(0.35),"03/2021")
add("TerjePillsNurofen","TerjePillsBase","NUROFEN",PILL,"Painkiller strength 1 of 3 plus antibiotic strength 2 of 3.",
    "mild pain and cold up to pneumonia.",dur(350)+" pain, "+dur(300)+" antibiotic, per tablet",tox(0.52),"10/2020")
add("TerjePillsNoopept","TerjePillsBase","NOOPEPT",PILL,"Nootropic. Painkiller strength 1 of 3 plus concussion treatment.",
    "headache, dizziness and blurred vision after a blow to the head.",dur(380)+PILLCAP,tox(0.35),"01/2022")

add("TerjePillsAmibaktam","TerjePillsBase","AMIBACTAM",PILL,"Antibiotic, strength 1 of 3.",
    "early cold. Very short acting, take often.",dur(60)+PILLCAP,tox(0.05),"05/2021")
add("TerjePillsAmoxiclav","TerjePillsBase","AMOXICLAV",PILL,"Antibiotic, strength 2 of 3.",
    "cold and pneumonia. Strongest oral antibiotic.",dur(1200)+PILLCAP,tox(0.75),"02/2020")
add("TerjePillsPiperacylin","TerjePillsBase","PIPERACILLIN",PILL,"Antibiotic, strength 2 of 3.",
    "cold and pneumonia.",dur(1100)+PILLCAP,tox(0.45),"08/2019")

add("TerjePillsPolisorb","TerjePillsBase","POLYSORB",PILL,"Absorbent antipoison, strength 1 of 3.",
    "early food poisoning.",dur(300)+PILLCAP,tox(0.05),"06/2022")
add("TerjePillsFtalazol","TerjePillsBase","PHTHALAZOLE",PILL,"Antipoison, strength 1 of 3.",
    "early food poisoning. Long acting.",dur(1200)+PILLCAP,tox(0.25),"11/2019")
add("TerjePillsMesalazin","TerjePillsBase","MESALAZINE",PILL,"Antipoison, strength 2 of 3.",
    "moderate food poisoning with vomiting.",dur(600)+PILLCAP,tox(0.35),"04/2021")

add("TerjePillsVikasol","TerjePillsBase","VIKASOL",PILL,"Hemostatic (clotting agent), strength 1 of 3.",
    "slowing blood loss from cuts and wounds until you can bandage.",dur(300)+PILLCAP,tox(0.15),"09/2020")
add("TerjePillsIrovit","TerjePillsBase","IROVIT",PILL,"Iron supplement. Blood regeneration, strength 1.",
    "faster blood recovery after bleeding.",dur(120)+PILLCAP,tox(0.3),"12/2021")
add("TerjePillsMagnesiumSulfate","TerjePillsBase","MAGNESIUM SULFATE",PILL,"Blood regeneration, strength 2.5.",
    "faster blood recovery after heavy bleeding.",dur(120)+PILLCAP,tox(0.3),"03/2020")

add("TerjePillsAdepress","TerjePillsBase","ADEPRESS",PILL,"Antidepressant, strength 1 of 3.",
    "mild stress, panic and shaking hands.",dur(150)+PILLCAP,tox(0.2),"07/2021")
add("TerjePillsAgteminol","TerjePillsBase","AGTEMINOL",PILL,"Antidepressant, strength 1 of 3.",
    "mild stress, panic and shaking hands.",dur(120)+PILLCAP,tox(0.2),"10/2019")
add("TerjePillsVenlafaxine","TerjePillsBase","VENLAFAXINE",PILL,"Antidepressant, strength 1 of 3.",
    "mild stress. Longest lasting of the tablets.",dur(250)+PILLCAP,tox(0.3),"01/2021")

add("TerjePillsB190","TerjePillsBase","B-190",PILL,"Radioprotector, strength 1 of 3.",
    "low radiation dose. Take before or right after exposure.",dur(140)+PILLCAP,tox(0.3),"05/2019")
add("TerjePillsPotassiumIodide","TerjePillsBase","POTASSIUM IODIDE",PILL,"Radioprotector, strength 1 of 3.",
    "low radiation dose. Very short acting.",dur(60)+PILLCAP,tox(0.2),"08/2020")
add("TerjePillsHexacyanoferrate","TerjePillsBase","HEXACYANOFERRATE",PILL,"Radioprotector (Prussian blue), strength 1 of 3.",
    "low radiation dose.",dur(120)+PILLCAP,tox(0.3),"02/2021")
add("TerjePillsMexamine","TerjePillsBase","MEXAMINE",PILL,"Radioprotector, strength 2 of 3.",
    "moderate radiation dose. Strong but very short.",dur(25)+PILLCAP,tox(0.75),"06/2019")

add("TerjePillsRombiopental","TerjePillsBase","ROMBIOPENTAL",PILL,"Chemical antidote, strength 1 of 3.",
    "early chemical poisoning (coughing after toxic gas).",dur(30)+PILLCAP,tox(0.15),"04/2022")

add("TerjePillsPotassiumCyanide","TerjePillsBase","POTASSIUM CYANIDE",PILL,"POISON. Not a medicine.",
    "nothing. Causes severe poisoning when swallowed.","poisoning builds with every tablet (+5 per tablet)",
    tox(1.5,"Keep away from food and water."),"NONE")
add("TerjePillsArsenic","TerjePillsBase","ARSENIC",PILL,"POISON. Not a medicine.",
    "nothing. Causes severe poisoning when swallowed.","poisoning builds with every tablet (+3.5 per tablet)",
    tox(2.5,"Two tablets can kill."),"NONE")
add("TerjePillsIversan","TerjePillsBase","IVERSAN",PILL,"Veterinary antiparasitic. Toxic to humans.",
    "nothing useful. Causes food poisoning when swallowed.","poisoning builds with every tablet (+2.2 per tablet)",
    tox(0.5),"03/2018")

# ---------------- AMPOULES ----------------
add("TerjeAmpouleAlcohol","TerjeAmpouleBase","MEDICAL ALCOHOL","Glass ampoule, 10 units. For disinfecting syringes and tools only.",
    "Disinfectant. Not a medicine.","cleaning used syringes and surgical tools before reuse.","instant",
    tox(4.0,"Never inject."),"n/a")
add("TerjeAmpouleAmoxivan","TerjeAmpouleBase","AMOXIVAN",AMP,"Antibiotic, strength 2 of 3.",
    "cold and pneumonia.",dur(900)+DOSECAP,tox(0.3),"07/2020")
add("TerjeAmpouleKetarol","TerjeAmpouleBase","KETAROL",AMP,"Antibiotic strength 2 of 3 plus painkiller strength 1 of 3.",
    "pneumonia with mild pain.",dur(1200)+DOSECAP,tox(0.5),"11/2020")
add("TerjeAmpouleFlemoclav","TerjeAmpouleBase","FLEMOCLAVE",AMP,"Antibiotic, strength 3 of 3. Also treats sepsis.",
    "severe pneumonia and infected wounds (sepsis).",dur(1200)+DOSECAP,tox(0.8),"01/2020")
add("TerjeAmpouleImipenem","TerjeAmpouleBase","IMIPENEM",AMP,"Antibiotic, strength 3 of 3. Also treats sepsis.",
    "severe pneumonia and infected wounds (sepsis).",dur(900)+DOSECAP,tox(0.7),"09/2019")

add("TerjeAmpouleNovacaine","TerjeAmpouleBase","NOVOCAINE",AMP,"Painkiller, strength 2 of 3.",
    "moderate pain from deep cuts and fractures.",dur(1200)+DOSECAP,tox(0.4),"05/2021")
add("TerjeAmpouleMorphine","TerjeAmpouleBase","MORPHINOCIN",AMP,"Opioid painkiller, strength 3 of 3.",
    "severe pain from gunshot wounds and surgery.",dur(850)+DOSECAP,tox(0.52),"12/2019")
add("TerjeAmpouleGexobarbital","TerjeAmpouleBase","HEXOBARBITAL",AMP,"Barbiturate painkiller, strength 3 of 3.",
    "severe pain from gunshot wounds and surgery.",dur(900)+DOSECAP,tox(0.65),"06/2020")
add("TerjeAmpouleKetamin","TerjeAmpouleBase","KETAMINE",AMP,"Anesthetic painkiller, strength 3 of 3.",
    "severe pain from gunshot wounds and surgery.",dur(600)+DOSECAP,tox(0.45),"10/2021")

add("TerjeAmpouleMetoclopramid","TerjeAmpouleBase","METOCLOPRAMID",AMP,"Antiemetic antipoison, strength 2 of 3.",
    "moderate food poisoning with vomiting.",dur(1200)+DOSECAP,tox(0.4),"08/2021")
add("TerjeAmpouleHeptral","TerjeAmpouleBase","HEPTRAL",AMP,"Liver protector antipoison, strength 3 of 3.",
    "severe food poisoning with dehydration.",dur(600)+DOSECAP,tox(0.6),"02/2020")

add("TerjeAmpouleNeirox","TerjeAmpouleBase","NEIROX",AMP,"Concussion treatment.",
    "headache, dizziness and blurred vision after head trauma.",dur(600)+DOSECAP,tox(0.6),"04/2019")
add("TerjeAmpouleErythropoetin","TerjeAmpouleBase","ERYTHROPOIETIN",AMP,"Blood regeneration, strength 1.",
    "faster blood recovery after bleeding.",dur(600)+DOSECAP,tox(0.4),"03/2022")
add("TerjeAmpouleAdrenalin","TerjeAmpouleBase","ADRENALINE",AMP,"Stimulant.",
    "waking an unconscious patient and restoring stamina.",dur(220)+DOSECAP,tox(0.3),"07/2019")

add("TerjeAmpoulePentacin","TerjeAmpouleBase","PENTACIN",AMP,"Radioprotector, strength 2 of 3.",
    "moderate radiation dose.",dur(400)+DOSECAP,tox(0.5),"11/2018")
add("TerjeAmpouleCarboxyme","TerjeAmpouleBase","CARBOXYME",AMP,"Radioprotector, strength 2 of 3.",
    "moderate radiation dose. Longer acting than Pentacin.",dur(600)+DOSECAP,tox(0.6),"09/2020")

add("TerjeAmpouleMetralindole","TerjeAmpouleBase","METRALINDOLE",AMP,"Antidepressant, strength 2 of 3.",
    "moderate stress, panic and hallucinations.",dur(300)+DOSECAP,tox(0.1),"01/2021")
add("TerjeAmpouleActaparoxetine","TerjeAmpouleBase","ACTAPAROXETINE",AMP,"Antidepressant, strength 2 of 3.",
    "moderate stress, panic and hallucinations.",dur(400)+DOSECAP,tox(0.4),"05/2020")
add("TerjeAmpouleAmitriptyline","TerjeAmpouleBase","AMITRIPTYLINE",AMP,"Antidepressant, strength 3 of 3.",
    "severe mental breakdown.",dur(600)+DOSECAP,tox(0.5),"08/2019")

add("TerjeAmpouleVaxicam","TerjeAmpouleBase","VAXICAM",AMP,"Influenza vaccine.",
    "preventing cold and pneumonia. Inject before exposure.",dur(14400)+" per dose",tox(0.8,"Does not cure an existing cold."),"02/2022")
add("TerjeAmpouleZerivax","TerjeAmpouleBase","ZERIVAX",AMP,"Zombie virus vaccine.",
    "preventing infection from zombie hits and bites. Inject before exposure.",dur(7200)+" per dose",tox(1.5,"Does not cure an existing infection."),"06/2021")
add("TerjeAmpouleRabivax","TerjeAmpouleBase","RABIVAX",AMP,"Rabies vaccine.",
    "preventing rabies from wolf bites. Inject before exposure.",dur(14400)+" per dose",tox(1.3,"Does not cure existing rabies."),"10/2020")
add("TerjeAmpouleRabinoline","TerjeAmpouleBase","RABINOLINE",AMP,"Rabies antibiotic, strength 2 of 3.",
    "early and mid stage rabies after a bite.",dur(600)+DOSECAP,tox(0.8),"03/2021")
add("TerjeAmpouleRifampicyne","TerjeAmpouleBase","RIFAMPICIN",AMP,"Rabies antibiotic, strength 3 of 3.",
    "advanced rabies.",dur(300)+DOSECAP,tox(1.35),"12/2020")
add("TerjeAmpouleNeirocetal","TerjeAmpouleBase","NEUROCETAL",AMP,"Chemical antidote, strength 2 of 3.",
    "moderate chemical poisoning from toxic gas.",dur(500)+DOSECAP,tox(1.25),"04/2020")
add("TerjeAmpouleZivirol","TerjeAmpouleBase","ZIVIROL (EXPERIMENTAL)",AMP,"Zombie virus antidote.",
    "an active zombie virus infection at any stage.",dur(1000)+DOSECAP,
    tox(2.35,"Side effects on injection: -25 health, -15 blood, knocks you unconscious. Have a friend nearby."),"UNKNOWN")

add("TerjeAmpoulePotassiumCyanide","TerjeAmpouleBase","POTASSIUM CYANIDE","Glass ampoule. POISON.",
    "POISON. Not a medicine.","nothing. Injection is fatal.","instant",
    tox(5.0,"Drains all food and water on injection."),"NONE")
add("TerjeAmpouleArsenic","TerjeAmpouleBase","ARSENIC","Glass ampoule. POISON.",
    "POISON. Not a medicine.","nothing. Injection is fatal.","instant",
    tox(5.0,"-50 health on injection."),"NONE")
add("TerjeAmpouleBeladonna","TerjeAmpouleBase","BELLADONNA EXTRACT","Glass ampoule. POISON.",
    "Plant toxin. Not a medicine.","nothing useful. Causes severe pain and concussion.","instant",
    tox(3.8,"Causes strong pain and a light concussion."),"NONE")
add("TerjeAmpouleStrychnine","TerjeAmpouleBase","STRYCHNINE","Glass ampoule. POISON.",
    "Convulsant poison. Not a medicine.","nothing. Injection is fatal.","instant",
    tox(3.2,"Massive blood loss, dehydration and heavy concussion."),"NONE")
add("TerjeAmpouleKonyin","TerjeAmpouleBase","KONYIN","Glass ampoule. Sedative poison.",
    "Sedative toxin. Not a medicine.","nothing useful. Puts the target to sleep.",
    "knocks the target out over "+dur(300),tox(3.0),"NONE")

# ---------------- INJECTORS ----------------
add("Epinephrine","Inventory_Base","EPINEPHRINE",INJ,"Stimulant (adrenaline).",
    "waking an unconscious patient and restoring stamina.",dur(720),tox(0.55),"09/2021")
add("Morphine","Inventory_Base","MORPHINE",INJ,"Opioid painkiller, strength 3 of 3.",
    "severe pain from gunshot wounds and surgery.",dur(300),tox(0.75),"05/2020")
add("AntiChemInjector","Inventory_Base","ANTICHEM",INJ,"Chemical antidote, strength 3 of 3.",
    "severe chemical poisoning from toxic gas.",dur(180),tox(1.1),"08/2018")

add("TerjeInjectorZivirol","TerjeInjectorBase","ZIVIROL (EXPERIMENTAL)",INJ,"Zombie virus antidote.",
    "an active zombie virus infection at any stage.",dur(1200),
    tox(2.5,"Side effects on injection: -20 health, -10 blood, knocks you unconscious. Have a friend nearby."),"UNKNOWN")
add("TerjeInjectorAmoxiclav","TerjeInjectorBase","AMOXICLAV",INJ,"Antibiotic, strength 3 of 3. Also treats sepsis.",
    "severe pneumonia and infected wounds (sepsis).",dur(1800)+" antibiotic, "+dur(300)+" sepsis",tox(0.6),"03/2021")
add("TerjeInjectorTopoizomeraza","TerjeInjectorBase","TOPOISOMERASE",INJ,"Antibiotic, strength 3 of 3. Also treats sepsis.",
    "severe pneumonia and infected wounds (sepsis).",dur(900)+" antibiotic, "+dur(600)+" sepsis",tox(0.65),"11/2020")
add("TerjeInjectorNeirox","TerjeInjectorBase","NEIROX",INJ,"Concussion treatment.",
    "headache, dizziness and blurred vision after head trauma.",dur(500),tox(0.3),"06/2021")
add("TerjeInjectorErythropoietin","TerjeInjectorBase","ERYTHROPOIETIN",INJ,"Blood regeneration, strength 1.",
    "faster blood recovery after bleeding.",dur(900),tox(0.4),"01/2022")
add("TerjeInjectorErytromixelin","TerjeInjectorBase","ERYTROMIXELIN",INJ,"Hemostatic strength 3 plus blood regeneration strength 2.",
    "heavy bleeding: slows blood loss and rebuilds blood.",dur(300)+" clotting, "+dur(150)+" regeneration",tox(0.32),"07/2021")
add("TerjeInjectorPromidol","TerjeInjectorBase","PROMIDOL",INJ,"Opioid painkiller, strength 3 of 3.",
    "severe pain from gunshot wounds and surgery.",dur(600),tox(0.45),"10/2020")
add("TerjeInjectorPropital","TerjeInjectorBase","PROPITAL",INJ,"Painkiller strength 2 of 3 plus rapid health regeneration.",
    "field stabilisation: moderate pain and a quick health boost.",dur(180)+" pain, "+dur(45)+" regeneration",tox(0.75),"04/2021")
add("TerjeInjectorReanimatal","TerjeInjectorBase","REANIMATAL",INJ,"Combat stimulant. Painkiller strength 3 of 3 plus health regeneration.",
    "critical patients: strong pain relief, health boost and clears shock.",dur(240)+" pain, "+dur(180)+" regeneration",
    tox(1.5,"Restores 75 shock."),"12/2021")
add("TerjeInjectorStomaproxidal","TerjeInjectorBase","STOMAPROXIDAL",INJ,"Antipoison, strength 3 of 3.",
    "severe food poisoning.",dur(900),tox(0.68),"02/2021")
add("TerjeInjectorRabinucoline","TerjeInjectorBase","RABINUCOLINE",INJ,"Rabies antibiotic, strength 3 of 3.",
    "advanced rabies.",dur(900),tox(1.46),"08/2020")
add("TerjeInjectorAmfitalicyne","TerjeInjectorBase","AMFITALICYNE",INJ,"Antidepressant, strength 3 of 3.",
    "severe mental breakdown.",dur(520),tox(0.6),"05/2021")
add("TerjeInjectorNovichek","TerjeInjectorBase","NOVICHEK","Auto-injector. NERVE AGENT.",
    "Nerve agent. Not a medicine.","nothing. Injection is fatal.","instant",
    tox(5.0,"Instant unconsciousness."),"NONE")

# ---------------- SALVES ----------------
add("TerjeSalveFinalgon","TerjeSalveBase","FINALGON",SALV,"Warming ointment for bruises.",
    "healing hematomas from zombie hits and blunt weapons.",dur(300)+" per application",tox(0.01),"09/2020")
add("TerjeSalveCapsicum","TerjeSalveBase","CAPSICUM",SALV,"Warming ointment for bruises.",
    "healing hematomas from zombie hits and blunt weapons.",dur(400)+" per application",tox(0.01),"04/2021")
add("TerjeSalveViprosal","TerjeSalveBase","VIPROSAL",SALV,"Snake venom ointment for bruises. Longest acting.",
    "healing hematomas from zombie hits and blunt weapons.",dur(600)+" per application",tox(0.01),"01/2020")

# ---------------- config.cpp ----------------
PARENTS = ["Edible_Base","Inventory_Base","TerjePillsBase","TerjeAmpouleBase","TerjeInjectorBase","TerjeSalveBase"]
BASES = ["TerjePillsBase","TerjeAmpouleBase","TerjeInjectorBase","TerjeSalveBase"]

cfg = io.StringIO()
cfg.write('''// MedicineLabels - pill-bottle style item descriptions for TerjeMedicine.
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
''')
for p in PARENTS:
    cfg.write(f"\tclass {p};\n")
cfg.write("\n\t// Base classes: flag every child so the script keeps the label visible\n\t// even when the player has the Pill/Ampoule/Injector Recognition perk.\n")
for b in BASES:
    cfg.write(f"\tclass {b}\n\t{{\n\t\tmedicineLabel=1;\n\t}};\n")

section = None
for cls, parent, key, text in ITEMS:
    sec = ("TABLETS" if parent in ("Edible_Base","TerjePillsBase") else
           "AMPOULES" if parent=="TerjeAmpouleBase" else
           "INJECTORS" if parent in ("Inventory_Base","TerjeInjectorBase") else "SALVES")
    if sec != section:
        cfg.write(f"\n\t// ---------------- {sec} ----------------\n")
        section = sec
    cfg.write(f"\tclass {cls}: {parent}\n\t{{\n\t\tdescriptionShort=\"#{key}\";\n\t\tmedicineLabel=1;\n\t}};\n")
cfg.write("};\n")

os.makedirs(OUT, exist_ok=True)
with open(os.path.join(OUT,"config.cpp"),"w",encoding="utf-8",newline="\n") as f:
    f.write(cfg.getvalue())

# ---------------- stringtable.csv ----------------
langs = ["original","english","czech","german","russian","polish","hungarian","italian","spanish","french","chinese","japanese","portuguese","chinesesimp"]
lines = ['"Language",' + ",".join(f'"{l}"' for l in langs) + ","]
for cls, parent, key, text in ITEMS:
    assert '"' not in text, cls
    lines.append(f'"{key}",' + ",".join(f'"{text}"' for _ in langs) + ",")
with open(os.path.join(OUT,"stringtable.csv"),"w",encoding="utf-8",newline="\n") as f:
    f.write("\n".join(lines) + "\n")

print(len(ITEMS), "items written")
