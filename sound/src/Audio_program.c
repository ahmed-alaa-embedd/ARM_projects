/***************************/
/*Author : ahmed alaa	*/
/*date : 13/10/2020 		*/
/*version : v01			*/
/***************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_int.h"
#include "GPIO_private.h"

#include "Audio_Interface.h"


volatile u16 i=0;




void HAudio_voidSetSong(u8 copy_u8ArrayName, u8 copy_u8ArrayLength)
{
	//interrupt every 125 ms and
	MSTK_VoidSetIntervalPeriodic(125,VoidSetDAC);
	GPIOA_ODR = copy_u8ArrayName[i];
	i++;
	if(i==copy_u8ArrayLength)
	{
		i=0;
	}
}
