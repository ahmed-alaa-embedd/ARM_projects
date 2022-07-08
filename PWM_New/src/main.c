#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
//#include "PWM_interface.h"
#include "STK_interface.h"

typedef struct
{
	volatile u32 CR1;           /*00*/
	volatile u32 CR2;           /*04*/
	volatile u32 SMCR;          /*08*/
	volatile u32 DIER;          /*0C*/
	volatile u32 SR;            /*10*/
	volatile u32 EGR;           /*14*/
	volatile u32 CCMR1;         /*18*/
	volatile u32 CCMR2;         /*1C*/
	volatile u32 CCER;          /*20*/
	volatile u32 CNT;           /*24*/
	volatile u32 PSC;           /*28*/
	volatile u32 ARR;           /*2C*/
	volatile u32 RCR;    		/*30*/
	volatile u32 CCR1;          /*34*/
	volatile u32 CCR2;          /*38*/
	volatile u32 CCR3;          /*3C*/
	volatile u32 CCR4;          /*40*/
	volatile u32 BDTR;			/*44*/
	volatile u32 DCR;           /*48*/
	volatile u32 DMAR;          /*4C*/
}TIM1_t;

#define  TIM4    ((volatile TIM1_t*)0x40000800)

int main(void)
{
	/* ENABLE ALT FUNC. GPIOB AND TIM4 AND ALT FUNCTION ENABLE  */
	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2, 3);
	 RCC_voidEnableClock(RCC_APB1, 2);
	 RCC_voidEnableClock(RCC_APB2,0);
	 /* Enable RCC FOR GPIOA FOR PULL UP */
	 RCC_voidEnableClock(RCC_APB2, 2);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_PULLUP_PULLDOWN);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN1,INPUT_PULLUP_PULLDOWN);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN2,INPUT_PULLUP_PULLDOWN);

	/* FOR PULL UP */
	MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_HIGH);
   /* CONFIGURE PINS AS ALT FUNC > OUTPUT PUSH PULL @ 50HZ */
	 MGPIO_voidSetPinDirection(GPIOB,PIN9,OUTPUT_SPEED_50MHZ_AFPP);

	 /* INIT SYSTICK */
	 MSTK_voidInit();

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

//	 SET_BIT(TIM4->CR1,8);
	 /* PWM freq = Fclk / PSC / ARR  */
	 /* PWM Duty = CCR4 / ARR        */

	 TIM4->PSC = 1000;
	 TIM4->ARR = 1440;

	 SET_BIT(TIM4->EGR,0);
	 SET_BIT(TIM4->CR1,0);

		/* DESIRED 50HZ
		 * FCLK / 50 = 1440000
		 * SO I NEED PSC * ARR = 1440000
		 * ARR = 1000
		 * PSC = 1440
		 * PWM DUTY = CCR4 / ARR
		 * 1ms ->0angle  // 2ms -> 180angle  // 1.5ms -> 90angle ->
		 * 1/20 * 100 = 5%
		 * 5/100 * 1000 = 50
		 * 2/20 * 100 = 10%
		 * 10/100 *1000 = 100
		 * 1.5/20 * 100 = 7.5%
		 * 7.5/100 * 1000 = 75
		 *  */
	while(1)
	{
		if(MGPIO_u8GetPinValue(GPIOA,PIN0) == 0)
		{
			//2ms Pwm - Servo motor arm rotates to 180 degree
			 TIM4->CCR4 = 100;
		}

		if(MGPIO_u8GetPinValue(GPIOA,PIN1) == 0)
		{
			//1.5ms Pwm - Servo motor arm rotates to 90 degree
			 TIM4->CCR4 = 75;
		}
		if(MGPIO_u8GetPinValue(GPIOA,PIN2) == 0)
		{
			//1ms Pwm - Servo motor arm rotates to 0 degree
			 TIM4->CCR4 = 50;
		}
	}
	return 0;
}



