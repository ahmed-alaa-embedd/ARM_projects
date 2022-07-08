///*
// * Tasks_program.c
// *
// *  Created on: Sep 5, 2020
// *      Author: Mohamed  Ebead
// */
//
//
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//
//#include "FreeRTOS.h"
//#include "FreeRTOSConfig.h"
//#include "task.h"
//#include "Tasks_interface.h"
//#include "queue.h"
//#include "semphr.h"
//
//
//
//#include "GPIO_int.h"
//
//extern xSemaphoreHandle Binary_Semaphor  ;
//extern QueueHandle_t MyQueue;
//
//
///**-------------------------------------------------------------------------------------------------------**/
//
//void vLed_Handler (void* params)
//{
//
//	while (1)
//	{
//		u8 ret = xSemaphoreTake(Binary_Semaphor ,100 ) ;
//		if(ret==1)
//		{
//			MGPIO_voidTogglePin(GPIOA,PIN0);
//		}
//
//		vTaskDelay(200) ;
//
//
//	}
//
//}
//
//void vLed_Handler2    (void* params)
//{
//	u8 RXData[30] ;
//	while (1)
//	{
//		if(MyQueue)
//		{
//			if(xQueueReceive(MyQueue, (void*)RXData, (TickType_t) 5))
//			{
//				MGPIO_voidTogglePin(GPIOA,PIN2);
//				//vTaskDelay(50);
//			}
//		}
//
//	}
//
//}
//
///**-------------------------------------------------------------------------------------------------------**/
//
//
