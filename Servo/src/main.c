#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_int.h"
#include "PWM_interface.h"
//#include "STK_interface.h"

int main(void)
{
	/* RCC FOR PWM ONLY */
	  PWM_RCC();

	 /* CONFIGURE PINS AS ALT FUNC > OUTPUT PUSH PULL @ 50HZ FOR PWM */
	 MGPIO_voidSetPinDirection(GPIOB,PIN9,OUTPUT_SPEED_50MHZ_AFPP);

	 /* Enable RCC FOR GPIOA FOR PULL UP */
	 RCC_voidEnableClock(RCC_APB2, 2);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN2,INPUT_PULLUP_PULLDOWN);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN3,INPUT_PULLUP_PULLDOWN);
	 /* PINA INPUT_PULLUP_PULLDOWN */
	 MGPIO_voidSetPinDirection(GPIOA,PIN4,INPUT_PULLUP_PULLDOWN);

	/* FOR PULL UP */
	MGPIO_voidSetPinValue(GPIOA,PIN0,GPIO_LOW);
	MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN3,GPIO_HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN4,GPIO_HIGH);

	/* INITLIZE PWM */
	 PWM_Init();

	while(1)
	{
//		if(MGPIO_u8GetPinValue(GPIOA,PIN0) == 0)
//		{
//			PWM_Angle(0);
//		}
//
//		if(MGPIO_u8GetPinValue(GPIOA,PIN1) == 0)
//		{
//			PWM_Angle(45);
//		}
		if(MGPIO_u8GetPinValue(GPIOA,PIN2) == 0)
		{
			PWM_Angle(0);
		}
		if(MGPIO_u8GetPinValue(GPIOA,PIN3) == 0)
		{
			PWM_Angle(90);
		}
		if(MGPIO_u8GetPinValue(GPIOA,PIN4) == 0)
		{
			PWM_Angle(250);
		}
	}
	return 0;
}



