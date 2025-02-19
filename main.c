#include "./Sys/Syscon.h"
#include "./Sys/Iocon.h"
#include "./Lcd/Lcd_Config.h"
#include "./Lcd/Lcd.h"
#include "./Ukeys/Ukeys_Config.h"
#include "./Ukeys/Ukeys.h"
#include "./Buz/Buz_Config.h"
#include "./Buz/Buz.h"

#include <stdint.h>
#include <stdio.h>

void Delay(uint32_t cycles)
{
    do
    {
        cycles--;
    } while (cycles > 0);
}

int rtc_set = 0;
uint8_t hour,min,sec;
uint8_t ahour,amin;
uint8_t ukey_clicks;
int main(void)
{
    // Mandatory Initial configurations
    Syscon_Pclk_Iocon_Enable();
    Syscon_Pclk_Gpio_Enable();

    Lcd_Config();
    Ukeys_Config();
    Buz_Config();
		while(1)
		{ 
			Lcd_Row_Select(0);
      printf("clock:%02d:%02d:%02d", hour, min, sec);
			Lcd_Row_Select(1);
			printf("Alarm:%02d:%02d",ahour,amin);
			if(rtc_set)
			{
				Delay(7200000);
				sec++;
				 if (sec > 59)
         {
					 sec = 0;
           min++;
         }
				 if (min > 59)
         {
           min = 0;
           hour++;
         }
         if (hour > 23)
         {
           hour = 0;
           min = 0;
           sec = 0;
         }
				 
				 
				 //alarm logic
				 if(ahour == hour && amin == min)
				 {
					 Buz_Set_Freq(500);
				 }
				 else
				 {
					 Buz_Set_Freq(0);
				 }
			 }
			else
			{
				Delay(2400000);
				//clock setting
				if(Ukey_Left_State_Get() == 1)
					{
						hour++;
						if(hour>23)
						{
							hour = 0;
						}
					}
					
				else if(Ukey_Right_State_Get() == 1)
					{
						min++;
						if(min>59)
						{
							min = 0;
						}
					}
					
					//alarm setting
					if(Ukey_Up_State_Get()== 1)
					{
						ahour++;
						if(ahour>23)
						{
							ahour = 0;
						}
					}
					
				else if(Ukey_Down_State_Get() == 1)
					{
						amin++;
						if(amin>59)
						{
							amin = 0;
						}
					}
					
				Ukey_Center_Clicks_Get(&ukey_clicks);
					if(1== ukey_clicks)
					{
						rtc_set =1;
					}
				}
					
		}
	
	
}



