/***************************/
/*Author : ahmed alaa	*/
/*date : 12/9/2020 		*/
/*version : v01			*/
/***************************/
/*Preprocessor File Guard*/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void DMA_voidChannel1Init(u8 copy_u8Channel);


void DMA_voidChannel1Start(u8 copy_u8Channel,u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);

#endif
