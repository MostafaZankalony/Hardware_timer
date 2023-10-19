#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_


#define MCUCR  *((volatile u8*)(0x55))
#define MCUCSR  *((volatile u8*)(0x54))
#define GICR  *((volatile u8*)(0x5B))
#define GIFR  *((volatile u8*)(0x5A))



#endif  //GLOBAL_INTERRUPT_REGISTER_H_
