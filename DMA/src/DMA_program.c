/***************************/
/*Author : ahmed alaa	*/
/*date : 12/9/2020 		*/
/*version : v01			*/
/***************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DMA_Interface.h"
#include "DMA_private.h"
#include "DMA_Config.h"

// channel from 0 to 7

void DMA_voidChannel1Init(u8 copy_u8Channel)
{
	/*
		Memory to memory
		Priority very high
		Source, destination size=32bit
		MINC , PINC activated
		No circular
		Direction: peripheral to memory
		Transfer complete interrupt enable
		Channel Disable
	*/

#if MEM_MODE== MEM2MEM
	SET_BIT(DMA -> Channel[copy_u8Channel].CCR,14);
#elif MEM_MODE== MEM2PRIPH
	CLR_BIT(DMA -> Channel[copy_u8Channel].CCR,14);
#elif MEM_MODE== PRIPH2MEM
	CLR_BIT(DMA -> Channel[copy_u8Channel].CCR,14);
#elif MEM_MODE== PRIPH2PRIPH
	CLR_BIT(DMA -> Channel[copy_u8Channel].CCR,14);

#endif

#if MEM_PRIPH_SIZE== BIT32
	DMA -> Channel[copy_u8Channel].CCR |= (0xA00|0x300A);
#elif MEM_PRIPH_SIZE== BIT16
	DMA -> Channel[copy_u8Channel].CCR |= (0x500|0x300A);
#elif MEM_PRIPH_SIZE== BIT8
	DMA -> Channel[copy_u8Channel].CCR |= (0x0|0x300A);


#endif


	DMA->Channel[copy_u8Channel].CCR=0x00007AC2;
}


void DMA_voidChannel1Start(u8 copy_u8Channel,u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/*Make sure channel is disabled*/
	CLR_BIT(DMA->Channel[copy_u8Channel].CCR,0);
	/*Load the addresses*/
	DMA->Channel[copy_u8Channel].CPAR=Copy_pu32SourceAddress;
	DMA->Channel[copy_u8Channel].CMAR=Copy_pu32DestinationAddress;
	
	/*Load the block length*/
	DMA->Channel[copy_u8Channel].CNDTR=Copy_u16BlockLength;
	
	SET_BIT(DMA->Channel[copy_u8Channel].CCR,0);
}
