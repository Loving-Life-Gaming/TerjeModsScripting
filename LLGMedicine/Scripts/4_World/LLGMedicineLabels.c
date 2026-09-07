// LLG Medicine - pharmacy label renderer.
//
// TerjeCore builds a dynamic "consumable effects" block for medical items
// and, when the medicine recognition perks say the player can read it,
// substitutes that block *for* descriptionShort (see TerjeCore
// ItemBase.DescriptionOverride and TerjeMedicine
// ItemBase.TerjeOverrideDescriptionByConsumableEffects). Pills gate on
// "pillrecog" at skill level 1, so for most players a pill's descriptionShort
// is never shown at all; ampoules gate on "amplrecog" at level 10, so theirs
// usually is.
//
// For items flagged llgPharmacyLabel=1 this override returns the label and
// stops there. It does not call down into the effects path: the strength,
// duration and overdose numbers that path would print are already on the
// label, and building that block over one of these items is where the
// pills-only crash on click lived.

modded class ItemBase
{
	override bool DescriptionOverride(out string output)
	{
		if (!ConfigGetBool("llgPharmacyLabel"))
		{
			return super.DescriptionOverride(output);
		}

		string label = ConfigGetString("descriptionShort");
		if (label == "")
		{
			return super.DescriptionOverride(output);
		}

		output = label;
		return true;
	}
}
