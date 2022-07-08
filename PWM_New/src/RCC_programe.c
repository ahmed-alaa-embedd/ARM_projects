/******************************************************************************************************/
/* Author    : Ahmed Saeed
/* Version   : V01
/* Date      : 8 Auguest 2020
/******************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if 		RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000 ;  /* ENABLE HSE WITH NO BYPASS */
		RCC_CFGR = 0x00000001;   /* SYSTEM CLOCK SWITCH HSE */
		
	#elif		RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000;   /* ENABLE HSE WITH BYPASS */
		RCC_CFGR = 0x00000001;   /* SYSTEM CLOCK SWITCH HSE */

	#elif    	RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081;   /* ENABLE HSI + TRIMMING = 0 */
		RCC_CFGR = 0x00000000;   /* SYSTEM CLOCK SWITCH HSI */

	#elif		RCC_CLOCK_TYPE == RCC_PLL
		#if 	RCC_PLL_INPUT  == RCC_PLL_IN_HSI_DIV_2
			RCC_CFGR = 0x00000002;
		#elif	RCC_PLL_INPUT  == RCC_PLL_IN_HSE_DIV_2 
			RCC_CFGR = 0x00030002;
		#elif	RCC_PLL_INPUT  == RCC_PLL_IN_HSE
			RCC_CFGR = 0x00010002;
		#endif
	#else
		#error ("you chosed wrong clock type")
	#endif
	
	/* check PLL multiple value */
	/*PLL multiplication factor. These bits can be
	  written only when PLL is disabled.*/

		#if 	RCC_PLL_MUL_VAL  == 2
			RCC_CFGR  = RCC_CFGR;
		#elif 	RCC_PLL_MUL_VAL  == 3
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_3)  << 18);
		#elif 	RCC_PLL_MUL_VAL  == 4
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_4)  << 18)
		#elif 	RCC_PLL_MUL_VAL  == 5
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_5)  << 18)
		#elif 	RCC_PLL_MUL_VAL  == 6
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_6)  << 18)
		#elif 	RCC_PLL_MUL_VAL  == 7
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_7)  << 18)
		#elif 	RCC_PLL_MUL_VAL  == 8
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_8)  << 18)
		#elif 	RCC_PLL_MUL_VAL  == 9
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_9)  << 18)
		#elif 	RCC_PLL_MUL_VAL  == 10
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_10) << 18)
		#elif 	RCC_PLL_MUL_VAL  == 11
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_11) << 18)
		#elif 	RCC_PLL_MUL_VAL  == 12
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_12) << 18)
		#elif 	RCC_PLL_MUL_VAL  == 13
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_13) << 18)
		#elif 	RCC_PLL_MUL_VAL  == 14
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_14) << 18)
		#elif 	RCC_PLL_MUL_VAL  == 15
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_15) << 18)
		#elif 	RCC_PLL_MUL_VAL  == 16
			RCC_CFGR |= ((PLL_INPUT_CLOCK_MUL_16) << 18)
		
		#endif
		
		/* Enable PLL */
		#if 	RCC_PLL_INPUT  == RCC_PLL_IN_HSI_DIV_2
			RCC_CR = 0x01000081;
		#elif	RCC_PLL_INPUT  == RCC_PLL_IN_HSE_DIV_2 
			RCC_CFGR = 0x01010000;
		#elif	RCC_PLL_INPUT  == RCC_PLL_IN_HSE
			RCC_CFGR = 0x01010000;		
		#else
		#error ("you chosed wrong clock type")
		
		#endif

}

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerId);   break;
			case RCC_APB1 :	SET_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2 :	SET_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
		}
	}
	else
	{
		/* Return Error */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PerId);   break;
			case RCC_APB1 :	CLR_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2 :	CLR_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
		}
	}
	else
	{
		/* Return Error */
	}
}

