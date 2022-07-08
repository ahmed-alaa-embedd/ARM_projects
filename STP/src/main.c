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
#include "STP_interface.h"

/*
u8 DataArray[42] =
		{0, 0,  0,  0,  0, 0, 0, 0, 60, 10, 60, 0,		//A
		0, 62, 8,  62, 0,								//H
		0, 60, 8,  16, 8, 60, 0,						//M
		0, 62, 42, 42, 0,								//E
		0, 62, 34, 28, 0,0, 0,  0,  0,  0, 0, 0, 0};	//D
*/

u8 DataArray[30]={124, 10, 10, 10, 124, 0, 126, 24, 24, 126, 0, 124, 2, 4, 2, 124, 0, 126, 90, 90, 90, 0, 126, 66, 36, 24, 0, 0, 0, 0};

//{0, 8, 100, 30, 100, 8, 0, 0}; //dance


void main()
{
	/*initiat clock*/
	RCC_voidInitSysClock();


	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA


	/*PIN mode*/
	MGPIO_VoidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);


	/*Initialise SYSTICk*/
	MSTK_VoidInit();	// clk=AHB/8 = 1MHz




	while(1)
	{
		HSTP_LEDMRX_VoidSheft(DataArray);
	}
}

