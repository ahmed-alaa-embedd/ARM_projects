/*
 * main.c
 *
 *  Created on: 24 Aug 2020
 *      Author: ahmed alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_int.h"
#include "STk_interface.h"
#include "ACTIM1_interface.h"
#include "GPTIM_interface.h"
#include "NVIC_interface.h"


void ahmed1 (void)
{
	MGPIO_voidTogglePin(GPIOA,0);
}
void ahmed2 (void)
{
	MGPIO_voidTogglePin(GPIOA,1);
}
void ahmed3 (void)
{
	MGPIO_voidTogglePin(GPIOA,2);
}
void ahmed4 (void)
{
	MGPIO_voidTogglePin(GPIOA,3);
}
void ahmeds (void)
{
	MGPIO_voidTogglePin(GPIOA,4);
}


void main(void)
{
	/*initiat clock*/
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,11);/*Enable clock for TIM1*/
	RCC_voidEnableClock(RCC_APB1,0);/*Enable clock for TIM2*/
	RCC_voidEnableClock(RCC_APB1,1);/*Enable clock for TIM3*/
	RCC_voidEnableClock(RCC_APB1,2);/*Enable clock for TIM4*/
	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA

	MNVIC_VoidEnableInterrupt(25);/* TIM1 Enable Update Interrupt */
	MNVIC_VoidEnableInterrupt(28);/* TIM2 Enable Interrupt */
	MNVIC_VoidEnableInterrupt(29);/* TIM3 Enable Interrupt */
	MNVIC_VoidEnableInterrupt(30);/* TIM4 Enable Interrupt */


	/*PIN mode*/
	MGPIO_VoidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN3 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN4 , OUTPUT_SPEED_2MHZ_PP);

	//initalize timer
	TIM1_voidInit();
	TIM2_voidInit();
	TIM3_voidInit();
	TIM4_voidInit();
	MSTK_VoidInit();

	TIM1_voidSetIntervalPeriodic(1000000,ahmed1);
	TIM2_voidSetIntervalPeriodic(1000000,ahmed2);
	TIM3_voidSetIntervalPeriodic(1000000,ahmed3);
	TIM4_voidSetIntervalPeriodic(1000000,ahmed4);
	MSTK_VoidSetIntervalPeriodic(1000000,ahmeds);





	while(1)
	{

	}
}
