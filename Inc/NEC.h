#ifndef NEC_H
#define NEC_H

#include "TIM.h"

// NEC Protocol Timing definitions in microseconds
#define NEC_HEADER_MARK    9000 // 9ms leader mark
#define NEC_HEADER_SPACE   4500 // 4.5ms leader space
#define NEC_BIT_MARK       560  // 560us for a bit mark
#define NEC_ONE_SPACE      1690 // 1.69ms for a '1' space
#define NEC_ZERO_SPACE     560  // 560us for a '0' space
#define NEC_END_MARK       560  // Final mark for end signal

void NEC_Init(void);
void NEC_SendCommand(uint8_t address, uint8_t command);

#endif
