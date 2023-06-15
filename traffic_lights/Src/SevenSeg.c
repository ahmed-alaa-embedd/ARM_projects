/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 18/8/2020				   */
/* version : V01 				   */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_int.h"
#include "STk_interface.h"

#include "SevenSeg_interface.h"
#include "SevenSeg_config.h"

u16 arr[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110
		,0b1101101,0b1111101,0b0000111,0b11111111,0b1101111};
u8 a15[]={0b0,0b0,0b1,0b1,0b1,0b1,0b1,0b0,0b1,0b1};

void VoidSevenSegLoop(u8 copy_Long_i,u8 copy_Short_i)
{


	for(s8 i=copy_Long_i;i>=0;i--)
	{
		for(s8 j=copy_Short_i;j>=0;j--)
		{
			VoidSevenSegDesplayNumber99(GPIOA,GPIOB, PIN9,i,j);
			MSTK_VoidSetBusyWait(1000000);
		}
	}
}

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

void VoidSevenSegDesplayNumber99(u8 copy_u8PORT,u8 copy_u8one_PIN_ON_PORT ,u8 copy_PIN,u8 copy_u8num1,u8 copy_u8num2)
{
#if copy_u8type == comm_cathode


	MGPIO_VoidSetPortValue( copy_u8PORT,arr[copy_u8num1]|(arr[copy_u8num2]<<7));
	MGPIO_VoidSetPinValue(copy_u8one_PIN_ON_PORT, copy_PIN, a15[copy_u8num2]);

#endif

}
void VoidSevenSegDesplayNumber(u8 copy_u8PORT,u8 copy_u8num)
{
	#if copy_u8type == comm_cathode
	
	if(copy_u8num == 0)
	{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b0111111);


	}

	else if(copy_u8num == 1)
	{
			MGPIO_VoidSetPortValue( copy_u8PORT,0b0000110);

	}
	else if(copy_u8num == 2)
	{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1011011);

	}
	else if(copy_u8num == 3)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1001111);

		}
	else if(copy_u8num == 4)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1100110);

		}
	else if(copy_u8num == 5)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1101101);
		}

	else if(copy_u8num == 6)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1111101);

		}
	else if(copy_u8num == 7)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b0000111);

		}
	else if(copy_u8num == 8)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b11111111);

		}
	else if(copy_u8num == 9)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,0b1101111);

		}



	
	#elif evenSeg_TYPE == comm_anode
	

	if(copy_u8num == 1)
	{

		MGPIO_VoidSetPortValue( copy_u8PORT,~(0b0000110));
	}
	else if(copy_u8num == 2)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1011011));
		}
	else if(copy_u8num == 3)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1001111));
		}
	else if(copy_u8num == 4)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1100110));
		}
	else if(copy_u8num == 5)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1101101));
		}
	else if(copy_u8num == 6)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1111101));
		}
	else if(copy_u8num == 7)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b0000111));
		}
	else if(copy_u8num == 8)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b11111111));
		}
	else if(copy_u8num == 9)
		{

			MGPIO_VoidSetPortValue( copy_u8PORT,~(0b1101111));
		}

	
	#endif
}

