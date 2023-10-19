/*
 * LCD_interface.h
 *
 *  Created on: Feb 4, 2023
 *      Author: midoy
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

/***************************************************************************************/
/********************************** LCD DIO *********************************************/
/***************************************************************************************/

#define lcd_DATAPORT       PORT_C
#define lcd_CONTROLPORT       PORT_A
#define lcd_RSPIN       PIN_0
#define lcd_RWPIN       PIN_1
#define lcd_EPIN       PIN_2


/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/


void LCD_vidInit(void);
void LCD_vidSendCommand(u8 u8CmdCpy);
void LCD_vidWriteCharctr(u8 u8DataCpy);
void LCD_vidWriteString (u8* pu8StringCpy);
void Gotoxy (u8 Y,u8 X);
void LCD_vidWriteExtraChar (u8 Y,u8 X);
void LCD_printNumber(int number);
/*
void LCD_voidSendSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber, u8 Copy_u8X , u8 Copy_u8Y);
void LCD_voidSendFloat(f32 number);*/
#endif /* LCD_INTERFACE_H_ */
