#ifndef __MAX_PAGE_000h_000Fh_H
#define __MAX_PAGE_000h_000Fh_H

#include "main.h"
#include "MAX17320.h"

							//START OF PAGE 000h TO 00Fh //
#define STATUS_REGISTER_ADDRESS 																0X00//
#define VOLTAGE_ALERT_THRESHOLD_REGISTER_ADDRESS 								0x01//yes - r
#define TEMPERATURE_ALERT_THRESHOLD_REGISTER_ADDRESS 						0x02//yes - r
#define SOC_ALERT_THRESHOLD_REGISTER_ADDRESS 										0X03//yes - r
#define AT_RATE_REGISTER_ADDRESS																0X04//
#define REPORTED_CAPACITY_REGISTER_ADDRESS 											0X05//
#define REPORTED_SOC_REGISTER_ADDRESS 													0X06//
#define AGE_REGISTER_ADDRESS 																		0X07//
#define MAX_MIN_VOLTAGE_REGISTER_ADDRESS 												0X08//yes - r
#define MAX_MIN_TEMPERATURE_REGISTER_ADDRESS 										0X09//yes - r
#define MAX_MIN_CURRENT_REGISTER_ADDRESS 												0X0A//yes - r
#define CONFIGURATION_REGISTER_ADDRESS													0X0B
#define QRESIDUAL_REGISTER_ADDRESS 															0X0C
#define MIXSOC_REGISTER_ADDRESS 																0X0D
#define AVERAGE_SOC_REGISTER_ADDRESS 														0X0E
#define MISCELLANIOUS_REGISTER_ADDRESS													0X0F

void MAX17320_STATUS_REGISTERS_R(void);    																//read
void MAX17320_VOLTAGE_ALERT_THRESHOLD_R(void);														//read     //multiply by 0.20 by the bits
void MAX17320_VOLTAGE_ALERT_THRESHOLD_W(uint16_t);  											//write		 //120
void MAX17320_TEMPERATURE_ALERT_THRESHOLD_R(void);												//read     //multiply by 1 celsius
void MAX17320_TEMPERATURE_ALERT_THRESHOLD_W(uint16_t);   									//write    //120
void MAX17320_SOC_ALERT_THRESHOLD_R(void);																//read     //121
void MAX17320_SOC_ALERT_THRESHOLD_W(uint16_t);														//write    //it is used to set the soc min and max value and the triger is set in the misccfgregister(0x00f)
void MAX17320_AT_RATE_REGISTER_R(void);																		//read
void MAX17320_AT_RATE_REGISTER_W(uint16_t);																//write		 //used to simulate the hypotetical load current //119 //give the negative value
void MAX17320_REPORTED_CAPACITY_R(void);    															//read		 //final reported capacity value  //101
void MAX17320_REPORTED_SOC_R(void);         															//read     //FINAL soc value  //101
void MAX17320_AGE_REGISTER_R(void);  																			//read
void MAX17320_MAX_MIN_VOLTAGE_REGISTER_R(void);  													//read		 //get the max and min values of voltage  //convert the bits to decimal multiply bt 0.20
void MAX17320_MAX_MIN_TEMPERATURE_REGISTER_R(void);   										//read     //get the max and min value of temperature  //convert the bits and multiply by 1C
void MAX17320_MAX_MIN_CURRENT_REGISTER_R(void);														//read     //95  //get the max and min value of current  //convert the bits nad multiply by 0.40
void MAX17320_CONFIGURATION_REGISTER_R(void);															//read		 //106
void MAX17320_CONFIGURATION_REGISTER_W(uint16_t);													//write		 //106
void MAX17320_QRESIDUAL_REGISTER_R(void);   															//read     //115
void MAX17320_MIXSOC_REGISTER_R(void);  																	//read		 //116
void MAX17320_AVERAGE_SOC_REGISTER_R(void); 														  //read		 //116
void MAX17320_MISSCELANEOUS_CONFIGURATION_REGISTER_R(void);								//read
void MAX17320_MISSCELANEOUS_CONFIGURATION_REGISTER_W(uint16_t);						//write

#endif
