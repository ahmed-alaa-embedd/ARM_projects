/*****************************************/
/* Author  : 		 Ahmed ALAA                 */
/* Date    : 		21/9/2020                   */
/* modifyed by :	Ahmed Alaa
 * modifyed date:	28/9/2020
 * version	:		v01       			 */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "SPI_interface.h"
#include "STk_interface.h"

#include "TFT_config.h"
#include "TFT_interface.h"
#include "TFT_private.h"


void HTFT_voidInitialize(void)
{
	//Reset pulse
	MGPIO_VoidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_VoidSetBusyWait(100);
	MGPIO_VoidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_VoidSetBusyWait(1); //prefer more than 1 Msec
	MGPIO_VoidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_VoidSetBusyWait(100);
	MGPIO_VoidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_VoidSetBusyWait(100);
	MGPIO_VoidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_VoidSetBusyWait(120000);

	//sleep out command
	voidWriteCommand(0x11);

	//wait 150 msec
	MSTK_VoidSetBusyWait(150000);

	//color mode command
	voidWriteCommand(0x3A);
	voidWriteData(0x05);

	//Display ON command
	voidWriteCommand(0x29);

}
void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	//set x addres
	voidWriteCommand(0x2A);
	// X start points 2bits end points 2bits
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127); //all screen

	//set Y addres
	voidWriteCommand(0x2B);
	// Y start points 2bits end points 2bits
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	//RAM write
	voidWriteCommand(0x2C);

//	voidWriteData(0xFFFF); //Black color
//	voidWriteData(0x0000); //white color
	//google -> 565 color coding#

	u8 Data;

	for (u16 counter=0;counter<20480;counter++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_Image[counter] & 0x00ff;
		voidWriteData(Data);
	}

}

void HTFT_voidFillColor(u16 Copy_u16color)
{
	//set x addres
	voidWriteCommand(0x2A);
	// X start points 2bits end points 2bits
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127); //all screen

	//set Y addres
	voidWriteCommand(0x2B);
	// Y start points 2bits end points 2bits
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	//RAM write
	voidWriteCommand(0x2C);

//	voidWriteData(0xFFFF); //Black color
//	voidWriteData(0x0000); //white color
	//google -> 565 color coding#

	u8 Data;

	for (u16 counter=0;counter<20480;counter++)
	{
		Data = Copy_u16color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16color & 0x00ff;
		voidWriteData(Data);
	}

}

void HTFT_voidDrawRect(u8 x1,u8 x2,u8 y1,u8 y2, u16 Copy_u16color)
{
	//make sure data valide for use (x&y)
	u16 size = (x2-x1)*(y2-y1);
	//set x addres
	voidWriteCommand(0x2A);
	// X start points 2bytes end points 2bytes
	voidWriteData(0);
	voidWriteData(x1); //LOW byte of fist byte
	voidWriteData(0);
	voidWriteData(x2); //LOW byte of 2nd byte

	//set Y addres
	voidWriteCommand(0x2B);
	// Y start points 2bits end points 2bits
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);

	//RAM write
	voidWriteCommand(0x2C);

//	voidWriteData(0xFFFF); //Black color
//	voidWriteData(0x0000); //white color
	//google -> 565 color coding#

	u8 Data;

	for (u16 counter=0;counter<size;counter++)
	{
		Data = Copy_u16color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16color & 0x00ff;
		voidWriteData(Data);
	}

}

void HTFT_voidDrawLine(u8 x1,u8 x2,u8 y1,u8 y2, u16 Copy_u16color)
{
	//make sure data valide for use (x&y)
	u16 size = (x2-x1)*(y2-y1);
	//set x addres
	voidWriteCommand(0x2A);
	// X start points 2bytes end points 2bytes
	voidWriteData(0);
	voidWriteData(x1); //LOW byte of fist byte
	voidWriteData(0);
	voidWriteData(x2); //LOW byte of 2nd byte

	//set Y addres
	voidWriteCommand(0x2B);
	// Y start points 2bits end points 2bits
	voidWriteData(0);
	voidWriteData(y1);
	voidWriteData(0);
	voidWriteData(y2);

	//RAM write
	voidWriteCommand(0x2C);

//	voidWriteData(0xFFFF); //Black color
//	voidWriteData(0x0000); //white color
	//google -> 565 color coding#

	u8 Data;

	for (u16 counter=0;counter<size;counter++)
	{
		Data = Copy_u16color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16color & 0x00ff;
		voidWriteData(Data);
	}

}

void HTFT_voidDrawchar(u8 x1,u8 y1, u16 Copy_u16color)
{

}

static voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8temp;

	/*set A0 pin to low*/
	MGPIO_VoidSetPinValue(TFT_A0_PIN,LOW);

	//send command over spi
	MSPI1_voidSendRecieveSynch(Copy_u8Command,&Local_u8temp);

}


static voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8temp;

	/*set A0 pin to High*/
	MGPIO_VoidSetPinValue(TFT_A0_PIN,HIGH);

	//send command over spi
	MSPI1_voidSendRecieveSynch(Copy_u8Data,&Local_u8temp);
}
