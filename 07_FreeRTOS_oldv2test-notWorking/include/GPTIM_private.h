/************************************************/
/* Author 		 :Hussin Ebrahim                 */
/* Date   		 :10/9/2020  					 */
/* modified by   : Ahmed Alaa					 */
/* modified Date : 8/10/2020                   	 */
/* Version		 :V03                            */
/************************************************/ 
#ifndef    BASICTIMERS_PRIVATE_H
#define    BASICTIMERS_PRIVATE_H
/****************TIM2*******************/

static volatile  u32 Global2_u32Routine=0;
static volatile  u32 Global2_u32Fraction;
static volatile  u32 Global2_u32CopyRoutine;
static volatile  u8  Global2_u8Flag=1;
/* Define Callback Global Variable */
static volatile void (*TIM2_CallBack)(void);
/* Define Variable for interval mode */
static volatile u8 TIM2_u8ModeOfInterval;

/****************TIM3*******************/

static volatile  u32 Global3_u32Routine=0;
static volatile  u32 Global3_u32Fraction;
static volatile  u32 Global3_u32CopyRoutine;
static volatile  u8  Global3_u8Flag=1;
static volatile  void (*TIM3_CallBack)(void);
static volatile  u8     TIM3_u8ModeOfInterval;

/****************TIM4*******************/

static volatile  u32 Global4_u32Routine=0;
static volatile  u32 Global4_u32Fraction;
static volatile  u32 Global4_u32CopyRoutine;
static volatile  u8  Global4_u8Flag=1;
static volatile  void (*TIM4_CallBack)(void);
static volatile  u8     TIM4_u8ModeOfInterval;






/*Interval Mode*/
#define    SINGLE_INTERVAL     0
#define    PERIODIC_INTERVAL   1

typedef struct
{
	volatile u32 TCR1;           /*00*/
	volatile u32 TCR2;           /*04*/
	volatile u32 TSMCR;          /*08*/
	volatile u32 TDIER;          /*0C*/
	volatile u32 TSR;            /*10*/
	volatile u32 TEGR;           /*14*/
	volatile u32 TCCMR1;         /*18*/
	volatile u32 TCCMR2;         /*1C*/
	volatile u32 TCCER;          /*20*/
	volatile u32 TCNT;           /*24*/
	volatile u32 TPSC;           /*28*/
	volatile u32 TARR;           /*2C*/
	volatile u32 TReserved1;     /*30*/
	volatile u32 TCCR1;          /*34*/
	volatile u32 TCCR2;          /*38*/
	volatile u32 TCCR3;          /*3C*/
	volatile u32 TCCR4;          /*40*/
	volatile u32 TReserved2;     /*44*/
	volatile u32 DCR;           /*48*/
	volatile u32 DMAR;          /*4C*/
}TIM_t;
#define  TIM2    ((volatile TIM_t*)0x40000000)
#define  TIM3    ((volatile TIM_t*)0x40000400)
#define  TIM4    ((volatile TIM_t*)0x40000800)

#endif
