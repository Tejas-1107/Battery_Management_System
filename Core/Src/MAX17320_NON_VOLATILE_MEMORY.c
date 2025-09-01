#include "MAX17320_NON_VOLATILE_MEMORY.h"

struct_MAX17320_NV_MEMORY MAX17320_NV_MEMORY;
nv_memory_status_t nv_memory_status;

uint8_t NON_VOLATILE_BLOCK_PROGRAMMING(void)
{
	uint16_t command1 = 0X0000;
	uint16_t command2 = 0XE904;
	uint16_t command3 = 0X000F;
	uint16_t command4 = 0X8000;
	uint16_t command5 = 0X00F9;
	uint16_t raw_data = 0;
	
	SEND_COMMAND_TO_COMMAND_STATUS_REGISTER(command1);      //step 1
	SEND_COMMAND_TO_COMMAND_STATUS_REGISTER(command1);			//step 1
	
	//implement step 2
	
	SEND_COMMAND_TO_COMMAND_STATUS_REGISTER(command1);			//step 3
	
	SEND_COMMAND_TO_COMMAND_REGISTER(command2);             //step 4 and step 5
	
  uint8_t rx_buf[2];
  HAL_I2C_Mem_Read(&hi2c1, MAX17320_I2C_SLAVE_ADDR, MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS, I2C_MEMADD_SIZE_8BIT, rx_buf, 2, HAL_MAX_DELAY);
  raw_data = rx_buf[0] | (rx_buf[1] << 8);

	if(raw_data & 0X0004)													          //check for the command status register
	{
		return NV_MEMORY_ERROR;                               //step 6
	}
	
	SEND_COMMAND_TO_COMMAND_REGISTER(command3);							//step 7
	
	HAL_Delay(20);																					//step 8
	
	SEND_COMMAND_TO_COMMAND_STATUS_REGISTER(command1);			//step 9
	 
	SEND_COMMAND_TO_CONFIG_2_REGISTER(command4);            //step 10
	
	uint8_t data1[2];
	HAL_I2C_Master_Receive(&hi2c1,MAX17320_I2C_SLAVE_ADDR,data1,2,HAL_MAX_DELAY);
	uint16_t raw_data1 = (data1[0] | (data1[1] << 8));															//step 11
	if(raw_data1 & 0X8000)
	{
		return NV_MEMORY_ERROR;
	}
	
	SEND_COMMAND_TO_COMMAND_STATUS_REGISTER(command5);
	
	return NV_MEMORY_SUCCESS;
}


void SEND_COMMAND_TO_COMMAND_STATUS_REGISTER(uint16_t data)
{
    uint8_t data_bytes[3];
    data_bytes[0] = MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS; // Command code
    data_bytes[1] = data & 0xFF;         													  // LSB
    data_bytes[2] = (data >> 8) & 0xFF;  													  // MSB

    HAL_I2C_Master_Transmit(&hi2c1, MAX17320_I2C_SLAVE_ADDR, data_bytes, 3, HAL_MAX_DELAY);
}

void SEND_COMMAND_TO_COMMAND_REGISTER(uint16_t data)
{
  uint8_t data_bytes[3];
  data_bytes[0] = MAX17320_COMMAND_REGISTER_ADDRESS; // Command code
  data_bytes[1] = data & 0xFF;         													  // LSB
  data_bytes[2] = (data >> 8) & 0xFF;  													  // MSB
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,data_bytes,3,HAL_MAX_DELAY);
	
	HAL_Delay(2000);                                                //step 4
}

void SEND_COMMAND_TO_CONFIG_2_REGISTER(uint16_t data)
{
	uint8_t data_bytes[3];
  data_bytes[0] = MAX17320_CONFIGURATION_2_REGISTER_ADDRESS;      // Command code
  data_bytes[1] = data & 0xFF;         													  // LSB
  data_bytes[2] = (data >> 8) & 0xFF;  													  // MSB
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,data_bytes,3,HAL_MAX_DELAY);
}

//

void MAX17320_NV_REMAINING_UPDATES(void)
{
	uint8_t unlock_data[3] = {MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,0X00,0X00};
	uint8_t write_data1[3] = {MAX17320_COMMAND_REGISTER_ADDRESS,0X9B,0XE2};
	uint8_t lock_data[3] = {MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,0XF9,0X00};
	uint8_t memory_address[1] = {0XFD};
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,unlock_data,3,HAL_MAX_DELAY);      //step 1	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,unlock_data,3,HAL_MAX_DELAY);			//step 1
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,write_data1,2,HAL_MAX_DELAY);			//step 2
	
	HAL_Delay(5);																																							//step 3
	
	uint8_t rxdata[2]; 
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,memory_address,1,HAL_MAX_DELAY);		//step 4	
	HAL_I2C_Master_Receive(&hi2c1,MAX17320_I2C_SLAVE_ADDR,rxdata,2,HAL_MAX_DELAY);						//step 4
	
	uint16_t raw = rxdata[0] | (rxdata[1] << 8);  // Little endian

	// 5. Count the number of bits set
	uint8_t lower = raw & 0xFF;
	uint8_t upper = (raw >> 8) & 0xFF;
	uint8_t combined = lower | upper;
	uint8_t writes_used = __builtin_popcount(combined);  // GCC built-in
	MAX17320_NV_MEMORY.updates_remaining = 7 - writes_used;
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,lock_data,2,HAL_MAX_DELAY);   //step 6
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,lock_data,2,HAL_MAX_DELAY);		//step 6
	
}
//
void MAX17320_NV_COMMUNICATION_STATUS_REGISTER(void)     //read
{
	MAX17320_NV_READ_DATA_FROM_REGISTER(MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,&MAX17320_NV_MEMORY.communication_status);
}
//
void MAX17320_NV_COMMUNICATION_STATUS_REGISTER_UNLOCK(void)
{
	uint8_t unlock_data[3] = {MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,0X00,0X00};
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,unlock_data,3,HAL_MAX_DELAY);      //step 1	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,unlock_data,3,HAL_MAX_DELAY);			//step 1
}
//
void MAX17320_NV_COMMUNICATION_STATUS_REGISTER_LOCK(void)
{
	uint8_t lock_data[3] = {MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,0XF9,0X00};
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,lock_data,2,HAL_MAX_DELAY);   //step 6
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_COMMUNICATION_STATUS_REGISTER_ADDRESS,lock_data,2,HAL_MAX_DELAY);		//step 6
	
}
//
void MAX17320_NV_LOCK_REGISTER(void)                     //read
{
	MAX17320_NV_READ_DATA_FROM_REGISTER(MAX17320_NV_LOCK_REGISTER_ADDRESS,&MAX17320_NV_MEMORY.lock_status);
}
//
void MAX17320_LOCKING_MEMORY_BLOCKS(uint16_t lock_data)    //write 
{
	MAX17320_NV_COMMUNICATION_STATUS_REGISTER_UNLOCK();     															//step 1
	MAX17320_NV_COMMUNICATION_STATUS_REGISTER_UNLOCK();																		//step 2
	
	uint8_t txdata[3] = {MAX17320_COMMAND_REGISTER_ADDRESS,(lock_data & 0XFF),((lock_data >> 8) & 0XFF)};
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,txdata,3,HAL_MAX_DELAY);     	//step 3
	
	HAL_Delay(100);																																				//step 4
	
	MAX17320_NV_COMMUNICATION_STATUS_REGISTER_LOCK();       															//step 6
}
//
//void MAX17320_SHA256_AUTHENTICATION(void)
//{
//	MAX17320_NV_COMMUNICATION_STATUS_REGISTER_UNLOCK();
//}
void MAX17320_NV_READ_DATA_FROM_REGISTER(uint8_t address,uint16_t *struct_register)
{
	uint8_t txdata[1];
	
	uint8_t rxdata[2];
	
	txdata[0] = address & 0XFF;
	
	HAL_I2C_Master_Transmit(&hi2c1,MAX17320_I2C_SLAVE_ADDR,txdata,1,HAL_MAX_DELAY);	
	
	HAL_I2C_Master_Receive(&hi2c1,(MAX17320_I2C_SLAVE_ADDR | 1),rxdata,2,HAL_MAX_DELAY);
	
	*struct_register = ((rxdata[1] << 8) | rxdata[0]);
}
//

//void MAX17320_NV_WRITE_DATA_TO_REGISTER(uint8_t address,uint16_t data)
//{
//	MAX17320_NV_COMMUNICATION_STATUS_REGISTER_UNLOCK();

//}


