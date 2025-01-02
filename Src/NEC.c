#include "NEC.h"
#include "stm32f4xx.h"

// Delay function in microseconds
static void delay_us(uint32_t us)
{
    uint32_t start = DWT->CYCCNT;
    uint32_t ticks = us * (76000000 / 1000000);
    while ((DWT->CYCCNT - start) < ticks);
}

// Transmit Mark (Turn on PWM for specified time)
static void transmit_mark(uint32_t time_us)
{
    IR_StartSignal();
    delay_us(time_us);
    IR_StopSignal();
}

// Transmit Space (Turn off PWM for specified time)
static void transmit_space(uint32_t time_us)
{
    IR_StopSignal();
    delay_us(time_us);
}

// Initialize the DWT for precise delay measurements
void NEC_Init(void)
{
    if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk))
    {
    	// Enable DWT
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    }
    DWT->CYCCNT = 0;           				// Reset the cycle counter
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk; 	// Enable the counter

    TIM_Init();
}

// Transmit NEC signal
void NEC_SendCommand(uint8_t address, uint8_t command)
{
    // Send leader code
    transmit_mark(NEC_HEADER_MARK);
    transmit_space(NEC_HEADER_SPACE);

    // Transmit 8-bit Address
    for (int i = 0; i < 8; i++)
    {
        transmit_mark(NEC_BIT_MARK);
        if (address & (1 << i))
        {
            transmit_space(NEC_ONE_SPACE);
        }
        else
        {
            transmit_space(NEC_ZERO_SPACE);
        }
    }

    // Transmit 8-bit Inverted Address
    for (int i = 0; i < 8; i++)
    {
        transmit_mark(NEC_BIT_MARK);
        if (~address & (1 << i))
        {
            transmit_space(NEC_ONE_SPACE);
        }
        else
        {
            transmit_space(NEC_ZERO_SPACE);
        }
    }

    // Transmit 8-bit Command
    for (int i = 0; i < 8; i++)
    {
        transmit_mark(NEC_BIT_MARK);
        if (command & (1 << i))
        {
            transmit_space(NEC_ONE_SPACE);
        }
        else
        {
            transmit_space(NEC_ZERO_SPACE);
        }
    }

    // Transmit 8-bit Inverted Command
    for (int i = 0; i < 8; i++)
    {
        transmit_mark(NEC_BIT_MARK);
        if (~command & (1 << i))
        {
            transmit_space(NEC_ONE_SPACE);
        }
        else
        {
            transmit_space(NEC_ZERO_SPACE);
        }
    }

    // Send stop bit
    transmit_mark(NEC_END_MARK);
}
