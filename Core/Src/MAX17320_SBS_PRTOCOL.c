#include "MAX17320_SBS_PROTOCOL.h"

void SBS_WRITE_WORD(uint8_t memory_address, uint16_t data)
{
	uint8_t txdata[3];
	txdata[0] = memory_address;         
	txdata[1] = data & 0xFF;            
	txdata[2] = (data >> 8) & 0xFF;    

  HAL_I2C_Master_Transmit(&hi2c1, MAX17320_I2C_SLAVE_ADDR_SBS, txdata, 3, HAL_MAX_DELAY);
}

void SBS_READ_WORD(uint8_t memory_address, uint16_t *struct_register)
{
    uint8_t rxdata[2];

    HAL_I2C_Mem_Read(&hi2c1, MAX17320_I2C_SLAVE_ADDR_SBS, memory_address,I2C_MEMADD_SIZE_8BIT, rxdata, 2, HAL_MAX_DELAY);

    *struct_register = ((rxdata[1] << 8) | rxdata[0]);  // Little endian
}

void SBS_WRITE_BLOCK(void)
{
	
}
void SBS_READ_BLOCK(uint8_t memory_address,uint16_t *struct_register)
{
	uint8_t txdata[1];
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR_SBS,txdata,1,HAL_MAX_DELAY);
	
	
}
