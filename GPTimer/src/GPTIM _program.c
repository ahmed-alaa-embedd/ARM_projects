/************************************************/
/* Author 		 :Hussin Ebrahim                 */
/* Date   		 :10/9/2020  					 */
/* modified by   : Ahmed Alaa					 */
/* modified Date : 8/10/2020                   	 */
/* Version		 :V02                            */
/************************************************/ 
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPTIM_interface.h"
#include"GPTIM_private.h"
#include"GPTIM_config.h"

/***********************TIM2****************************/
/*  Clock of TIM2 is APB1_clk(8 MHZ)
   Disable TIM7 interrupt
   Disable TIM6
   F(TIM2)=8M/(1+PSC)
   If PSC=7
	Tick=>1us                 */
void TIM2_voidInit(void)
{
	/*Up Counter Mode*/
	CLR_BIT(TIM2->TCR1,4);
	//	TIM2->TCR1&=~(0b111<<4);
	//	TIM2->TCR1|=(UPCOUNTER<<4);


	/*ARR is Buffered can't changed Execpt at Update Event*/
	SET_BIT(TIM2->TCR1,GPTIM_ARPE);

	/*Only Counter OverFlow UnderFlow Generate update Interrupt */
	SET_BIT(TIM2->TCR1,GPTIM_URS);

	/*Enable Update Event */
	CLR_BIT(TIM2->TCR1,GPTIM_UDIS);

	/*Disable Update Interrupt */
	CLR_BIT(TIM2->TDIER,GPTIM_UIE);

	/*F(TIM2)=8M/(1+PSC)=1MHz
	 *Ticks equal 1us*/
	TIM2->TPSC=7;
}

void TIM2_voidPWMInit(void)
{
	/* Clock division = 1 */
	SET_BIT(TIM2->TCR1,8);

	/* Capture/Compare 4 output enable CC4E */
	SET_BIT(TIM2->TCCER,12);

	/* Capture/Compare 4 output polarity ACTIVE HIGH */
	CLR_BIT(TIM2->TCCER,13);

	/* Output compare 1 mode = PWM MODE   -> OC4M */
	SET_BIT(TIM2->TCCMR2,13);
	SET_BIT(TIM2->TCCMR2,14);

	/* Output compare 1 preload enable OC4PE */
	SET_BIT(TIM2->TCCMR2,11);

	/* PWM freq = (8MHz)Fclk / PSC * ARR  */ // servo psc=19 , ARR= 1000 so frq=421.05 hz
	/* PWM Duty = CCR4 / ARR        */		  // motor psc=400 , ARR= 250 so frq=80 hz



	TIM2->TPSC = 400;
	TIM2->TARR = 250;

	SET_BIT(TIM2->TEGR,0);
	SET_BIT(TIM2->TCR1,0);

}

/* Synchronous API  Lock Processor For Certain Ticks
 *Disable SysTick interrupt
 *enable Systick
 *polling flag (underflow)
 *Tick=>1us*/
void TIM2_voidSetBusyWait( u32 Copy_u32Ticks )
{
	u32 Local_u32Routine=Copy_u32Ticks/65535;
	u32 Local_u32Fraction=Copy_u32Ticks%65535;
	while(Local_u32Routine--)
	{
		TIM2->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM2->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM2->TCR1,GPTIM_CEN);
		while(GET_BIT(TIM2->TSR,GPTIM_UIF)==0);
		/*Clear Uderflow Flag*/
		CLR_BIT(TIM2->TSR,GPTIM_UIF);
	}

	TIM2->TARR=Local_u32Fraction;
	/*Re-Initialize the the counter & prescaller*/
	SET_BIT(TIM2->TEGR,GPTIM_UG);
	/*Enable counter*/
	SET_BIT(TIM2->TCR1,GPTIM_CEN);
	while(GET_BIT(TIM2->TSR,GPTIM_UIF)==0);
	/*Clear Uderflow Flag*/
	CLR_BIT(TIM2->TSR,GPTIM_UIF);
	/*Stop Timer*/
	CLR_BIT(TIM2->TCR1,GPTIM_CEN);



}
void TIM2_voidSetIntervalSingle( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM2_CallBack=Copy_ptr;
	/*Set Mode to Single*/
	TIM2_u8ModeOfInterval=SINGLE_INTERVAL;

	Global2_u32Routine =(Copy_u32Ticks/65535);
	Global2_u32Fraction=Copy_u32Ticks%65535;
	/*    to be initialize before enter the interrupt */
	Global2_u32CopyRoutine=Global2_u32Routine;
	/*stop timer */
	CLR_BIT(TIM2->TCR1,GPTIM_CEN);

	if(Global2_u32Routine)
	{
		TIM2->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM2->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM2->TCR1,GPTIM_CEN);
	}
	else
	{
		TIM2->TARR=Global2_u32Fraction;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM2->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM2->TCR1,GPTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM2->TDIER,GPTIM_UIE);
}
void TIM2_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM2_CallBack=Copy_ptr;
	/*Set Mode to Periodic*/
	TIM2_u8ModeOfInterval=PERIODIC_INTERVAL;

	Global2_u32Routine =(Copy_u32Ticks/65535) ;
	Global2_u32Fraction=Copy_u32Ticks%65535;

	if(Global2_u32Routine)
	{
		TIM2->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM2->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM2->TCR1,GPTIM_CEN);
	}
	else
	{
		TIM2->TARR=Global2_u32Fraction;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM2->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM2->TCR1,GPTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM2->TDIER,GPTIM_UIE);
}

void TIM2_voidStopInterval(void)
{
	//*Disable Update Interrupt
	CLR_BIT(TIM2->TDIER,GPTIM_UIE);
	//*Stop Timer
	CLR_BIT(TIM2->TCR1,GPTIM_CEN);
}
u32  TIM2_u16GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	u16 Local_u16Cycle=Global2_u32Routine - Global2_u32CopyRoutine;

	Local_u32ElapsedTime=((TIM2->TARR)-(TIM2->TCNT))+(Local_u16Cycle*65535);
	return Local_u32ElapsedTime;
}
u32  TIM2_u16GetRemainingTime(void)
{
	u32 local_u32RemainingTime=0;
	if(Global2_u32CopyRoutine>=1)
	{
		local_u32RemainingTime=(TIM2->TCNT)+(Global2_u32CopyRoutine-1)*65535+Global2_u32Fraction;
	}
	else if(Global2_u32CopyRoutine==0)
	{
		local_u32RemainingTime=TIM2->TCNT;
	}
	return local_u32RemainingTime;
}
/***********************TIM3******************************/

/*  Clock of TIM2 is APB1_clk(8 MHZ)
   Disable TIM7 interrupt
   Disable TIM6
   F(TIM2)=8M/(1+PSC)
   If PSC=7
	Tick=>1us                 */

void TIM3_voidInit(void)
{
	/*Up Counter Mode*/
	TIM3->TCR1&=~(0b111<<4);
	TIM3->TCR1|=(DOWNCOUNTER<<4);

	/*ARR is Buffered can't changed Execpt at Update Event*/
	SET_BIT(TIM3->TCR1,GPTIM_ARPE);

	/*Only Counter OverFlow UnderFlow Generate update Interrupt */
	SET_BIT(TIM3->TCR1,GPTIM_URS);

	/*Enable Update Event */
	CLR_BIT(TIM3->TCR1,GPTIM_UDIS);

	/*Disable Update Interrupt */
	CLR_BIT(TIM3->TDIER,GPTIM_UIE);

	/*F(TIM2)=8M/(1+PSC)=1MHz
	 *Ticks equal 1us*/
	TIM3->TPSC=7;
}

void TIM3_voidPWMInit(void)
{
	/* Clock division = 1 */
	SET_BIT(TIM3->TCR1,8);

	/* Capture/Compare 4 output enable CC4E */
	SET_BIT(TIM3->TCCER,12);

	/* Capture/Compare 4 output polarity ACTIVE HIGH */
	CLR_BIT(TIM3->TCCER,13);

	/* Output compare 1 mode = PWM MODE   -> OC4M */
	SET_BIT(TIM3->TCCMR2,13);
	SET_BIT(TIM3->TCCMR2,14);

	/* Output compare 1 preload enable OC4PE */
	SET_BIT(TIM3->TCCMR2,11);

	/* PWM freq = (8MHz)Fclk / PSC * ARR  */ // servo psc=19 , ARR= 1000 so frq=421.05 hz
	/* PWM Duty = CCR4 / ARR        */		  // motor psc=400 , ARR= 250 so frq=80 hz



	TIM2->TPSC = 400;
	TIM2->TARR = 250;

	SET_BIT(TIM3->TEGR,0);
	SET_BIT(TIM3->TCR1,0);

}

/* Synchronous API  Lock Processor For Certain Ticks
 *Disable SysTick interrupt
 *enable Systick
 *polling flag (underflow)
 *Tick=>1us*/
void TIM3_voidSetBusyWait( u32 Copy_u32Ticks )
{
	u32 Local_u32Routine=Copy_u32Ticks/65535;
	u32 Local_u32Fraction=Copy_u32Ticks%65535;
	while(Local_u32Routine--)
	{
		TIM3->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM3->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM3->TCR1,GPTIM_CEN);
		while(GET_BIT(TIM3->TSR,GPTIM_UIF)==0);
		/*Clear Underflow Flag*/
		CLR_BIT(TIM3->TSR,GPTIM_UIF);
	}

	TIM3->TARR=Local_u32Fraction;
	/*Re-Initialize the the counter & prescaller*/
	SET_BIT(TIM3->TEGR,GPTIM_UG);
	/*Enable counter*/
	SET_BIT(TIM3->TCR1,GPTIM_CEN);
	while(GET_BIT(TIM3->TSR,GPTIM_UIF)==0);
	/*Clear Uderflow Flag*/
	CLR_BIT(TIM3->TSR,GPTIM_UIF);
	/*Stop Timer*/
	CLR_BIT(TIM3->TCR1,GPTIM_CEN);



}
void TIM3_voidSetIntervalSingle( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM3_CallBack=Copy_ptr;
	/*Set Mode to Single*/
	TIM3_u8ModeOfInterval=SINGLE_INTERVAL;

	Global3_u32Routine =(Copy_u32Ticks/65535);
	Global3_u32Fraction=Copy_u32Ticks%65535;
	/*    to be initialize before enter the interrupt */
	Global3_u32CopyRoutine=Global3_u32Routine;
	/*stop timer */
	CLR_BIT(TIM3->TCR1,GPTIM_CEN);

	if(Global3_u32Routine)
	{
		TIM3->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM3->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM3->TCR1,GPTIM_CEN);
	}
	else
	{
		TIM3->TARR=Global3_u32Fraction;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM3->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM3->TCR1,GPTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM3->TDIER,GPTIM_UIE);
}
void TIM3_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM3_CallBack=Copy_ptr;
	/*Set Mode to Periodic*/
	TIM3_u8ModeOfInterval=PERIODIC_INTERVAL;

	Global3_u32Routine =(Copy_u32Ticks/65535) ;
	Global3_u32Fraction=Copy_u32Ticks%65535;

	if(Global3_u32Routine)
	{
		TIM3->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM3->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM3->TCR1,GPTIM_CEN);
	}
	else
	{
		TIM3->TARR=Global3_u32Fraction;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM3->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM3->TCR1,GPTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM3->TDIER,GPTIM_UIE);
}

void TIM3_voidStopInterval(void)
{
	//*Disable Update Interrupt
	CLR_BIT(TIM3->TDIER,GPTIM_UIE);
	//*Stop Timer
	CLR_BIT(TIM3->TCR1,GPTIM_CEN);
}
u32  TIM3_u16GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	u16 Local_u16Cycle=Global3_u32Routine - Global3_u32CopyRoutine;

	Local_u32ElapsedTime=((TIM3->TARR)-(TIM3->TCNT))+(Local_u16Cycle*65535);
	return Local_u32ElapsedTime;
}
u32  TIM3_u16GetRemainingTime(void)
{
	u32 local_u32RemainingTime=0;
	if(Global3_u32CopyRoutine>=1)
	{
		local_u32RemainingTime=(TIM3->TCNT)+(Global3_u32CopyRoutine-1)*65535+Global3_u32Fraction;
	}
	else if(Global3_u32CopyRoutine==0)
	{
		local_u32RemainingTime=TIM3->TCNT;
	}
	return local_u32RemainingTime;
}
/**********************TIM4*********************************/

/*  Clock of TIM2 is APB1_clk(8 MHZ)
   Disable TIM7 interrupt
   Disable TIM6
   F(TIM2)=8M/(1+PSC)
   If PSC=7
	Tick=>1us                 */
void TIM4_voidInit(void)
{
	/*Up Counter Mode*/
	TIM4->TCR1&=~(0b111<<4);
	TIM4->TCR1|=(DOWNCOUNTER<<4);

	/*ARR is Buffered can't changed Execpt at Update Event*/
	SET_BIT(TIM4->TCR1,GPTIM_ARPE);

	/*Only Counter OverFlow UnderFlow Generate update Interrupt */
	SET_BIT(TIM4->TCR1,GPTIM_URS);

	/*Enable Update Event */
	CLR_BIT(TIM4->TCR1,GPTIM_UDIS);

	/*Disable Update Interrupt */
	CLR_BIT(TIM4->TDIER,GPTIM_UIE);

	/*F(TIM2)=8M/(1+PSC)=1MHz
	 *Ticks equal 1us*/
	TIM4->TPSC=7;
}

void TIM4_voidPWMInit(void)
{
	/* Clock division = 1 */
	SET_BIT(TIM4->TCR1,8);

	/* Capture/Compare 4 output enable CC4E */
	SET_BIT(TIM4->TCCER,12);

	/* Capture/Compare 4 output polarity ACTIVE HIGH */
	CLR_BIT(TIM4->TCCER,13);

	/* Output compare 1 mode = PWM MODE   -> OC4M */
	SET_BIT(TIM4->TCCMR2,13);
	SET_BIT(TIM4->TCCMR2,14);

	/* Output compare 1 preload enable OC4PE */
	SET_BIT(TIM4->TCCMR2,11);

	/* PWM freq = (8MHz)Fclk / PSC * ARR  */ // servo psc=19 , ARR= 1000 so frq=421.05 hz
	/* PWM Duty = CCR4 / ARR        */		  // motor psc=400 , ARR= 250 so frq=80 hz



	TIM2->TPSC = 19;
	TIM2->TARR = 1000;

	SET_BIT(TIM4->TEGR,0);
	SET_BIT(TIM4->TCR1,0);

}


/* Synchronous API  Lock Processor For Certain Ticks
 *Disable SysTick interrupt
 *enable Systick
 *polling flag (underflow)
 *Tick=>1us*/
void TIM4_voidSetBusyWait( u32 Copy_u32Ticks )
{
	u32 Local_u32Routine=Copy_u32Ticks/65535;
	u32 Local_u32Fraction=Copy_u32Ticks%65535;
	while(Local_u32Routine--)
	{
		TIM4->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM4->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM4->TCR1,GPTIM_CEN);
		while(GET_BIT(TIM4->TSR,GPTIM_UIF)==0);
		/*Clear Uderflow Flag*/
		CLR_BIT(TIM4->TSR,GPTIM_UIF);
	}

	TIM4->TARR=Local_u32Fraction;
	/*Re-Initialize the the counter & prescaller*/
	SET_BIT(TIM4->TEGR,GPTIM_UG);
	/*Enable counter*/
	SET_BIT(TIM4->TCR1,GPTIM_CEN);
	while(GET_BIT(TIM4->TSR,GPTIM_UIF)==0);
	/*Clear Uderflow Flag*/
	CLR_BIT(TIM4->TSR,GPTIM_UIF);
	/*Stop Timer*/
	CLR_BIT(TIM4->TCR1,GPTIM_CEN);



}
void TIM4_voidSetIntervalSingle( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM4_CallBack=Copy_ptr;
	/*Set Mode to Single*/
	TIM4_u8ModeOfInterval=SINGLE_INTERVAL;

	Global4_u32Routine =(Copy_u32Ticks/65535);
	Global4_u32Fraction=Copy_u32Ticks%65535;
	/*    to be initialize before enter the interrupt */
	Global4_u32CopyRoutine=Global4_u32Routine;
	/*stop timer */
	CLR_BIT(TIM4->TCR1,GPTIM_CEN);

	if(Global4_u32Routine)
	{
		TIM4->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM4->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM4->TCR1,GPTIM_CEN);
	}
	else
	{
		TIM4->TARR=Global4_u32Fraction;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM4->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM4->TCR1,GPTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM4->TDIER,GPTIM_UIE);
}
void TIM4_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*save CallBack*/
	TIM4_CallBack=Copy_ptr;
	/*Set Mode to Periodic*/
	TIM4_u8ModeOfInterval=PERIODIC_INTERVAL;

	Global4_u32Routine =(Copy_u32Ticks/65535) ;
	Global4_u32Fraction=Copy_u32Ticks%65535;

	if(Global4_u32Routine)
	{
		TIM4->TARR=65535;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM4->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM4->TCR1,GPTIM_CEN);
	}
	else
	{
		TIM4->TARR=Global2_u32Fraction;
		/*Re-Initialize the the counter & prescaller*/
		SET_BIT(TIM4->TEGR,GPTIM_UG);
		/*Enable counter*/
		SET_BIT(TIM4->TCR1,GPTIM_CEN);
	}

	/*Enable Update Interrupt */
	SET_BIT(TIM4->TDIER,GPTIM_UIE);
}

void TIM4_voidStopInterval(void)
{
	//*Disable Update Interrupt
	CLR_BIT(TIM4->TDIER,GPTIM_UIE);
	//*Stop Timer
	CLR_BIT(TIM4->TCR1,GPTIM_CEN);
}
u32  TIM4_u16GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	u16 Local_u16Cycle=Global4_u32Routine - Global4_u32CopyRoutine;

	Local_u32ElapsedTime=((TIM4->TARR)-(TIM4->TCNT))+(Local_u16Cycle*65535);
	return Local_u32ElapsedTime;
}
u32  TIM4_u16GetRemainingTime(void)
{
	u32 local_u32RemainingTime=0;

	if(Global4_u32CopyRoutine>=1)
	{
		local_u32RemainingTime=(TIM4->TCNT)+(Global4_u32CopyRoutine-1)*65535+Global4_u32Fraction;
	}
	else if(Global4_u32CopyRoutine==0)
	{
		local_u32RemainingTime=TIM4->TCNT;
	}
	return local_u32RemainingTime;
}
/**************************TIM5**********************/

/*  Clock of TIM2 is APB1_clk(8 MHZ)
   Disable TIM7 interrupt
   Disable TIM6                        
   F(TIM2)=8M/(1+PSC)
   If PSC=7
	Tick=>1us                 */

//**********************TIM2****************************
void TIM2_IRQHandler(void)
{
	if(Global2_u8Flag){
		Global2_u32CopyRoutine=Global2_u32Routine;
		Global2_u8Flag=0;
	}

	//Local_u32Routine=Global_u32Routine;
	if((Global2_u32CopyRoutine)>1)
	{
		Global2_u32CopyRoutine--;
		//Clear Uderflow Flag
		CLR_BIT(TIM2->TSR,GPTIM_UIF);
		TIM2->TARR=65535;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM2->TEGR,GPTIM_UG);

	}
	else if((Global2_u32CopyRoutine)==1)
	{
		Global2_u32CopyRoutine--;
		//*Clear Uderflow Flag
		CLR_BIT(TIM2->TSR,GPTIM_UIF);
		TIM2->TARR=Global2_u32Fraction;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM2->TEGR,GPTIM_UG);

	}
	else
	{
		if(TIM2_u8ModeOfInterval==SINGLE_INTERVAL)
		{
			//*Disable Update Interrupt
			CLR_BIT(TIM2->TDIER,GPTIM_UIE);
			//*Stop Timer
			CLR_BIT(TIM2->TCR1,GPTIM_CEN);
		}
		//*Callback Notification
		TIM2_CallBack();
		//Clear Uderflow Flag/
		CLR_BIT(TIM2->TSR,GPTIM_UIF);

		if(Global2_u32Routine)TIM2->TARR=65535;
		else TIM2->TARR=Global2_u32Fraction;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM2->TEGR,GPTIM_UG);

		Global2_u8Flag=1;
	}

}

/**************TIM3***********************/
void TIM3_IRQHandler(void)
{
	if(Global3_u8Flag){
		Global3_u32CopyRoutine=Global3_u32Routine;
		Global3_u8Flag=0;
	}
	if((Global3_u32CopyRoutine)>1)
	{
		Global3_u32CopyRoutine--;
		//Clear Uderflow Flag
		CLR_BIT(TIM3->TSR,GPTIM_UIF);
		TIM3->TARR=65535;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM3->TEGR,GPTIM_UG);

	}
	else if((Global3_u32CopyRoutine)==1)
	{
		Global3_u32CopyRoutine--;
		//*Clear Uderflow Flag
		CLR_BIT(TIM3->TSR,GPTIM_UIF);
		TIM3->TARR=Global3_u32Fraction;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM3->TEGR,GPTIM_UG);

	}
	else
	{
		if(TIM3_u8ModeOfInterval==SINGLE_INTERVAL)
		{
			//*Disable Update Interrupt
			CLR_BIT(TIM3->TDIER,GPTIM_UIE);
			//*Stop Timer
			CLR_BIT(TIM3->TCR1,GPTIM_CEN);
		}
		//*Callback Notification
		TIM3_CallBack();
		//Clear Uderflow Flag/
		CLR_BIT(TIM3->TSR,GPTIM_UIF);

		if(Global3_u32Routine)TIM3->TARR=65535;
		else TIM3->TARR=Global3_u32Fraction;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM3->TEGR,GPTIM_UG);

		Global3_u8Flag=1;
	}

}

//**************TIM4***********************
void TIM4_IRQHandler(void)
{
	if(Global4_u8Flag){
		Global4_u32CopyRoutine=Global4_u32Routine;
		Global4_u8Flag=0;
	}
	if((Global4_u32CopyRoutine)>1)
	{
		Global4_u32CopyRoutine--;
		//Clear Uderflow Flag
		CLR_BIT(TIM4->TSR,GPTIM_UIF);
		TIM4->TARR=65535;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM4->TEGR,GPTIM_UG);

	}
	else if((Global4_u32CopyRoutine)==1)
	{
		Global4_u32CopyRoutine--;
		//*Clear Uderflow Flag
		CLR_BIT(TIM4->TSR,GPTIM_UIF);
		TIM4->TARR=Global4_u32Fraction;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM4->TEGR,GPTIM_UG);

	}
	else
	{
		if(TIM4_u8ModeOfInterval==SINGLE_INTERVAL)
		{
			//*Disable Update Interrupt
			CLR_BIT(TIM4->TDIER,GPTIM_UIE);
			//*Stop Timer
			CLR_BIT(TIM4->TCR1,GPTIM_CEN);
		}
		//*Callback Notification
		TIM4_CallBack();
		//Clear Uderflow Flag/
		CLR_BIT(TIM4->TSR,GPTIM_UIF);

		if(Global4_u32Routine)TIM4->TARR=65535;
		else TIM4->TARR=Global4_u32Fraction;
		//*Re-Initialize the the counter & prescaller
		SET_BIT(TIM4->TEGR,GPTIM_UG);

		Global4_u8Flag=1;
	}

}

void PWM_Angle(u8 Copy_u8Angle,u8 Copy_u8TimerType)
{
	if(Copy_u8TimerType == TIM2)
	{
		switch (Copy_u8Angle)
		{
		case 0:  TIM2->TCCR4 = 60; break;
		case 45:  TIM2->TCCR4 = 90; break;
		case 90:  TIM2->TCCR4 = 120; break;
		case 135:  TIM2->TCCR4 = 180; break;
		case 180:  TIM2->TCCR4 = 240; break;
		case 200:  TIM2->TCCR4 = 200; break;
		case 250:  TIM2->TCCR4 = 250; break;
		default:
			break;
		}
	}
	if(Copy_u8TimerType == TIM3)
	{
		switch (Copy_u8Angle)
		{
		case 0:  TIM3->TCCR4 = 60; break;
		case 45:  TIM3->TCCR4 = 90; break;
		case 90:  TIM3->TCCR4 = 120; break;
		case 135:  TIM3->TCCR4 = 180; break;
		case 180:  TIM3->TCCR4 = 240; break;
		case 200:  TIM3->TCCR4 = 200; break;
		case 250:  TIM3->TCCR4 = 250; break;

		default:
			break;
		}
	}
	if(Copy_u8TimerType == TIM4)
	{


		switch (Copy_u8Angle)
		{
		case 0:  TIM4->TCCR4 = 60; break;
		case 45:  TIM4->TCCR4 = 90; break;
		case 90:  TIM4->TCCR4 = 120; break;
		case 135:  TIM4->TCCR4 = 180; break;
		case 180:  TIM4->TCCR4 = 240; break;
		case 250:  TIM4->TCCR4 = 250; break;
		default:
			break;
		}
	}
}


