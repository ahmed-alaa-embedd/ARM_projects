/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 6/11/2020			   */
/* version : V01 				   */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
//#include "queue.h"
//#include "semphr.h"
#include "Tasks_interface.h"


#include "RCC_interface.h"
#include "GPIO_int.h"
#include "USART_interface_Old.h"
/*  queue have a bug in FreeRTOS New version   */

//systick timer is used by freeRTOS


TaskHandle_t xTaskHandle1 = NULL ;
TaskHandle_t xTaskHandle2 = NULL ;
TaskHandle_t xTaskHandle3 = NULL ;
//xSemaphoreHandle Binary_Semaphor = NULL ;
//QueueHandle_t MyQueue;

u8 GlobalDirection;

int main (void)
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
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);


	//	Binary_Semaphor = xSemaphoreCreateBinary() ;
	xTaskCreate(vLed_Handler    ,"Led"   ,configMINIMAL_STACK_SIZE,NULL ,1,&xTaskHandle1) ;
	xTaskCreate(vLed_Handler2    ,"Led2"   ,configMINIMAL_STACK_SIZE,NULL ,2,&xTaskHandle2) ;
	xTaskCreate(UartRecieve    ,"UART"   ,configMINIMAL_STACK_SIZE,NULL ,3,&xTaskHandle3) ;



	//Initialize UART
	MUSART1_voidInit();

	vTaskStartScheduler() ;


	while (1)
	{

	}

	return 0 ;
}


void UartRecieve (void* params)
{
	// A semaphore is going to be used to guard a shared resource. In this case a
	//	Binary type .

	//	xSemaphoreGive(Binary_Semaphor) ;
	//	u8 TXData[30];
	//
	//	MyQueue = xQueueCreate(5,sizeof(TXData));



	while (1)
	{



		//		if (MGPIO_u8GetPinValue(GPIOA,PIN1))
		//		{
		//			xSemaphoreGive(Binary_Semaphor) ;
		//			sprintf(TXData,"message 1");
		//			xQueueSend(MyQueue, (void*) TXData, (TickType_t) 0);
		//
		//		}
		//		else
		//		{
		//			//xSemaphoreTake(Binary_Semaphor ,100 );
		//			//do nothing
		//		}
		//
		//		vTaskDelay( pdMS_TO_TICKS(100) ) ;

		xTaskNotifyGive(xTaskHandle1);
		xTaskNotifyGive(xTaskHandle2);
		GlobalDirection = MUSART1_u8Receive();
		vTaskDelay( pdMS_TO_TICKS(500) ) ;

	}

}



void vLed_Handler (void* params)
{

	u8 notificationValue;
	while (1)
	{
		//		u8 ret = xSemaphoreTake(Binary_Semaphor ,100 ) ;
		//		if(ret==1)
		//		{
		//			MGPIO_voidTogglePin(GPIOA,PIN0);
		//		}
		//
		//		vTaskDelay(200) ;

		notificationValue = ulTaskNotifyTake(pdFALSE,(TickType_t) portMAX_DELAY);

		if(notificationValue>0)
		{
			if(GlobalDirection=='F')
			{
				MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
			}
			else if(GlobalDirection=='B')
			{
				MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
			}

		}


	}

}

void vLed_Handler2    (void* params)
{
	//	u8 RXData[30] ;
	u8 notificationValue;

	while (1)
	{
		//		if(MyQueue !=0)
		//		{
		//			if(xQueueReceive(MyQueue, (void*)RXData, (TickType_t) 5))
		//			{
		//				MGPIO_voidTogglePin(GPIOA,PIN2);
		//				//vTaskDelay(200);
		//			}
		//		}

		notificationValue = ulTaskNotifyTake(pdFALSE,(TickType_t) portMAX_DELAY);

		if(notificationValue>0)
		{
			if(GlobalDirection=='R')
			{
				MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
			}
			else if(GlobalDirection=='L')
			{
				MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
			}
		}
	}

}





