/*
 * main.c
 *
 *  Created on: 18 Aug 2020
 *      Author: ahmed alaa
 *      vesion: 01
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

//interface>>config>>private
#include "RCC_interface.h"
#include "GPIO_int.h"

#include "SevenSeg_interface.h"



int main()
{
	RCC_voidInitSysClock();				//initiate RCC

	RCC_voidEnableClock(RCC_APB2,2); 	//Enable RCC for GPIOA
	RCC_voidEnableClock(RCC_APB2,2);	//Enable RCC for GPIOB
	RCC_voidEnableClock(RCC_APB2,2);	//Enable RCC for GPIOC

	VoidSevenSegconfig(GPIOA);


u16 w=1000;

	while(1)
	{

		VoidSevenSegDesplayNumber(GPIOA,0);

		for(int i = 0 ; i < w ; i++ )
		{
			for(int j = 0 ; j < w ; j++ )
				{
					asm("NOP");
				}
		}

		VoidSevenSegDesplayNumber(GPIOA,1);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,2);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,3);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,4);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,5);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,6);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,7);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,8);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}
		VoidSevenSegDesplayNumber(GPIOA,9);
		for(int i = 0 ; i < w ; i++ )
				{
					for(int j = 0 ; j < w ; j++ )
						{
							asm("NOP");
						}
				}

	}

	return 0;
}


