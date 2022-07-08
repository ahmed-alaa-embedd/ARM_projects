///*
// * main.c
// *
// *  Created on: 24 Aug 2020
// *      Author: ahmed alaa
// */
//
//
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//
//#include "GPIO_int.h"
//#include "RCC_interface.h"
//#include "STk_interface.h"
//#include "SPI_interface.h"
//
//
//#include "TFT_interface.h"
//#include "Image.h"
//
//
//
//void main(void)
//{
//	/*initiat clock*/
//	RCC_voidInitSysClock();
//	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA
//	RCC_voidEnableClock(RCC_APB2, 12); // Enable clock for SPI1
//
//
//	/*PIN mode*/
//	MGPIO_VoidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP); //A0
//	MGPIO_VoidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);	//RST
//	MGPIO_VoidSetPinDirection(GPIOA , PIN5 , OUTPUT_SPEED_10MHZ_AFPP);	//CLK
//	MGPIO_VoidSetPinDirection(GPIOA , PIN7 , OUTPUT_SPEED_10MHZ_AFPP);	//MOSI
//
//
//	/*Initialise SYSTICk*/
//	MSTK_VoidInit();	// clk=AHB/8 = 1MHz
//
//	//Initalise SPI
//	MSPI1_voidInit();
//
//	//Init TFT
//	HTFT_voidInitialize(); // byzhr n8m4a lw 3mlt build XD
//
//
//	//display image
//	HTFT_voidDisplayImage(Image_Array);
////	HTFT_voidFillColor(0xffff);				//white background
////	HTFT_voidDrawRect(50,52,50,100,0); 	//black Line
////	HTFT_voidDrawRect(50,52,50,100,0); 	//black Line
////	HTFT_voidDrawRect(50,52,50,100,0); 	//black Line
////	HTFT_voidDrawRect(53,98,53,98,0xffff);
//
//
//	while(1)
//	{
//
//	}
//}
