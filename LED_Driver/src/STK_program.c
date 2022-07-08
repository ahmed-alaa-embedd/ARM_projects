/***************************************************/
/* Author  :Hussin Ebrahim                         */
/* Date    :30/8/2020                              */
/* Version :                                       */
/***************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"STK_interface.h"
#include"STK_private.h"
#include"STK_config.h"
static u32 Global_u32Fix=0;

/* Define Callback Global Variable */
static void (*STK_CallBack)(void);
/* Define Variable for interval mode */
static u8 Global_u8ModeOfInterval;
/* Apply Clock choice from configuration file 
   Disable SysTick interrupt 
   Disable Systick                          */
void STK_voidInit(void)
{
	CLR_BIT(STK->CTRL,ENABLE);  /*diable counter   */
	CLR_BIT(STK->CTRL,TICKINT); /*diable Interrupt */
	
	#if      STK_CLOCk_SOURCE==AHB_DIV_8
		CLR_BIT(STK->CTRL,CLKSO); 
	#elif    STK_CLOCk_SOURCE==AHB
	    SET_BIT(STK->CTRL,CLKSO); 
	#else 	
		#error "Wrong Clock Choice"
	#endif	
}
/* Synchronous API  Lock Processor For Certain Ticks
   Disable SysTick interrupt                           
   enable Systick
   polling flag (underflow)	                    */
void STK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	if(STK->VAL !=0)
	{
		Global_u32Fix=STK->VAL;
		/*Stop Timer*/
		CLR_BIT(STK->CTRL,ENABLE);
		STK->LOAD=0;
		STK->VAL=0;
	}
	else Global_u32Fix=0;
	/*Load Ticks To LoadRegister*/
	STK->LOAD=Copy_u32Ticks;
     /*Start Timer   */
	SET_BIT(STK->CTRL,ENABLE); 
    /* Wait till flag is raised */	
	while(GET_BIT(STK->CTRL,FLAG)==0)
		{asm("NOP");}
	if(Global_u32Fix==0)
	{
		/*Stop Timer*/
			CLR_BIT(STK->CTRL,ENABLE);
			STK->LOAD=0;
			STK->VAL=0;
	}
	else
	{
		STK->LOAD=Global_u32Fix;
	}

	
}
void STK_voidSetIntervalSingle ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	 /*stop timer*/
	CLR_BIT(STK->CTRL,ENABLE);
	STK -> VAL = 0;
	/*save CallBack*/
	STK_CallBack=Copy_ptr;
	/*Load Ticks To LoadRegister*/
	STK->LOAD=Copy_u32Ticks;
    /*enable Interrupt */	
	SET_BIT(STK->CTRL,TICKINT); 
	/*Set Mode to Single*/
	Global_u8ModeOfInterval=SINGLE_INTERVAL;
	 /*Start timer*/
	SET_BIT(STK->CTRL,ENABLE); 
}

void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
		/*save CallBack*/
	STK_CallBack=Copy_ptr;
	/*Load Ticks To LoadRegister*/
	STK->LOAD=Copy_u32Ticks;
    /*enable Interrupt */	
	SET_BIT(STK->CTRL,TICKINT); 
	/*Set Mode to Periodic*/
	Global_u8ModeOfInterval=PERIODIC_INTERVAL;
	 /*Start timer*/
	SET_BIT(STK->CTRL,ENABLE); 
}

void STK_voidStopInterval(void)
{
		/*Disable Interrupt*/
		CLR_BIT(STK->CTRL,TICKINT);
		/*Stop Timer*/
		CLR_BIT(STK->CTRL,ENABLE);
	    STK->LOAD=0;
	    STK->VAL=0;
}

u32  STK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime=(STK->LOAD)-(STK->VAL);
	return Local_u32ElapsedTime; 
}
u32  STK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	Local_u32RemainTime=(STK->VAL);
	return Local_u32RemainTime; 
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary=0;
	if(Global_u8ModeOfInterval==SINGLE_INTERVAL)
	{
		/*Disable Interrupt*/
		CLR_BIT(STK->CTRL,TICKINT);
		/*Stop Timer*/
		CLR_BIT(STK->CTRL,ENABLE);
	    STK->LOAD=0;
	    STK->VAL=0;
	}
    /*Callback Notification*/	
	STK_CallBack();
	/*Clear Interrupt Flag*/
	Local_u8Temporary=GET_BIT(STK->CTRL,FLAG);
}
