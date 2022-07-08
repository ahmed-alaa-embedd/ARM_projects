/****************************************************/
/*  Author :   Hussin Ebrahim                       */
/*  Version:   V01                                  */
/*  Date   :   3/8/2020                             */
/****************************************************/
#ifndef   GPIO_INTERFACE_H
#define   GPIO_INTERFACE_H
 
#define   PORTA       0 
#define   PORTB       1 
#define   PORTC       2

#define   HIGH        1 
#define   LOW         0 


#define   PIN0        0
#define   PIN1        1
#define   PIN2        2
#define   PIN3        3
#define   PIN4        4
#define   PIN5        5
#define   PIN6        6
#define   PIN7        7
#define   PIN8        8
#define   PIN9        9
#define   PIN10       10
#define   PIN11       11
#define   PIN12       12
#define   PIN13       13
#define   PIN14       14
#define   PIN15       15  

/*    INPUT MODE             */
#define   INPUT_ANALOG                      0b0000
#define   INPUT_FLOATING                    0b0100
#define   INPUT_PULLUP_PULLDOWN             0b1000
/*     OUTPUT MODE  10MHz     */
#define   OUTPUT_SPEED_10M_PP               0b0001       //ordinary output
#define   OUTPUT_SPEED_10M_OD               0b0101 
#define   OUTPUT_SPEED_10M_ALLPP            0b1001 
#define   OUTPUT_SPEED_10M_ALLOD            0b1101 
/*     OUTPUT MODE  2MHz     */
#define   OUTPUT_SPEED_2MHZ_PP               0b0010       //ordinary output
#define   OUTPUT_SPEED_2M_OD               0b0110 
#define   OUTPUT_SPEED_2M_ALLPP            0b1010 
#define   OUTPUT_SPEED_2M_ALLOD            0b1110 
/*     OUTPUT MODE  50MHz     */
#define   OUTPUT_SPEED_50M_PP               0b0011       //ordinary output
#define   OUTPUT_SPEED_50M_OD               0b0111 
#define   OUTPUT_SPEED_50M_ALLPP            0b1011 
#define   OUTPUT_SPEED_50M_ALLOD            0b1111 


void GPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8PinNum,u8 Copy_u8Mode);
void GPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum,u8 Copy_u8value);
void GPIO_voidEnablePin(u8 Copy_u8Port,u8 Copy_u8PinNum);
void GPIO_voidClearPin(u8 Copy_u8Port,u8 Copy_u8PinNum);
u8   GPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum);
void GPIO_voidTogglePin(u8 Copy_u8Port,u8 Copy_u8PinNum);
void GPIO_voidSet8PinsDirection(u8 Copy_u8Port,u8 Copy_u8FirstPinNum,u8 Copy_u8Mode);
void GPIO_voidSet8PinsValue(u8 Copy_u8Port,u8 Copy_u8FirstPinNum,u8 Copy_u8ByteValue);
#endif
