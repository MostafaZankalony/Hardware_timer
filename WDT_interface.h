#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_
// Time_out
#define ms16_3 0
#define ms32_5 1
#define ms65 2
#define s0_13 3
#define s0_26 4
#define s0_52 5
#define s1 6
#define s2_1 7
void WDT_init(u8 Time_out);
void WDT_ON();
void WDT_OFF();


#endif /* WDT_INTERFACE_H_ */
