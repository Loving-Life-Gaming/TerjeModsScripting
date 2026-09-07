// LLG Medicine - pharmacy label renderer.
//
// TerjeCore already builds a dynamic "consumable effects" block for medical
// items and, when the medicine recognition perks say the player can read it,
// substitutes that block *for* descriptionShort instead of adding to it
// (see TerjeCore ItemBase.DescriptionOverride and
// TerjeMedicine ItemBase.TerjeOverrideDescriptionByConsumableEffects).
//
// The practical effect is that a hand-written descriptionShort disappears the
// moment a player trains Pill/Ampoule/Injector Recognition, and on a server
// that leaves those perks unregistered it never shows at all.
//
// This override puts the label back in front of that block for items flagged
// with llgPharmacyLabel=1, without touching the perk gate itself: an untrained
// player still gets the label only, a trained player gets the label plus the
// effects they have earned the right to read.

modded class ItemBase
{
	override bool DescriptionOverride(out string output)
	{
		// The label itself, read straight off the class in config.cpp. It is
		// rich text: <br/> line breaks and <color> spans, the same markup
		// TerjeCore uses when it builds the effects block below.
		string label = ConfigGetString("descriptionShort");

		// Not one of ours, or nothing to show: leave the item alone entirely.
		if (label == "" || !ConfigGetBool("llgPharmacyLabel"))
		{
			return super.DescriptionOverride(output);
		}

		// Ask TerjeCore for the effects block. It returns false, and leaves
		// `effects` untouched, whenever the player may not read it.
		string effects = "";
		bool hasEffects = super.DescriptionOverride(effects);

		// If the chain handed back the label itself - TerjeCore does that when
		// its override type is 2 - use it as-is rather than printing it twice.
		if (hasEffects && effects != "" && effects.IndexOf(label) != 0)
		{
			output = label + "<br/>" + effects;
		}
		else if (hasEffects && effects != "")
		{
			output = effects;
		}
		else
		{
			output = label;
		}

		return true;
	}
}
