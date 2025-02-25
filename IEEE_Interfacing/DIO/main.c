#include "LIB/stdTypes.h"
#include "LIB/errorStates.h"
#include "DIO/DIO_int.h"
#include "util/delay.h"

// 7-Segment Display Numbers (Common Cathode)
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

void looping() {
    for (u8 i = 0; i <= 9; i++) {
        enuSetPortValue(DIO_PORTC, sev_seg[i]);
        _delay_ms(100);
    }
}

int main(void) {
    DIO_enuInit();

    enuSetPortDirection(DIO_PORTC, 0xFF);
    enuSetPortValue(DIO_PORTD,0x00);

    enuSetPinDirection(DIO_PORTD, DIO_PIN5, OUTPUT);
    enuSetPinDirection(DIO_PORTD, DIO_PIN6, OUTPUT);
    enuSetPinDirection(DIO_PORTD, DIO_PIN7, OUTPUT);

    while (1) {
    	u8 led=5;
    	for(;led<8;led++){
    	enuSetPinValue(DIO_PORTD,led,HIGH);
        looping();
        enuSetPinValue(DIO_PORTD,led,LOW);
    	}
    }

    return 0;
}
