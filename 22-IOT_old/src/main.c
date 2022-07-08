/***************************/
/*Author : ahmed alaa	*/
/*date : 2/10/2020 		*/
/*version : v01			*/
/***************************/

//Lib
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//MCAL
#include "RCC_interface.h"
#include "GPIO_int.h"
#include "USART_interface.h"
#include "Esp_interface.h"






/************** APP functions ************/
void main(void){

	/* Initialize the RCC to HSE */
	RCC_voidInitSysClock();

	//	/* Enable the clock for all ports */
	RCC_voidEnableClock(RCC_APB2, 2);		// Enable clock for GPIOA
	RCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	//	/* Configure pins for UART */
	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	MGPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	MGPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	//Configure pins for System
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);	//DataLED
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);	//ErrorLED

	/* Configure pins for Wifi */
	HEsp_voidInit();

	HEsp_voidConnectOnWifi("WE_9A2B93","k6m21723");

	HEsp_voidConnectOnServer("162.253.155.226");

	HEsp_voidSendData(45,"ahmedarm.freevar.com");

	//Initialize UART
	MUSART1_voidInit();

	u8 Data = HEsp_u8CheckData();

	while(1)
	{
		if (Data == 1)
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
			MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
		}
		else if (Data == 0)
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
			MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
		}
		else
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
		}
	}

}
