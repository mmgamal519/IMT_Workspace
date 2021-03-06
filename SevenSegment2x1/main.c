/*
 * main.c
 *
 *  Created on: May 30, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include <util/delay.h>

#include "SevSeg2x1_Interface.h"

/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */






int main (void)
{
	u8 SW1;
	u8 SW2;
	SevSeg2x1_VidInit();
	DIO_VidSetPinDirection(PORTB, PIN6, INPUT); 			// SW1 as Input
	DIO_VidSetPinValue(PORTB, PIN6, OUT_HIGH);					// SW1 enable pull up resistor
	DIO_VidSetPinDirection(PORTB, PIN7, INPUT);			// SW2 as Input
	DIO_VidSetPinValue(PORTB, PIN7, OUT_HIGH);					// SW2 enable pull up resistor
	DIO_VidSetPortDirection(PORTA, 0xff);														// LED Port direction as output
	while (1)
	{
		SW1 = DIO_u8GetPinValue(PORTB, PIN6);
		SW2 = DIO_u8GetPinValue(PORTB, PIN7);
		if ((SW1==0) and (SW2==0))
		{
			SevSeg2x1_VidCountUp(0,99)
		}
		else if  ((SW1==1) and (SW2==0))
		{
			SevSeg2x1_VidCountDown(99,0);
		}
		else if  ((SW1==0) and (SW2==1))
		{
			SevSeg2x1_VidLoading();
		}
		else if  ((SW1==0) and (SW2==0))
		{
			LED_VidButterfly(10,100);
		}

		/*SevSeg2x1_VidLoading(400);
		SevSeg2x1_VidDisplayRightDigit(0);
		_delay_ms(500);
		SevSeg2x1_VidDisplayLeftDigit(0);
		_delay_ms(500);
		SevSeg2x1_VidDisplayRightDigit(9);
			_delay_ms(500);
			SevSeg2x1_VidDisplayLeftDigit(9);
			_delay_ms(500);
		SevSeg2x1_VidCountUp(0,99);*/
		SevSeg2x1_VidCountDown(99,0);
	}
}

/*
void DIO_7Seg (int intial, int upto, int refresh)
{
	DDRC=0xFF;
	DDRB=0b00000011;
	PORTB=0x00;
	int i = 0;
	int j = 0;
	for (int count=intial; count<(upto+1); count++)
	{
		i = count /10;
		j = count % 10;

		for (int z=0; z<refresh; z++)
		{
			SET_bit(PORTB, 0);
			PORTC=_7Seg_array[j];
			_delay_ms(10);
			CLR_bit(PORTB, 0);
			SET_bit(PORTB, 1);
			PORTC=_7Seg_array[i];
			_delay_ms(10);
			CLR_bit(PORTB, 1);
		}
	}
}
 */
