/*****************************************/
/*Author    :Hussin Ebrahim              */
/*Version   :V01                         */
/*Date      :19/8/2020                   */
/*****************************************/
#ifndef  NVIC_INTERFACE_H
#define  NVIC_INTERFACE_H

void NVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void NVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 NVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);
void NVIC_voidSetPriority(u8 copy_u8GroupID,u8 copy_u8SubID,u8 copy_u8IntID);
#endif
