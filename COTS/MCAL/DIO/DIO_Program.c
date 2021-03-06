#include "STD_TYPES.h"
#include "DIO_Register.h"
#include "BIT_Math.h"


void DIO_VidSetPinDirection	( u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8State);
{
	if ( OUTPUT==LOC_u8State)
	{
		switch (LOC_u8Port)
		{
			case 0: SET_BIT(DDRA, LOC_u8Pin); break;
			case 1: SET_BIT(DDRB, LOC_u8Pin); break;
			case 2: SET_BIT(DDRC, LOC_u8Pin); break;
			case 3: SET_BIT(DDRD, LOC_u8Pin); break;
		}
	}
	else if (INPUT==LOC_u8State)
		{
		switch (LOC_u8Port)
		{
			case 0: CLR_BIT(DDRA, LOC_u8Pin); break;
			case 1: CLR_BIT(DDRB, LOC_u8Pin); break;
			case 2: CLR_BIT(DDRC, LOC_u8Pin); break;
			case 3: CLR_BIT(DDRD, LOC_u8Pin); break;
		}
	}
}

void DIO_VidSetPinValue	( u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8State);
{
	if ( OUTPUT==LOC_u8State)
	{
		switch (LOC_u8Port)
		{
			case 0: SET_BIT(PORTA, LOC_u8Pin); break;
			case 1: SET_BIT(PORTB, LOC_u8Pin); break;
			case 2: SET_BIT(PORTC, LOC_u8Pin); break;
			case 3: SET_BIT(PORTD, LOC_u8Pin); break;
		}
	}
	else if (INPUT==LOC_u8State)
		{
		switch (LOC_u8Port)
		{
			case 0: CLR_BIT(PORTA, LOC_u8Pin); break;
			case 1: CLR_BIT(PORTB, LOC_u8Pin); break;
			case 2: CLR_BIT(PORTC, LOC_u8Pin); break;
			case 3: CLR_BIT(PORTD, LOC_u8Pin); break;
		}
	}
}