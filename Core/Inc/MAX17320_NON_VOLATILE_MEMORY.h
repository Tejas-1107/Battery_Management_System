#ifndef __MAX17320_NON_VOLATILE_MEMORY_H
#define __MAX17320_NON_VOLATILE_MEMORY_H

#include "main.h"
#include "I2C.h"

#define MAX17320_I2C_SLAVE_ADDR   																	(0x36 << 1) 
#define MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS  						 0X61
#define MAX17320_COMMAND_REGISTER_ADDRESS  													 0X60
#define MAX17320_NV_LOCK_REGISTER_ADDRESS														 0X7F
#define MAX17320_CONFIGURATION_2_REGISTER_ADDRESS										 0XAB

typedef enum
{
	NV_MEMORY_ERROR = 0,
	NV_MEMORY_SUCCESS = 1
}nv_memory_status_t;

extern nv_memory_status_t nv_memory_status;

typedef struct
{
	uint8_t updates_remaining;
	uint16_t communication_status;
	uint16_t lock_status;
}struct_MAX17320_NV_MEMORY;

extern struct_MAX17320_NV_MEMORY MAX17320_NV_MEMORY;

uint8_t NON_VOLATILE_BLOCK_PROGRAMMING(void);
void SEND_COMMAND_TO_COMMAND_STATUS_REGISTER(uint16_t);
void SEND_COMMAND_TO_COMMAND_REGISTER(uint16_t);
void SEND_COMMAND_TO_CONFIG_2_REGISTER(uint16_t);

void MAX17320_NV_REMAINING_UPDATES(void);
void MAX17320_NV_READ_DATA_FROM_REGISTER(uint8_t,uint16_t*);
void MAX17320_NV_COMMUNICATION_STATUS_REGISTER_UNLOCK(void);
void MAX17320_NV_COMMUNICATION_STATUS_REGISTER_LOCK(void);
void MAX17320_NV_COMMUNICATION_STATUS_REGISTER(void);
void MAX17320_NV_LOCK_REGISTER(void);
void MAX17320_LOCKING_MEMORY_BLOCKS(uint16_t);
void MAX17320_SHA256_AUTHENTICATION(void);    //not implemented
void MAX17320_NV_WRITE_DATA_TO_REGISTER(uint8_t,uint16_t);  //not implemented

#endif
