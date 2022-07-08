/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 25/9/2020			 	   */
/* version : V01				   */
/***********************************/


#ifndef MTIMER6_interface_H
#define MTIMER6_interface_H

void MTimer6_voidInit();
void MTimer6_voidCounter();
void MTimer6_VoidSetBusyWait(u32 copy_u32ticks);

/*give u interrupt that ticks end
	takes time and function that return to after end*/
void MTimer6_VoidSetIntervalSingle(u32 copyu32ticks,void (*copy_ptr)(void));
void MTimer6_VoidSetIntervalPeriodic(u32 copyu32ticks,void (*copy_ptr)(void));
void MTimer6_VoidStopInterval(void);
u32 MTimer6_U32GetElapsedTime(void);
u32 MTimer6_U32GetRemainingTime(void);

void MTimer6_voidOverFlow();



#endif
