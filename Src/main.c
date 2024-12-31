#include "stm32f4xx.h"

void PWM_Init(void) {
    // Enable clock for GPIOA and TIM1
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;  // Enable TIM1 clock

    // Configure PA8 as Alternate Function (AF1 - TIM1 CH1)
    GPIOA->MODER &= ~GPIO_MODER_MODER8;      // Clear MODER bits for PA8
    GPIOA->MODER |= GPIO_MODER_MODER8_1;    // Set PA8 to Alternate Function mode
    GPIOA->AFR[1] &= ~GPIO_AFRH_AFRH0;      // Clear AFR bits for PA8
    GPIOA->AFR[1] |= GPIO_AFRH_AFRH0_0;     // Set AF1 for TIM1 on PA8

    // Configure TIM1 for PWM
    TIM1->PSC = 0;                          // Prescaler value (no prescaling, f_timer = 76 MHz)
    TIM1->ARR = (76000000 / 38000) - 1;     // Set Auto-Reload Register for 38 kHz (1999 for 76 MHz clock)
    TIM1->CCR1 = TIM1->ARR / 2;             // Set Compare Register 1 for 50% duty cycle (ARR/2)

    TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;         // Clear Output Compare mode bits
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // Set PWM mode 1 (110)
    TIM1->CCMR1 |= TIM_CCMR1_OC1PE;         // Enable Preload for CCR1

    TIM1->CCER |= TIM_CCER_CC1E;            // Enable Capture/Compare 1 output
    TIM1->BDTR |= TIM_BDTR_MOE;             // Enable Main Output (for TIM1 specific)
    TIM1->CR1 |= TIM_CR1_ARPE;              // Enable Auto-Reload Preload
    TIM1->CR1 |= TIM_CR1_CEN;               // Enable TIM1 counter
}

int main(void)
{
	PWM_Init();

    while (1)
    {

    }
}
