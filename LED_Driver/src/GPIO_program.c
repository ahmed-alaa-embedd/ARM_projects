#include "STD_TYPES.h"
#include "BIT_MATH.H"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8PinNum,u8 Copy_u8Mode){
	switch(Copy_u8Port){
		case PORTA:
			if(Copy_u8PinNum<8){
				GPIOA_CRL &=~(0b1111<<(Copy_u8PinNum*4));
				GPIOA_CRL |=(Copy_u8Mode<<(Copy_u8PinNum*4));
			}
			else if(Copy_u8PinNum<16){
				Copy_u8PinNum -=8;
				GPIOA_CRH &=~(0b1111<<(Copy_u8PinNum*4));
				GPIOA_CRH |=(Copy_u8Mode<<(Copy_u8PinNum*4));
			}
			break;
			
		case PORTB:
			if(Copy_u8PinNum<8){
				GPIOB_CRL &=~(0b1111<<(Copy_u8PinNum*4));
				GPIOB_CRL |=(Copy_u8Mode<<(Copy_u8PinNum*4));
			}
			else if(Copy_u8PinNum<16){
				Copy_u8PinNum -=8;
				GPIOB_CRH &=~(0b1111<<(Copy_u8PinNum*4));
				GPIOB_CRH |=(Copy_u8Mode<<(Copy_u8PinNum*4));
			}
			break;
			
		case PORTC:
			if(Copy_u8PinNum<8){
				GPIOC_CRL &=~(0b1111<<(Copy_u8PinNum*4));
				GPIOC_CRL |=(Copy_u8Mode<<(Copy_u8PinNum*4));
			}
			else if(Copy_u8PinNum<16){
				Copy_u8PinNum -=8;
				GPIOC_CRH &=~(0b1111<<(Copy_u8PinNum*4));
				GPIOC_CRH |=(Copy_u8Mode<<(Copy_u8PinNum*4));
			}
			break;
	}
}
void GPIO_voidSet8PinsDirection(u8 Copy_u8Port,u8 Copy_u8FirstPinNum,u8 Copy_u8Mode){

	for(u8 x=0;x<=7;++x){
		GPIO_voidSetPinDirection( Copy_u8Port, Copy_u8FirstPinNum + x, Copy_u8Mode);
	}
}
void GPIO_voidEnablePin(u8 Copy_u8Port,u8 Copy_u8PinNum){
	switch(Copy_u8Port){
		case PORTA:
			 GPIOA_BSRR= 1<<Copy_u8PinNum;
		     break;
		case PORTB:
		    GPIOB_BSRR= 1<<Copy_u8PinNum;
			break;
		case PORTC:
		    GPIOC_BSRR= 1<<Copy_u8PinNum;
			break;
			
	}
		
}
void GPIO_voidClearPin(u8 Copy_u8Port,u8 Copy_u8PinNum){
	switch(Copy_u8Port){
		case PORTA:
			 GPIOA_BRR= 1<<Copy_u8PinNum;
		     break;
		case PORTB:
		    GPIOB_BRR= 1<<Copy_u8PinNum;
			break;
		case PORTC:
		    GPIOC_BRR= 1<<Copy_u8PinNum;
			break;
			
	}
		
}
void GPIO_voidTogglePin(u8 Copy_u8Port,u8 Copy_u8PinNum){
	switch(Copy_u8Port){
		case PORTA:
			 TOG_BIT(GPIOA_ODR,Copy_u8PinNum) ;
		     break;
		case PORTB:
			 TOG_BIT(GPIOB_ODR,Copy_u8PinNum) ;
		     break;
		case PORTC:
			 TOG_BIT(GPIOC_ODR,Copy_u8PinNum) ;
		     break;
			
	}
}
void GPIO_voidSet8PinsValue(u8 Copy_u8Port,u8 Copy_u8FirstPinNum,u8 Copy_u8ByteValue){
	switch(Copy_u8Port){
			case PORTA:
				GPIOA_ODR &=~(0xff<<Copy_u8FirstPinNum);
				GPIOA_ODR |=(Copy_u8ByteValue<<Copy_u8FirstPinNum);
			    break;
			case PORTB:
				GPIOB_ODR &=~(0xff<<Copy_u8FirstPinNum);
				GPIOB_ODR |=(Copy_u8ByteValue<<Copy_u8FirstPinNum);
				break;
			case PORTC:
				GPIOB_ODR &=~(0xff<<Copy_u8FirstPinNum);
				GPIOB_ODR |=(Copy_u8ByteValue<<Copy_u8FirstPinNum);
				break;

		}

}
u8  GPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum){
	u8 Local_u8Result=0;
	switch(Copy_u8Port){
		case PORTA:
			Local_u8Result=GET_BIT(GPIOA_IDR,Copy_u8PinNum);
			break;
		case PORTB:
			Local_u8Result=GET_BIT(GPIOB_IDR,Copy_u8PinNum);
			break;
		case PORTC:
			Local_u8Result=GET_BIT(GPIOC_IDR,Copy_u8PinNum);
			break;
	}
	return Local_u8Result;
}
void GPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum,u8 Copy_u8value){
	switch(Copy_u8Port){
		case PORTA:
				GPIOA_ODR &=~(1<<Copy_u8PinNum);
				GPIOA_ODR |=(Copy_u8value<<Copy_u8PinNum);
		     break;
		case PORTB:
				GPIOB_ODR &=~(1<<Copy_u8PinNum);
				GPIOB_ODR |=(Copy_u8value<<Copy_u8PinNum);
			break;
		case PORTC:
				GPIOC_ODR &=~(1<<Copy_u8PinNum);
				GPIOC_ODR |=(Copy_u8value<<Copy_u8PinNum);
			break;
			
	}
}
