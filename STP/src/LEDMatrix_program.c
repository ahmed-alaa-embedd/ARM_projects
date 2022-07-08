/*****************************************/
/* Author  :  Ahmed ALAA                */
/* Version :  V01                        */
/* Date    : 31/8/2020              */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "STk_interface.h"
#include "LEDMatrix_Interface.h"
#include "LEDMatrix_private.h"
#include "LEDMatrix_config.h"

/* pins config:
 * pinA0 => A7
 * pinB0-B1-B5=>B10*/

void HLEDMRX_VoidInit()
{
	MGPIO_VoidSetPinDirection(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);





	MGPIO_VoidSetPinDirection(LEDMRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(LEDMRX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);

}


void HLEDMRX_VoidDisplay(u8 *copy_U8Data)
{

	for(u8 i=0; i<8;i++)  //speed LOW i = HIGH speed
	{
		DisableAllCols();
		SetRowValue(copy_U8Data[0]);
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL0_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms

		DisableAllCols();
		SetRowValue(copy_U8Data[1]);
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL1_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms

		DisableAllCols();
		SetRowValue(copy_U8Data[2]);
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL2_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms

		DisableAllCols();
		SetRowValue(copy_U8Data[3]);
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL3_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms

		DisableAllCols();
		SetRowValue(copy_U8Data[4]);	// there is 2 cols empty
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL4_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms

		DisableAllCols();
		SetRowValue(copy_U8Data[5]);
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL5_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms

		DisableAllCols();
		SetRowValue(copy_U8Data[6]);
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL6_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms

		DisableAllCols();
		SetRowValue(copy_U8Data[7]);
		//Enable col 0
		MGPIO_VoidSetPinValue(LEDMRX_COL7_PIN,LOW);
		MSTK_VoidSetBusyWait(2500); //2.5 ms
	}

}

void HLEDMRX_VoidSheft(u8 *copy_U8Data)
{
	for(u8 j=0; j<35;j++)		//j is less than array index by 8
	{
		for(u8 i=0; i<10;i++)  //speed LOW i = HIGH speed
		{
			//MSTK_VoidSetBusyWait(500000);
			DisableAllCols();
			SetRowValue(copy_U8Data[j]);
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL0_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms

			DisableAllCols();
			SetRowValue(copy_U8Data[j+1]);
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL1_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms

			DisableAllCols();
			SetRowValue(copy_U8Data[j+2]);
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL2_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms

			DisableAllCols();
			SetRowValue(copy_U8Data[j+3]);
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL3_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms

			DisableAllCols();
			SetRowValue(copy_U8Data[j+4]);	// there is 2 cols empty
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL4_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms

			DisableAllCols();
			SetRowValue(copy_U8Data[j+5]);
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL5_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms

			DisableAllCols();
			SetRowValue(copy_U8Data[j+6]);
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL6_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms

			DisableAllCols();
			SetRowValue(copy_U8Data[j+7]);
			//Enable col 0
			MGPIO_VoidSetPinValue(LEDMRX_COL7_PIN,LOW);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


		}
		//MSTK_VoidSetBusyWait(500000); //0.5 s not usefull
	}


}

void DisableAllCols()
{
	//Disable all cols

	MGPIO_VoidSetPinValue(LEDMRX_COL0_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL1_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL2_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL3_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL4_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL5_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL6_PIN,HIGH);
	MGPIO_VoidSetPinValue(LEDMRX_COL7_PIN,HIGH);

}

void SetRowValue(u8 copy_u8Value)
{

	u8 Local_U8Bit;
	Local_U8Bit=GET_BIT(copy_u8Value,0);
	MGPIO_VoidSetPinValue(LEDMRX_ROW0_PIN,Local_U8Bit);

	Local_U8Bit=GET_BIT(copy_u8Value,1);
	MGPIO_VoidSetPinValue(LEDMRX_ROW1_PIN,Local_U8Bit);

	Local_U8Bit=GET_BIT(copy_u8Value,2);
	MGPIO_VoidSetPinValue(LEDMRX_ROW2_PIN,Local_U8Bit);

	Local_U8Bit=GET_BIT(copy_u8Value,3);
	MGPIO_VoidSetPinValue(LEDMRX_ROW3_PIN,Local_U8Bit);

	Local_U8Bit=GET_BIT(copy_u8Value,4);
	MGPIO_VoidSetPinValue(LEDMRX_ROW4_PIN,Local_U8Bit);

	Local_U8Bit=GET_BIT(copy_u8Value,5);
	MGPIO_VoidSetPinValue(LEDMRX_ROW5_PIN,Local_U8Bit);

	Local_U8Bit=GET_BIT(copy_u8Value,6);
	MGPIO_VoidSetPinValue(LEDMRX_ROW6_PIN,Local_U8Bit);

	Local_U8Bit=GET_BIT(copy_u8Value,7);
	MGPIO_VoidSetPinValue(LEDMRX_ROW7_PIN,Local_U8Bit);


}
