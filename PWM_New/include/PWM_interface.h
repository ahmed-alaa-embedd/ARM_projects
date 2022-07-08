/******************************************************************************************************/
/* Author    : Ahmed Saeed
/* Version   : V01
/* Date      : 2020
/* Descrip   : pwm
/******************************************************************************************************/
#ifndef    PWM_INTERFACE_H
#define    PWM_INTERFACE_H

void TIM1_Generate_PWM_Config(void);

void TIM8_Generate_OnePulse_Config(void);

void TIM1_Update_PWM(void);
void config_PWM(void);

//void PWM_Init(void);

#endif
