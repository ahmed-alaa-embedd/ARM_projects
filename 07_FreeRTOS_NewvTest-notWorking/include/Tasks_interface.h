/*
 * Tasks_interface.h
 *
 *  Created on: Sep 5, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef TASKS_INTERFACE_H_
#define TASKS_INTERFACE_H_

/**-------------------------------------------------------------------------------------------------------**/



void vApplicationIdleHook( void );
void vUartRecieve (void* params) ;
void vMotor_Handler    (void* params) ;
void vServo_Handler    (void* params) ;
void vCheck (void* params) ;

/**-------------------------------------------------------------------------------------------------------**/

#endif /* TASKS_INTERFACE_H_ */
