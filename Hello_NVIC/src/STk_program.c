/***************************/
/*Author : ahmed alaa	*/
/*date : 26/8/2020 		*/
/*version : v02			*/
/***************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STk_interface.h"
#include "STk_config.h"
#include "STk_private.h"



//Global variable pointer to function
void (*CALLBACK)(void);

//Global variable check for repeating delay
u8 STK_Repeat;

void MSTK_VoidInit(void)
{
#if CLKSOURCE==AHB/8	/* Disable counter - Set clock source AHB/8*/

	STK_CTRL = 0 ;
#elif CLKSOURCE==AHB

	STK_CTRL = 0x00000004 ;/* Disable counter - Set clock source AHB*/

#else
	/*REPORT ERROR*/

#endif
}

void MSTK_VoidSetBusyWait(u32 copy_u32ticks)
{
//	copy_u32ticks-=1;

	STK_LOAD = copy_u32ticks; /* Load ticks to load register */

	SET_BIT(STK_CTRL,0) ;	/* start count*/

	/* Wait till flag is raised */
	while(GET_BIT(STK_CTRL,16)==0);

	/*Stop timer and no repeating*/
	STK_CTRL=0;
	STK_LOAD = 0;
	STK_VAL=0;

}


void MSTK_VoidSetIntervalSingle(u32 copyu32ticks,void (*copy_ptr)(void))
{
	STK_LOAD = copyu32ticks; /* Load ticks to load register */

	SET_BIT(STK_CTRL,0) ;	/* start count*/

	SET_BIT(STK_CTRL,1) ;	//enable interrupt

	CALLBACK = copy_ptr;	// point to the passed function

}
void MSTK_VoidSetIntervalPeriodic(u32 copyu32ticks,void (*copy_ptr)(void))
{
	STK_LOAD = copyu32ticks; /* Load ticks to load register */

	SET_BIT(STK_CTRL,0) ;	/* start count*/

	SET_BIT(STK_CTRL,1) ;	//enable interrupt

	CALLBACK = copy_ptr;	// point to the passed function

}
void MSTK_VoidStopInterval(void)
{

}
u32 MSTK_U32GetElapsedTime(void)
{

}
u32 MSTK_U32GetRemainingTime(void)
{

}

//void systick_Handler()	/*mwgoda f el .c m4 f el main */
//{
//
//	if()
//	{
//		/*Stop timer and no repeating*/
//			STK_CTRL=0;
//			STK_LOAD = 0;
//			STK_VAL=0;
//	}
//	CALLBACK();
//}
