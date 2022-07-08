/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 8 August 2020			   */
/* version : V01 				   */
/***********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR = 0x00010000; /*Enable HSI with no bypass*/
	
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR = 0x00050000; /*Enable HSI with bypass*/
	
	#elif  RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR = 0x00000081; /*HSI Enable Trimming= 0*/
	
	#elif  RCC_CLOCK_TYPE == RCC_PLL
	
	
	#else  
		#error("you choose wrong clock type")
	
	#endif 
}


void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB 	: SET_BIT(RCC_AHBENR , Copy_u8PerId); break;
			case RCC_APB1 	: SET_BIT(RCC_APB1ENR , Copy_u8PerId); break;
			case RCC_APB2 	: SET_BIT(RCC_APB2ENR , Copy_u8PerId); break;
			//default 	 	: /*Return Error*/   break; // 34an b3d el compilar m4 by7bo defult fdya
		}
		
	}
	
	else
	{
		/*Return Error*/
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB 	: CLR_BIT(RCC_AHBENR , Copy_u8PerId); break;
			case RCC_APB1 	: CLR_BIT(RCC_APB1ENR , Copy_u8PerId); break;
			case RCC_APB2 	: CLR_BIT(RCC_APB2ENR , Copy_u8PerId); break;
			//default 	 	: /*Return Error*/   break; // 34an b3d el compilar m4 by7bo defult fdya
		}
		
	}
	
	else
	{
		/*Return Error*/
	}
}