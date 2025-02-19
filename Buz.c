#include "Buz.h"


void Buz_Set_Freq(int ton)
{
	//Set the Gpt base mode as Internal timer to make use of internal clock.
	Gpt2_Base_Mode_Set(INTERNAL_TIMER);

	// Set the match0 value (for 5ms Ton , match value = 5ms/1us = 5000)
	Gpt2_Match0_Count_Set(ton);

	// Set the counter initial value to 0
	Gpt2_Count_Set(0);

	// Set the match0 internal option: counter reset
	Gpt2_Match0_iOption_Set(COUNTER_RESET);

	// Set the match0 external option: toggle the pin
	Gpt2_Match0_eOption_Set(MAT_PIN_TOGGLE);
}
