#ifndef __LCD_H__
#define __LCD_H__

#include <stdint.h>
#include "./Dio/Dio.h"


// Lcd Driver Functions
void Lcd_Cmd_Set(uint8_t cmd);   
void Lcd_Row_Select(int row);      // 0 or 1 
char Lcd_Put_Char(char dat);	
void Lcd_Put_String(char *str);
void Lcd_Put_Num(uint8_t num); 	  // 2-digit decimal (00   to 99)
void Lcd_Put_Hex(uint8_t num);    // 8-bit hex (00 to ff)
void Lcd_Put_NumV2(uint16_t num); // 4-digit decimal (0000 to 9999)
void Lcd_Delay(volatile  uint32_t cycles);

#endif
