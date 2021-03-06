/*
 * main.c
 *
 *  Created on: May 15, 2020
 *      Author: MGIsmail
 */

#include <avr/io.h>
#include <util/delay.h>
#define SET_bit(var, bit_no)		var = (1<<bit_no)|var
#define CLR_bit(var, bit_no)		var = ~(1<<bit_no)&var
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
void loading (int cycle );

int main (void)
{
	char _7Seg_array[10]={Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine};

	DDRD=0xFF;
	DDRC=0xFF;
	while (1)
	{
		loading(10);
		for (char i=0; i<10; i++)
		{
			for (char j=0; j<10; j++)
					{
						PORTC=_7Seg_array[i];
						PORTD=_7Seg_array[j];
						_delay_ms(200);
					}
		}

	}

}

void loading (int cycle)
{

	char _7Seg_loading_array_Right[3]={0b11111110, 0b11111101, 0b11111011, 0b11110111};
	char _7Seg_loading_array_Left [3]={0b11110111, 0b11101111, 0b11011111, 0b11111110};
	PORTD = 0b11111111;
	PORTC = 0b11111111;
	for (char j=0; j<=cycle; j++)
	{
		for (char i=0; i<4; i++)
		{
			PORTD=_7Seg_loading_array_Right[i];
			_delay_ms(300);
			PORTD = 0b11111111;
		}
		for (char i=0; i<3; i++)
		{
			PORTC=_7Seg_loading_array_Left[i];
			_delay_ms(300);
			PORTC = 0b11111111;
		}
		PORTC=0b11111110;
		_delay_ms(300);
		PORTD = 0b11111111;
		PORTC = 0b11111111;
	}
}
