/*****************************************/
/* Author  :  Ahmed ALAA                 */
/* Date    : 21/9/2020                   */
/* Version :  V01            			 */
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
	voidWriteCommand(0x31);
	voidWriteData(0x05);

	//Display ON command
	voidWriteCommand(0x29);

}
void HTFT_voidDisplayImage(const u16* Copy_Image)
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
