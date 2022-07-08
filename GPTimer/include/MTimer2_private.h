/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 25/9/2020			 	   */
/* version : V01				   */
/***********************************/



#ifndef MTIMER6_PRIVATE_H
#define MTIMER6_PRIVATE_H

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 Reserved0;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 Reserved1;
	volatile u32 Reserved2;
	volatile u32 Reserved3;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;

}MTimer6_Type;

#define MTimer6 ((MTimer6_Type*)0x40001000 )

#define ENABLE	1
#define DISABLE	0

#endif
