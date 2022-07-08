

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_int.h"
//#include "STk_interface.h"
#include "USART_interface.h"

/************** APP functions ************/
void main(void)
{
	/* Initialize the RCC to HSE */
	MRCC_voidInitSysClock();

	//	/* Enable the clock for all ports */
	MRCC_voidEnableClock(RCC_APB2, 2);		// Enable clock for GPIOA
	MRCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	//	/* Configure pins for UART */
	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	MGPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	MGPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	//Configure pins for System
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	//	/* Configure pins for Wifi */


	/* Initialize STK */
//	MSTK_VoidInit();	// clk=AHB/8 = 1MHz

	//Initialize UART
	MUSART1_voidInit();

	while(1)
	{
//		MUSART1_voidTransmit("97");
//		x = MUSART1_u8Receive();
//		if(x == '5')
//		{
//			MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
//		}
//		else if(x == '6')
//		{
//			MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
//		}

		u8 Direction = MUSART1_u8Receive(100);


		if(Direction=='F')
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
		}
		else if(Direction=='B')
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
		}

	}

}
