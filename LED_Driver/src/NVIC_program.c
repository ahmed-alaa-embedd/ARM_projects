/*****************************************/
/*Author    :Hussin Ebrahim              */
/*Version   :V01                         */
/*Date      :19/8/2020                   */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
 
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber){
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
}
void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber){
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
}
void NVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber){
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
}
void NVIC_voidClearPendingFlag (u8 Copy_u8IntNumber){
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
}
u8 NVIC_u8GetActiveFlag(u8 Copy_u8IntNumber){
	u8 local_u8Result=0;
	if ( Copy_u8IntNumber <= 31)
	{
		local_u8Result=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	
	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		local_u8Result=GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	
	else
	{
		/* Return Error */
	}
	return local_u8Result;
}

void NVIC_voidSetPriority(u8 copy_u8GroupID,u8 copy_u8SubID,u8 copy_u8IntID){
#define       SCB_AIRCR       *((u32*)(0xE000ED00+0x0C))

	u8 Local_u8Priority=copy_u8SubID|(copy_u8GroupID<<((NO_OF_GROUPS_SUB-0x05FA0300)/256));
	SCB_AIRCR=NO_OF_GROUPS_SUB;
	NVIC_IPR[copy_u8IntID]=Local_u8Priority<<4;
}
