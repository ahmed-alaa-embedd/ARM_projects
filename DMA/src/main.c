#include "STD_TYPES.h"
#include "DMA_Interface.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "DMA_private.h"

u16 Local_u16Index;
void main(void)
{
	u32 Arr1[1000]={0};
	u32 Arr2[1000];

	u32 Arr3[1000]={0};
	u32 Arr4[1000];

	MRCC_voidInitSysClock();

	/*Enable clock on DMA Peripheral*/
	MRCC_voidEnableClock(RCC_AHB,1);

	DMA_voidChannel1Init();

	MNVIC_VoidEnableInterrupt(11);
	DMA_voidChannel1Start(Arr1,Arr2,1000);

	for(Local_u16Index=0;Local_u16Index<1000;Local_u16Index++)
	{
		Arr4[Local_u16Index]=Arr3[Local_u16Index];
	}


	while(1)
	{

	}
}
void DMA1_Channel1_IRQHandler(void)
{
	/*Clear Interrupt flag*/
	DMA->IFCR=1<<0;		/*Clear Global Interrupt flag of channel1*/
	DMA->IFCR=1<<1;		/*Clear transfer complete Interrupt flag of channel1*/
}
