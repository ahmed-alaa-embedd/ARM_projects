/***************************************************/
/* Author  :Hussin Ebrahim                         */
/* Date    :30/8/2020                              */
/* Version :                                       */
/***************************************************/

#ifndef    STk_PRIVATE_H
#define    STk_PRIVATE_H
 
typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}STK_t;

#define     STK         ((volatile STK_t *)0xE000E010)
/*clock option for STk*/
#define    AHB_DEV_8            0
#define    AHB		            1
/* Bits Description for STK-CTRL */
#define    ENABLE              0
#define    TICKINT             1
#define    CLKSO               2
#define    FLAG                16
/*Interval Mode*/
#define    SINGLE_INTERVAL     0
#define    PERIODIC_INTERVAL   1

#endif
