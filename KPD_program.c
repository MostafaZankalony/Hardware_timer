/*
 * KEYBAD_program.c
 *
 *  Created on: Feb 10, 2023
 *      Author: midoy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "util/delay.h"
#define F_CPU 8000000

u8 KPD_arr[4][4]={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
};




void KPD_init(void){
	u8 i;
	for(i=ROW_START;i<=ROW_END;i++){
		DIO_SetPinDirection(KPD_PORT,i,PIN_INPUT);
		DIO_SetPinValue(KPD_PORT,i,PIN_HIGH);


	}
	for(i=COLUMN_START;i<=COLUMN_END;i++){
		DIO_SetPinDirection(KPD_PORT,i,PIN_OUTPUT);
		DIO_SetPinValue(KPD_PORT,i,PIN_HIGH);


	}
}
u8 KPD_Getkey(void){
	u8 KEY=0xff;
	u8 i,j,k;
	u8 result;
	u8 exitflag=0;

	for(i=0;i<4;i++){
		for(k=COLUMN_START;k<=COLUMN_END;k++){
			DIO_SetPinValue(KPD_PORT,k,PIN_HIGH);
		}
		DIO_SetPinValue(KPD_PORT,(COLUMN_START+i),PIN_LOW);
		for(j=0;j<4;j++){
			result =DIO_GetPinValue(KPD_PORT,(ROW_START+j));
			_delay_ms(20);
			if(result==0){
				KEY=KPD_arr[j][i];
				exitflag=1;
				if(exitflag==1){
					break;
				}
			}

		}
		if(exitflag==1){
			break;
		}
	}
	return KEY;
}

