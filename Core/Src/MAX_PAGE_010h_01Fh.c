#include "MAX_PAGE_010h_01Fh.h"

void MAX17320_FULL_CAPACITY_REPORT_R(void)     //READ
{
	MAX17320_READ_DATA_FROM_REGISTER(FULL_CAPACITY_REPORT_REGISTER_ADDRESS,&MAX17320.full_capacity_report);
}

void MAX17320_TIME_TO_EMPTY_REGISTER_R(void)    //READ
{	
	MAX17320_READ_DATA_FROM_REGISTER(TIME_TO_EMPTY_REGISTER_ADDRESS,&MAX17320.time_to_empty);
}

void MAX17320_QR_TABLE_00_REGISTER_R(void)        //not important
{
	MAX17320_READ_DATA_FROM_REGISTER(QR_TABLE_00_REGISTER_ADDRESS,&MAX17320.qr_table_00);
}

void MAX17320_FULL_SOC_THRESHOLD_REGISTER_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(QR_TABLE_00_REGISTER_ADDRESS,&MAX17320.full_soc_threshold);
}

void MAX17320_FULL_SOC_THRESHOLD_REGISTER_W(uint16_t full_soc_threshold)    //this soc is related to the reported soc and act as threshold for the reported soc 
{
	MAX17320_WRITE_DATA_TO_REGISTERS(FULL_SOC_THRESHOLD_REGISTER_ADDRESS,full_soc_threshold);
}


void MAX17320_RCELL_REGISTER_R(void)              																	 //get the internal cell resistance
{	
	MAX17320_READ_DATA_FROM_REGISTER(RCELL_REGISTER_ADDRESS,&MAX17320.rcell);
}

void MAX17320_AVERAGE_TEMPERATURE_REGISTER_R(void)                            			 //get the average temperature   
{
	MAX17320_READ_DATA_FROM_REGISTER(AVERAGE_TEMPERATURE_REGISTER_ADDRESS,&MAX17320.avgTA);
}

void MAX17320_CYCLE_COUNT_REGISTER_R(void)																					 //check the number of charge and discharge cycles of the cells
{
	MAX17320_READ_DATA_FROM_REGISTER(CYCLE_COUNT_REGISTER,&MAX17320.cycle_count);		  // each of the lsb bit is of (multiply the bits by 0.25)
}

void MAX17320_DESIGN_CAPACITY_REGISTER_W(uint16_t design_capacity)									 //write //used to write the design capacity of the battery
{
	MAX17320_WRITE_DATA_TO_REGISTERS(DESIGN_CAPACITY_REGISTER_ADDRESS,design_capacity);
}

void MAX17320_DESIGN_CAPACITY_REGISTER_R(void)														           //write //used to write the design capacity of the battery
{
	MAX17320_READ_DATA_FROM_REGISTER(DESIGN_CAPACITY_REGISTER_ADDRESS,&MAX17320.design_capacity);
}

void MAX17320_AVERAGE_VOLTAGE_CELL_REGISTER_R(void)  																 //get the average temperature //not so imp
{
	MAX17320_READ_DATA_FROM_REGISTER(AVERAGE_VOLTAGE_CELL_REGISTER_ADDRESS,&MAX17320.avgVcell);  
}

void MAX17320_VCELL_REGISTER_R(void) 																								 //Get the lowest readings from the cell
{
	MAX17320_READ_DATA_FROM_REGISTER(VCELL_REGISTER_ADDRESS,&MAX17320.vcell);
}

void MAX17320_TEMPERATURE_REGISTER_R(void)                                             //get the highest temperature   
{
	MAX17320_READ_DATA_FROM_REGISTER(TEMPERATURE_REGISTER_ADDRESS,&MAX17320.temp);
}

void MAX17320_CURRENT_REGISTER(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(CURRENT_REGISTER_ADDRESS,&MAX17320.current);
}

void MAX17320_AVERAGE_CURRENT_REGISTER_R(void)                                       //not important
{
	MAX17320_READ_DATA_FROM_REGISTER(AVERAGE_CURRENT_REGISTER_ADDRESS,&MAX17320.average_current);
}

void MAX17320_CHARGE_TERMINATION_REGISTER_R(void)                                    //106
{
	MAX17320_READ_DATA_FROM_REGISTER(CHARGE_TERMINATION_REGISTER_ADDRESS,&MAX17320.charge_termination);
}

void MAX17320_CHARGE_TERMINATION_REGISTER_W(uint16_t charge_termination)
{
	MAX17320_WRITE_DATA_TO_REGISTERS(CHARGE_TERMINATION_REGISTER_ADDRESS,charge_termination);
}

void MAX17320_AVERAGE_CAPACITY_REGISTER_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(AVERAGE_CAPACITY_REGISTER,&MAX17320.average_capacity);
}
