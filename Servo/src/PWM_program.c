/******************************************************************************************************/
/* Author    : Ahmed Saeed
/* Version   : V01
/* Date      : 2020
/* Descrip   : pwm
/******************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**********MCAL****************/
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "RCC_interface.h"

#define RCC_CFGR     *((u32*)0x40021004)
#define RCC_CR       *((u32*)0x40021000)

void PWM_RCC(void)
{
	/* ENABLE ALT FUNC. GPIOB AND TIM4 AND ALT FUNCTION ENABLE  */
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2, 3);
	 RCC_voidEnableClock(RCC_APB1, 2);
	 RCC_voidEnableClock(RCC_APB2,0);

	 	 /* RCC PRESCALER  */
	 	 	 /* AHB PRESCALER = 4  */
	 	 	 SET_BIT(RCC_CFGR,4);
	 	 	 SET_BIT(RCC_CFGR,7);

	 	 	 /* APB1 PRESCALER = 1 */
	 	 	 /* APB2 PRESCALER = 4 */
	 	 	 SET_BIT(RCC_CFGR,11);
	 	 	 SET_BIT(RCC_CFGR,13);

	 	 	 /* CALIBRATION HSI = 16 */
	 	 	 SET_BIT(RCC_CR,12);
}
void PWM_Init(void)
{
	 /* Capture/Compare 4 output enable CC4E */
	 SET_BIT(TIM4->CCER,12);

	/* Capture/Compare 4 output polarity ACTIVE HIGH */
	 CLR_BIT(TIM4->CCER,13);

	 /* Auto-reload preload enable */
	 SET_BIT(TIM4->CR1,7);

	 /* Output compare 1 mode = PWM MODE   -> OC4M */
	 SET_BIT(TIM4->CCMR2,13);
	 SET_BIT(TIM4->CCMR2,14);

	 /* Output compare 1 preload enable OC4PE */
	 SET_BIT(TIM4->CCMR2,11);

	 /* Clock division = 1 */
	 SET_BIT(TIM4->CR1,8);

	 /* PWM freq = (8MHz)Fclk / PSC * ARR  */ // s3eed use psc=19 , ARR= 1000 so frq=421.05 hz
	 /* PWM Duty = CCR4 / ARR        */



	 TIM4->PSC = 400;
	 TIM4->ARR = 250;

	 SET_BIT(TIM4->EGR,0);
	 SET_BIT(TIM4->CR1,0);
}

void PWM_Angle(u8 Copy_u8Angle)
{
	switch (Copy_u8Angle)
	{
		case 0:  TIM4->CCR4 = 60; break;
		case 45:  TIM4->CCR4 = 90; break;
		case 90:  TIM4->CCR4 = 120; break;
		case 135:  TIM4->CCR4 = 180; break;
		case 180:  TIM4->CCR4 = 240; break;
		case 250:  TIM4->CCR4 = 250; break; // mn awl hna m4 by2ra ya m3lm
		case 750:  TIM4->CCR4 = 750; break;
		case 1000:  TIM4->CCR4 = 1000; break;
		default:
			break;
	}

}
