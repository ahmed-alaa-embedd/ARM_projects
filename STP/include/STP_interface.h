/*****************************************************/
/* Author   : Ahmed Assaf                            */
/* Version  : V01                                    */
/* Date     : 14 SEP 2020                            */
/*****************************************************/
#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend);// synchronuse = no return befor the requird from it had finished
void HSTP_LEDMRX_VoidDisplay(u8 *copy_U8Data);
void HSTP_LEDMRX_VoidSheft(u8 *copy_U8Data);

#endif
