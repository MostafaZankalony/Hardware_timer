#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_register.h"
#include "DIO_interface.h"

void DIO_SetPortDirection(u8 u8PortIdCopy,u8 u8PortDirCopy){
	switch(u8PortIdCopy){
	case PORT_A :
		DDRA_Register=u8PortDirCopy;
		break;
	case PORT_B :
		DDRB_Register=u8PortDirCopy;
		break;
	case PORT_C :
		DDRC_Register=u8PortDirCopy;
		break;
	case PORT_D :
		DDRD_Register=u8PortDirCopy;
		break;
	default:
		break;
	}

}

void DIO_SetPortValue(u8 u8PortIdCopy,u8 u8PortValCopy){
	switch(u8PortIdCopy){
	case PORT_A :
		PORTA_Register=u8PortValCopy;
		break;
	case PORT_B :
		PORTB_Register=u8PortValCopy;
		break;
	case PORT_C :
		PORTC_Register=u8PortValCopy;
		break;
	case PORT_D :
		PORTD_Register=u8PortValCopy;
		break;
	default :
		break;
	}

}


void DIO_TogglePortValue(u8 u8PortIdCopy){
	switch(u8PortIdCopy){
	case PORT_A:
		PORTA_Register = ~ PORTA_Register;
		break;
	case PORT_B:
		PORTB_Register = ~ PORTB_Register;
		break;
	case PORT_C:
		PORTC_Register = ~ PORTC_Register;
		break;
	case PORT_D:
		PORTD_Register = ~ PORTD_Register;
		break;
	default :
		break;

	}

}
u8 DIO_GetPortValue(u8 u8PortIdCopy){
	u8 u8LocalReturnCopy;
	switch(u8PortIdCopy){
	case PORT_A:
		u8LocalReturnCopy = PINA_Register ;
		break;
	case PORT_B:
		u8LocalReturnCopy = PINB_Register ;
		break;
	case PORT_C:
		u8LocalReturnCopy = PINC_Register ;
		break;
	case PORT_D:
		u8LocalReturnCopy = PIND_Register ;
		break;
	default :
		break;
	}
	return u8LocalReturnCopy;

}
/* IO Pins */
void DIO_SetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy){
	switch(u8PortIdCopy){
	case PORT_A:
		if(u8PinValCopy == PIN_LOW){
			CLR_BIT(PORTA_Register,u8PinIdCopy);
		}
		else if (u8PinValCopy == PIN_HIGH){
			SET_BIT(PORTA_Register,u8PinIdCopy);
		}
		else {
		}
		break;
	case PORT_B:
		if(u8PinValCopy == PIN_LOW){
			CLR_BIT(PORTB_Register,u8PinIdCopy);
		}
		else if (u8PinValCopy == PIN_HIGH){
			SET_BIT(PORTB_Register,u8PinIdCopy);
		}
		else {
		}
		break;
	case PORT_C:
		if(u8PinValCopy == PIN_LOW){
			CLR_BIT(PORTC_Register,u8PinIdCopy);
		}
		else if (u8PinValCopy == PIN_HIGH){
			SET_BIT(PORTC_Register,u8PinIdCopy);
		}
		else {

		}
		break;
	case PORT_D:
		if(u8PinValCopy == PIN_LOW){
			CLR_BIT(PORTD_Register,u8PinIdCopy);
		}
		else if (u8PinValCopy == PIN_HIGH){
			SET_BIT(PORTD_Register,u8PinIdCopy);
		}
		else {
		}
		break;
	default :
		break;
	}
}
u8 DIO_GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy){
	u8 u8LocalReturnCopy;
	switch(u8PortIdCopy){
	case PORT_A:
		u8LocalReturnCopy = GET_BIT(PINA_Register,u8PinIdCopy) ;
		break;
	case PORT_B:
		u8LocalReturnCopy = GET_BIT(PINB_Register,u8PinIdCopy) ;
		break;
	case PORT_C:
		u8LocalReturnCopy = GET_BIT(PINC_Register,u8PinIdCopy) ;
		break;
	case PORT_D:
		u8LocalReturnCopy = GET_BIT(PIND_Register,u8PinIdCopy) ;
		break;
	default :
		break;
	}
	return u8LocalReturnCopy;
}
void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy){
	switch(u8PortIdCopy){
	case PORT_A:
		if(u8PinDirCopy == PIN_INPUT){
			CLR_BIT(DDRA_Register,u8PinIdCopy);
		}
		else if (u8PinDirCopy == PIN_OUTPUT){
			SET_BIT(DDRA_Register,u8PinIdCopy);
		}
		else {
		}
		break;
	case PORT_B:
		if(u8PinDirCopy == PIN_INPUT){
			CLR_BIT(DDRB_Register,u8PinIdCopy);
		}
		else if (u8PinDirCopy == PIN_OUTPUT){
			SET_BIT(DDRB_Register,u8PinIdCopy);
		}
		else {
		}
		break;
	case PORT_C:
		if(u8PinDirCopy == PIN_INPUT){
			CLR_BIT(DDRC_Register,u8PinIdCopy);
		}
		else if (u8PinDirCopy == PIN_OUTPUT){
			SET_BIT(DDRC_Register,u8PinIdCopy);
		}
		else {
		}
		break;
	case PORT_D:
		if(u8PinDirCopy == PIN_INPUT){
			CLR_BIT(DDRD_Register,u8PinIdCopy);
		}
		else if (u8PinDirCopy == PIN_OUTPUT){
			SET_BIT(DDRD_Register,u8PinIdCopy);
		}
		else {
		}
		break;
	default :
		break;
	}
}
void DIO_TogglePinValue(u8 u8PortIdCopy,u8 u8PinIdCopy){
	switch(u8PortIdCopy){
		case PORT_A:
			TOG_BIT(PORTA_Register,u8PinIdCopy);
			break;
		case PORT_B:
			TOG_BIT(PORTB_Register,u8PinIdCopy);
			break;
		case PORT_C:
			TOG_BIT(PORTC_Register,u8PinIdCopy);
			break;
		case PORT_D:
			TOG_BIT(PORTD_Register,u8PinIdCopy);
			break;
		default :
			break;
	}

}
