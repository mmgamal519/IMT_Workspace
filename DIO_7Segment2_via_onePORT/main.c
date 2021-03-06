/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */

#include <avr/io.h>
#include <util/delay.h>
#define SET_bit(var, bit_no)		var = (1<<bit_no)|var
#define CLR_bit(var, bit_no)		var = var&(~(1<<bit_no))
#define Zero		0b11000000//0
#define One			0b11111001//1
#define Two			0b10100100//2
#define Three		0b10110000//3
#define Four		0b10011001//4
#define Five		0b10010010//5
#define Six			0b10000010//6
#define Seven		0b11111000//7
#define Eight		0b10000000//8
#define Nine		0b10010000//9
void loading_7seg (int cycle);
void DIO_7Seg (int intial, int upto, int refresh);

int _7Seg_array[10]={Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine};
int _7Seg_loading_array_Right[4]={0b11111110, 0b11111101, 0b11111011, 0b11110111};
int _7Seg_loading_array_Left [4]={0b11110111, 0b11101111, 0b11011111, 0b11111110};

int main (void)
{
	while (1)
	{
		DDRD=0x01;
		PORTD=0x01;
		if ((PIND & 0x01) ==1)
		{
			loading_7seg(2);
		}
		else if ((PIND & 0x01)==0)
		{
			DIO_7Seg (2,8,10);
		}


	}
}

void loading_7seg (int cycle)
{
	DDRC=0xFF;
	DDRB=0b00000011;
	PORTB=0x00;

	for (int j=0; j<=cycle; j++)
	{
		for (int i=0; i<4; i++)
		{
			SET_bit(PORTB, 0);
			PORTC=_7Seg_loading_array_Right[i];
			_delay_ms(150);
			PORTC = 0b11111111;
			CLR_bit(PORTB, 0);
		}
		for (int i=0; i<4; i++)
		{
			SET_bit(PORTB, 1);
			PORTC=_7Seg_loading_array_Left[i];
			_delay_ms(150);
			PORTC = 0b11111111;
			CLR_bit(PORTB, 1);
		}



	}
}
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
