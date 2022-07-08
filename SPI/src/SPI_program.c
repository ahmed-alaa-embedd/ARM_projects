/*****************************************/
/* Author  :  Ahmed ALAA                 */
/* Date    : 16/9/2020                   */
/* Version :  V01            			 */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"


void (*CallBack)(u8);

void MSPI1_voidInit(void)
{
	//CPOL=1 CPHA=1 Prescaler= CLK/2 SPI Enable MSB First
	MSPI1->CR1 = 0x0347;
}

void MSPI1_voidSendRecieveSynch(u8 copy_u8DatatoTransmit,u8 *copy_u8DataToRecieve)
{
	/*clear for Slave select bin*/
	MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,LOW);

	//send Data
	MSPI1 -> DR = copy_u8DatatoTransmit;

	//wait busy flag
	while(GET_BIT(MSPI1 -> SR,7)==1);

	//return to the recieved data
	*copy_u8DataToRecieve = MSPI1 -> DR;

	//set slave slect pin
	MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

void MSPI1_voidSendRecieveASynch(u8 copy_u8DatatoTransmit,void (*CallBack)(u8))
{

}


void SPI1_Handler()
{
	CallBack(MSPI1 -> DR);
}
