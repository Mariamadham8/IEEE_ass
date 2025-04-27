/*
 * Timer_prog.c
 *
 *  Created on: Feb 26, 2025
 *      Author: Mariem
 */

#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include "../../MCAL/Interrupt.h"

#include"../../MCAL/Timer/Timer_priv.h"
#include"../../MCAL/Timer/Timer_config.h"

#include"avr/io.h"

static u32 NUM_OVF = 0;
static u32 preload = 0;
static void (*GFUN)(void*) = NULL;
static void *GPARAMETER = NULL;

ES_t TIMER0_Init()
{
    ES_t LocalErrorStatus = NOT_OK;

    //prescaller init
    #if Timer_Presc == 1024
        TCCR0 &= 0xF8;  // Clear prescaler bits
        TCCR0 |= 5;      // Set prescaler to 1024

#elif Timer_Presc == 256
       TCCR0 &= 0xF8;  // Clear prescaler bits
       TCCR0 |= 4;      // Set prescaler to 1024

#elif Timer_Presc == 64
       TCCR0 &= 0xF8;  // Clear prescaler bits
       TCCR0 |= 3;      // Set prescaler to 1024

#elif Timer_Presc == 8
       TCCR0 &= 0xF8;  // Clear prescaler bits
       TCCR0 |= 1;      // Set prescaler to 1024
   #endif

       //WGM00,WGM01 init
    #if TIMER0_MODE == TIMER0_MODE_NORMAL
        TCCR0 &= ~(1 << 3);
        TCCR0 &= ~(1 << 6);
   #elif TIMER0_MODE== TIMER0_MODE_CTC
        TCCR0 |= (1 << 3);
        TCCR0 &= ~(1 << 6);
   #elif TIMER0_MODE== TIMER0_MODE_FAST_PWM
        TCCR0 |= (1 << 3);
        TCCR0 |= (1 << 6);
   #elif TIMER0_MODE== TIMER0_MODE_PHASE_PWM
        TCCR0 &= ~(1 << 3);
        TCCR0 |= (1 << 6);
    #endif

        //COM00,COM01 init
    #if OC_MODE == DISC
        TCCR0 &= ~(1 << 4);
        TCCR0 &= ~(1 << 5);
    #elif OC_MODE == non_invert
        TCCR0 &= ~(1 << 4);
         TCCR0 |= (1 << 5);
    #elif OC_MODE == invert
          TCCR0 |= (1 << 4);
           TCCR0 |=(1 << 5);
    #endif

    LocalErrorStatus = OK; // Mark as successful
    return LocalErrorStatus;
}

ES_t TIMER_Set_Preload(u8 copy_u8Preload)
{
    ES_t LocalErrorStatus = NOT_OK;
    TCNT0 = copy_u8Preload;
    LocalErrorStatus = OK;
    return LocalErrorStatus;
}

ES_t TIMER_Set_AsychDelay(u32 Copy_u8Time, void (*Copy_pFuncAPP)(void *), void *parameter)
{
    ES_t LocalErrorStatus = NOT_OK;

    f64 OVT = 256.0 * ((f64)Timer_Presc / Timer_F_cpu);
    f64 NOF = Copy_u8Time / OVT;

    if (NOF - (u32)NOF != 0.0)
    {
        u32 NOF_INT = (u32)NOF + 1;
        NOF = NOF - (u32)NOF;
        u32 Preload = 256 - (256 * NOF);
        NUM_OVF = NOF_INT;
        preload = Preload;
        TCNT0 = Preload;
    }
    else
    {
        NUM_OVF = NOF;
        preload = 0;
    }

    if (Copy_pFuncAPP != NULL)
    {
        GFUN = Copy_pFuncAPP;
        GPARAMETER = parameter;
    }

    TIMSK |= (1 << 0); // Enable Timer0 Overflow Interrupt

    LocalErrorStatus = OK;
    return LocalErrorStatus;
}

ES_t TIMER_Set_Synch_Delay(u32 Copy_u8Time)  // POLLING
{
    ES_t LocalErrorStatus = NOT_OK;

    TIMSK &= ~(1 << 0); // Disable Timer0 Overflow Interrupt

    f64 OVT = 256.0 * ((f64)Timer_Presc / Timer_F_cpu);
    f64 NOF = Copy_u8Time / OVT;

    if (NOF - (u32)NOF != 0.0)
    {
        u32 NOF_INT = (u32)NOF + 1;
        NOF = NOF - (u32)NOF;
        u32 Preload = 256 - (256 * NOF);
        TCNT0 = Preload;
        while (NOF_INT > 0)
        {
            while ((TIFR & (1 << 0)) == 0);
            TIFR |= (1 << 0);
            NOF_INT--;
        }
    }
    else
    {
        u32 NOF_INT = (u32)NOF;
        while (NOF_INT > 0)
        {
            while ((TIFR & (1 << 0)) == 0);
            TIFR |= (1 << 0);
            NOF_INT--;
        }
    }

    LocalErrorStatus = OK;
    return LocalErrorStatus;
}

void TIMER0_CTC(u8 CompareValue)
{
    OCR0 = CompareValue;
}

void TIMER0_FastPWM(u8 DutyCycle)
{

    OCR0 = DutyCycle ;

    // Set PB3 (OC0) as output
    DDRB |= (1 << 3);
}

/*
ISR(TIMER0_OVF_vect)  // Correct ISR declaration
{
    u32 counts = NUM_OVF;

    counts--;
    if (counts == 0)
    {
        TCNT0 = preload;
        if (GFUN != NULL)
        {
            GFUN(GPARAMETER);
        }
        counts = NUM_OVF;
    }
}
*/

