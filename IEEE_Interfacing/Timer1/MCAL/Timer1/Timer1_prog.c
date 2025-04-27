/*
 * Timer1_prog.c
 *
 *  Created on: Apr 1, 2025
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../DIO/DIO_int.h"
#include"../Timer1/Timer1_priv.h"
#include"../Timer1/Timer1_config.h"

ES_t TIMER1_Iint()
{
	ES_t LocalErrorStates=NOT_OK;
   #if(Timer_Mode==TIMER1_MODE_NORMAL)
	TCCR1A=0;

#elif(Timer_Mode==TIMER1_MODE_PHASE_PWM_8)
	TCCR1A |=(1<<0);
	TCCR1A &=~(1<<1);
	TCCR1B &=~(1<<3);
	TCCR1A &=~(1<<4);

#elif(Timer_Mode==TIMER1_MODE_PHASE_PWM_9)
	TCCR1A &=~(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B &=~(1<<3);
	TCCR1A &=~(1<<4);

#elif(Timer_Mode==TIMER1_MODE_PHASE_PWM_10)
	TCCR1A |=(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B &=~(1<<3);
	TCCR1A &=~(1<<4);

#elif(Timer_Mode==TIMER1_CTC_MODE4)
	TCCR1A &=~(1<<0);
	TCCR1A &=~(1<<1);
	TCCR1B |=(1<<3);
	TCCR1A &=~(1<<4);

#elif(Timer_Mode==TIMER1_MODE_FAST_PWM8)
	TCCR1A |=(1<<0);
	TCCR1A &=~(1<<1);
	TCCR1B |=(1<<3);
	TCCR1A &=~(1<<4);

#elif(Timer_Mode==TIMER1_MODE_FAST_PWM9)
	TCCR1A &=~(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B |=(1<<3);
	TCCR1A &=~(1<<4);

#elif(Timer_Mode==TIMER1_MODE_FAST_PWM10)
	TCCR1A |=(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B |=(1<<3);
	TCCR1A &=~(1<<4);

#elif(Timer_Mode==TIMER1_MODE_PHASE_Freq1)
	TCCR1A &=~(1<<0);
	TCCR1A &=~(1<<1);
	TCCR1B &=~(1<<3);
	TCCR1A |=(1<<4);
#elif(Timer_Mode==TIMER1_MODE_PHASE_Freq2)
	TCCR1A |=(1<<0);
	TCCR1A &=~(1<<1);
	TCCR1B &=~(1<<3);
	TCCR1A |=(1<<4);

#elif(Timer_Mode==TIMER1_MODE_PHASE_CORRECT1)
	TCCR1A &=~(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B &=~(1<<3);
	TCCR1A |=(1<<4);

#elif(Timer_Mode==TIMER1_MODE_PHASE_CORRECT2)
	TCCR1A |=(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B &=~(1<<3);
	TCCR1A |=(1<<4);

#elif(Timer_Mode==TIMER1_CTC_MODE12)
	TCCR1A &=~(1<<0);
	TCCR1A &=~(1<<1);
	TCCR1B |=(1<<3);
	TCCR1A |=(1<<4);

#elif(Timer_Mode==TIMER1_MODE_FAST_PWM1)
	TCCR1A &=~(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B |=(1<<3);
	TCCR1A |=(1<<4);

#elif(Timer_Mode==TIMER1_MODE_FAST_PWM2)
	TCCR1A |=(1<<0);
	TCCR1A |=(1<<1);
	TCCR1B |=(1<<3);
	TCCR1A |=(1<<4);

   #endif

#if(OC_Mode==Normal)
	TCCR1A &=~(1<<4);
	TCCR1A &=~(1<<5);
	TCCR1A &=~(1<<6);
	TCCR1A &=~(1<<7);
#elif(OC_Mode==DISC)
	TCCR1A |=(1<<4);
	TCCR1A |=(1<<5);
	TCCR1A &=~(1<<6);
	TCCR1A &=~(1<<7);
#elif(OC_Mode==non_invert)
	TCCR1A &=~(1<<4);
	TCCR1A &=~(1<<5);
	TCCR1A |=(1<<6);
	TCCR1A |=(1<<7);
#elif(OC_Mode==invert)
	TCCR1A |=(1<<4);
	TCCR1A |=(1<<5);
	TCCR1A |=(1<<6);
	TCCR1A |=(1<<7);
#endif

#if(Timer1_Pres==pres_8)
	TCCR1B &=~(1<<0);
	TCCR1B |=(1<<1);
	TCCR1B &=~(1<<2);
#elif(Timer1_Pres==pres_64)
	TCCR1B |=(1<<0);
	TCCR1B |=(1<<1);
	TCCR1B &=~(1<<2);

#elif(Timer1_Pres==pres_256)
	TCCR1B &=~(1<<0);
	TCCR1B &=~(1<<1);
	TCCR1B |=(1<<2);
#elif(Timer1_Pres==pres_1024)
	TCCR1B |=(1<<0);
	TCCR1B &=~(1<<1);
	TCCR1B |=(1<<2);
#endif

	return LocalErrorStates;

}
void TIMER1_SetDutyCycleA(u8 dutyCycle) {
    if (dutyCycle > 100) dutyCycle = 100; // Limit to 100%
    OCR1A = (u16)(((u32)dutyCycle * ICR1) / 100);  // Calculate OCR1A value
    enuSetPinDirection(DIO_PORTD, DIO_PIN5, OUTPUT);
}

void TIMER1_SetDutyCycleB(u8 dutyCycle) {
    if (dutyCycle > 100) dutyCycle = 100; // Limit to 100%
    OCR1B = (u16)(((u32)dutyCycle * ICR1) / 100);  // Calculate OCR1B value
    enuSetPinDirection(DIO_PORTD, DIO_PIN4, OUTPUT);
}

void TIMER1_SetTopValue(u16 value) {
    ICR1 = value;
}

void TIMER1_Stop() {
    TCCR1B &= 0xF8;
}
