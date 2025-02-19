#include "Ukeys.h"


uint8_t Ukey_Up_State_Get(void)
{
	uint8_t uk = UNTOUCH, pn = HIGH;
	
	pn = Gpio0_Pin_Get(3);
	
	if(LOW == pn)
	{
		uk = TOUCH;
	}	
	return uk;
}

uint8_t Ukey_Down_State_Get(void)
{
	uint8_t uk = UNTOUCH, pn = HIGH;
	
	pn = Gpio2_Pin_Get(6);
	
	if(LOW == pn)
	{
		uk = TOUCH;
	}	
	return uk;
}

uint8_t Ukey_Center_State_Get(void)
{
	uint8_t uk = UNTOUCH, pn = HIGH;
	
	pn = Gpio2_Pin_Get(8);
	
	if(LOW == pn)
	{
		uk = TOUCH;
	}	
	return uk;
}

uint8_t Ukey_Left_State_Get(void)
{
	uint8_t uk = UNTOUCH, pn = HIGH;
	
	pn = Gpio2_Pin_Get(7);
	
	if(LOW == pn)
	{
		uk = TOUCH;
	}	
	return uk;
}

uint8_t Ukey_Right_State_Get(void)
{
	uint8_t uk = UNTOUCH, pn = HIGH;
	
	pn = Gpio1_Pin_Get(4);
	
	if(LOW == pn)
	{
		uk = TOUCH;
	}	
	return uk;
}

void Ukey_Up_Clicks_Get(uint8_t *clicks)
{
	uint8_t state_current  = UNTOUCH;
	static uint8_t state_previous = UNTOUCH;
	
	state_current = Ukey_Up_State_Get();
	
	if(state_current == UNTOUCH)
	{
		if(state_previous == TOUCH)
		{
			(*clicks)++;
		}	
	}	
	state_previous = state_current;
}  

void Ukey_Down_Clicks_Get(uint8_t *clicks)
{
	uint8_t state_current  = UNTOUCH;
	static uint8_t state_previous = UNTOUCH;
	
	state_current = Ukey_Down_State_Get();
	
	if(state_current == UNTOUCH)
	{
		if(state_previous == TOUCH)
		{
			(*clicks)++;
		}	
	}	
	state_previous = state_current;
}  

void Ukey_Center_Clicks_Get(uint8_t *clicks)
{
	uint8_t state_current  = UNTOUCH;
	static uint8_t state_previous = UNTOUCH;
	
	state_current = Ukey_Center_State_Get();
	
	if(state_current == UNTOUCH)
	{
		if(state_previous == TOUCH)
		{
			(*clicks)++;
		}	
	}	
	state_previous = state_current;
}

void Ukey_Left_Clicks_Get(uint8_t *clicks) 
{
	uint8_t state_current  = UNTOUCH;
	static uint8_t state_previous = UNTOUCH;
	
	state_current = Ukey_Left_State_Get();
	
	if(state_current == UNTOUCH)
	{
		if(state_previous == TOUCH)
		{
			(*clicks)++;
		}	
	}	
	state_previous = state_current;
}

void Ukey_Right_Clicks_Get(uint8_t *clicks)
{
	uint8_t state_current  = UNTOUCH;
	static uint8_t state_previous = UNTOUCH;
	
	state_current = Ukey_Right_State_Get();
	
	if(state_current == UNTOUCH)
	{
		if(state_previous == TOUCH)
		{
			(*clicks)++;
		}	
	}	
	state_previous = state_current;
}



