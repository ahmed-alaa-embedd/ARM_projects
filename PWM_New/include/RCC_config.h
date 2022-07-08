/******************************************************************************************************/
/* Author    : Ahmed Saeed
/* Version   : V01
/* Date      : 8 Auguest 2020
/******************************************************************************************************/

#ifndef RCC_config_H
#define RCC_config_H

/* Options :    RCC_HSE_CRYSTAL
				RCC_HSE_RC 	
				RCC_HSI
				RCC_PLL
*/
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL


/* OPTIONS :	RCC_PLL_IN_HSI_DIV_2
				RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE	*/
				
/* NOTE : SELECT VALUE ONLY IF YOU HAVE PLL AS INPUT CLOCK SOURCE */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT   RCC_PLL_IN_HSE_DIV_2
#endif

/* OPTIONS 2 TO 16 */
/* NOTE : SELECT VALUE ONLY IF YOU HAVE PLL AS INPUT CLOCK SOURCE */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL    4
#endif

#endif