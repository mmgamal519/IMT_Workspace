/*
 * main.c
 *
 *  Created on: May 17, 2020
 *      Author: MGIsmail
 */

#include <avr/io.h>
#include <util/delay.h>

#define SET_bit(var, bit_no)		var = (1<<bit_no)|var
#define CLR_bit(var, bit_no)		var = ~(1<<bit_no)&var

int main (void)
{
	DDRD=0x00;
	DDRA=0xff;
	SET_bit(PORTD, 0);

	while(1)
	{
		if ((PIND&0b00000001)==0)
		{
			SET_bit(PORTA, 0);
		}
		else
		{
			CLR_bit(PORTA, 0);
		}
		}

	}


