#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_register.h"
#include "WDT_interface.h"

void WDT_init(u8 Time_out){

#if Time_out == ms16_3
	CLR_BIT(WDTCR,WDP0);
	CLR_BIT(WDTCR,WDP1);
	CLR_BIT(WDTCR,WDP2);
#elif Time_out == ms32_5
	SET_BIT(WDTCR,WDP0);
	CLR_BIT(WDTCR,WDP1);
	CLR_BIT(WDTCR,WDP2);

#elif Time_out == ms65
	CLR_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDP1);
	CLR_BIT(WDTCR,WDP2);
#elif Time_out ==  s0_13
	SET_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDP1);
	CLR_BIT(WDTCR,WDP2);
#elif Time_out ==  s0_26
	CLR_BIT(WDTCR,WDP0);
	CLR_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP2);
#elif Time_out ==  s0_52
	SET_BIT(WDTCR,WDP0);
	CLR_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP2);
#elif Time_out ==  s1
	CLR_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP2);
#elif Time_out ==  s2_1
	SET_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP2);
#else
#endif
}

void WDT_ON(){
	SET_BIT(WDTCR,WDE);
}


void WDT_OFF(){
	WDTCR = (1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
}
