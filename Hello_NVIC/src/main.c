/*
 * main.c
 *
 *  Created on: 24 Aug 2020
 *      Author: ahmed alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"

void main()
{
	/*initiat clock*/
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA

	/*PIN mode*/

	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);

	/*Initialise MNVIC*/

	MNVIC_VoidInit();

	MNVIC_VoidSetPriority(6,0b01000000); /* EXTI0 Group 1 sub 0*/
	MNVIC_VoidSetPriority(7,0b00110000); /* EXTI1 Group 0 sub 3*/


	/*enable EXTI0 interrupt from NVIC*/

	MNVIC_VoidEnableInterrupt(6);	/*EXTI0*/
	MNVIC_VoidEnableInterrupt(7);	/*EXTI1*/

	MNVIC_VoidSetPendingFlag(6);
	while(1)
	{

	}
}

//void EXTI0_IRQHandler(void)
//{
//	MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
//	MNVIC_VoidSetPendingFlag(7);			//Set pending flag for EXTI 1
//	MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
//
//}
//
//void EXTI1_IRQHandler(void)
//{
//	MGPIO_VoidSetPinValue(GPIOA,PIN2,HIGH);
//}