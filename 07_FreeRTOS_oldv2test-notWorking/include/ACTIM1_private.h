/************************************************/
/* Author : Ahmed	Alaa                        */
/* Date   : 7/10/2020                           */
/* Version: V01                                 */
/************************************************/
#ifndef    ACTIM1_PRIVATE_H
#define    ACTIM1_PRIVATE_H


static volatile  u32 Global1_u32Routine=0;
static volatile  u32 Global1_u32Fraction;
static volatile  u32 Global1_u32CopyRoutine;
static volatile  u8  Global1_u8Flag=1;
/* Define Callback Global Variable */
static volatile void (*TIM1_CallBack)(void);
/* Define Variable for interval mode */
static volatile u8 TIM1_u8ModeOfInterval;




/*Interval Mode*/
#define    SINGLE1_INTERVAL     0
#define    PERIODIC1_INTERVAL   1

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

#endif
