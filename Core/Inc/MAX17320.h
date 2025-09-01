#ifndef __MAX17320_H
#define __MAX17320_H

#include "main.h"
#include "I2C.H"

#define MAX17320_I2C_SLAVE_ADDR   	(0x6c << 1) 
#define NUM_CELLS 4

typedef struct
{
	uint8_t Npackcfg_Register_data[3];
	uint16_t device_name;
	uint8_t Cell1_Cell4_Register_data[NUM_CELLS][2];
	float cell_volatge[4];
	uint8_t sManufactureDate_Register_data[2];
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint16_t reported_capacity;
	uint16_t reported_soc;
	uint16_t time_to_empty;
	uint16_t time_to_full;
	uint16_t full_capacity_report;
	uint16_t voltage_alert_threshold;
	uint16_t temperature_alert_threshold;
	uint16_t soc_alert_threshold;
	uint16_t status_register;
	uint16_t at_rate;
	uint16_t age_register;
	uint16_t max_min_voltage;
	uint16_t max_min_temperature;
	uint16_t max_min_current;
	uint16_t config;
	uint16_t q_residual;
	uint16_t mixsoc;
	uint16_t avgsoc;
	uint16_t miscellanous_configuration;
	uint16_t qr_table_00;
	uint16_t qr_table_10;
	uint16_t qr_table_20;
	uint16_t qr_table_30;
	uint16_t vempty;
	uint16_t qh;
	uint16_t ql;
	uint16_t full_soc_threshold;
	uint16_t full_capacity_nominal;
	uint16_t rcell;
	uint16_t avgTA;
	uint16_t cycle_count;
	uint16_t design_capacity;
	uint16_t avgVcell;
	uint16_t vcell;
	uint16_t temp;
	uint16_t current;
	uint16_t average_current;
	uint16_t charge_termination;
	uint16_t average_capacity;
	uint16_t charging_current;
	uint16_t charging_voltage;
	uint16_t filter_configuration;
	uint16_t mixcapacity;
	uint16_t die_temperature;
	uint16_t fstatus;
	uint16_t timer;
	uint16_t average_timer_register;
	uint16_t voltage_fuel_remaining_capacity;
	uint16_t protection_alert_register;
	uint16_t status2_register;
	uint16_t power_register;
	uint16_t voltage_ripple;
	uint16_t average_power;
	uint16_t age_forecast;
	uint16_t timerh;
	uint16_t soc_hold;
	uint16_t average_cell_4;
	uint16_t average_cell_3;
	uint16_t average_cell_2;
	uint16_t average_cell_1;
	uint16_t cell_4;
	uint16_t cell_3;
	uint16_t cell_2;
	uint16_t cell_1;
	uint16_t protection_status;
	uint16_t battery;
	uint16_t pckp;
	uint16_t at_qresidual;
	uint16_t at_time_to_empty;
	uint16_t at_average_capacity;\
	uint16_t relax_config;
	uint16_t learn_config;
	uint16_t ialrtth;
}struct_MAX17320;

extern struct_MAX17320 MAX17320;

void MAX17320_WRITE_DATA_TO_REGISTERS(uint8_t,uint16_t);								//write function
void MAX17320_READ_DATA_FROM_REGISTER(uint8_t,uint16_t*);								//read function
#endif
