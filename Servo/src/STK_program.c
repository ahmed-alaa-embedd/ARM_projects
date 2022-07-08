/**********************************************************/
/* Author      : Ahmed saeed                                */
/* Date        : 6 october 2020                             */
/* Version     : V01										*/
/* description : systick                                    */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	#if MSTK_CLK_SRC == MSTK_SRC_AHB
		MSTK -> CTRL  = 0x00000004; /* disable stk , disable interrupt, clk sourc AHB */
		#else
		MSTK -> CTRL  = 0x00000000; /* disable stk , disable interrupt, clk sourc AHB/8 */
	#endif
}

void MSTK_SetBusyWait(u32 Copy_u32Ticks)
{	
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* enable systick */
	SET_BIT(MSTK->CTRL,0);
	/* Wait till flag is raised */
	while((GET_BIT(MSTK->CTRL,16)) == 0);
	
	/* STOP TIMER */
	CLR_BIT(MSTK->CTRL,0);
	MSTK -> LOAD = 0;
	MSTK -> VAL = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	
	/* enable systick */
	SET_BIT(MSTK->CTRL,0);

	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;

	/* enable interrupt*/
	SET_BIT(MSTK->CTRL,1);	
	
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void))
{
	/* load ticks in load register */
	MSTK -> LOAD = Copy_u32Ticks;
	
	/* ENABLE SYSTICK */
	SET_BIT(MSTK->CTRL,0);
	
	/* SAVE CALLBACK */
	MSTK_CallBack = Copy_ptr;
	
	/* set mode to interval */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	
	/* enable interrupt */
	SET_BIT(MSTK->CTRL,1);
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)  // interrupt for once
	{
		/* disable interrupt */
		CLR_BIT(MSTK->CTRL,1);
		
		/* STOP TIMER */
		CLR_BIT(MSTK->CTRL,0);
		MSTK->LOAD = 0;
		MSTK->VAL  = 0;
	}
	MSTK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(MSTK->CTRL,16);
}

void MSTK_voidStopInterval(void)
{
	/* disable interrupt */
		CLR_BIT(MSTK->CTRL,1);
		
	/* STOP TIMER */
		CLR_BIT(MSTK->CTRL,0);
		MSTK->LOAD = 0;
		MSTK->VAL  = 0;
}

u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	/* HOW TIME I COUNT IT FROM MY TIME*/
	Local_u32ElapsedTime = MSTK->LOAD - MSTK->VAL;
	
	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainingTime;
	/* how time remain to reach to zero*/
	Local_u32RemainingTime = MSTK->VAL;
	return Local_u32RemainingTime;
}
