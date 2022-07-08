/***************************/
/*Author : ahmed alaa	*/
/*date : 12/9/2020 		*/
/*version : v01			*/
/***************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;

#define DMA	((volatile DMA_t*)0x40020000)

#define MEM2MEM			0
#define MEM2PRIPH		1
#define	PRIPH2MEM		2
#define PRIPH2PRIPH		3

#define BIT32	0
#define BIT16	1
#define BIT8	2



#endif

