/************************************************/
/* Author : Ahmed	Alaa                        */
/* Date   : 7/10/2020                           */
/* Version: V01                                 */
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "GPTIM_interface.h"
#include "ACTIM1_interface.h"
#include "LED_interface.h"
#include "STK_interface.h"

void Hussin1(void)
{
	LED_voidToggleLed(PORTA,4);
}

void Hussin2(void)
{
	LED_voidToggleLed(PORTA,0);
}

void Hussin3(void)
{
	LED_voidToggleLed(PORTA,1);
}
void Hussin4(void)
{
	LED_voidToggleLed(PORTA,2);
}
void Hussin5(void)
{
	LED_voidToggleLed(PORTA,3);
}


void main(void){
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,11);/*Enable clock for TIM1*/
	RCC_voidEnableClock(RCC_APB1,0);/*Enable clock for TIM2*/
	RCC_voidEnableClock(RCC_APB1,1);/*Enable clock for TIM3*/
	RCC_voidEnableClock(RCC_APB1,2);/*Enable clock for TIM4*/
//	RCC_voidEnableClock(RCC_APB1,3);/*Enable clock for TIM5 not exist*/
//	RCC_voidEnableClock(RCC_APB1,4);/*Enable clock for TIM6 not exist*/
//	RCC_voidEnableClock(RCC_APB1,5);/*Enable clock for TIM7 not exist*/
//	RCC_voidEnableClock(RCC_APB2,13);/*Enable clock for TIM8 not exist*/
//	RCC_voidEnableClock(RCC_APB2,19);/*Enable clock for TIM9 not exist*/
//	RCC_voidEnableClock(RCC_APB2,20);/*Enable clock for TIM10 not exist*/
//	RCC_voidEnableClock(RCC_APB2,21);/*Enable clock for TIM11 not exist*/
//	RCC_voidEnableClock(RCC_APB1,6);/*Enable clock for TIM12 not exist*/
//	RCC_voidEnableClock(RCC_APB1,7);/*Enable clock for TIM13 not exist*/
//	RCC_voidEnableClock(RCC_APB1,8);/*Enable clock for TIM14 not exist*/




	RCC_voidEnableClock(RCC_APB2,2);  //enable clock to GPIOA

	NVIC_voidEnableInterrupt(25);/* TIM1 Enable Update Interrupt */
	NVIC_voidEnableInterrupt(28);/* TIM2 Enable Interrupt */
	NVIC_voidEnableInterrupt(29);/* TIM3 Enable Interrupt */
	NVIC_voidEnableInterrupt(30);/* TIM4 Enable Interrupt */




	LED_voidInitLed(PORTA,0);
	LED_voidInitLed(PORTA,1);
	LED_voidInitLed(PORTA,2);
	LED_voidInitLed(PORTA,3);
	LED_voidInitLed(PORTA,4);

	TIM1_voidInit();
	TIM2_voidInit();
	TIM3_voidInit();
	TIM4_voidInit();
	STK_voidInit();

	TIM1_voidSetIntervalPeriodic(1000000,Hussin1);
	TIM2_voidSetIntervalPeriodic(1000000,Hussin2);
	TIM3_voidSetIntervalPeriodic(1000000,Hussin3);
	TIM4_voidSetIntervalPeriodic(1000000,Hussin4);
	STK_voidSetIntervalSingle(1000000,Hussin5);

	while(1)
	{
		/*LED_voidTurnOnLed(PORTA,0);
		LED_voidTurnOffLed(PORTA,0);
		TIM2_voidSetBusyWait(1000000);*/

	}
}


