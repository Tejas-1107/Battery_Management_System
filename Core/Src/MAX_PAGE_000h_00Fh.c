#include "MAX_PAGE_000h_00Fh.h"

void MAX17320_STATUS_REGISTERS_R(void)																							// por,imin,imax,dSoC,Vmin,Vmax,Tmin,Tmax,Smin,Smax,PA these status are stored in the status registers
{																																									// we should set the values to get the status 
	MAX17320_READ_DATA_FROM_REGISTER(STATUS_REGISTER_ADDRESS,&MAX17320.status_register);
}

void MAX17320_VOLTAGE_ALERT_THRESHOLD_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(VOLTAGE_ALERT_THRESHOLD_REGISTER_ADDRESS,&MAX17320.voltage_alert_threshold);
}

void MAX17320_VOLTAGE_ALERT_THRESHOLD_W(uint16_t volt_min_max)                  		// this will store the min and max values of the voltage if this exceeds then in the status register the correspoding bit will be set or reset
{																																									// multiply by 20mv to get the vmax and vmin threholds
	MAX17320_WRITE_DATA_TO_REGISTERS(VOLTAGE_ALERT_THRESHOLD_REGISTER_ADDRESS,volt_min_max);
}

void MAX17320_TEMPERATURE_ALERT_THRESHOLD_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(TEMPERATURE_ALERT_THRESHOLD_REGISTER_ADDRESS,&MAX17320.temperature_alert_threshold);
}

void MAX17320_TEMPERATURE_ALERT_THRESHOLD_W(uint16_t temp_min_max)									// this will store the min and max values of the temperature if this exceeds then in the status register the correspoding bit will be set or reset
{
	MAX17320_WRITE_DATA_TO_REGISTERS(TEMPERATURE_ALERT_THRESHOLD_REGISTER_ADDRESS,temp_min_max);
}

void MAX17320_SOC_ALERT_THRESHOLD_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(SOC_ALERT_THRESHOLD_REGISTER_ADDRESS,&MAX17320.soc_alert_threshold);
}

void MAX17320_SOC_ALERT_THRESHOLD_W(uint16_t min_max_soc)														// this will store the min and max values of the soc if this exceeds then in the status register the correspoding bit will be set or reset
{
	MAX17320_WRITE_DATA_TO_REGISTERS(SOC_ALERT_THRESHOLD_REGISTER_ADDRESS,min_max_soc);
}

void MAX17320_AT_RATE_REGISTER_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(AT_RATE_REGISTER_ADDRESS,&MAX17320.at_rate);
}

void MAX17320_AT_RATE_REGISTER_W(uint16_t at_rate)
{
	MAX17320_WRITE_DATA_TO_REGISTERS(AT_RATE_REGISTER_ADDRESS,at_rate);
	HAL_Delay(1000);
}

void MAX17320_REPORTED_CAPACITY_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(REPORTED_CAPACITY_REGISTER_ADDRESS,&MAX17320.reported_capacity);
}

void MAX17320_REPORTED_SOC_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(REPORTED_SOC_REGISTER_ADDRESS,&MAX17320.reported_soc);	
}

void MAX17320_AGE_REGISTER_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(AGE_REGISTER_ADDRESS,&MAX17320.age_register);
}

void MAX17320_MAX_MIN_VOLTAGE_REGISTER_R(void)         
{																																									// multiply by 20mv to get the max and min voltage values 	
	MAX17320_READ_DATA_FROM_REGISTER(MAX_MIN_VOLTAGE_REGISTER_ADDRESS,&MAX17320.max_min_voltage);
}
//
void MAX17320_MAX_MIN_TEMPERATURE_REGISTER_R(void)         													//inital value 807f
{																																									// multiply by 1C to get the max and min voltage values 
	MAX17320_READ_DATA_FROM_REGISTER(MAX_MIN_TEMPERATURE_REGISTER_ADDRESS,&MAX17320.max_min_temperature);
}

void MAX17320_MAX_MIN_CURRENT_REGISTER_R(void)
{	
	MAX17320_READ_DATA_FROM_REGISTER(MAX_MIN_CURRENT_REGISTER_ADDRESS,&MAX17320.max_min_current);
}

void MAX17320_CONFIGURATION_REGISTER_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(CONFIGURATION_REGISTER_ADDRESS,&MAX17320.config);
}

void MAX17320_CONFIGURATION_REGISTER_W(uint16_t config_register)
{
	MAX17320_WRITE_DATA_TO_REGISTERS(CONFIGURATION_REGISTER_ADDRESS,config_register);
}

void MAX17320_QRESIDUAL_REGISTER_R(void)                                            //amount of current present still inside the cell
{	
	MAX17320_READ_DATA_FROM_REGISTER(QRESIDUAL_REGISTER_ADDRESS,&MAX17320.q_residual);
}

void MAX17320_MIXSOC_REGISTER_R(void)																								//mix mode estimation of coloumb counting,modelgauge m5,ocv estimation
{	
	MAX17320_READ_DATA_FROM_REGISTER(MIXSOC_REGISTER_ADDRESS,&MAX17320.mixsoc);
}

void MAX17320_AVERAGE_SOC_REGISTER_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(AVERAGE_SOC_REGISTER_ADDRESS,&MAX17320.avgsoc);
}

void MAX17320_MISSCELANEOUS_CONFIGURATION_REGISTER_R(void)
{
	MAX17320_READ_DATA_FROM_REGISTER(MISCELLANIOUS_REGISTER_ADDRESS,&MAX17320.miscellanous_configuration);
}

void MAX17320_MISSCELANEOUS_CONFIGURATION_REGISTER_W(uint16_t miscellanious)
{
	MAX17320_WRITE_DATA_TO_REGISTERS(MISCELLANIOUS_REGISTER_ADDRESS,miscellanious);
}
