/**********************************************************/
/* Author      : Ahmed saeed                                */
/* Date        : 6 october 2020                             */
/* Version     : V01										*/
/* description : systick                                    */
/**********************************************************/
#ifndef STK_PRIVATER_H
#define STK_PRIVATER_H

typedef struct
{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL  ;
}MSTK_TYPE;

#define MSTK ((MSTK_TYPE*)0xE000E010)

#define     MSTK_SRC_AHB           0
#define     MSTK_SRC_AHB_8         1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1


#endif