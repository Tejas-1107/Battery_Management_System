#include "MAX17320.h"

struct_MAX17320 MAX17320;

//from this //

void MAX17320_WRITE_DATA_TO_REGISTERS(uint8_t address,uint16_t data)
{
	uint8_t txdata[3]; 
	
	txdata[0] = address & 0XFF;
	
	txdata[1] = ((data >> 8) & 0XFF);
	
	txdata[2] = (data & 0XFF);
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,txdata,3,HAL_MAX_DELAY);	
}

void MAX17320_READ_DATA_FROM_REGISTER(uint8_t address,uint16_t *struct_register)
{
	uint8_t txdata[1];
	
	uint8_t rxdata[2];
	
	txdata[0] = address & 0XFF;
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,txdata,1,HAL_MAX_DELAY);	
	
	HAL_I2C_Master_Receive(&hi2c1,(MAX17320_I2C_SLAVE_ADDR | 1),rxdata,2,HAL_MAX_DELAY);
	
	*struct_register = ((rxdata[1] << 8) | rxdata[0]);
}



















