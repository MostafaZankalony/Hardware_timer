/*********************************************************/
/*********************************************************/
/*************    Author: Mohamed Haggag    **************/
/*************    Layer: MCAL               **************/
/*************    SWC: DIO                  **************/
/*********************************************************/
/*********************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Port Defines */
#define PORT_A    0
#define PORT_B    1
#define PORT_C    2
#define PORT_D    3

/* PIN Defines */
#define PIN_0   0
#define PIN_1   1
#define PIN_2   2
#define PIN_3   3
#define PIN_4   4
#define PIN_5   5
#define PIN_6   6
#define PIN_7   7


/* PORT Directions */
#define PORT_INPUT  0x00
#define PORT_OUTPUT 0xff
/* PORT Value Options */
#define PORT_LOW  0x00
#define PORT_HIGH 0xff
/* PIN Directions */
#define PIN_INPUT  0
#define PIN_OUTPUT 1
/* PIN Value Options */
#define PIN_LOW  0
#define PIN_HIGH 1

/* IO Ports */
void DIO_SetPortDirection(u8 u8PortIdCopy,u8 u8PortDirCopy);
void DIO_SetPortValue(u8 u8PortIdCopy,u8 u8PortValCopy);
void DIO_TogglePortValue(u8 u8PortIdCopy);
u8 DIO_GetPortValue(u8 u8PortIdCopy);

/* IO Pins */
void DIO_SetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy);
u8 DIO_GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy);
void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy);
void DIO_TogglePinValue(u8 u8PortIdCopy,u8 u8PinIdCopy);




#endif /* DIO_INTERFACE_H_ */
