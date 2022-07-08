/*
 * main.c
 *
 *  Created on: 	Aug 13, 2020
 *      Author: 	mosad
 *  modifyed by :	Ahmed Alaa
 *  modifyed date:	28/9/2020
 *  version	:		v01
 */

/************* Includes ***************/
/* Library */
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GPIO_int.h"
#include "RCC_interface.h"
#include "STk_interface.h"
#include "SPI_interface.h"

/* Hal */
#include "TFTClock_interface.h"

/**************** Prototypes *****************/
void voidClockMainScreen (void);
void counting( void );
void voidUpdateDate (void);


/**************** Data types ******************/
typedef enum {
	CLOCK_AM ,
	CLOCK_PM
}CLK_state_t;

/************* Global variables ******************/
volatile u8 global_u8SecondsCounter = 10 ;
volatile u8 global_u8MinCounter = 12;
volatile u8 global_u8HoursCounter = 05 ;
volatile u8 global_u8DaysCounter = 9 ;
volatile u8 global_u8MonCounter = 10 ;
volatile u16 global_u16YearCounter = 2020 ;
volatile u16 global_u8DayIndex = 0 ;
volatile CLK_state_t global_state = CLOCK_PM ;

const u8 *days[7] = {"FRI" , "SAT" , "SUN" , "MON" , "TUS" , "WED" , "THUR" };

/************** APP functions ************/
void main(void){

	/* Initialize the RCC to HSE */
	RCC_voidInitSysClock();
//	/* Enable the clock for all ports */
	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA
	RCC_voidEnableClock(RCC_APB2, 12); // Enable clock for SPI1

//	/* Configure pins for SPI */

	MGPIO_VoidSetPinDirection(GPIOA , PIN5 , OUTPUT_SPEED_10MHZ_AFPP);	//CLK
	MGPIO_VoidSetPinDirection(GPIOA , PIN7 , OUTPUT_SPEED_10MHZ_AFPP);	//MOSI



//	/* Configure pins for TFT */
	MGPIO_VoidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP); //A0
	MGPIO_VoidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);	//RST

	/* Initialize STK */
	MSTK_VoidInit();	// clk=AHB/8 = 1MHz

	//Initalise SPI
	MSPI1_voidInit();

	/* Initialize TFT */
	HTFT_voidInitialize(); // byzhr n8m4a lw 3mlt build XD

	/* Set Background */
	/*white > 0
	 *black >ffff*/
	TFT_voidFillDisplay(0);

	/* Set main screen */
	voidClockMainScreen();

	/* Set the timing task */
	MSTK_VoidSetIntervalPeriodic(1000000, counting);
	while(1){

	}

}

/* The opening screen */
void voidClockMainScreen (void)
{
	s8 loacl_s8TimeBuffer[20] ;
	s8 loacl_s8DateBuffer[20] ;
	/* Header */
	TFT_voidPrintText( "Digital"  , 20 , 0  , 2 ,TFT_BLUE , TFT_BLACK);
	TFT_voidPrintText( " CLOCK" , 20 , 30 , 2 ,TFT_BLUE,TFT_BLACK );

	/* Line */
//	TFT_voidDrawRectangle(0 , 55 , 127 , 5 , TFT_GREEN);

	/* Time */
	sprintf(loacl_s8TimeBuffer, "%.2i:%.2i:%.2iAM", global_u8HoursCounter , global_u8MinCounter ,global_u8SecondsCounter );
	TFT_voidPrintText( loacl_s8TimeBuffer , 0 , 60 , 2,TFT_RED,TFT_BLACK );

	/* Line  2*/
//	TFT_voidDrawRectangle(0 , 85 , 127 , 5 , TFT_GREEN);

	/* Date */
	sprintf(loacl_s8DateBuffer, "%.2i/%.2i/%.4i", global_u8DaysCounter , global_u8MonCounter ,global_u16YearCounter);
	TFT_voidPrintText( loacl_s8DateBuffer , 0 , 90 , 2,TFT_ORANGE,TFT_BLACK );

	/* Line 3 */
//	TFT_voidDrawRectangle(0 , 115 , 127 , 5 , TFT_GREEN);

	/* Day */
	TFT_voidPrintText(days[global_u8DayIndex] , 40 , 120 , 2,TFT_GREEN ,TFT_BLACK);
}

/* Counting task  , triggered by STK ISR every 1000 ms */
void counting( void ){
	global_u8SecondsCounter++;
	/* One minute passed */
	if (global_u8SecondsCounter == 60){
		global_u8MinCounter++;
		global_u8SecondsCounter = 0 ;

		/* One hour passed */
		if (global_u8MinCounter == 60){
			global_u8MinCounter = 0 ;
			global_u8HoursCounter++;

			/* One days passed */
			if (global_u8HoursCounter == 12){
				switch (global_state){
					case CLOCK_PM :
						/* Update the data values */
						voidUpdateDate();
						global_state = CLOCK_AM ;
						break ;
					case CLOCK_AM : global_state = CLOCK_PM ; break ;
				}
			}
			if (global_u8HoursCounter == 13){
				global_u8HoursCounter = 1 ;

			}
		}
	}

	/* Output the result */
	s8 loacl_s8Buffer[20] ;
	switch (global_state){
		case CLOCK_PM :
			sprintf(loacl_s8Buffer, "%.2i:%.2i:%.2iPM", global_u8HoursCounter , global_u8MinCounter ,global_u8SecondsCounter  );
			break ;
		case CLOCK_AM :
			sprintf(loacl_s8Buffer, "%.2i:%.2i:%.2iAM", global_u8HoursCounter , global_u8MinCounter ,global_u8SecondsCounter  );
			break ;
	}

	TFT_voidPrintText( loacl_s8Buffer , 0 , 60 , 2,TFT_RED,TFT_BLACK );
}



void voidUpdateDate (void)
{
	s8 loacl_s8DateBuffer[20] ;
	/* Increment to the next day name */
	global_u8DayIndex++;
	if (global_u8DayIndex == 7 ){
		global_u8DayIndex = 0 ;
	}

	global_u8DaysCounter++;
	/* Month passed */
	if (global_u8DaysCounter == 31){
		global_u8DaysCounter = 0 ;
		global_u8MonCounter++;

		/* Year passed */
		if (global_u8MonCounter == 13){
			global_u8MonCounter = 0 ;
			global_u16YearCounter++;
		}
	}

	/* Output day and date */
	sprintf(loacl_s8DateBuffer, "%.2i/%.2i/%.4i", global_u8DaysCounter , global_u8MonCounter ,global_u16YearCounter);
	TFT_voidPrintText( loacl_s8DateBuffer , 0 , 90 , 2,TFT_ORANGE,TFT_BLACK );

	TFT_voidPrintText(days[global_u8DayIndex] , 40 , 120 , 2,TFT_GREEN,TFT_BLACK );

}
