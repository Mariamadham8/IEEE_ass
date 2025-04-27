#include"../LIB/stdTypes.h"
#include"../LIB/errorStates.h"

#include"avr/io.h"

#include"../MCAL/Interrupt.h"

#include"../HAL/LCD/LCD_int.h"
#include"../HAL/LCD/LCD_config.h"

enum {
	start,
	ton,
	Tt,
	off
}state;

u16 Timeon,tonc,counts=0,Total,ttc;

int main()
{

	//ICU SW impelementation
	//if i dont have to use the timers resoirces or somethimg like this
	LCD_enuInit();
	DDRD &=~(1<<6);
	TCCR1A=0;
    TCCR1B=0X45;
    ICR1H=0;
    ICR1L=0;
    TCNT1H=0;
    TCNT1L=0;
    TIMSK|=(1<<5);
    SREG |=(1<<7);
	while(1)
	{
		if(state==off)
		{
			f32 duty= (f32)Timeon/Total;
			f32 time =(f32)Total*1024/1000000ul;
			f32 freq =1.0/time;
			LCD_FloatingPoint(duty);
			LCD_enuSendCommand(0XC0);
			LCD_FloatingPoint(freq);
			state =98;
		}

	}

    return 0;
}
ISR(TIMER1_CAPT_vect)
{
	if(state==start)
	{
		ICR1H=0;
		ICR1L=0;
		TCNT1H=0;
		TCNT1L=0;
		TCCR1B=0x05;
		state=ton;
	}
	else if(state==ton)
	{
		Timeon=ICR1L;
		Timeon |=(ICR1H<<8);
		TCCR1B=0x045;
		state=Tt;
	}
	else if(state==Tt)
		{
		   Total=ICR1L;
		   Total |=((u16)ICR1H<<8);
		   state=off;
		}

}



