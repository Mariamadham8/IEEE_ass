/*
 * Timer_priv.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Mariem
 */

#ifndef MCAL_TIMER_TIMER_PRIV_H_
#define MCAL_TIMER_TIMER_PRIV_H_


#define TIMER0_MODE_NORMAL   0
#define TIMER0_MODE_CTC      1
#define TIMER0_MODE_FAST_PWM 2
#define TIMER0_MODE_PHASE_PWM 3  // If you want Phase Correct PWM

// c00-csc01-csc02  Configuration
//System Clock

//prescaller
#define pres_8    8
#define pres_64   64
#define pres_256   256
#define pres_1024  1024
//EXTI
#define Falling_Edge 23
#define Rising_Edge  36


//
#define    OVF  44
#define    DISC   45
#define    non_invert 46
#define    invert     47

#define TCCR0    *((volatile u8 *)0x53 )
#define TCNT0    *((volatile u8 *)0x52 )
#define OCR0     *((volatile u8 *)0x5C )
#define TIMSK    *((volatile u8 *)0x59 )
#define TIFR     *((volatile u8 *)0x58 )

#endif /* MCAL_TIMER_TIMER_PRIV_H_ */
