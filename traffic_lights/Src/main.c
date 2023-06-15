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
#include "NVIC_Interface.h"
#include "EXTI_interface.h"
#include "STk_interface.h"
#include "SevenSeg_interface.h"
	u8 flag=0;
void ahmed (void)
	{
		flag=1;

	}

void main()
{
	/*initiat clock*/
	MRCC_voidInitSysClock();

	MRCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA
	MRCC_voidEnableClock(RCC_APB2, 3); // Enable clock for GPIOB
	MRCC_voidEnableClock(RCC_APB2, 0); // Enable clock for AFIO

	/*PIN mode*/

	MGPIO_VoidSetPinDirection(GPIOB,PIN6,OUTPUT_SPEED_2MHZ_PP);//red
	MGPIO_VoidSetPinDirection(GPIOB,PIN1,OUTPUT_SPEED_2MHZ_PP);//yellow
	//there is no pinB2 and don't use B3 and B4 as they used for flashing
	MGPIO_VoidSetPinDirection(GPIOB,PIN5,OUTPUT_SPEED_2MHZ_PP);//green
	MGPIO_VoidSetPinDirection(GPIOB,PIN9,OUTPUT_SPEED_2MHZ_PP);//7-seg pin
	MGPIO_VoidSetPinDirection(GPIOB,PIN0,INPUT_PULLUP_DOWN);//switch
	MGPIO_VoidSetPinValue(GPIOB , PIN0 ,LOW );//pull down
	//7 segment config
	//seg1 is from A0 to A6 seg2 is from B0 to B6
	VoidSevenSegconfig(GPIOA);

	//systick init
	MSTK_VoidInit();

	/*Initialise MNVIC*/
//	NVIC_voidSetPriorityConfig(GROUP3BITS_SUBGROUP1BITS);
//	NVIC_voidSetIntPriority(6,0,0);
//	NVIC_voidSetIntPriority(7,1,0);

	/*AFIO*/
	MAFIO_voidSetEXTIConfiguration(0,1);
	/*Initialise MEXTI*/
	MEXTI_VoidInit();
	MEXTI_VoidSetSignalLatch(EXTI_LINE0,FALLING_EDGE);

	MEXTI_VoidSetCallBack(ahmed);
	/*enable EXTI0 and EXTI1 interrupt from NVIC*/

	NVIC_voidEnablePerInt(6);	/*EXTI0*/
//	NVIC_voidEnablePerInt(7);	/*EXTI1*/

//	NVIC_voidSetPendingFlag(6);
	//testing
//	VoidSevenSegDesplayNumber(GPIOA, 0, 1);
//	VoidSevenSegDesplayNumber(GPIOA, 0, 2);


	while(1)
	{
		if(flag==1)
		{
			MGPIO_VoidSetPinValue(GPIOB,PIN5,LOW);
			MGPIO_VoidSetPinValue(GPIOB,PIN6,HIGH);
			VoidSevenSegDesplayNumber99(GPIOA,GPIOB, PIN9,3,0);
			MSTK_VoidSetBusyWait(1000000);
			VoidSevenSegLoop(2,9);
			MGPIO_VoidSetPinValue(GPIOB,PIN6,LOW);
			MGPIO_VoidSetPinValue(GPIOB,PIN1,HIGH);
			VoidSevenSegDesplayNumber99(GPIOA,GPIOB, PIN9,1,0);
			MSTK_VoidSetBusyWait(1000000);
			VoidSevenSegLoop(0,9);
			MGPIO_VoidSetPinValue(GPIOB,PIN1,LOW);
			MGPIO_VoidSetPinValue(GPIOB,PIN5,HIGH);
			VoidSevenSegDesplayNumber99(GPIOA,GPIOB, PIN9,3,0);
			VoidSevenSegLoop(2,9);





		}

	}
}

//void EXTI0_IRQHandler(void)
//{
//	//start traffic light system
//	flag=1;
//}

//void EXTI1_IRQHandler(void)
//{
//	MGPIO_VoidSetPinValue(GPIOA,PIN2,HIGH);
//	NVIC_voidSetPendingFlag(6);
//	MGPIO_VoidSetPinValue(GPIOA,PIN2,LOW);
//
//}
