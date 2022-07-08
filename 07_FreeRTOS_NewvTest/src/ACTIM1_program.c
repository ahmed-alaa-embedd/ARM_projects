/************************************************/
/* Author : Ahmed	Alaa                        */
/* Date   : 7/10/2020                           */
/* Version: V02                                 */
/************************************************/

/*********Liberary**********/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**********MCAL****************/
#include "ACTIM1_interface.h"
#include "ACTIM1_private.h"
#include "ACTIM1_config.h"



/*  Clock of TIM2 is APB1_clk(8 MHZ)
   Disable TIM7 interrupt
   Disable TIM6
   F(TIM2)=8M/(1+PSC)
   If PSC=7
	Tick=>1us                 */
void TIM1_voidInit(void)
{
	/*Up Counter Mode*/
	TIM1->CR1&=~(0b111<<4);
	TIM1->CR1|=(DOWNCOUNTER1<<4);

	/*ARR is Buffered can't changed Execpt at Update Event*/
	SET_BIT(TIM1->CR1,ACTIM_ARPE);

	/*Only Counter OverFlow UnderFlow Generate update Interrupt */
	SET_BIT(TIM1->CR1,ACTIM_URS);

	/*Enable Update Event */
	CLR_BIT(TIM1->CR1,ACTIM_UDIS);

	/*Disable Update Interrupt */
	CLR_BIT(TIM1->DIER,ACTIM_UIE);

	/*F(TIM2)=8M/(1+PSC)=1MHz
	*Ticks equal 1us*/
	TIM1->PSC=7;
}
/* Synchronous API  Lock Processor For Certain Ticks
   *Disable SysTick interrupt
   *enable Systick
   *polling flag (underflow)
   *Tick=>1us*/
void TIM1_voidSetBusyWait( u32 Copy_u32Ticks )
{
	u32 Local_u32Routine=Copy_u32Ticks/65535;
	u32 Local_u32Fraction=Copy_u32Ticks%65535;
	while(Local_u32Routine--)
	{
		TIM1->ARR=65535;
	    /*Re-Initialize the the counter & prescaller*/
	    SET_BIT(TIM1->EGR,ACTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM1->CR1,ACTIM_CEN);
		while(GET_BIT(TIM1->SR,ACTIM_UIF)==0);
		/*Clear Uderflow Flag*/
		CLR_BIT(TIM1->SR,ACTIM_UIF);
	}

	TIM1->ARR=Local_u32Fraction;
	/*Re-Initialize the the counter & prescaller*/
	SET_BIT(TIM1->EGR,ACTIM_UG);
	/*Enable counter*/
	SET_BIT(TIM1->CR1,ACTIM_CEN);
	while(GET_BIT(TIM1->SR,ACTIM_UIF)==0);
	/*Clear Uderflow Flag*/
	CLR_BIT(TIM1->SR,ACTIM_UIF);
	/*Stop Timer*/
	CLR_BIT(TIM1->CR1,ACTIM_CEN);



}
void TIM1_voidSetIntervalSingle( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM1_CallBack=Copy_ptr;
	/*Set Mode to Single*/
	TIM1_u8ModeOfInterval=SINGLE1_INTERVAL;

	Global1_u32Routine =(Copy_u32Ticks/65535);
	Global1_u32Fraction=Copy_u32Ticks%65535;
	/*    to be initialize before enter the interrupt */
	Global1_u32CopyRoutine=Global1_u32Routine;
	/*stop timer */
	CLR_BIT(TIM1->CR1,ACTIM_CEN);

	if(Global1_u32Routine)
	{
		TIM1->ARR=65535;
	    /*Re-Initialize the the counter & prescaller*/
	    SET_BIT(TIM1->EGR,ACTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM1->CR1,ACTIM_CEN);
	}
	else
	{
		TIM1->ARR=Global1_u32Fraction;
	    /*Re-Initialize the the counter & prescaller*/
	    SET_BIT(TIM1->EGR,ACTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM1->CR1,ACTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM1->DIER,ACTIM_UIE);
}
void TIM1_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM1_CallBack=Copy_ptr;
	/*Set Mode to Periodic*/
	TIM1_u8ModeOfInterval=PERIODIC1_INTERVAL;

	Global1_u32Routine =(Copy_u32Ticks/65535) ;
	Global1_u32Fraction=Copy_u32Ticks%65535;

	if(Global1_u32Routine)
	{
		TIM1->ARR=65535;
	    /*Re-Initialize the the counter & prescaller*/
	    SET_BIT(TIM1->EGR,ACTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM1->CR1,ACTIM_CEN);
	}
	else
	{
		TIM1->ARR=Global1_u32Fraction;
	    /*Re-Initialize the the counter & prescaller*/
	    SET_BIT(TIM1->EGR,ACTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM1->CR1,ACTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM1->DIER,ACTIM_UIE);
}

void TIM1_voidStopInterval(void)
{
	//*Disable Update Interrupt
    CLR_BIT(TIM1->DIER,ACTIM_UIE);
	//*Stop Timer
	CLR_BIT(TIM1->CR1,ACTIM_CEN);
}
u32  TIM1_u16GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	u16 Local_u16Cycle=Global1_u32Routine - Global1_u32CopyRoutine;

	Local_u32ElapsedTime=((TIM1->ARR)-(TIM1->CNT))+(Local_u16Cycle*65535);
	return Local_u32ElapsedTime;
}
u32  TIM1_u16GetRemainingTime(void)
{
	u32 local_u32RemainingTime=0;
	if(Global1_u32CopyRoutine>=1)
	{
		local_u32RemainingTime=(TIM1->CNT)+(Global1_u32CopyRoutine-1)*65535+Global1_u32Fraction;
	}
	else if(Global1_u32CopyRoutine==0)
	{
		local_u32RemainingTime=TIM1->CNT;
	}
	return local_u32RemainingTime;
}

void TIM1_UP_IRQHandler(void)
{
	if(Global1_u8Flag){
		Global1_u32CopyRoutine=Global1_u32Routine;
		Global1_u8Flag=0;
	}

	//Local_u32Routine=Global_u32Routine;
	if((Global1_u32CopyRoutine)>1)
	{
		Global1_u32CopyRoutine--;
		//Clear Uderflow Flag
		CLR_BIT(TIM1->SR,ACTIM_UIF);
		TIM1->ARR=65535;
	    //*Re-Initialize the the counter & prescaller
	    SET_BIT(TIM1->EGR,ACTIM_UG);

	}
	else if((Global1_u32CopyRoutine)==1)
	{
		Global1_u32CopyRoutine--;
		//*Clear Uderflow Flag
		CLR_BIT(TIM1->SR,ACTIM_UIF);
		TIM1->ARR=Global1_u32Fraction;
	    //*Re-Initialize the the counter & prescaller
	    SET_BIT(TIM1->EGR,ACTIM_UG);

	}
	else
	{
		if(TIM1_u8ModeOfInterval==SINGLE1_INTERVAL)
		{
			//*Disable Update Interrupt
	        CLR_BIT(TIM1->DIER,ACTIM_UIE);
			//*Stop Timer
			CLR_BIT(TIM1->CR1,ACTIM_CEN);
		}
		//*Callback Notification
		TIM1_CallBack();
		//Clear Uderflow Flag/
		CLR_BIT(TIM1->SR,ACTIM_UIF);

		if(Global1_u32Routine)TIM1->ARR=65535;
		else TIM1->ARR=Global1_u32Fraction;
	    //*Re-Initialize the the counter & prescaller
	    SET_BIT(TIM1->EGR,ACTIM_UG);

		Global1_u8Flag=1;
	}

}
