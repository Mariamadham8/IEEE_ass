/*
 * Mainfile.c
 *
 *  Created on: Mar 19, 2025
 *      Author: Mariem
 */

#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/DIO/DIO_config.h"

#include "../MCAL/GIE/GIE_int.h"

#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/EXTI/EXTI_config.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_config.h"

#include "../HAL/KeyPad/KeyPad2_int.h"
#include "../HAL/KeyPad/KeyPad2_config.h"

#include "../HAL/LED/LED_int.h"
#include "../HAL/LED/LED_config.h"

#include "util/delay.h"

// Function Prototypes
void Reset(void*);

// External Variables
extern EXTI_t EXTI_AstrEXTIConfig[3];

int main() {

    DIO_enuInit();
    LCD_enuInit();
    Keypad_enuInit();
    EXTI_enuinit(EXTI_AstrEXTIConfig);
    GIE_enuEnable();

    EXTI_enuSetSenceMOde(2, Rising_edge);
    EXTI_enuEnableINT(2);


    enuSetPinDirection(DIO_PORTD, DIO_PIN0, OUTPUT);
    enuSetPinDirection(DIO_PORTB, DIO_PIN2, INPUT);

    u8 val = '\0';
    u8 flag;
    char pass[4] = {'1', '2', '3', '4'};

    while (1) {
        flag = 1;

        LCD_enuSendCommand(0x01);
        _delay_ms(500);

        for (u8 i = 0; i < 4; i++) {
            do {
                Keypad_enuScan(&val);
            } while (val == '\0');

            LCD_enuDisplayChar(val);
            _delay_ms(300);

            if (val != pass[i]) {
                flag = 0;
            }
        }

        if (flag == 0) {
            LCD_enuSendCommand(0x01);
            LCD_enuSendString("Wrong Pass!");
            _delay_ms(1000);
        } else {
            LCD_enuSendCommand(0x01);
            LCD_enuSendString("Access Granted!");
            _delay_ms(1000);
            EXTI_enuCallBack(Reset, NULL, 2);
        }
    }

    return 0;
}


void Reset(void* ptr) {
    enuSetPinValue(DIO_PORTD, DIO_PIN0, HIGH);
}
