/*****************************************/
/*Author    :Hussin Ebrahim              */
/*Version   :V01                         */
/*Date      :19/8/2020                   */
/*****************************************/

#ifndef  NVIC_PRIVATE_H
#define  NVIC_PRIVATE_H
#include "STD_TYPES.h"
#include "BIT_MATH.h"
           /* 1 enable  0 has no effect */
#define NVIC_ISER0                 *((u32*)0xE000E100)//enable external interuupt from 0 to 31
#define NVIC_ISER1                 *((u32*)0xE000E104)//enable external interuupt from 32 to63
           /* 1 disable  0 has no effect */
#define NVIC_ICER0            	   *((u32*)0xE000E180)//clear external interuupt from 0 to 31
#define NVIC_ICER1           	   *((u32*)0xE000E184)//clear external interuupt from 32 to63

#define NVIC_ISPR0                 *((u32*)0xE000E200)//set pending flag  from 0 to 31
#define NVIC_ISPR1                 *((u32*)0xE000E204)//set pending flag  from 32 to63

#define NVIC_ICPR0                 *((u32*)0xE000E280)//clear pending flag  from 0 to 31
#define NVIC_ICPR1                 *((u32*)0xE000E284)//clear pending flag  from 32 to63

#define NVIC_IABR0                 *((volatile u32*)0xE000E300)
#define NVIC_IABR1                 *((volatile u32*)0xE000E304)

#define NVIC_IPR                   ((u8*)0xE000E400)

/* in (SCB => AIRCR) 4 bits for group and 0 sub => 4bits in (IPR) to determine group number	*/
#define GROUP_BITS_4               0x05FA0300
/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define GROUP_BITS_3               0x05FA0400
/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define GROUP_BITS_2               0x05FA0500
/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define GROUP_BITS_1               0x05FA0600
/* in (SCB => AIRCR) 0 bits for Group and 4 bit for sub										*/
#define GROUP_BITS_0               0x05FA0700
#endif
