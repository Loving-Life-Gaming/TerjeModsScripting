// MedicineLabels
//
// TerjeMedicine replaces the inventory description of tablets, ampoules and
// injectors with an auto-generated effect list once the player has unlocked the
// matching Recognition perk (see TerjeMedicine/Scripts/4_World/Entities/ItemBase.c,
// TerjeOverrideDescriptionByConsumableEffects returns 1 = "effects only").
//
// That would silently hide the label text this mod sets in descriptionShort.
// For any item flagged with medicineLabel=1 in config.cpp we upgrade mode 1 to
// mode 2 = "descriptionShort + effects", so the label always stays on screen and
// perk owners get the detailed effect list appended underneath it.
//
// Runs on the client only (the tooltip is built client side). No server impact.

modded class ItemBase
{
	override int TerjeOverrideDescriptionByConsumableEffects()
	{
		int mode = super.TerjeOverrideDescriptionByConsumableEffects();
		if (mode == 1 && ConfigGetBool("medicineLabel"))
		{
			return 2;
		}

		return mode;
	}
}
