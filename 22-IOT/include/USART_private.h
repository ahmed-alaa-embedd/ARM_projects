/***************************/
/*Author : ahmed alaa	*/
/*date : 29/9/2020 		*/
/*version : v02			*/
/***************************/


#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}USART_Register;


#define 	USART1 		((USART_Register *) 0x40013800)

#define R115200	1
#define R9600	2

#endif
