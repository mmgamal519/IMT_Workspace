#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"
#include "DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include "SevSeg2x1_Config.h"
#include "SevSeg2x1_Register.h"
#include "SevSeg2x1_Interface.h"
#include "LCD_Config.h"
#include "LCD_Register.h"
#include "LCD_Interface.h"

#include <util/delay.h>

void LCD_VidInit(void)
{
	_delay_ms(50); // wait for LCD to initialize
	DIO_VidSetPortDirection(LCD_DataPort, 0xff ); //Data port direction output
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_RS_PIN, OUT_HIGH); //RS
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_RW_PIN, OUT_HIGH); //RW
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_Enb_PIN, OUT_HIGH); //Enb    CTRL PINS direction output
	LCD_VidWriteCommand(FunctionSet_8bit); 	//function set
	_delay_ms(1); // wait for LCD to Function set
	LCD_VidWriteCommand(DisplayOn);	//Display On
	_delay_ms(1); // wait for LCD to Display On
	LCD_VidWriteCommand(CLRDisplay);	//Clear Display
	_delay_ms(2); // wait for LCD to Clear Display
}

void LCD_VidWriteCommand(u8 LOC_u8Command)
{
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_LOW);  //RS = 0   register selection
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Command);  // Write Command
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display
}

void LCD_VidWriteData(u8 LOC_u8Data)
{
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_HIGH);  //RS = 1
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Data);  // Write data
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display

}

void LCD_VidWriteString(u8 LOC_u8String[])
{


	for (u8 i=0; LOC_u8String[i] != '\0'; i++)
	{
		DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_HIGH);  //RS = 0
		DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0

		DIO_VidSetPortValue(LCD_DataPort, LOC_u8String[i]);  // Write data
		DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
		_delay_ms(1);	// required by LCD Datasheet
		DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
		_delay_ms(1); // give the LCD time to wite / display
	}
}
