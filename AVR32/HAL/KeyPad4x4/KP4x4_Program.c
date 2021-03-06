/*
 * KP4x4_Program.c
 *
 *  Created on: Jun 7, 2020
 *      Author: MGIsmail
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Register.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "../../HAL/LCD16x2/LCD_Register.h"
#include "../../HAL/LCD16x2/LCD_Interface.h"

#include "KP4x4_Interface.h"
#include "KP4x4_Config.h"
#include <util/delay.h>


/***************************************************************************************/

/************* KeyPad Key Index ***************/
/*         Col_1    Col_2   Col_3   Col_4    		 */
/*	                                         							 */
/* row_1      1        2       3       4      				*/
/*	                                         							 */
/* row_2  	  5        6       7       8     				 */
/*	                                          							*/
/* row_3	  9        10      11      12    				 */
/*	                                         							 */
/* row_4	  13       14      15      16    				 */
/**********************************************/


/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
u8 KPD_au8SwitchVal[4][4] =
{
		{
				KeyB4,    KeyB8,    KeyB12,    KeyB16 },
				{
						KeyB3,    KeyB7,    KeyB11,    KeyB15 },
						{
								KeyB2,    KeyB6,    KeyB10,    KeyB14 },
								{
										KeyB1,    KeyB5,    KeyB9,    KeyB13 }

};

/***************************************************************************************/





void KeyPad_4x4_VidInit(void)
{
	DIO_VidSetPortDirection(KeyPadColRow_port, 0x0F);
	DIO_VidSetPortValue(KeyPadColRow_port, 0xFF);	// inactive all Columns C1-C4, and activate pull up resistor for R1-R4
}

u8 KeyPad_4x4_u8ButtonPressed(void)
{
	{
		/* Initialize the switch status to NOT Pressed                                                                     */
		volatile u8 LOC_u8Retrun = NOT_PRESSED;

		/* Looping on columns of the Key Pad                                                                               */
		for (u8 LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
		{
			/* Activate the Column                                                                                           */
			DIO_VidSetPinValue(KeyPadColRow_port, LOC_u8Column, OUT_LOW);

			/* Loop on the rows of the Key Pad                                                                               */
			for (u8 LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
			{
				/* Check the status of the switch                                                                              */
				if (!DIO_u8GetPinValue(KeyPadColRow_port, LOC_u8Row))
				{
					/* Get the value of the currently pressed switch                                                             */
					LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];

					/* Wait until the switch is released (Single Press)                                                          */
					while (!DIO_u8GetPinValue(KeyPadColRow_port, LOC_u8Row))
						;

					/* Delay to avoid bouncing                                                                                   */
					_delay_ms(	50);

				}
			}

			/* Deactivate the Column                                                                                         */
			DIO_VidSetPinValue(KeyPadColRow_port, LOC_u8Column, OUT_HIGH);
		}

		return LOC_u8Retrun;
	}
}

void KeyPad4x4_TEST(void)
{
	u8 keypressed=NOT_PRESSED;
	while (keypressed !=KeyB16)
		{
			keypressed = KeyPad_4x4_u8ButtonPressed();
			if (keypressed !=NOT_PRESSED)
			{
				LCD_VidWriteData(keypressed+48);
			}
		}
}

