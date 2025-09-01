#include "MAX_PAGE_030h_03F.h"

void MAX17320_QR_TABLE_20_REGISTER_R(void)         				//not important
{
	MAX17320_READ_DATA_FROM_REGISTER(QR_TALBE_20_REGISTER_ADDRESS,&MAX17320.qr_table_20);
}

void MAX17320_DIE_TEMPERATURE_REGISTER_R(void)      			//shows the iternal temperatuer i degree celsius
{
	MAX17320_READ_DATA_FROM_REGISTER(DIE_TEMPERATURE_REGISTER_ADDRESS,&MAX17320.die_temperature);
}

void MAX17320_VOLTAGE_EMPTY_REGISTER_W(uint16_t vempty)  	//gine the empty voltage ad the recovery voltage  // (ve * 0.01) (vr * 0.04)
{
	MAX17320_WRITE_DATA_TO_REGISTERS(VOLTAGE_EMPTY_REGISTER_ADDRESS,vempty);
}

void MAX17320_VOLTAGE_EMPTY_REGISTER_R(void)              //read
{
	MAX17320_READ_DATA_FROM_REGISTER(VOLTAGE_EMPTY_REGISTER_ADDRESS,&MAX17320.vempty);
}

void MAX17320_FSTATUS_REGISTER_R(void)                    //it gives the cell is relaxed or not ad the empty detection long relaxation 
{
	MAX17320_READ_DATA_FROM_REGISTER(FSTATUS_REGISTER_ADDRESS,&MAX17320.fstatus);
}

void MAX17320_TIMER_REGISTER_R(void)                      //read only
{
	MAX17320_READ_DATA_FROM_REGISTER(TIMER_REGISTER_ADDRESS,&MAX17320.timer);
}
