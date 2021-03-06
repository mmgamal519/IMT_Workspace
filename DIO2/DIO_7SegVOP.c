#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_Register.h"
#include "BIT_Math.h"
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


int _7Seg_array[10]={Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine};
int _7Seg_loading_array_Right[4]={0b11111110, 0b11111101, 0b11111011, 0b11110111};
int _7Seg_loading_array_Left [4]={0b11110111, 0b11101111, 0b11011111, 0b11111110};


void loading_7seg (int cycle)
{
	DDRC=0xFF;
	DDRB=0b00000011;
	PORTB=0x00;

	for (int j=0; j<=cycle; j++)
	{
		for (int i=0; i<4; i++)
		{
			SET_BIT(PORTB, 0);
			PORTC=_7Seg_loading_array_Right[i];
			_delay_ms(150);
			PORTC = 0b11111111;
			CLR_BIT(PORTB, 0);
		}
		for (int i=0; i<4; i++)
		{
			SET_BIT(PORTB, 1);
			PORTC=_7Seg_loading_array_Left[i];
			_delay_ms(150);
			PORTC = 0b11111111;
			CLR_BIT(PORTB, 1);
		}



	}
}
void DIO_VidCountUp_7SegViaOnePort	( u8 LOC_u8DataPort, u8 LOC_u8CTRLPort, u8 LOC_u8CTRLPinR, u8 LOC_u8CTRLPinL, u8 LOC_u8Intialvalue, u8 LOC_u8Endvalue, u8 LOC_u8Refresh)
{

	// set port direction as output
	switch (LOC_u8DataPort)
	{
	case 0: DDRA = 0xff; break;
	case 1: DDRB = 0xff; break;
	case 2: DDRC = 0xff; break;
	case 3: DDRD = 0xff; break;
	}
	DDRC = 0xff;
	SET_BIT(LOC_u8CTRLPort,LOC_u8CTRLPinR); //set CTRL pins direction as output
	SET_BIT(LOC_u8CTRLPort,LOC_u8CTRLPinL);
	int L = 0;
	int R = 0;
	for (int count=LOC_u8Intialvalue; count<(LOC_u8Endvalue+1); count++)
	{
		L = count /10;
		R= count % 10;

		for (int z=0; z<LOC_u8Refresh; z++)
		{
			SET_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinR);
			PORTC=_7Seg_array[R];
			_delay_ms(10);
			CLR_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinR);
			SET_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinL);
			PORTC=_7Seg_array[L];
			_delay_ms(10);
			CLR_BIT(LOC_u8CTRLPort, LOC_u8CTRLPinL);
		}
	}
}
/*void DIO_7Seg (int intial, int upto, int refresh)
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
}*/
