#include"../LIB/stdTypes.h"
#include"../LIB/errorStates.h"

#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/DIO/DIO_config.h"
#include"../MCAL/Timer1/Timer1_config.h"
#include"../MCAL/Timer1/Timer1_priv.h"

int main()
{
	//fast pwm ,icr1 is the top ,non inverted ,64pres
	//f=50hz,duty
	TCCR1A=0X23;
	TCCR1B=0X1B;

	OCR1AH=0x01;
	OCR1AL=0x39;

	OCR1BH=0x00;
	OCR1BL=0x13;

	ICR1H=0X10;
	ICR1L=0X05;

	  enuSetPinDirection(DIO_PORTD,DIO_PIN4,OUTPUT);
	  enuSetPinDirection(DIO_PORTD,DIO_PIN5,OUTPUT);
	while(1);


}



