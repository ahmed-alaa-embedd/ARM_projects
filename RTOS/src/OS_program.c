/***************************/
/*Author : ahmed alaa	*/
/*date : 5/9/2020 		*/
/*version : v01			*/
/***************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STk_interface.h"

#include "OS_Interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL	(void * )0

//array of tasks "Array of structure"
static Task OS_TASKS[NUMBER_OF_TASKS]	= {NULL};


void SOS_VoidCreateTask(u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr)(void), u8 copy_u8FirstDelay)
{

	OS_TASKS[copy_u8ID].priodicity = copy_u16Priodicity ;
	OS_TASKS[copy_u8ID].fprt = ptr ;
	OS_TASKS[copy_u8ID].FirstDelay = copy_u8FirstDelay;

}


void SOS_VoidStart(void)
{
	//Initialization
	MSTK_VoidInit();

	//Tick Time = 1 msec
	// HSE 8MHZ /8  ==> 1000 MicroSec ==> 1 m sec 
	MSTK_VoidSetIntervalPeriodic(1000, Scheduler);

}

volatile u16 TickCounts = 0;

void Scheduler(void)
{
	for (u8 i=0 ; i<NUMBER_OF_TASKS; i++)
	{
		if((TickCounts%OS_TASKS[i].priodicity )== 0)
		{
			OS_TASKS[i].fprt();
		}


	}
	TickCounts++;
}

void SOS_VoidTaskReady(u8 copy_u8ID)
{
	OS_TASKS[copy_u8ID].State=READY;
}
/*
void Scheduler(void)
{
	for (u8 i=0 ; i<NUMBER_OF_TASKS; i++)
	{
		if((OS_TASKS[i].fprt != NULL) && (OS_TASKS[i].State == READY))//for safty
		{
			if(OS_TASKS[i].FirstDelay == 0)
			{
				//replace first delay with priodicity and -1 as we already start 1 time before
				OS_TASKS[i].FirstDelay = OS_TASKS[i].priodicity-1;
				OS_TASKS[i].fprt();
			}
			else
			{
				OS_TASKS[i].FirstDelay--;
			}
		}



	}

}
*/
