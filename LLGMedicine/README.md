# LLG Medicine

Pharmacy-style labels for every medical item in
[TerjeMedicine](https://github.com/TerjeBruoygard/TerjeMods/blob/master/WIKI/en/Medicine/README.md).
Hover an item and the tooltip reads like the label on the bottle:

```
IBUPROFEN 400 MG - ORAL CAPSULE
TAKE 1 CAPSULE BY MOUTH FOR PAIN AND COLD/PNEUMONIA.
PAIN L1 for 10 min - COLD/PNEUMONIA L2 for 5 min
OVERDOSE 0.35 (Moderate Risk). Take with food. May irritate the stomach.
LOT 3699P - EXP 2030-04-06
```

92 items: every pill, ampoule, auto-injector, ointment and energy drink
TerjeMedicine ships, the vanilla medical items it takes over, and the first
aid kits and surgical tools.

## How it works

The mod **re-opens no config classes**. `config.cpp` only registers the addon
and its script module — the shape of Bohemia's DayZ sample mod. The labels
live in `Scripts/4_World/LLGMedicineLabels.c` as a table keyed by item class
name, and are handed to the inventory tooltip through
`ItemBase.DescriptionOverride`, the same hook TerjeCore uses for its own
descriptions. Nothing about the items themselves changes: models, health,
quantities, medical values and inheritance all stay exactly as TerjeMedicine
ships them.

That is deliberate. Re-opening a TerjeMedicine class from an override config
only merges if the parent named in the override matches the one in the
shipped mod; if it does not, the engine replaces the class and the item loses
its model and health. The shipped class tree is not the one in this repo's
interface copy, so no override built from here can be trusted to merge. A
script table has no such dependency.

## Label format

Five lines, always in the same order, plain text with `<br/>` breaks:

| Line | Content |
|------|---------|
| 1 | Drug name, strength, dose form, and `RX ONLY` / `CONTROLLED POISON` where it applies |
| 2 | Directions: `TAKE 1 TABLET BY MOUTH FOR …`, `DRAW WITH A STERILE SYRINGE AND INJECT …` |
| 3 | Strength and duration per effect: `PAIN L1 for 10 min - COLD/PNEUMONIA L2 for 5 min` |
| 4 | Overdose value, risk word, and one short warning |
| 5 | Lot code and expiry |

Effects are named after the conditions the
[Medicine wiki](https://github.com/TerjeBruoygard/TerjeMods/tree/master/WIKI/en/Medicine#-medicines)
uses — `COLD/PNEUMONIA`, `FOOD POISONING`, `CHEMICAL POISONING`, `SEPSIS`,
`RABIES`, `ZOMBIE VIRUS`, `MENTAL HEALTH`, `BLEEDING RATE`, `BLOOD REGEN`,
`CONCUSSION`, `HEMATOMA`, `RADIATION`, `PAIN`. Drug names match each item's
in-game name. Strength, duration and overdose were generated from
TerjeMedicine's config values rather than typed, then checked against them.
Expiry dates run 2026–2031.

## Editing a label

Open `Scripts/4_World/LLGMedicineLabels.c`. Each item is one line:

```c
s_Labels.Insert("TerjePillsIbuprofen", "IBUPROFEN 400 MG - ORAL CAPSULE<br/>TAKE 1 CAPSULE ...");
```

Edit the text, keep `<br/>` between lines, keep the file ASCII, do not put a
double quote inside the text. To add an item, copy a line and change the
class name to the item's config class (`GetType()` — the concrete class, so a
coloured variant like `TerjeFirstAidKitIndividual_Black`, not its base). An
entry for a class that does not exist is harmless.

To shift every expiry year at once:

```
python3 LLGMedicine/Tools/restamp_dates.py --shift -38    # 1988-1993
python3 LLGMedicine/Tools/restamp_dates.py --base 2040    # 2040-2045
```

## Building

```
python3 LLGMedicine/Tools/pack_pbo.py
```

Writes `build/@LLGMedicine/addons/LLGMedicine.pbo`. `config.cpp` is
binarised to `config.bin` on the way in by `Tools/rap.py`, whose output was
verified byte-identical to Bohemia's own tool on the same file. The PBO is
not signed; sign it with your `.biprivatekey` and put the `.bikey` in
`@LLGMedicine/keys/`.

Install as a `-mod=` mod on the **server and every client** — it carries a
script, so both sides must run the identical PBO.

## Interaction with the medicine recognition perks

TerjeCore normally swaps its own "consumable effects" text in for an item's
description once the player has the matching recognition perk (Pill
Recognition at skill level 1, Ampoule at 10, Injector at 20). This mod's
`DescriptionOverride` returns the label before that happens, so labelled
items show the label regardless of perks. The numbers TerjeCore would have
shown are already on the label.
