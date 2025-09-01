#ifndef __MAX17320_SBS_PROTOCOL_H
#define __MAX17320_SBS_PROTOCOL_H

#include "main.h"
#include "I2C.h"

#define MAX17320_I2C_SLAVE_ADDR_SBS  (0x16 << 1)

void SBS_WRITE_WORD(uint8_t,uint16_t);
void SBS_READ_WORD(uint8_t,uint16_t*);
void SBS_WRITE_BLOCK(void);
void SBS_READ_BLOCK(uint8_t,uint16_t*);

#endif
