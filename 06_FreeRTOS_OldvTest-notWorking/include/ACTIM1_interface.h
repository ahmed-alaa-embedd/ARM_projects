/************************************************/
/* Author : Ahmed	Alaa                        */
/* Date   : 7/10/2020                           */
/* Version: V01                                 */
/************************************************/
#ifndef    ACTIM1_INTERFACE_H
#define    ACTIM1_INTERFACE_H

/********************TIM2********************/
void TIM1_voidInit(void);
void TIM1_voidSetBusyWait( u32 Copy_u32Ticks );
void TIM1_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void TIM1_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void TIM1_voidStopInterval(void);
u32  TIM1_u16GetElapsedTime(void);
u32  TIM1_u16GetRemainingTime(void);



/********************CR1**********************/
#define   ACTIM_CEN           0
#define   ACTIM_UDIS          1
#define   ACTIM_URS           2
#define   ACTIM_OPM           3
#define   ACTIM_ARPE          7
/******************DIER***********************/
#define   ACTIM_UIE           0
/*******************EGR**************************/
#define   ACTIM_UG            0
/*******************SR***************************/
#define   ACTIM_UIF           0



#endif
