# MedicineLabels

Client-side DayZ mod that replaces the generic TerjeMedicine item descriptions
("Sealed pack of old tablets with just the name and expiration date showing...")
with a pill-bottle style label for every drug.

Each label reads like this in the inventory tooltip:

```
ANALGIN
10 tablets. Swallow one at a time.
What: Painkiller, strength 1 of 3.
Use: mild pain from bruises and small wounds.
Lasts: ~8 min per tablet, stacks up to 30 min max
Warning: Low toxicity (0.15 per dose). Safe if spaced out.
EXP 11/2021
```

Covered items (81 total):

- all `TerjePills*` tablets plus the vanilla tablets TerjeMedicine repurposes
  (Codeine, Tetracycline, Charcoal, Chelating, Vitamins)
- all `TerjeAmpoule*` ampoules, including vaccines and the poison ampoules
- all `TerjeInjector*` injectors plus vanilla Epinephrine, Morphine and AntiChem
- the three `TerjeSalve*` ointments

## Where the numbers come from

Strength, duration and toxicity are read straight from TerjeMedicine's own
`config.cpp` files (`Pills`, `Ampouls`, `Injectors`, `Salves`, `FixVanilla`):

| Label line | Config source |
|---|---|
| strength N of 3 | `med*Level` (antibiotic, painkiller, antipoison, antirad, antidepressant, rabies, chemical) |
| Lasts | `med*TimeSec` / `med*Timer` per tablet or dose, capped by `med*MaxTimeSec` (1800 s = 30 min) |
| toxicity | `overdosedIncrement` |
| side effects | `terjeAddHealth`, `terjeAddBlood`, `terjeAddShock`, `terjeAddWater`, `terjeAddEnergy`, `medContussion*`, `medSleepDamage*` |

One tablet, one syringe draw or one injector = one dose = one multiple of the timer
(the syringe and injector scripts apply the effect with amount 1).

The expiration date is flavour text only. TerjeMedicine has no expiry mechanic, so
every item works regardless of the printed date. Poisons print `EXP NONE`.

## How it works

1. `config.cpp` overrides `descriptionShort` on each item class and sets `medicineLabel=1`.
2. `stringtable.csv` holds the label text under `STR_MEDLBL_<CLASSNAME>` keys.
   Only English text is provided; it is copied into every language column so no
   client sees a blank tooltip.
3. `Scripts/4_World/MedicineLabels.c` handles one TerjeMedicine quirk: once a player
   unlocks the Pill / Ampoule / Injector Recognition perk, TerjeMedicine replaces the
   description with an auto-generated effect list and drops `descriptionShort`
   entirely. The script upgrades that mode to "description + effect list" for any
   item flagged `medicineLabel=1`, so the label stays visible and the effect list is
   appended below it.

## Building the PBO

Standard DayZ mod layout (see the Bohemia wiki page DayZ:Modding Structure):

```
P:\MedicineLabels\            <- this folder, on the P drive
    $PBOPREFIX$               <- contains "MedicineLabels"
    config.cpp
    stringtable.csv
    Scripts\4_World\MedicineLabels.c

@MedicineLabels\              <- what you ship
    mod.cpp
    addons\MedicineLabels.pbo <- packed from P:\MedicineLabels with Addon Builder or Mikero's pboProject
    keys\                     <- your public .bikey if you sign it
```

1. Copy this folder to `P:\MedicineLabels`.
2. Pack it with DayZ Tools Addon Builder (or pboProject) into
   `@MedicineLabels\addons\MedicineLabels.pbo`. Keep the `$PBOPREFIX$` file so the
   script path `MedicineLabels/Scripts/4_World` resolves.
3. Copy `mod.cpp` next to the `addons` folder.
4. Load it after TerjeCore and TerjeMedicine on the client
   (`-mod=@CF;@TerjeCore;@TerjeMedicine;@MedicineLabels`). Server side it is
   optional: descriptions and the tooltip script are client only, but loading it on
   the server too is harmless and lets you sign it.

Requires: TerjeCore, TerjeMedicine. TerjeSkills is optional (the script only matters
when the recognition perks exist). TerjeRadiation's `TerjeAntiradInjector` is not
covered because that would add a hard dependency on TerjeRadiation.

## Regenerating

`tools/generate_labels.py` holds the label table and writes both `config.cpp` and
`stringtable.csv`, so the two cannot drift apart. Edit the text or numbers there and run:

```
python3 tools/generate_labels.py
```

If TerjeMedicine changes a drug's timer or overdose value, update the matching
entry in the script and regenerate.
