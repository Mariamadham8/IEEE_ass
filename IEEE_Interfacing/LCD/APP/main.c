/*
 * main.c
 *
 *  Created on: Oct 25, 2024
 *      Author: Mariem
 */

#include"../LIB/stdTypes.h"
#include"../LIB/errorStates.h"

#include"../MCAL/DIO/DIO_int.h"

#include"../HAL/LCD_int.h"
#include"util/delay.h"

int main()
{
	  LCD_enuInit();
	LCD_enuDisplayChar('M');
	LCD_enuDisplayChar('E');
	LCD_enuDisplayChar('R');
	LCD_enuDisplayChar('o');
	_delay_ms(3000);
	LCD_enuSendCommand(0x01);
	 LCD_enuSendString("MARIAM");
	 _delay_ms(3000);
	 LCD_enuSendCommand(0x01);
	 u8 x=5,y=0;
	  LCD_enuSetPosition( x, y);
	  LCD_enuSendString("Hello");
	  _delay_ms(3000);
	  LCD_enuSendCommand(0x01);
		while (1);
	return 0;
}
