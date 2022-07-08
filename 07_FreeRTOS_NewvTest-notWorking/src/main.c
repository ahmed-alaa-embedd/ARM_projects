/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 6/11/2020			   */
/* version : V01 				   */
/***********************************/

#include "stdio.h"
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
TaskHandle_t IdelTaskHandle = NULL;
TaskHandle_t MotorHandle = NULL;
TaskHandle_t ServoHandle = NULL;
TaskHandle_t xUARTHandle = NULL;
TaskHandle_t CheckHandle = NULL;

/* Dimensions the buffer that the task being created will use as its stack.
    NOTE:  This is the number of words the stack will hold, not the number of
    bytes.  For example, if each stack item is 32-bits, and this is set to 100,
    then 400 bytes (100 * 32-bits) will be allocated. */
#define STACK_SIZE 200

/* Structure that will hold the TCB of the task being created. */
StaticTask_t IdelTaskTCB;
StaticTask_t MotorTCB;
StaticTask_t ServoTCB;
StaticTask_t UartTCB;
StaticTask_t CheckTCB;

/* Buffer that the task being created will use as its stack.  Note this is
    an array of StackType_t variables.  The size of StackType_t is dependent on
    the RTOS port. */
StackType_t IdelTaskBuffer[ STACK_SIZE ];
StackType_t MotorBuffer[ STACK_SIZE ];
StackType_t ServoBuffer[ STACK_SIZE ];
StackType_t UartBuffer[ STACK_SIZE ];
StackType_t CheckBuffer[ STACK_SIZE ];


//TaskHandle_t xTaskHandle1 = NULL ;
//TaskHandle_t xTaskHandle2 = NULL ;
//TaskHandle_t xTaskHandle3 = NULL ;
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

	/**********************************************************************************************************/

	/************* tasks create ************/

	/*****---- Idel task ---- ****/


	/* Create the task without using any dynamic memory allocation. */
	IdelTaskHandle = xTaskCreateStatic(
			vApplicationIdleHook,       /* Function that implements the task. */
			"Idel task",          /* Text name for the task. */
			STACK_SIZE,      /* Number of indexes in the xStack array. */
			( void * ) 1,    /* Parameter passed into the task. */
			tskIDLE_PRIORITY,/* Priority at which the task is created. */
			IdelTaskBuffer,          /* Array to use as the task's stack. */
			&IdelTaskTCB );  /* Variable to hold the task's data structure. */

	/* puxStackBuffer and pxTaskBuffer were not NULL, so the task will have
	        been created, and xHandle will be the task's handle.  Use the handle
	        to suspend the task. */
	//vTaskSuspend( IdelTaskHandle );
	/**********************************************************************************************************/

	/*****---- Motor task ---- ****/

	/* Create the task without using any dynamic memory allocation. */
	MotorHandle = xTaskCreateStatic(vMotor_Handler, "motor task", STACK_SIZE,( void * ) 1,2,MotorBuffer, &MotorTCB );

//	vTaskSuspend( MotorHandle );
	/**********************************************************************************************************/

	/*****---- Servo task ---- ****/


	/* Create the task without using any dynamic memory allocation. */
	ServoHandle = xTaskCreateStatic(vServo_Handler, "Servo task", STACK_SIZE,( void * ) 1,3,ServoBuffer, &ServoTCB );

	vTaskSuspend( ServoHandle );
	/**********************************************************************************************************/

	/*****---- UART task ---- ****/


	/* Create the task without using any dynamic memory allocation. */
	xUARTHandle = xTaskCreateStatic(vUartRecieve, "UART task", STACK_SIZE,( void * ) 1,7,UartBuffer, &UartTCB );

	vTaskSuspend( xUARTHandle );
	/**********************************************************************************************************/

	/*****---- Check task ---- ****/


	/* Create the task without using any dynamic memory allocation. */
	CheckHandle = xTaskCreateStatic(vCheck, "Check task", STACK_SIZE,( void * ) 1,6,CheckBuffer, &CheckTCB);

	vTaskSuspend( CheckHandle );
	/**********************************************************************************************************/

//	xTaskCreate(vLed_Handler    ,"Led"   ,configMINIMAL_STACK_SIZE,NULL ,1,&xTaskHandle1) ;
//	xTaskCreate(vLed_Handler2    ,"Led2"   ,configMINIMAL_STACK_SIZE,NULL ,2,&xTaskHandle2) ;
//	xTaskCreate(UartRecieve    ,"UART"   ,configMINIMAL_STACK_SIZE,NULL ,3,&xTaskHandle3) ;



	//Initialize UART
	MUSART1_voidInit();

	vTaskStartScheduler() ;


	while (1)
	{

	}

	return 0 ;
}


/* configSUPPORT_STATIC_ALLOCATION is set to 1, so the application must provide an
implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
used by the Idle task. */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    uint32_t *pulIdleTaskStackSize )
{
/* If the buffers to be provided to the Idle task are declared inside this
function then they must be declared static – otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task’s
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task’s stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
/*———————————————————–*/

/* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     uint32_t *pulTimerTaskStackSize )
{
/* If the buffers to be provided to the Timer task are declared inside this
function then they must be declared static – otherwise they will be allocated on
the stack and so not exists after this function exits. */
static StaticTask_t xTimerTaskTCB;
static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task’s state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task’s stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

void vApplicationIdleHook( void )
{
	 /* The parameter value is expected to be 1 as 1 is passed in the
	        pvParameters value in the call to xTaskCreateStatic(). */
	        configASSERT( ( uint32_t ) pvParameters == 1UL );

	        for( ;; )
	        {
	            /* Task code goes here. */
	        	/*prefare to enter save mood by entering idle task */
	        }
}

void vCheck (void* params)
{
	 configASSERT( ( uint32_t ) pvParameters == 1UL );
	//	mot1_ADC = analogRead(CURRENT_SENSE);
	//	    mot1_voltage = mot1_ADC * (5.0 / 1024);
	//	    Serial.print("Motor 1 Current: ");
	//	    Serial.print (mot1_voltage * 26*100);
	//	    Serial.println (" mA");
}


void vUartRecieve (void* params)
{
	 configASSERT( ( uint32_t ) pvParameters == 1UL );
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

		xTaskNotifyGive(MotorHandle);
		xTaskNotifyGive(ServoHandle);
		GlobalDirection = MUSART1_u8Receive();
		vTaskDelay( pdMS_TO_TICKS(500) ) ;

	}

}



void vMotor_Handler (void* params)
{
	 configASSERT( ( uint32_t ) pvParameters == 1UL );

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

void vServo_Handler    (void* params)
{
	 configASSERT( ( uint32_t ) pvParameters == 1UL );
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





