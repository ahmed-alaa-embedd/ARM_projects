/**********************************************************/
/* Author      : Ahmed saeed                                */
/* Date        : 6 october 2020                             */
/* Version     : V01										*/
/* description : systick                                    */
/**********************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void (*Callback) (void);

/* apply clock choise from configuration filebuf
	disable systick interrupt
	disable systick
 */
 
void MSTK_voidInit(void);

void MSTK_SetBusyWait(u32 Copy_u32Ticks); /* NO OF COUNTS */

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr) (void));

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr) (void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);

#endif