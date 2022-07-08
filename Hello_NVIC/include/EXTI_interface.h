/***************************/
/*Author : ahmed alaa	*/
/*date : 22/8/2020 		*/
/*version : v02			*/
/***************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_VoidInit(u8 EXTI_LINE);
void MEXTI_VoidSetSignalLatch(u8 Copy_U8EXTILine, u8 Copy_U8EXTISenseMode);
void MEXTI_VoidEnable(u8 Copy_U8EXTILine);
void MEXTI_VoidDisnable(u8 Copy_U8EXTILine);
void MEXTI_VoidSoftwareTrigger(u8 Copy_U8EXTILine);

void MEXTI_VoidSetCallBack(void (*ptr) (void));




#endif
