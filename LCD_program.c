/*
 * LCD_program.c

 *
 *  Created on: Feb 4, 2023
 *      Author: midoy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_extra.h"
#include "util/delay.h"

void LCD_vidInit(void){
	DIO_SetPortDirection(lcd_DATAPORT,PORT_OUTPUT);

	DIO_SetPinDirection(lcd_CONTROLPORT,lcd_RSPIN,PIN_OUTPUT);
	DIO_SetPinDirection(lcd_CONTROLPORT,lcd_RWPIN,PIN_OUTPUT);
	DIO_SetPinDirection(lcd_CONTROLPORT,lcd_EPIN,PIN_OUTPUT);

	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);

	_delay_ms(30);

	LCD_vidSendCommand(lcd_Home);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(5);

	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(5);


}
void LCD_vidSendCommand(u8 u8CmdCpy){
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RSPIN,PIN_LOW);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RWPIN,PIN_LOW);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);
	DIO_SetPortValue(lcd_DATAPORT,u8CmdCpy);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_HIGH);
	_delay_ms(5);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);

}
void LCD_vidWriteCharctr(u8 u8DataCpy){
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RSPIN,PIN_HIGH);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_RWPIN,PIN_LOW);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);
	DIO_SetPortValue(lcd_DATAPORT,u8DataCpy);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_HIGH);
	_delay_ms(5);
	DIO_SetPinValue(lcd_CONTROLPORT,lcd_EPIN,PIN_LOW);
}
void LCD_vidWriteString (u8* pu8StringCpy){
	u8 i=0;
	for(i=0;pu8StringCpy[i]!='\0';i++){
		LCD_vidWriteCharctr(pu8StringCpy[i]);

	}
}
void Gotoxy (u8 Y,u8 X){
	if (X>=0 && X<=16)
	{
		switch(Y)
		{
		case 1:
			LCD_vidSendCommand(X+128);
			break;
		case 2:
			LCD_vidSendCommand(X+192);
			break;
		default:
			break;
		}
	}
}
void LCD_vidWriteExtraChar (u8 Y,u8 X){
	LCD_vidSendCommand(64);
	u8 i;
	for(i=0;i<64;i++){
		LCD_vidWriteCharctr(ExtraChar[i]);
	}
	Gotoxy(Y,X);
	LCD_vidWriteCharctr(0);
/*
	for(i=0;i<8;i++){
		LCD_vidWriteCharctr(i);

	}*/
}

void LCD_printNumber(int number) {
    char buffer[16];
    sprintf(buffer, "%d", number); // Convert the integer to a string
    for (int i = 0; buffer[i] != 0; i++) {
    	LCD_vidWriteCharctr(buffer[i]);
    }
}
