/***************************/
/*Author : ahmed alaa	*/
/*date : 5/9/2020 		*/
/*version : v01			*/
/***************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_VoidCreateTask(u8 copy_u8ID, u16 copy_u16Priodicity, void (*ptr)(void),u8 copy_u8FirstDelay);
void SOS_VoidStart(void);
void SOS_VoidTaskReady(u8 copy_u8ID);
//void SOS_VoidDeleteTask();

#endif
