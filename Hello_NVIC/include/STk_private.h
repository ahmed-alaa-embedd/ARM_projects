/***************************/
/*Author : ahmed alaa	*/
/*date : 26/8/2020 		*/
/*version : v02			*/
/***************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


#define STK_BASE_ADDRESS		 0xE000E010
#define STK_CTRL				*((u32*)STK_BASE_ADDRESS)
#define STK_LOAD				*((u32*)STK_BASE_ADDRESS+0x04)
#define STK_VAL					*((u32*)STK_BASE_ADDRESS+0x08)
#define STK_CALIB				*((u32*)STK_BASE_ADDRESS+0x0C)




#endif
