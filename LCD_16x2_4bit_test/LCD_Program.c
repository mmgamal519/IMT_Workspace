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
	DIO_VidSetPortDirection(LCD_DataPort, 0xFF ); //Data port direction output
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_RS_PIN, OUTPUT); //RS
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_RW_PIN, OUTPUT); //RW
	DIO_VidSetPinDirection(LCD_CTRLPort,  LCD_Enb_PIN, OUTPUT); //Enb    CTRL PINS direction output
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_LOW);  //RS = 0   register selection
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0
	LCD_VidWriteCommand(FunctionSet_4bit); 	//function set
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
	// to send 1st 4bits
	u8 LOC_u8Command4Bit = (LOC_u8Command & 0xf0) | (DIO_u8ReadPortValue(LCD_DataPort) & 0x0f) ;
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Command4Bit);  // Write Command
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display
	// to send 2nd 4bits
	LOC_u8Command4Bit =( (LOC_u8Command <<4)& 0xf0) | (DIO_u8ReadPortValue(LCD_DataPort) & 0x0f) ;
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Command4Bit);  // Write Command
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display
}
void LCD_VidWriteData(u8 LOC_u8Data)
{
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_HIGH);  //RS = 1
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0
	// to send 1st 4bits Higher order D7~D4
	u8 LOC_u8Data4Bit = (LOC_u8Data & 0xf0) | (DIO_u8ReadPortValue(LCD_DataPort) & 0x0f) ;
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Data4Bit);  // Write data
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display
	// to send 2nd 4bits lower order D3~D0
	LOC_u8Data4Bit = ((LOC_u8Data <<4)& 0xf0) | (DIO_u8ReadPortValue(LCD_DataPort) & 0x0f) ;
	DIO_VidSetPortValue(LCD_DataPort, LOC_u8Data4Bit);  // Write data
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_HIGH);  //Enable = 1 high rise edge
	_delay_ms(1);	// required by LCD Datasheet
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_Enb_PIN, OUT_LOW);  //Enable = 0  Falling edge
	_delay_ms(1); // give the LCD time to wite / display
}
void LCD_VidWriteString(u8 LOC_u8String[])
{
	for (u8 i=0; LOC_u8String[i] != '\0'; i++)
	{
		DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_HIGH);  //RS = 1
		DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);  //RW = 0
		LCD_VidWriteData (LOC_u8String[i]);
	}
}
/*
void LCD_VidWriteCommand4Bits (u8 LOC_u8Command4bits)
{
	DIO_VidSetPinDirection(LCD_CTRLPort, LCD_RS_PIN, OUTPUT); // set RS PIN as output
	DIO_VidSetPinDirection(LCD_CTRLPort, LCD_RW_PIN, OUTPUT); // set RW PIN as output
	DIO_VidSetPinDirection(LCD_CTRLPort, LCD_Enb_PIN, OUTPUT); // set Enable PIN as output
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RS_PIN, OUT_LOW);
	DIO_VidSetPinValue(LCD_CTRLPort, LCD_RW_PIN, OUT_LOW);
	DIO_VidSetPortValue(LCD_DataPort, (LOC_u8Command4bits & 0xF0)); 		// Higher order D7~D4
	DIO_VidSetPortValue(LCD_DataPort, ((LOC_u8Command4bits<<4 ) & 0xF0));			// Lower order D3~D0
}
*/
