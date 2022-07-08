/***************************/
/*Author : ahmed alaa	*/
/*date : 2/10/2020 		*/
/*version : v02			*/
/***************************/

//Lib
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
//MCAL
#include "../include/RCC_interface.h"
#include "../include/GPIO_int.h"
#include "../include/USART_interface.h"
#include "../include/Esp_interface.h"






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

	//Initialize UART
	MUSART1_voidInit();

	/* Configure pins for Wifi */
	HEsp_voidInit();

	HEsp_voidConnectOnWifi("WE_9A2B93","k6m21723"); //stuck on this XD

	HEsp_voidConnectOnServer("162.253.155.226");

	HEsp_voidSendData(44,"ahmedarm.freevar.com");



	u8 Data = HEsp_u8CheckData();
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
			MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
		}
		else if (Data == 0)
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
		}
		else
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
		}
	}

}
