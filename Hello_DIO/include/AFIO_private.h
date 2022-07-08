/*  Created on: 24 Aug 2020
  *      Author: ahmed alaa
  *     version:	01
  */

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

typedef struct
{
	 u32 EVCR;
	 u32 EXTICR[4];
	 u32 MAPR;
	 u32 MAPR2;


}AFIO_t;

#define AFIO	((volatile AFIO_t *)0x40010000)


#endif /* AFIO_PRIVATE_H_ */
