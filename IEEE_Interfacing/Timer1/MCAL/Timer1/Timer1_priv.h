/*
 * Timer1_priv.h
 *
 *  Created on: Apr 1, 2025
 *      Author: Mariem
 */

#ifndef MCAL_TIMER1_TIMER1_PRIV_H_
#define MCAL_TIMER1_TIMER1_PRIV_H_

#define TIMER1_MODE_NORMAL   0

#define TIMER1_MODE_PHASE_PWM_8 1
#define TIMER1_MODE_PHASE_PWM_9 2
#define TIMER1_MODE_PHASE_PWM_10 3

#define TIMER1_CTC_MODE4 4

#define TIMER1_MODE_FAST_PWM8 5
#define TIMER1_MODE_FAST_PWM9 6
#define TIMER1_MODE_FAST_PWM10 7

#define TIMER1_MODE_PHASE_Freq1 8
#define TIMER1_MODE_PHASE_Freq2 9
#define TIMER1_MODE_PHASE_CORRECT1 10
#define TIMER1_MODE_PHASE_CORRECT2 11

#define TIMER1_CTC_MODE12 12

#define TIMER1_MODE_FAST_PWM1 14
#define TIMER1_MODE_FAST_PWM2 15




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
#define    Normal  44
#define    DISC   45
#define    non_invert 46
#define    invert     47

#define TCCR1A  *((volatile u8*)0x4F)
#define TCCR1B  *((volatile u8*)0x4E)

#define TCNT1   *((volatile u16*)0x4D)
#define TCNT1H  *((volatile u8*)0x4D)
#define TCNT1L  *((volatile u8*)0x4C)

#define OCR1A  *((volatile u16*)0x4B)
#define OCR1AH  *((volatile u8*)0x4B)
#define OCR1AL  *((volatile u8*)0x4A)

#define OCR1B  *((volatile u16*)0x49)
#define OCR1BH  *((volatile u8*)0x49)
#define OCR1BL  *((volatile u8*)0x48)

#define ICR1  *((volatile u16*)0x47)
#define ICR1H   *((volatile u8*)0x47)
#define ICR1L   *((volatile u8*)0x46)

#define TIMSK   *((volatile u8*)0x59)





#endif /* MCAL_TIMER1_TIMER1_PRIV_H_ */
