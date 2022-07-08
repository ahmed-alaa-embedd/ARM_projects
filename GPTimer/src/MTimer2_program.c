/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 25/9/2020			 	   */
/* version : V01				   */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTimer2_interface.h"
#include "MTimer2_private.h"
#include "MTimer2_config.h"





//Global variable pointer to function
static void (*CALLBACK)(void);

void MTimer6_voidInit()
{
	/*F(TIM2)=8M/(1+PSC)=1MHz
	*Ticks equal 1us*/
	MTimer6 -> PSC = 7;
	// Disable Auto-reload preload (dont wait to reload counter)
	CLR_BIT(MTimer6 -> CR1 ,7);

//#if ONE_PULSE_MODE==ENABLE
//	SET_BIT(MTimer6 -> CR1 , 3);
//
//#elif ONE_PULSE_MODE==DISABLE
//	CLR_BIT(MTimer6 -> CR1 , 3);
//
//#endif

	/*Update request source (URS) bit =>
	Counter overflow/underflow
	Setting the UG bit
	Update generation through the slave mode controller
	*/
	CLR_BIT(MTimer6 -> CR1 ,2);

	//Update disable (UDIS) bit ->  UEV enabled
	CLR_BIT(MTimer6 -> CR1 , 1);

//	//Update DMA request enable
//	SET_BIT(MTimer6 -> DIER ,8);





}

void MTimer6_voidOverFlow()
{
	// SET UG bit =  Re-initializes the timer counter and generates an update of the registers.
	SET_BIT(MTimer6 -> EGR , 0);

}

void MTimer6_VoidSetBusyWait(u32 copy_u32ticks)
{
	/* Load ticks to ARR register */
	MTimer6 -> ARR = copy_u32ticks;

	//no repeate
	SET_BIT(MTimer6 -> CR1,3);

	// Counter enable
	SET_BIT(MTimer6 -> CR1 ,0);

	/* Wait till flag is raised */
	while(GET_BIT(MTimer6 -> SR,0)==0)
	{
		asm("NOP");
	}

}

void MTimer6_VoidSetIntervalSingle(u32 copyu32ticks,void (*copy_ptr)(void))
{
	//Update interrupt enable
	SET_BIT(MTimer6 -> DIER ,0);

	/* Load ticks to ARR register */
	MTimer6 -> ARR = copyu32ticks;

	//no repeate
	CLR_BIT(MTimer6 -> CR1,3);

	// Counter enable
	SET_BIT(MTimer6 -> CR1 ,0);



}
void MTimer6_VoidSetIntervalPeriodic(u32 copyu32ticks,void (*copy_ptr)(void))
{
	//Update interrupt enable
	SET_BIT(MTimer6 -> DIER ,0);

	/* Load ticks to ARR register */
	MTimer6 -> ARR = copyu32ticks;

	//enable repeate
	SET_BIT(MTimer6 -> CR1,3);


	// Counter enable
	SET_BIT(MTimer6 -> CR1 ,0);
}

void TIM6_IRQ_Callback(void)	/*mwgoda f el .c m4 f el main */
{
	CALLBACK();
}



