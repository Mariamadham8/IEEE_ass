/*
 * Timer1_int.h
 *
 *  Created on: Apr 1, 2025
 *      Author: Mariem
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#ifndef MCAL_TIMER1_TIMER1_INT_H_
#define MCAL_TIMER1_TIMER1_INT_H_

ES_t TIMER1_Iint();
void TIMER1_SetDutyCycleA(u8 dutyCycle);
void TIMER1_SetDutyCycleB(u8 dutyCycle) ;
void TIMER1_SetTopValue(u16 value);
void TIMER1_Stop();

#endif /* MCAL_TIMER1_TIMER1_INT_H_ */
