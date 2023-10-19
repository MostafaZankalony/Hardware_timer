#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_register.h"
#include"DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "Global_Interrupt_interface.h"
#include "Global_Interrupt_register.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "WDT_register.h"
#include "WDT_interface.h"
#include <util/delay.h>
int arr[6];
int i=0,A=7;
int num1,num2,num3;
int flag_num=0;
int flag_reset=0;
int flag_lcd=0;
void numbers(void);
void start_timer(void);
void reset_timer(void);
void stop_timer(void);
void main (void){
	KPD_init();
	LCD_vidInit();
	DIO_SetPinDirection(PORT_D,PIN_2,PIN_INPUT);
	DIO_SetPinValue(PORT_D,PIN_2,PIN_HIGH);
	DIO_SetPinDirection(PORT_D,PIN_3,PIN_INPUT);
	DIO_SetPinValue(PORT_D,PIN_3,PIN_HIGH);
	DIO_SetPinDirection(PORT_A,PIN_6,PIN_OUTPUT);
	Global_Interrupt_Enable();
	EXT_INTERRUPT_VID_INIT();
	EXT_INTERRUPT_VID_ENABLE(EXT0);
	EXT_INTERRUPT_VID_ENABLE(EXT1);
	EXT0__VID_SET_CALL_BACK(stop_timer);
	EXT1__VID_SET_CALL_BACK(reset_timer);
	WDT_init(ms16_3);
	while(1){
					u8 read=KPD_Getkey();
					Gotoxy(1,0);
					LCD_vidWriteString("Timer: ");
				    if(A!=15 && flag_lcd==0){
						Gotoxy(1,A);
				    	LCD_vidWriteCharctr('0');
				    	Gotoxy(2,A-1);
				    	LCD_vidWriteCharctr(' ');
				    	LCD_vidWriteExtraChar(2,A);
				    	_delay_ms(200);
				    	flag_lcd=1;
				  	}
					_delay_ms(200);
					switch(read){
					case 1:{
						WDT_ON();
						break;
					}
					case 2:{
						Gotoxy(1,A);
						LCD_vidWriteCharctr('0');
						_delay_ms(200);
						arr[i]=0;
						break;
					}
					case 5:{
						Gotoxy(1,A);
						LCD_vidWriteCharctr('1');
						_delay_ms(200);
						arr[i]=1;
						break;
					}
				    case 6:{
				    	Gotoxy(1,A);
						LCD_vidWriteCharctr('2');
					    _delay_ms(200);
						arr[i]=2;
					    break;
				    }
				    case 7:{
				    	Gotoxy(1,A);
					    LCD_vidWriteCharctr('3');
						_delay_ms(200);
						arr[i]=3;
						break;
						}
				    case 9:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('4');
						_delay_ms(200);
						arr[i]=4;
						break;
					}
					case 10:{
						Gotoxy(1,A);
						LCD_vidWriteCharctr('5');
						_delay_ms(200);
						arr[i]=5;
						break;
					}
				    case 11:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('6');
					    _delay_ms(200);
						arr[i]=6;
					    break;
				    }
				    case 12:{
				    	start_timer();
				    	WDT_ON();
						break;
					}
				    case 13:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('7');
					    _delay_ms(200);
						arr[i]=7;
					    break;
				    }
				    case 14:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('8');
				        _delay_ms(200);
						arr[i]=8;
				        break;
					}
					case 15:{
						Gotoxy(1,A);
					    LCD_vidWriteCharctr('9');
						_delay_ms(200);
						arr[i]=9;
						break;
					}
				    case 16:{
					    A++;
					    i++;
					    flag_lcd=0;
					    switch(A){
					    case 9:
					    case 12:
					    	Gotoxy(1,A);
					    	LCD_vidWriteCharctr(':');
					    	_delay_ms(200);
					    case 15:
					    	Gotoxy(2,A-1);
					    	LCD_vidWriteCharctr(' ');
					    	flag_num++;
					    	numbers();
					    	A++;
					    	i=0;
					    	break;
					    default:
					    	break;
					    }
					    break;
				    }
				    default:{
					    break;
				    }
				}
			}
	}

void numbers(void){
	switch (flag_num){
	case 1:{
		num1=arr[0]*10+arr[1];
	    i=0;
	    break;
	}
	case 2:{
		num2=arr[0]*10+arr[1];
	    i=0;
	    break;
	}
	case 3:{
		num3=arr[0]*10+arr[1];
	    i=0;
	    flag_num=0;
	    break;
	    }
	}
}
void start_timer(void){
	while ((num1!=0 || num2!=0 || num3!=0) && flag_reset==0 ){
		for (;num1>=0;num1--){
	    	for (;num2>=0;num2--){
		    	for (;num3>=0;num3--){
		    		if(flag_reset==1){
		    			break;
		    		}
					LCD_vidSendCommand(lcd_Clear);
					Gotoxy(1,0);
					LCD_vidWriteString("Timer|");
					Gotoxy(2,0);
					LCD_vidWriteString("start|");
					Gotoxy(1,7);
			    	LCD_vidWriteCharctr((num1%100/10)+48);
			    	LCD_vidWriteCharctr((num1%10)+48);
			    	LCD_vidWriteCharctr(':');
		    		LCD_vidWriteCharctr((num2%100/10)+48);
		    		LCD_vidWriteCharctr((num2%10)+48);
		    		LCD_vidWriteCharctr(':');
		    		LCD_vidWriteCharctr((num3%100/10)+48);
		    		LCD_vidWriteCharctr((num3%10)+48);
		    		_delay_ms(1000);
		    	}
		    	if(flag_reset==1){
		    		break;
		    	}
		    	num3=59;
	    	}
	    	if(flag_reset==1){
	    		break;
	    	}
	    	num2=59;
		}
	}
    if (flag_reset==0){
    	 LCD_vidSendCommand(lcd_Clear);
    	 Gotoxy(1,0);
    	 LCD_vidWriteString("Timer: finished");
	     DIO_SetPinValue(PORT_A,PIN_6,PIN_HIGH);
	     _delay_ms(5000);
	     DIO_SetPinValue(PORT_A,PIN_6,PIN_LOW);
}
}
void reset_timer(void){
	flag_reset=1;
}
void stop_timer(void){
	Gotoxy(2,0);
	LCD_vidWriteString("stop |");
	_delay_ms(50);
	u8 read=KPD_Getkey();
	while (read!=12){
	read=KPD_Getkey();
	}
}
#include"STD_Types.h"
#include"BIT_MATH.h"
#include"DIO_register.h"
#include"DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "Global_Interrupt_interface.h"
#include "Global_Interrupt_register.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "WDT_register.h"
#include "WDT_interface.h"
#include <util/delay.h>
int arr[6];
int i=0,A=7;
int num1,num2,num3;
int flag_num=0;
int flag_reset=0;
int flag_lcd=0;
void numbers(void);
void start_timer(void);
void reset_timer(void);
void stop_timer(void);
void main (void){
	KPD_init();
	LCD_vidInit();
	DIO_SetPinDirection(PORT_D,PIN_2,PIN_INPUT);
	DIO_SetPinValue(PORT_D,PIN_2,PIN_HIGH);
	DIO_SetPinDirection(PORT_D,PIN_3,PIN_INPUT);
	DIO_SetPinValue(PORT_D,PIN_3,PIN_HIGH);
	DIO_SetPinDirection(PORT_A,PIN_6,PIN_OUTPUT);
	Global_Interrupt_Enable();
	EXT_INTERRUPT_VID_INIT();
	EXT_INTERRUPT_VID_ENABLE(EXT0);
	EXT_INTERRUPT_VID_ENABLE(EXT1);
	EXT0__VID_SET_CALL_BACK(stop_timer);
	EXT1__VID_SET_CALL_BACK(reset_timer);
	WDT_init(ms16_3);
	while(1){
					u8 read=KPD_Getkey();
					Gotoxy(1,0);
					LCD_vidWriteString("Timer: ");
				    if(A!=15 && flag_lcd==0){
						Gotoxy(1,A);
				    	LCD_vidWriteCharctr('0');
				    	Gotoxy(2,A-1);
				    	LCD_vidWriteCharctr(' ');
				    	LCD_vidWriteExtraChar(2,A);
				    	_delay_ms(200);
				    	flag_lcd=1;
				  	}
					_delay_ms(200);
					switch(read){
					case 1:{
						WDT_ON();
						break;
					}
					case 2:{
						Gotoxy(1,A);
						LCD_vidWriteCharctr('0');
						_delay_ms(200);
						arr[i]=0;
						break;
					}
					case 5:{
						Gotoxy(1,A);
						LCD_vidWriteCharctr('1');
						_delay_ms(200);
						arr[i]=1;
						break;
					}
				    case 6:{
				    	Gotoxy(1,A);
						LCD_vidWriteCharctr('2');
					    _delay_ms(200);
						arr[i]=2;
					    break;
				    }
				    case 7:{
				    	Gotoxy(1,A);
					    LCD_vidWriteCharctr('3');
						_delay_ms(200);
						arr[i]=3;
						break;
						}
				    case 9:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('4');
						_delay_ms(200);
						arr[i]=4;
						break;
					}
					case 10:{
						Gotoxy(1,A);
						LCD_vidWriteCharctr('5');
						_delay_ms(200);
						arr[i]=5;
						break;
					}
				    case 11:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('6');
					    _delay_ms(200);
						arr[i]=6;
					    break;
				    }
				    case 12:{
				    	start_timer();
				    	WDT_ON();
						break;
					}
				    case 13:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('7');
					    _delay_ms(200);
						arr[i]=7;
					    break;
				    }
				    case 14:{
				    	Gotoxy(1,A);
				        LCD_vidWriteCharctr('8');
				        _delay_ms(200);
						arr[i]=8;
				        break;
					}
					case 15:{
						Gotoxy(1,A);
					    LCD_vidWriteCharctr('9');
						_delay_ms(200);
						arr[i]=9;
						break;
					}
				    case 16:{
					    A++;
					    i++;
					    flag_lcd=0;
					    switch(A){
					    case 9:
					    case 12:
					    	Gotoxy(1,A);
					    	LCD_vidWriteCharctr(':');
					    	_delay_ms(200);
					    case 15:
					    	Gotoxy(2,A-1);
					    	LCD_vidWriteCharctr(' ');
					    	flag_num++;
					    	numbers();
					    	A++;
					    	i=0;
					    	break;
					    default:
					    	break;
					    }
					    break;
				    }
				    default:{
					    break;
				    }
				}
			}
	}

void numbers(void){
	switch (flag_num){
	case 1:{
		num1=arr[0]*10+arr[1];
	    i=0;
	    break;
	}
	case 2:{
		num2=arr[0]*10+arr[1];
	    i=0;
	    break;
	}
	case 3:{
		num3=arr[0]*10+arr[1];
	    i=0;
	    flag_num=0;
	    break;
	    }
	}
}
void start_timer(void){
	while ((num1!=0 || num2!=0 || num3!=0) && flag_reset==0 ){
		for (;num1>=0;num1--){
	    	for (;num2>=0;num2--){
		    	for (;num3>=0;num3--){
		    		if(flag_reset==1){
		    			break;
		    		}
					LCD_vidSendCommand(lcd_Clear);
					Gotoxy(1,0);
					LCD_vidWriteString("Timer|");
					Gotoxy(2,0);
					LCD_vidWriteString("start|");
					Gotoxy(1,7);
			    	LCD_vidWriteCharctr((num1%100/10)+48);
			    	LCD_vidWriteCharctr((num1%10)+48);
			    	LCD_vidWriteCharctr(':');
		    		LCD_vidWriteCharctr((num2%100/10)+48);
		    		LCD_vidWriteCharctr((num2%10)+48);
		    		LCD_vidWriteCharctr(':');
		    		LCD_vidWriteCharctr((num3%100/10)+48);
		    		LCD_vidWriteCharctr((num3%10)+48);
		    		_delay_ms(1000);
		    	}
		    	if(flag_reset==1){
		    		break;
		    	}
		    	num3=59;
	    	}
	    	if(flag_reset==1){
	    		break;
	    	}
	    	num2=59;
		}
	}
    if (flag_reset==0){
    	 LCD_vidSendCommand(lcd_Clear);
    	 Gotoxy(1,0);
    	 LCD_vidWriteString("Timer: finished");
	     DIO_SetPinValue(PORT_A,PIN_6,PIN_HIGH);
	     _delay_ms(5000);
	     DIO_SetPinValue(PORT_A,PIN_6,PIN_LOW);
}
}
void reset_timer(void){
	flag_reset=1;
}
void stop_timer(void){
	Gotoxy(2,0);
	LCD_vidWriteString("stop |");
	_delay_ms(50);
	u8 read=KPD_Getkey();
	while (read!=12){
	read=KPD_Getkey();
	}
}
