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
//
// Load order matters. @LLGMedicine must come AFTER @Terje-Core and
// @Terje-Medicine in the launch parameters. Script modules are compiled in
// -mod= order, so loading this first puts it on the wrong side of TerjeCore's
// own ItemBase and the label ends up fighting the effects block instead of
// sitting in front of it. requiredAddons cannot fix that - it orders configs,
// not scripts.

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

		// Ask whoever is further down the chain for the effects block. On the
		// intended load order that is TerjeCore, and it returns false without
		// touching `effects` whenever the player may not read it.
		string effects = "";
		bool hasEffects = super.DescriptionOverride(effects);

		// If the chain handed back the label itself - TerjeCore does that when
		// its override type is 2, and it will if load order puts it outside
		// this class - use it as-is rather than printing the label twice.
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
