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
#include "EXTI_interface.h"
#include "STk_interface.h"


void ahmed (void)
{
	/*Pin A2 High			*/
	MGPIO_VoidSetPinValue(GPIOA , PIN2 , HIGH );
	/*Delay for 1 Sec		*/
	MSTK_VoidSetBusyWait( 1000000 );

	/*Pin A2 Low			*/
	MGPIO_VoidSetPinValue(GPIOA , PIN2 , LOW );
	/*Delay for 1 Sec		*/
	MSTK_VoidSetBusyWait( 1000000 );

}
void atia (void)
{
	/*Pin A2 High			*/
	MGPIO_VoidSetPinValue(GPIOA , PIN3 , HIGH );
	/*Delay for 1 Sec		*/
	MSTK_VoidSetBusyWait( 1000000 );

	/*Pin A2 Low			*/
	MGPIO_VoidSetPinValue(GPIOA , PIN3 , LOW );
	/*Delay for 1 Sec		*/
	MSTK_VoidSetBusyWait( 1000000 );

}

void main()
{
	/*initiat clock*/
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2, 0); // Enable clock for AFIO
	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA

	MEXTI_VoidSetCallBack(ahmed);
	MEXTI_VoidSetCallBack(atia);


	/*PIN mode*/

	/*	A0 & A1 ======> input PULL UP Resistor	*/
	MGPIO_VoidSetPinDirection(GPIOA , PIN0 , INPUT_PULLUP_DOWN);
	MGPIO_VoidSetPinValue(GPIOA , PIN0 ,HIGH );
	MGPIO_VoidSetPinDirection(GPIOA , PIN1 , INPUT_PULLUP_DOWN);
	MGPIO_VoidSetPinValue(GPIOA , PIN1 ,HIGH );

	/**	A2 & A3 ======> OUTPUT  SPEED 2MHZ PUSH PULL 	*/
	MGPIO_VoidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN3 , OUTPUT_SPEED_2MHZ_PP);

	/*Initialise SYSTICk*/
	MSTK_VoidInit();

	/*Initialise MNVIC*/
	MNVIC_VoidInit();

	/*AFIO*/
	MAFIO_voidSetEXTIConfiguration(0,1);
	/*Initialise MEXTI*/
	MEXTI_VoidInit();
	MEXTI_VoidSetSignalLatch(EXTI_LINE0,FALLING_EDGE);
	MEXTI_VoidSetSignalLatch(EXTI_LINE1,FALLING_EDGE);

	MNVIC_VoidSetPriority(6 , 2);
	MNVIC_VoidSetPriority(7 , 1);
	MNVIC_VoidEnableInterrupt(6);
	MNVIC_VoidEnableInterrupt(7);
	//MNVIC_voidSetPendingFlag(6);

//	MNVIC_VoidSetPriority(6,0b01000000); /* EXTI0 Group 1 sub 0*/
//	MNVIC_VoidSetPriority(7,0b00110000); /* EXTI1 Group 0 sub 3*/


	/*enable EXTI0 interrupt from NVIC*/

//	MNVIC_VoidEnableInterrupt(6);	/*EXTI0*/
//	MNVIC_VoidEnableInterrupt(7);	/*EXTI1*/

//	MNVIC_VoidSetPendingFlag(6);
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
