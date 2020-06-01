/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

#include <util/delay.h>

int main (void)
{


	DIO_VidSetPortDirection(PORTA, OUTPUT);
	//DIO_VidSetPinDirection(PORTD, PIN0, INPUT);
	DIO_VidSetPortDirection(PORTD, INPUT);

	while (1)
	{
		/*for (u8 i=0; i<8; i++)
		{
			DIO_VidSetPinValue(PORTA, i, OUT_HIGH );
			_delay_ms(300);
			DIO_VidSetPinValue(PORTA, i, OUT_LOW );
			_delay_ms(300);
		}
		DIO_VidSetPinValue(PORTD,PIN0, OUT_HIGH); // to activate pull-up resistor
		if (DIO_u8GetPinValue(PORTD,PIN0)==1)
		{
			DIO_VidSetPinValue(PORTA, PIN0, OUT_LOW );
			_delay_ms(1500);
		}
		else
		{
			DIO_VidSetPinValue(PORTA, PIN0, OUT_HIGH);
			_delay_ms(1500);
		}
		//DIO_VidSetPinDirection(PORTD,PIN0,OUTPUT); //input from s/w 1
		DIO_VidSetPinValue(PORTD, PIN0, OUT_HIGH); // pull-up resistor

		if ((DIO_u8GetPinValue(PORTD, PIN0) & 0x01) ==1)
		{*/
		loading_7seg(2);
		DIO_VidCountUp_7SegViaOnePort(PORTC, PORTB, PIN0, PIN1,5,15,30);
		/*
		}
		else if ((DIO_u8GetPinValue(PORTD, PIN0) & 0x01)==0)
		{

		}*/
	}
	return 0;
}
