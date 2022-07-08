/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 18/8/2020				   */
/* version : V01 				   */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_int.h"
#include "SevenSeg_interface.h"
#include "SevenSeg_config.h"

void VoidSevenSegconfig(u8 copy_u8port)
{
	#if copy_u8port == GPIOA
	MGPIO_VoidSetPortDirection(copy_u8port,PORT_OUTPUT_SPEED_10MHZ_PP);


	
	#elif copy_u8port == GPIOB
	MGPIO_VoidSetPortDirection(GPIOB,PORT_OUTPUT_SPEED_10MHZ_PP);


	#elif copy_u8port == GPIOC
	MGPIO_VoidSetPortDirection(GPIOC,PORT_OUTPUT_SPEED_10MHZ_PP);
	
#endif

}
void VoidSevenSegDesplayNumber(u8 copy_u8PORT,u16 copy_u16num)
{
	#if copy_u8type == comm_cathode
	
	if(copy_u16num == 0)
	{
		MGPIO_VoidSetPortValue( copy_u8PORT,0b0111111);
	}

	if(copy_u16num == 1)
	{

		MGPIO_VoidSetPortValue( copy_u8PORT,0b0000110);
	}
	else if(copy_u16num == 2)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1011011);
		}
	else if(copy_u16num == 3)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1001111);
		}
	else if(copy_u16num == 4)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1100110);
		}
	else if(copy_u16num == 5)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1101101);
		}
	else if(copy_u16num == 6)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1111101);
		}
	else if(copy_u16num == 7)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b0000111);
		}
	else if(copy_u16num == 8)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b11111111);
		}
	else if(copy_u16num == 9)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1101111);
		}



	
	#elif evenSeg_TYPE == comm_anode
	

	if(copy_u16num == 1)
	{

		MGPIO_VoidSetPortValue( copy_u8PORT,~(0b0000110));
	}
	else if(copy_u16num == 2)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1011011));
		}
	else if(copy_u16num == 3)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1001111));
		}
	else if(copy_u16num == 4)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1100110));
		}
	else if(copy_u16num == 5)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1101101));
		}
	else if(copy_u16num == 6)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1111101));
		}
	else if(copy_u16num == 7)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b0000111));
		}
	else if(copy_u16num == 8)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b11111111));
		}
	else if(copy_u16num == 9)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1101111));
		}

	
	#endif
}

