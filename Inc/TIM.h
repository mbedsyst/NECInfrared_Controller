#ifndef TIM_H
#define TIM_H

#include "stm32f4xx.h"

#define IR_GPIO_PORT 		GPIOA
#define IR_GPIO_PIN  		GPIO_PIN_8
#define IR_TIMER     		TIM1
#define IR_TIMER_CHANNEL 	TIM_CHANNEL_1

void TIM_Init(void);
void GPIO_Init(void);
void IR_StartSignal(void);
void IR_StopSignal(void);

#endif
