#include "stm32f4xx.h"
#include "SYSTICK.h"
#include "NEC.h"

int main(void)
{
	NEC_Init();


    while (1)
    {
    	NEC_SendCommand(0x10, 0x20);
    	delay_ms(1000);
    }
}
