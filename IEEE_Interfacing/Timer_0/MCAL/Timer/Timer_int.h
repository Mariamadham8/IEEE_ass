/*
 * Timer_int.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"../Timer/Timer_config.h"
#include"../Timer/Timer_priv.h"

#ifndef MCAL_TIMER_TIMER_INT_H_
#define MCAL_TIMER_TIMER_INT_H_

ES_t TIMER0_Init();

ES_t TIMER_Set_Preload(u8 copy_u8Preload);

ES_t TIMER_Set_AsychDelay( u32 Copy_u8Time,void *(Copy_pFuncAPP)(void *),void *parameter);

ES_t TIMER_Set_Synch_Delay( u32 Copy_u8Time);

void TIMER0_FastPWM(u8 DutyCycle);
void TIMER0_CTC(u8 CompareValue);




#endif /* MCAL_TIMER_TIMER_INT_H_ */
