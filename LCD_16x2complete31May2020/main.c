/*
 * main.c
 *
 *  Created on: May 30, 2020
 *      Author: MGIsmail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"


int main (void)
{
	LCD_VidInit();
	LCD_VidWriteData('A');
	LCD_VidWriteData('N');
	LCD_VidWriteData('A');
	LCD_VidWriteData('S');
	LCD_VidWriteData(' ');
	LCD_VidWriteData(' ');
	LCD_VidWriteData('M');
	LCD_VidWriteData('O');
	LCD_VidWriteData('S');
	LCD_VidWriteData('T');
	LCD_VidWriteData('A');
	LCD_VidWriteData('F');
	LCD_VidWriteData('A');
	LCD_VidWriteData(' ');
	//LCD_VidWriteString('Mostafa');




	while(1)
	{

	}
	return 0;
}

