/*


 * LED_Program.c
 *
 *  Created on: Jun 4, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"

#include <util/delay.h>

void LED_VidButterFly(u8 LOC_u8Cycles, u8 LOC_u8Speed)
{
	for (u8 i=0; i<LOC_u8Cycles; i++)

	{
		DIO_VidSetPortValue(LED_Port, 0b00011000 );
		_delay_ms(LOC_u8Speed);
		DIO_VidSetPortValue(LED_Port, 0b00100100 );
		_delay_ms(LOC_u8Speed);
		DIO_VidSetPortValue(LED_Port, 0b01000010 );
		_delay_ms(LOC_u8Speed);
		DIO_VidSetPortValue(LED_Port, 0b10000001 );
		_delay_ms(LOC_u8Speed);
		DIO_VidSetPortValue(LED_Port, 0b01000010 );
		_delay_ms(LOC_u8Speed);
		DIO_VidSetPortValue(LED_Port, 0b00100100 );
		_delay_ms(LOC_u8Speed);
		DIO_VidSetPortValue(LED_Port, 0b00011000 );
		_delay_ms(LOC_u8Speed);
	}
}

