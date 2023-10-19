#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

// interrupt 0 type
#define ISC00 0
#define ISC01 1

// interrupt 1 type
#define ISC10 2
#define ISC11 3

// interrupt 2 type
#define ISC2 6

// interrupt enables
#define INT2 5
#define INT0 6
#define INT1 7

// interrupt flags
#define INTF2 5
#define INTF0 6
#define INTF1 7

#define LOW_LEVEL 0
#define IOC 1  // interrupt on change
#define FALLING_EDGE 2
#define RISING_EDGE 3

#define EXT0 0
#define EXT1 1
#define EXT2 2

#define INT0_MODE IOC
#define INT1_MODE LOW_LEVEL
#define INT2_MODE RISING_EDGE

void EXT_INTERRUPT_VID_INIT(void);
void EXT_INTERRUPT_VID_ENABLE(u8 interrupt_number);
void EXT_INTERRUPT_VID_DISABLE(u8 interrupt_number);
void EXT_INTERRUPT_VID_SET_MODE(u8 interrupt_number, u8 mode);
void EXT0__VID_SET_CALL_BACK(void (*PTR)(void));
void EXT1__VID_SET_CALL_BACK(void (*PTR)(void));
void EXT2__VID_SET_CALL_BACK(void (*PTR)(void));



#endif  //EXTI_INTERFACE_H_
