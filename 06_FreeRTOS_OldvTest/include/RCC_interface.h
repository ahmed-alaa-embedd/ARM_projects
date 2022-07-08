/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 8 August 2020			   */
/* version : V02 				   */
/***********************************/

#ifndef RCC_interface_H
#define RCC_interface_H

#define RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);




#endif
