/*******************************************************/
/* Author  :Hussin Ebrahim                             */
/* Version :V01                                        */
/* Date    :13/8/2020                                  */
/*******************************************************/
#ifndef     LED_INTERFACE_h
#define     LED_INTERFACE_h


void LED_voidInitLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum);
void LED_voidTurnOnLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum);
void LED_voidTurnOffLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum);
void LED_voidToggleLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum);

void LED_voidInitLedAnimation(void);
void LED_voidStopAnimation(void);
void LED_voidOn_OffLedAnimation(u32 copy_u32Delay);
void LED_voidPingPongLedAnimation(u32 copy_u32Delay);
void LED_voidInOutAnimation(u32 copy_u32Delay);

#endif
