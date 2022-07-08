

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STk_interface.h"
#include "OS_Interface.h"

void Led1(void);
void Led2(void);
void Led3(void);

int main(void)
{
	
	/*initiat clock*/
	RCC_voidInitSysClock();


	RCC_voidEnableClock(RCC_APB2, 2); // Enable clock for GPIOA
	
	MGPIO_VoidSetPinDirection(GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP);

	SOS_VoidTaskReady(0);
	SOS_VoidTaskReady(1);
	SOS_VoidTaskReady(2);
	SOS_VoidCreateTask(0,1000,Led1,0);
	SOS_VoidCreateTask(1,2000,Led2,1);
	SOS_VoidCreateTask(2,3000,Led3,2);
		
	SOS_VoidStart();
		
	while(1)
	{
		
	}
	
	return 0;
}

void Led1(void)
{
	//toggile LED
	static u8 Local_u8PIN0 = 0 ;
	TOG_BIT(Local_u8PIN0,0);
	MGPIO_VoidSetPinValue(GPIOA,PIN0,Local_u8PIN0);
}

void Led2(void)
{
	//toggile LED
	static u8 Local_u8PIN1 = 0 ;
	TOG_BIT(Local_u8PIN1,0);
	MGPIO_VoidSetPinValue(GPIOA,PIN1,Local_u8PIN1);
}

void Led3(void)
{
	//toggile LED
	static u8 Local_u8PIN2 = 0 ;
	TOG_BIT(Local_u8PIN2,0);
	MGPIO_VoidSetPinValue(GPIOA,PIN2,Local_u8PIN2);
}

