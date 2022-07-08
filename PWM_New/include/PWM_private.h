/******************************************************************************************************/
/* Author    : Ahmed Saeed
/* Version   : V01
/* Date      : 2020
/* Descrip   : pwm
/******************************************************************************************************/
#ifndef    PWM_PRIVATE_H
#define    PWM_PRIVATE_H


typedef struct
{
	volatile u32 CR1;           /*00*/
	volatile u32 CR2;           /*04*/
	volatile u32 SMCR;          /*08*/
	volatile u32 DIER;          /*0C*/
	volatile u32 SR;            /*10*/
	volatile u32 EGR;           /*14*/
	volatile u32 CCMR1;         /*18*/
	volatile u32 CCMR2;         /*1C*/
	volatile u32 CCER;          /*20*/
	volatile u32 CNT;           /*24*/
	volatile u32 PSC;           /*28*/
	volatile u32 ARR;           /*2C*/
	volatile u32 RCR;    		/*30*/
	volatile u32 CCR1;          /*34*/
	volatile u32 CCR2;          /*38*/
	volatile u32 CCR3;          /*3C*/
	volatile u32 CCR4;          /*40*/
	volatile u32 BDTR;			/*44*/
	volatile u32 DCR;           /*48*/
	volatile u32 DMAR;          /*4C*/
}TIM1_t;

#define  TIM1    ((volatile TIM1_t*)0x40012C00)

#define  TIM8    ((volatile TIM1_t*)0x40013400)

#define  TIM2    ((volatile TIM1_t*)0x40000000)

#define  TIM4    ((volatile TIM1_t*)0x40000800)



#endif
