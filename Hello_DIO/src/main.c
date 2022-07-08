/*
 * main.c
 *
 *  Created on: 13 Aug 2020
 *      Author: ahmed alaa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
//interface>>config>>private
#include "RCC_interface.h"
#include "GPIO_int.h"

int main (void)
{

	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2, 2); // Enable RCC for GPIOA
	RCC_voidEnableClock(RCC_APB2, 3); // Enable RCC for GPIOB
	RCC_voidEnableClock(RCC_APB2, 4); // Enable RCC for GPIOC

	//PINA 0 is output push pull 10MHz
//	MGPIO_VoidSetPinDirection(GPIOA,PIN0,INPUT_PULLUP_DOWN);
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_10MHZ_PP);

	u16 w=600;

	while(1)
	{


		MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
		for(u16 i=0; i<w; i++)
		{
			for(u16 j=0; j<w; j++)
			{
				asm("NOP");
			}
		}

		MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
		for(u16 i=0; i<w; i++)
		{
			for(u16 j=0; j<w; j++)
			{
				asm("NOP");
			}
		}

		//		/*delay 500 ms*/
		//		for(u16 i=0; i<w; i++)
		//		{
		//			for(u16 j=0; j<w; j++)
		//			{
		//				asm("NOP");
		//			}
		//		}
		//
		//
		//		/*delay 500 ms*/
		//		for(u16 i=0; i<w; i++)
		//		{
		//			for(u16 j=0; j<w; j++)
		//			{
		//				asm("NOP");
		//			}
		//		}
	}

	return 0;
}


