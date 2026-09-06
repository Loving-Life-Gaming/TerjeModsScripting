# LLG Medicine

A text-only override for [TerjeMedicine](https://github.com/TerjeBruoygard/TerjeMods/blob/master/WIKI/en/Medicine/README.md).
Every medical item in the mod gets a description that reads like the label on a
pharmacy bottle: what the drug is, how to take it, and what it will do to you if
you get it wrong.

```
IBUPROFEN 400 MG · ORAL CAPSULE
TAKE 1 CAPSULE BY MOUTH FOR PAIN AND CHEST INFECTION.
CAUTION: Take with food. May irritate the stomach.
```

```
ZIVIROL Z-ANTIDOTE 10 ML · SINGLE-USE AUTO-INJECTOR · RX ONLY
PRESS FIRMLY AGAINST THE OUTER THIGH IMMEDIATELY AFTER Z-VIRUS INFECTION.
DANGER: Costs blood and health. One dose only.
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

Three lines, always in the same order:

| Line | Content | Colour |
|------|---------|--------|
| 1 | Drug name, strength, dose form, and `RX ONLY` or `CONTROLLED POISON` where it applies | light grey |
| 2 | Directions: `TAKE 1 TABLET BY MOUTH FOR …`, `DRAW WITH A STERILE SYRINGE AND INJECT …` | default |
| 3 | `NOTE:` / `CAUTION:` / `WARNING:` / `DANGER:` and one short warning | grey, amber or red by severity |

Warning severity tracks the item's `overdosedIncrement` in TerjeMedicine:
grey below 0.2, amber to 1.0, red above it. Poisons and the things that only
look like medicine (Iversan, Novichek, arsenic, cyanide, belladonna,
strychnine, coniine, injectable alcohol) are red and say plainly that they are
not medicine.

Deliberately absent: exact numbers. Durations, levels and overdose values are
not printed on the label because TerjeMedicine already renders them live from
the config, and a hand-typed copy goes stale the moment upstream rebalances
anything.

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

All label text is in `stringtable.csv`, one row per item. To reword a label,
edit the `original` and `english` columns of its row; nothing in `config.cpp`
needs to change. The other language columns are empty and fall back to
`original`, so a translator can fill in a column without touching anything else.

Markup allowed in a label: `<br/>` for a line break and
`<color rgba='r,g,b,a'>…</color>` for colour. The palette in use is
`222,226,230` header, `150,155,160` note, `240,173,78` caution, `217,83,79`
danger.

To label an item that is not covered yet, add a row to `stringtable.csv` and a
block to `config.cpp`:

```cpp
class TerjePillsSomething: TerjePillsBase
{
    llgPharmacyLabel=1;
    descriptionShort="#STR_LLGMED_PILL_SOMETHING_DESC";
};
```

The parent in that declaration must be the same parent the class has in
TerjeMedicine. Declaring a different one re-parents the class and silently
drops everything TerjeMedicine set on it.

## Building

```
python3 LLGMedicine/Tools/pack_pbo.py
```

Writes `build/@LLGMedicine/addons/LLGMedicine.pbo`. Copy that `@LLGMedicine`
folder next to your other mods and add it to the launch parameters.

`config.cpp` ships as plain text rather than binarised `config.bin`. DayZ parses
a raw config out of a PBO without complaint — the mod this one replaces shipped
exactly that way — so no Windows-only Addon Builder is in the loop.

The PBO is **not signed**. That is fine for a local client test and for a server
running `verifySignatures = 0`, but a server with signature checking on will
reject it. To sign, run `DSSignFile.exe` from the BI Tools against the PBO with
your `.biprivatekey`, and put the matching `.bikey` in `@LLGMedicine/keys/`.

Load order: after `@TerjeCore` and `@TerjeMedicine`. The `requiredAddons` list in
`config.cpp` enforces this, so the config will refuse to load in the wrong order
rather than half-applying.
