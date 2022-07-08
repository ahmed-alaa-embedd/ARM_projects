/*******************************************************/
/* Author  :Hussin Ebrahim                             */
/* Version :V01                                        */
/* Date    :13/8/2020                                  */
/*******************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

static void Delay_us(u32 copy_u32Time)
{
	while(copy_u32Time--)asm("NOP");
}
void LED_voidTurnOnLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum){
	 GPIO_voidEnablePin( Copy_u8PortNum, Copy_u8PinNum);
}

void LED_voidInitLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum){
	 GPIO_voidSetPinDirection( Copy_u8PortNum, Copy_u8PinNum,OUTPUT_SPEED_10M_PP);
}
void LED_voidTurnOffLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum){
	GPIO_voidClearPin(Copy_u8PortNum, Copy_u8PinNum);
}
void LED_voidToggleLed(u8 Copy_u8PortNum,u8 Copy_u8PinNum){
	GPIO_voidTogglePin(Copy_u8PortNum, Copy_u8PinNum);
	
}
void LED_voidInitLedAnimation(void)
{

	LED_voidInitLed(PORTA,START_PIN+0);
	LED_voidInitLed(PORTA,START_PIN+1);
	LED_voidInitLed(PORTA,START_PIN+2);
	LED_voidInitLed(PORTA,START_PIN+3);
	LED_voidInitLed(PORTA,START_PIN+4);
	LED_voidInitLed(PORTA,START_PIN+5);
	LED_voidInitLed(PORTA,START_PIN+6);
	LED_voidInitLed(PORTA,START_PIN+7);


}
void LED_voidStopAnimation(void)
{
	LED_voidTurnOffLed(PORTA,START_PIN+0);
	LED_voidTurnOffLed(PORTA,START_PIN+1);
	LED_voidTurnOffLed(PORTA,START_PIN+2);
	LED_voidTurnOffLed(PORTA,START_PIN+3);
	LED_voidTurnOffLed(PORTA,START_PIN+4);
	LED_voidTurnOffLed(PORTA,START_PIN+5);
	LED_voidTurnOffLed(PORTA,START_PIN+6);
	LED_voidTurnOffLed(PORTA,START_PIN+7);

}
void LED_voidOn_OffLedAnimation(u32 copy_u32Delay)
{


	LED_voidTurnOnLed(PORTA,START_PIN+0);
	LED_voidTurnOnLed(PORTA,START_PIN+1);
	LED_voidTurnOnLed(PORTA,START_PIN+2);
	LED_voidTurnOnLed(PORTA,START_PIN+3);
	LED_voidTurnOnLed(PORTA,START_PIN+4);
	LED_voidTurnOnLed(PORTA,START_PIN+5);
	LED_voidTurnOnLed(PORTA,START_PIN+6);
	LED_voidTurnOnLed(PORTA,START_PIN+7);

	Delay_us(copy_u32Delay);

	LED_voidTurnOffLed(PORTA,START_PIN+0);
	LED_voidTurnOffLed(PORTA,START_PIN+1);
	LED_voidTurnOffLed(PORTA,START_PIN+2);
	LED_voidTurnOffLed(PORTA,START_PIN+3);
	LED_voidTurnOffLed(PORTA,START_PIN+4);
	LED_voidTurnOffLed(PORTA,START_PIN+5);
	LED_voidTurnOffLed(PORTA,START_PIN+6);
	LED_voidTurnOffLed(PORTA,START_PIN+7);

	Delay_us(copy_u32Delay);


}
void LED_voidPingPongLedAnimation(u32 copy_u32Delay)
{
	int x=1;


		for(x=START_PIN;x<=END_PIN;++x){
			if(x==START_PIN){
				LED_voidTurnOnLed(PORTA,1);
				Delay_us(copy_u32Delay);
			}
			else{
				LED_voidTurnOffLed(PORTA,x-1);
				LED_voidTurnOnLed(PORTA,x);
				Delay_us(copy_u32Delay);
			}
		}

		for(x=END_PIN;x>START_PIN;--x){
			if(x==(1+(START_PIN))){
				LED_voidTurnOffLed(PORTA,x);
			}
			else{
				LED_voidTurnOffLed(PORTA,x);
				LED_voidTurnOnLed(PORTA,x-1);
				Delay_us(copy_u32Delay);
			}
		}


}
void LED_voidInOutAnimation(u32 copy_u32Delay)
{
	int x=1;

		for(int x=0;x<4;++x){
			LED_voidTurnOnLed(PORTA,(START_PIN+3)-x);
			LED_voidTurnOnLed(PORTA,(START_PIN+4)+x);
			Delay_us(copy_u32Delay);
		}

		for(x=3;x>=0;--x){
			LED_voidTurnOffLed(PORTA,(START_PIN+3)-x);
			LED_voidTurnOffLed(PORTA,(START_PIN+4)+x);
			Delay_us(copy_u32Delay);
		}


}
