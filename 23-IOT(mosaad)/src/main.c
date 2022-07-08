
/***************************/
/*Author : ahmed alaa	*/
/*date : 8 Jan 2022		*/
/*version : v03		*/
/***************************/

//Lib
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//MCAL
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
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
	GPIO_voidSetPinMode(PORTA,PIN9,GPIO_OUTPUT_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	GPIO_voidSetPinMode(PORTA,PIN10,GPIO_INPUT_FLOATING);

	//Configure pins for System
	GPIO_voidSetPinMode(PORTA,PIN0,GPIO_OUTPUT_2MHZ_PP);	//DataLED
	GPIO_voidSetPinMode(PORTA,PIN1,GPIO_OUTPUT_2MHZ_PP);	//ErrorLED

	//Initialize UART
	UART_voidInit();

	/* Configure pins for Wifi */
	ESP_voidInit();

	ESP_voidConnectToWifi("WE_9A2B93","k6m21723"); //stuck on this XD

	ESP_voidConnectToServer("162.253.155.226",80);

	u8 Data = ESP_voidRecData("http://ahmedarm.freevar.com/status.txt");




//	u32 timeOut=0;
//	u32 Copy_u32timeout=1100000;

	while(1)
	{

//		MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
//		while(1)//stuck here it clear when read
//		{
//			timeOut++;
//			if(timeOut==Copy_u32timeout)
//			{
//				break;
//			}
//		}
//		timeOut=0;
//		MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
//		while(1)//stuck here it clear when read
//		{
//			timeOut++;
//			if(timeOut==Copy_u32timeout)
//			{
//				break;
//			}
//		}
//		timeOut=0;

		if (Data == 1)
		{
			GPIO_voidsetPinValue(PORTA,PIN0,HIGH);
		}
		else if (Data == 0)
		{
			GPIO_voidsetPinValue(PORTA,PIN0,LOW);
		}
		else
		{
			GPIO_voidsetPinValue(PORTA,PIN1,HIGH);
		}
	}

}


