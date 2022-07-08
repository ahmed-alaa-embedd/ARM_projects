/*****************************************************/
/* Author   : Ahmed Assaf                            */
/* Version  : V01                                    */
/* Date     : 14 SEP 2020                            */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

#include "LEDMatrix_Interface.h"
#include "LEDMatrix_private.h"
#include "LEDMatrix_config.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_s8Counter;	// signed var as if it reach 0 then -1 it will be 255 if it is unsigned (infinit loop)
	u8 Local_u8Bit;
	for (Local_s8Counter = 7; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit strating from MSb */
		Local_u8Bit =  GET_BIT(Copy_u8DataToSend,Local_s8Counter);

		MGPIO_VoidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);

		/* Send Pulse to Shift Clock */
		MGPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_VoidSetBusyWait(1);
		MGPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_VoidSetBusyWait(1);
	}

	/* Send Pulse to Store Clock */
	MGPIO_VoidSetPinValue(HSTP_STORE_CLOCK,HIGH);
	MSTK_VoidSetBusyWait(1);
	MGPIO_VoidSetPinValue(HSTP_STORE_CLOCK,LOW);
	MSTK_VoidSetBusyWait(1);

}

void HSTP_LEDMRX_VoidDisplay(u8 *copy_U8Data)
{
	/*1st shift register is cols 2nd is rows*/

	for(u8 i=0; i<8;i++)  //speed LOW i = HIGH speed
	{


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[0]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 0
		HSTP_SetRowValue(copy_U8Data[0]);
		HSTP_SetColValue(0xFE);
		MSTK_VoidSetBusyWait(2500); //2.5 ms


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[1]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 1
		HSTP_SetRowValue(copy_U8Data[1]);
		HSTP_SetColValue(0xFD);
		MSTK_VoidSetBusyWait(2500); //2.5 ms


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[2]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 2
		HSTP_SetRowValue(copy_U8Data[2]);
		HSTP_SetColValue(0xFB);
		MSTK_VoidSetBusyWait(2500); //2.5 ms


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[3]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 3
		HSTP_SetRowValue(copy_U8Data[3]);
		HSTP_SetColValue(0xF7);
		MSTK_VoidSetBusyWait(2500); //2.5 ms


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[4]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 4
		HSTP_SetRowValue(copy_U8Data[4]);
		HSTP_SetColValue(0xEF);
		MSTK_VoidSetBusyWait(2500); //2.5 ms


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[5]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 5
		HSTP_SetRowValue(copy_U8Data[5]);
		HSTP_SetColValue(0xDF);
		MSTK_VoidSetBusyWait(2500); //2.5 ms


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[6]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 6
		HSTP_SetRowValue(copy_U8Data[6]);
		HSTP_SetColValue(0xBF);
		MSTK_VoidSetBusyWait(2500); //2.5 ms


		//Set Row Value
		HSTP_SetRowValue(copy_U8Data[7]);
		//	Disable All Cols
		HSTP_SetColValue(0xFF);
		//Enable col 7
		HSTP_SetRowValue(copy_U8Data[7]);
		HSTP_SetColValue(0x7F);
		MSTK_VoidSetBusyWait(2500); //2.5 ms
	}

}

void HSTP_LEDMRX_VoidSheft(u8 *copy_U8Data)
{
	for(u8 j=0; j<30-8;j++)		//j is less than array index by 8
	{
		for(u8 i=0; i<10;i++)  //speed LOW i = HIGH speed
		{
			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 0
			HSTP_SetRowValue(copy_U8Data[j]);
			HSTP_SetColValue(0xFE);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j+1]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 1
			HSTP_SetRowValue(copy_U8Data[j+1]);
			HSTP_SetColValue(0xFD);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j+2]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 2
			HSTP_SetRowValue(copy_U8Data[j+2]);
			HSTP_SetColValue(0xFB);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j+3]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 3
			HSTP_SetRowValue(copy_U8Data[j+3]);
			HSTP_SetColValue(0xF7);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j+4]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 4
			HSTP_SetRowValue(copy_U8Data[j+4]);
			HSTP_SetColValue(0xEF);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j+5]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 5
			HSTP_SetRowValue(copy_U8Data[j+5]);
			HSTP_SetColValue(0xDF);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j+6]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 6
			HSTP_SetRowValue(copy_U8Data[j+6]);
			HSTP_SetColValue(0xBF);
			MSTK_VoidSetBusyWait(2500); //2.5 ms


			//Set Row Value
			HSTP_SetRowValue(copy_U8Data[j+7]);
			//	Disable All Cols
			HSTP_SetColValue(0xFF);
			//Enable col 7
			HSTP_SetRowValue(copy_U8Data[j+7]);
			HSTP_SetColValue(0x7F);
			MSTK_VoidSetBusyWait(2500); //2.5 ms
		}
	}
}

void HSTP_SetColValue(u8 copy_u8value)
{
	s8 Local_s8Counter;	// signed var as if it reach 0 then -1 it will be 255 if it is unsigned (infinit loop)
	u8 Local_u8Bit;
	for (Local_s8Counter = 7; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit strating from MSb */
		Local_u8Bit =  GET_BIT(copy_u8value,Local_s8Counter);

		MGPIO_VoidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);

		/* Send Pulse to Shift Clock */
		MGPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_VoidSetBusyWait(1);
		MGPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_VoidSetBusyWait(1);
	}
	/* Send Pulse to Store Clock */
	MGPIO_VoidSetPinValue(HSTP_STORE_CLOCK,HIGH);
	MSTK_VoidSetBusyWait(1);
	MGPIO_VoidSetPinValue(HSTP_STORE_CLOCK,LOW);
	MSTK_VoidSetBusyWait(1);
}
void HSTP_SetRowValue(u8 copy_u8Value)
{

	s8 Local_s8Counter;	// signed var as if it reach 0 then -1 it will be 255 if it is unsigned (infinit loop)
	u8 Local_u8Bit;
	for (Local_s8Counter = 7; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit strating from MSb */
		Local_u8Bit =  GET_BIT(copy_u8Value,Local_s8Counter);

		MGPIO_VoidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);

		/* Send Pulse to Shift Clock */
		MGPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_VoidSetBusyWait(1);
		MGPIO_VoidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_VoidSetBusyWait(1);
	}
	//	/* Send Pulse to Store Clock */
	//	MGPIO_VoidSetPinValue(HSTP_STORE_CLOCK,HIGH);
	//	MSTK_VoidSetBusyWait(1);
	//	MGPIO_VoidSetPinValue(HSTP_STORE_CLOCK,LOW);
	//	MSTK_VoidSetBusyWait(1);


}
