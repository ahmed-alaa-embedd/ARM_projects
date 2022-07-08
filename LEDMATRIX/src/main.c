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
#include "STk_interface.h"
#include "LEDMatrix_Interface.h"

//AHMED
//u8 DataArray[42] =	{0, 0,  0,  0,  0, 0, 0, 0, 60, 10, 60, 0,		//A
//				  	 0, 62, 8,  62, 0,								//H
//					 0, 60, 8,  16, 8, 60, 0,						//M
//					 0, 62, 42, 42, 0,								//E
//					 0, 62, 34, 28, 0,0, 0,  0,  0,  0, 0, 0, 0};	//D


//hamada(dance)

u8 DataArray[8] ={0, 8, 100, 30, 100, 8, 0, 0};
u8 DataArray2[8]= {0, 66, 36, 30, 36, 66, 0, 0};

//u8 DataArray[8]={0};


void main()
{
	/*initiat clock*/
	RCC_voidInitSysClock();


	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA
	RCC_voidEnableClock(RCC_APB2, 3); // Enable clock for GPIOB


	//init systick

	MSTK_VoidInit();


	/*Init LEDmatrix*/
	HLEDMRX_VoidInit();





	while(1)
	{

		/*Send data to ledMatrix*/
		HLEDMRX_VoidDisplay(DataArray);
	//	MSTK_VoidSetBusyWait(1000000); //wait 1 sec
		HLEDMRX_VoidDisplay(DataArray2);


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
