/***************************/
/*Author : ahmed alaa	*/
/*date : 5/9/2020 		*/
/*version : v01			*/
/***************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define READY 1

typedef struct
{
	u16 priodicity    ;
	void (*fprt)(void);
	u16 FirstDelay     ;
	u8 State   ;
	
	
}Task;

void Scheduler(void);





#endif
