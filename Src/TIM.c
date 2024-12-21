#include "TIM.h"

void GPIO_Init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    IR_GPIO_PORT->MODER &= ~(GPIO_MODER_MODER8);
    IR_GPIO_PORT->MODER |= (2U << GPIO_MODER_MODER8_Pos);
    IR_GPIO_PORT->OTYPER &= ~(GPIO_OTYPER_OT_8);
    IR_GPIO_PORT->OSPEEDR |= (3U << GPIO_OSPEEDER_OSPEEDR8_Pos);
    IR_GPIO_PORT->PUPDR &= ~(GPIO_PUPDR_PUPDR8);
    IR_GPIO_PORT->PUPDR |= (1U << GPIO_PUPDR_PUPDR8_Pos);
    IR_GPIO_PORT->AFR[1] &= ~(0xF << ((8 - 8) * 4));
    IR_GPIO_PORT->AFR[1] |= (IR_GPIO_AF << ((8 - 8) * 4));
}

void TIM_Init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    // Timer configuration for 38 kHz PWM
    IR_TIMER->PSC = (76 - 1); 						// Prescaler to divide 76 MHz to 1 MHz
    IR_TIMER->ARR = (26 - 1); 						// Auto-reload for 38 kHz (1 MHz / 38 kHz = ~26)
    IR_TIMER->CCR1 = (13 - 1); 						// 50% duty cycle
    // Configure PWM mode 1 on channel 1
    IR_TIMER->CCMR1 |= (6U << TIM_CCMR1_OC1M_Pos); 	// PWM mode 1
    IR_TIMER->CCMR1 |= TIM_CCMR1_OC1PE; 			// Pre-Load Enable
    // Enable output for channel 1
    IR_TIMER->CCER |= TIM_CCER_CC1E;
    // Enable main output (MOE)
    IR_TIMER->BDTR |= TIM_BDTR_MOE;
    // Enable counter
    IR_TIMER->CR1 |= TIM_CR1_CEN;
}

void IR_StartSignal(void)
{
    // Enable PWM signal on PA8
    IR_TIMER->CCR1 = 13 - 1; // 50% duty cycle
}

void IR_StopSignal(void)
{
    // Stop PWM signal by setting CCR1 to 0
    IR_TIMER->CCR1 = 0;
}
