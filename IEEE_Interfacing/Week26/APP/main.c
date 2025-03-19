/*
 * main.c
 *
 *  Created on: Oct 14, 2024
 *      Author: Mariem
 */

#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../MCAL/DIO_int.h"
#include "../HAL/Switch/Switch_config.h"
#include "../HAL/Switch/Switch_int.h"
#include "util/delay.h"

u8 sev_seg[] = {
       0x3F, // 0
       0x06, // 1
       0x5B, // 2
       0x4F, // 3
       0x66, // 4
       0x6D, // 5
       0x7D, // 6
       0x07, // 7
       0x7F, // 8
       0x6F  // 9
   };

extern SW_t Switch_AstrSwitchState[SW_NUM];
int main(void)
{
    DIO_enuInit();
    Switch_enuInit(Switch_AstrSwitchState);

    enuSetPortDirection(DIO_PORTA,0xff);
    enuSetPortDirection(DIO_PORTC,0xff);

    u8 pinstate;
    u8 counter = 0;
    while(1)
    {
        Switch_enuGetState(&Switch_AstrSwitchState[1], &pinstate);

        if (pinstate == 0)
        {
            if (counter < 99)
            {
                counter++;
            }
            else
            {
                counter = 0;
            }
            enuSetPortValue(DIO_PORTC, sev_seg[counter % 10]);
            enuSetPortValue(DIO_PORTA, sev_seg[counter / 10]);
            _delay_ms(250);
        }
    }
}
