/*
 * Tasks_interface.h
 *
 *  Created on: 6/11/2020
 *      Author: ahmed alaa
 *      version: 2
 */

#ifndef TASKS_INTERFACE_H_
#define TASKS_INTERFACE_H_

/**-------------------------------------------------------------------------------------------------------**/




//void vApplicationIdleHook( void );
void vUartRecieve (void* params) ;
void vMotor_Handler    (void* params) ;
void vServo_Handler    (void* params) ;
void vCheck (void* params) ;

/**-------------------------------------------------------------------------------------------------------**/

#endif /* TASKS_INTERFACE_H_ */
