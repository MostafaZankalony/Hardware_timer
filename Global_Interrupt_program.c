#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "Global_Interrupt_register.h"
#include "Global_Interrupt_interface.h"


void Global_Interrupt_Enable() {
	SET_BIT(SREG,I);
}

void Global_Interrupt_Disable() {
	CLR_BIT(SREG,I);
}
