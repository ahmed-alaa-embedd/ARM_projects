/***************************/
/*Author : ahmed alaa	*/
/*date : 29/9/2020 		*/
/*version : v03			*/
/***************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
#if baud_rate == R9600

	/*	baud rate = 9600		*/
	USART1 -> BRR = 0x341;


#elif baud_rate == R115200

	/*	baud rate = 115200		*/
		USART1 -> BRR = 0x45;

#endif

	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */

	USART1 -> SR = 0;						/* Clearing status register */
}

u8 MUSART1_u8Transmit(u8 arr[],u16 Copy_u32timeout)
{
	u8 i = 0;
	u16 timeOut=0;
	u8 Loc_u8ReceivedData = 0;
	while(arr[i] != '\0')
	{
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0)
		{
			timeOut++;
			if(timeOut>Copy_u32timeout)
			{
				Loc_u8ReceivedData = 255; //this var will not reach 255 as max value in ASCII table is 128
				break;
			}
		}
		if(timeOut>Copy_u32timeout)
		{

			break;
		}
		i++;
	}
	return Loc_u8ReceivedData;

}

u8 MUSART1_u8Receive(u32 Copy_u32timeout)
{
	u32 timeOut=0;

	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0)
	{
		timeOut++;
		if(timeOut==Copy_u32timeout)
		{
			Loc_u8ReceivedData = 255; //this var will not reach 255 as max value in ASCII table is 128
			break;
		}
	}
	if(Loc_u8ReceivedData == 0)
	{
		Loc_u8ReceivedData = USART1 -> DR;
	}
	return (Loc_u8ReceivedData);
}
