#include "Lcd.h"
#include <stdio.h>

struct __FILE 
{ 
	int handle; 
};

FILE __stdout;
FILE __stdin;


/* LCD IO Map 
LCD 4-bit Bus : PIO3_0 to PIO3_3
LCD RS: PIO0_6
LCD EN:	PIO1_11
LCD RW: GND
*/

#define LCD_RS_Command()	Gpio0_Pin_Set(6, LOW)
#define LCD_RS_Data()		Gpio0_Pin_Set(6, HIGH)

#define LCD_EN_HIGH()		Gpio1_Pin_Set(11, HIGH)
#define LCD_EN_LOW()		Gpio1_Pin_Set(11, LOW)

#define LCD_Write_4Bit(dat)	Gpio3_Nibble_Set(0, dat)


void Lcd_Delay(volatile  uint32_t cycles)
{
	do
	{
		cycles--;
	} while (cycles>0);
}	

void Lcd_Cmd_Set(uint8_t cmd)   
{
	uint8_t cmd_h, cmd_l;
	
	cmd_l = (cmd >>0) & 0xF;
	cmd_h = (cmd >>4) & 0xF;
		
	LCD_RS_Command();

	LCD_EN_HIGH();
	LCD_Write_4Bit(cmd_h);
	LCD_EN_LOW();

	LCD_EN_HIGH();
	LCD_Write_4Bit(cmd_l);
	LCD_EN_LOW();
	Lcd_Delay(500);  
}

void Lcd_Row_Select(int row)
{
	switch(row)
	{
		case 0: Lcd_Cmd_Set(0X80);
			break;
			
		case 1: Lcd_Cmd_Set(0xC0);
			break;
	}
}

char Lcd_Put_Char(char dat)
{
   	char dat_h, dat_l;
	
	dat_l = (dat >>0) & 0xF;
	dat_h = (dat >>4) & 0xF;
		
	LCD_RS_Data();

	LCD_EN_HIGH();
	LCD_Write_4Bit(dat_h);
	LCD_EN_LOW();

	LCD_EN_HIGH();
	LCD_Write_4Bit(dat_l);
	LCD_EN_LOW();
	Lcd_Delay(500);  
	
	return dat;
}	

int fputc(int c, FILE *f) 
{
	return (Lcd_Put_Char(c));  // printf() internally uses Lcd_Put_Char()
}


