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
#include "LEDMatrix_Interface.h"

//8lt
#include "GPIO_private.h"

#include "file2.h"


u8 DataArray[8] ={0, 8, 100, 30, 100, 8, 0, 0};
u8 DataArray2[8]= {0, 66, 36, 30, 36, 66, 0, 0};

volatile u16 i=0;

void VoidSetDAC()
{
	GPIOA_ODR = dancingLEDMTX_raw[i];
	i++;
	if(i==32136)
	{
		i=0;
	}
}



void main(void)
{
	/*initiat clock*/
	RCC_voidInitSysClock();


	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA
	RCC_voidEnableClock(RCC_APB2, 3); // Enable clock for GPIOA
	RCC_voidEnableClock(RCC_APB2, 4); // Enable clock for GPIOC

	/*PIN Direction*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);

//	MGPIO_VoidSetPinDirection(GPIOB,PIN0,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOB,PIN1,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOB,PIN5,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOB,PIN6,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOB,PIN7,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOB,PIN8,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOB,PIN9,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOB,PIN10,OUTPUT_SPEED_2MHZ_PP);

//	MGPIO_VoidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOA,PIN10,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOA,PIN11,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOA,PIN12,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOA,PIN15,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOC,PIN13,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VoidSetPinDirection(GPIOC,PIN15,OUTPUT_SPEED_2MHZ_PP);



	//init systick

	MSTK_VoidInit();



	/*Init LEDmatrix*/
	HLEDMRX_VoidInit();




	while(1)
	{
		HLEDMRX_VoidDisplay(DataArray);
		HLEDMRX_VoidDisplay(DataArray2);
		//interrupt every 125 ms and
		MSTK_VoidSetIntervalPeriodic(125,VoidSetDAC);
	}

}

