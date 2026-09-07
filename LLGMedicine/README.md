# LLG Medicine

A text-only override for [TerjeMedicine](https://github.com/TerjeBruoygard/TerjeMods/blob/master/WIKI/en/Medicine/README.md).
Every medical item in the mod gets a description that reads like the label on a
pharmacy bottle: what the drug is, how to take it, and what it will do to you if
you get it wrong.

```
IBUPROFEN 400 MG · ORAL CAPSULE
TAKE 1 CAPSULE BY MOUTH FOR PAIN AND COLD/PNEUMONIA.
PAIN L1 for 10 min · COLD/PNEUMONIA L2 for 5 min
OVERDOSE 0.35 (Moderate Risk). Take with food. May irritate the stomach.
LOT 3699P · EXP 2030-04-06
```

```
REANIMATAL 200 MG · SINGLE-USE AUTO-INJECTOR · RX ONLY
PRESS FIRMLY AGAINST THE OUTER THIGH TO REVIVE A COLLAPSING CASUALTY.
PAIN L3 for 4 min · HEALTH REGEN for 3 min · SHOCK -75
OVERDOSE 1.5 (Severe Risk). Buys minutes only, and takes a heavy toll to do it.
LOT 8365K · EXP 2029-05-12
```

92 items are labelled: every pill, ampoule, auto-injector, ointment and energy
drink TerjeMedicine ships, plus the vanilla medical items it takes over, plus
the first aid kit and surgical tool base classes.

## What it does not do

It changes **no gameplay values**. It sets `descriptionShort` and one marker
flag, and nothing else. Painkiller levels, timers, overdose increments, models,
textures and inventory sizes all stay where TerjeMedicine puts them, so an
upstream balance patch takes effect without this mod fighting it.

## Label format

Five lines, always in the same order:

| Line | Content | Colour |
|------|---------|--------|
| 1 | Drug name, strength, dose form, and `RX ONLY` or `CONTROLLED POISON` where it applies | light grey |
| 2 | Directions: `TAKE 1 TABLET BY MOUTH FOR …`, `DRAW WITH A STERILE SYRINGE AND INJECT …` | default |
| 3 | Strength and duration per effect: `PAIN L1 for 10 min · COLD/PNEUMONIA L2 for 5 min` | grey |
| 4 | Overdose value, risk word, and one short warning | grey, amber or red by severity |
| 5 | Lot code and expiry: `LOT 3699P · EXP 2030-04-06` | grey |

Line 3 lists each effect separately rather than collapsing them into one
`Strength:` / `Duration:` pair, because plenty of items do two things at once
and a single pair cannot say which number belongs to which effect.

Effects are named after the conditions the
[Medicine wiki](https://github.com/TerjeBruoygard/TerjeMods/tree/master/WIKI/en/Medicine#-medicines)
uses — `COLD/PNEUMONIA`, `FOOD POISONING`, `CHEMICAL POISONING`, `SEPSIS`,
`RABIES`, `ZOMBIE VIRUS`, `MENTAL HEALTH`, `BLEEDING RATE`, `BLOOD REGEN`,
`CONCUSSION`, `HEMATOMA`, `RADIATION`, `PAIN` — so a label maps straight onto
the illness the mod models rather than onto a drug class. The drug name on
line 1 is the item's own in-game name, so the bottle matches the item.

Six items carry no `med*` values in `CfgVehicles` (the first aid kits, surgical
tools, the alcohol ampoule, purification tablets and the antirad injector).
Their line 3 says where the numbers actually live instead of inventing any.

Warning severity tracks the printed `overdosedIncrement`: grey below 0.2,
amber to 1.0, red above it. Poisons and the things that only
look like medicine (Iversan, Novichek, arsenic, cyanide, belladonna,
strychnine, coniine, injectable alcohol) are red and say plainly that they are
not medicine.

## Expiry dates

Every item carries a lot code and an expiry, printed as plain text in the
description like the rest of the label. Dates run **2026 to 2031**. Nothing is pinned to a theme year.

The verb follows the dose form the way a real shelf does: `EXP` on medication,
`BEST BY` on the energy drinks, `STERILE UNTIL` on sealed kits and instruments.
Shelf life is ordered realistically too — biologics in glass ampoules go off
first, sealed tablets last longest. Lot codes are unique per item and stable.

If your server's year sits elsewhere, move the whole window in one command:

```
python3 LLGMedicine/Tools/restamp_dates.py --shift -38    # 1988-1993
python3 LLGMedicine/Tools/restamp_dates.py --base 2040    # 2040-2045
python3 LLGMedicine/Tools/restamp_dates.py --show         # list, change nothing
```

It rewrites only the four-digit years. Months, lot codes, wording and the
spread between items all survive, so hand edits to label text are safe. Re-pack
afterwards.

## Where the numbers come from

Strength, duration and overdose are read out of TerjeMedicine's own configs
and written into the labels, rather than typed by hand. That matters: the
override this replaces had seven items whose printed numbers disagreed with
the config it was overriding — Reanimatal claimed painkiller L1 / overdose
1.85 against a real L3 / 1.5, and Amitriptyline, Ketamin, Strychnine, Konyin
and the cyanide and arsenic pills were all wrong too. Chelating Tablets were
described as treating chemical poisoning when their `medAntipoisonLevel` makes
them a food-poisoning treatment, which is where the wiki lists them too.

Because the numbers are generated, they are correct as of the TerjeMedicine
version in this repo. After an upstream rebalance they are stale in exactly
the way hand-typed ones would be — the difference is that regenerating is
mechanical rather than 92 manual edits.

## Interaction with the medicine recognition perks

TerjeCore builds a dynamic effects panel for medical items and, when a player
can read it, substitutes that panel **for** `descriptionShort` rather than
adding to it — see `TerjeCore/Scripts/4_World/Entities/ItemBase.c` and
`TerjeMedicine/Scripts/4_World/Entities/ItemBase.c`. A plain
`descriptionShort` override therefore disappears as soon as a player trains
Pill / Ampoule / Injector Recognition, and never appears at all on a server
that leaves those perks unregistered.

`Scripts/4_World/LLGMedicineLabels.c` puts the label back in front of that
panel without touching the perk gate:

| Player | Sees |
|--------|------|
| No recognition perk (perk registered) | label only |
| Recognition perk trained | label, then the effects panel |
| Perks not registered on the server | label, then the effects panel |

## Editing labels

Every label is written out in full on the class it belongs to, in `config.cpp`.
The text you read there is the text the game shows, so rewording one is a
straight edit of that string:

```cpp
class TerjePillsNoopept: TerjePillsBase
{
    llgPharmacyLabel=1;
    descriptionShort="<color rgba='222,226,230,255'>NOOPEPT 10 MG · ORAL TABLET · RX ONLY</color><br/>TAKE 1 TABLET BY MOUTH FOR HEADACHE AND CONCUSSION.<br/><color rgba='150,155,160,255'>PAINKILLER L1 for 6 min 20 sec · CONCUSSION RELIEF for 6 min 20 sec</color><br/><color rgba='240,173,78,255'>OVERDOSE 0.35 (Moderate Risk). May cause irritability and disturbed sleep.</color><br/><color rgba='150,155,160,255'>LOT 4463B · EXP 2028-07-06</color>";
};
```

Markup allowed in a label: `<br/>` for a line break and
`<color rgba='r,g,b,a'>…</color>` for colour. The palette in use is
`222,226,230` header, `150,155,160` note, `240,173,78` caution, `217,83,79`
danger. Config strings cannot span lines or contain a double quote, so each
label is one long line and colour attributes use single quotes.

To label an item that is not covered yet, copy a block and change the class
name. Two rules:

- The parent in a **definition** must be the same parent the class has in
  TerjeMedicine. Declaring a different one re-parents the class and silently
  drops everything TerjeMedicine set on it.
- A **forward declaration** at the top of `CfgVehicles` must be bare —
  `class TerjePillsBase;`, never `class TerjePillsBase: Edible_Base;`. The
  second form is a syntax error and stops the game from loading.

`Tools/check_config.py` enforces both.

## Building

```
python3 LLGMedicine/Tools/check_config.py    # parse config.cpp, report line numbers
python3 LLGMedicine/Tools/pack_pbo.py        # runs the check, then packs
```

`pack_pbo.py` refuses to pack a config that fails the check. A config syntax
error is otherwise invisible until the game shows a popup on start, which is
how `class TerjePillsBase: Edible_Base;` shipped once — a forward declaration
cannot carry a base class, and the parser reports it as
`';' encountered instead of '{'`.

Writes `build/@LLGMedicine/addons/LLGMedicine.pbo`. Copy that `@LLGMedicine`
folder next to your other mods and add it to the launch parameters.

`config.cpp` ships as plain text rather than binarised `config.bin`. DayZ parses
a raw config out of a PBO without complaint — the mod this one replaces shipped
exactly that way — so no Windows-only Addon Builder is in the loop.

The PBO is **not signed**. That is fine for a local client test and for a server
running `verifySignatures = 0`, but a server with signature checking on will
reject it. To sign, run `DSSignFile.exe` from the BI Tools against the PBO with
your `.biprivatekey`, and put the matching `.bikey` in `@LLGMedicine/keys/`.

## Dependencies

`config.cpp` declares the whole TerjeMedicine chain in `requiredAddons`, so the
engine merges this addon after them wherever it sits in the `-mod=` list.
Position in that list is not something you need to manage.

The addons folder must contain only this mod's PBO. If an older medicine
override is still sitting in the same `addons/` folder, both will define the
same classes and fight each other.
