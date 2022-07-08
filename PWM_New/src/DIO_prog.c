/******************************************************************************************************/
/* Author    : Ahmed Saeed
/* Version   : V01
/* Date      : 30 Auguest 2020
/* Descrip   : GPIO
/******************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_private.h"


void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					/* CRL REG FROM PIN0 : PIN7 */
					if(copy_u8PIN <= 7)
					{
						/* reset for 4 bits */
						GPIOA_CRL &= ~ ((0b1111)<< (copy_u8PIN * 4)); 
						
						/* set for 4 bits */
						GPIOA_CRL |= ((copy_u8MODE)<< (copy_u8PIN * 4));
					}
					
					/* CRH REG FROM PIN8 : PIN15 */
					else if(copy_u8PIN <= 15)
					{
						/* SUBTRACTION 8 BECAUSE 8 * 4 =PIN32 BUT NO PIN 32 SO FOR PIN8 ---> 8 -8 = 0 SO IT PIN0 */
						copy_u8PIN = copy_u8PIN - 8;
						
						/* reset for 4 bits */
						GPIOA_CRH &= ~ ((0b1111)<< (copy_u8PIN * 4)); 
						
						/* set for 4 bits */
						GPIOA_CRH |= ((copy_u8MODE)<< (copy_u8PIN * 4));
					}
					break;
		case GPIOB :
					/* CRL REG FROM PIN0 : PIN7 */
					if(copy_u8PIN <= 7)
					{
						/* reset for 4 bits */
						GPIOB_CRL &= ~ ((0b1111)<< (copy_u8PIN * 4)); 
						
						/* set for 4 bits */
						GPIOB_CRL |= ((copy_u8MODE)<< (copy_u8PIN * 4));
					}
					
					/* CRH REG FROM PIN8 : PIN15 */
					else if(copy_u8PIN <= 15)
					{
						/* SUBTRACTION 8 BECAUSE 8 * 4 =PIN32 BUT NO PIN 32 SO FOR PIN8 ---> 8 -8 = 0 SO IT PIN0 */
						copy_u8PIN = copy_u8PIN - 8;
						
						/* reset for 4 bits */
						GPIOB_CRH &= ~ ((0b1111)<< (copy_u8PIN * 4)); 
						
						/* set for 4 bits */
						GPIOB_CRH |= ((copy_u8MODE)<< (copy_u8PIN * 4));
					}
					break;
		case GPIOC :		
					/* CRL REG FROM PIN0 : PIN7 */
					if(copy_u8PIN <= 7)
					{
						/* reset for 4 bits */
						GPIOC_CRL &= ~ ((0b1111)<< (copy_u8PIN * 4)); 
						
						/* set for 4 bits */
						GPIOC_CRL |= ((copy_u8MODE)<< (copy_u8PIN * 4));
					}
					
					/* CRH REG FROM PIN8 : PIN15 */
					else if(copy_u8PIN <= 15)
					{
						/* SUBTRACTION 8 BECAUSE 8 * 4 =PIN32 BUT NO PIN 32 SO FOR PIN8 ---> 8 -8 = 0 SO IT PIN0 */
						copy_u8PIN = copy_u8PIN - 8;
						
						/* reset for 4 bits */
						GPIOC_CRH &= ~ ((0b1111)<< (copy_u8PIN * 4)); 
						
						/* set for 4 bits */
						GPIOC_CRH |= ((copy_u8MODE)<< (copy_u8PIN * 4));
					}
					break;
					
					default : break;
	}
}	

void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8VALUE)
{	
	switch(copy_u8PORT)
	{
		case GPIOA :
					if(copy_u8VALUE == GPIO_HIGH)
					{
						SET_BIT(GPIOA_ODR, copy_u8PIN);
					}
					
					else if(copy_u8VALUE == GPIO_LOW)
					{
						CLR_BIT(GPIOA_ODR, copy_u8PIN);
					}
					break;
		case GPIOB :
					if(copy_u8VALUE == GPIO_HIGH)
					{
						SET_BIT(GPIOB_ODR, copy_u8PIN);
					}
					
					else if(copy_u8VALUE == GPIO_LOW)
					{
						CLR_BIT(GPIOB_ODR, copy_u8PIN);
					}
					break;
					
		case GPIOC :
					if(copy_u8VALUE == GPIO_HIGH)
					{
						SET_BIT(GPIOC_ODR, copy_u8PIN);
					}
					
					else if(copy_u8VALUE == GPIO_LOW)
					{
						CLR_BIT(GPIOC_ODR, copy_u8PIN);
					}
					break;
					
					default : break;
	}
}

u8 MGPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	switch(copy_u8PORT)
	{
		case GPIOA :
					LOC_u8Result = GET_BIT(GPIOA_IDR,copy_u8PIN);
					break;
		case GPIOB :
					LOC_u8Result = GET_BIT(GPIOB_IDR,copy_u8PIN);
					break;
					
		case GPIOC :
					LOC_u8Result = GET_BIT(GPIOC_IDR,copy_u8PIN);
					break;
					
					default : break;
	}
	return LOC_u8Result;
}

void LED_voidON(u8 copy_u8PORT , u8 copy_u8PIN)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
			SET_BIT(GPIOA_ODR,copy_u8PIN);  break;
		case GPIOB :
			SET_BIT(GPIOB_ODR,copy_u8PIN);	break;
		case GPIOC :
			SET_BIT(GPIOC_ODR,copy_u8PIN);  break;
	}
}

void LED_voidOFF(u8 copy_u8PORT , u8 copy_u8PIN)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
			CLR_BIT(GPIOA_ODR,copy_u8PIN);  break;
		case GPIOB :
			CLR_BIT(GPIOB_ODR,copy_u8PIN);	break;
		case GPIOC :
			CLR_BIT(GPIOC_ODR,copy_u8PIN);  break;
	}
}

void LED_voidTOG(u8 copy_u8PORT, u8 copy_u8PIN)
{
	u16 w = 600;
	switch(copy_u8PORT)
	{
	case GPIOA :
		SET_BIT(GPIOA_ODR,copy_u8PIN);

	/* FUCTTION LOOP */
		for(u16 i = 0 ; i < w ; i++)
		{
			for(u16 j = 0 ; j < w ; j++)
			{
				asm("NOP");
			}
		}

		CLR_BIT(GPIOA_ODR,copy_u8PIN);

		/* FUCTTION LOOP */
		for(u16 i = 0 ; i < w ; i++)
		{
			for(u16 j = 0 ; j < w ; j++)
			{
				asm("NOP");
			}
		}

		break;

	case GPIOB :
		SET_BIT(GPIOB_ODR,copy_u8PIN);
		/* FUCTTION LOOP */
		for(u16 i = 0 ; i < w ; i++)
		{
			for(u16 j = 0 ; j < w ; j++)
			{
				asm("NOP");
			}
		}
		CLR_BIT(GPIOB_ODR,copy_u8PIN);
		/* FUCTTION LOOP */
		for(u16 i = 0 ; i < w ; i++)
		{
			for(u16 j = 0 ; j < w ; j++)
			{
				asm("NOP");
			}
		}
		break;
	case GPIOC :
		SET_BIT(GPIOC_ODR,copy_u8PIN);
		/* FUCTTION LOOP */
		for(u16 i = 0 ; i < w ; i++)
		{
			for(u16 j = 0 ; j < w ; j++)
			{
				asm("NOP");
			}
		}
		CLR_BIT(GPIOC_ODR,copy_u8PIN);

		/* FUCTTION LOOP */
			for(u16 i = 0 ; i < w ; i++)
			{
				for(u16 j = 0 ; j < w ; j++)
				{
					asm("NOP");
				}
			}
		break;
}
}


