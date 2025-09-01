#ifndef __MAX_PAGE_010h_01Fh_H
#define __MAX_PAGE_010h_01Fh_H

#include "main.h"
#include "MAX17320.h"

							//START OF PAGE 010h TO 01Fh //
#define FULL_CAPACITY_REPORT_REGISTER_ADDRESS 			            0X10
#define TIME_TO_EMPTY_REGISTER_ADDRESS							            0x11
#define QR_TABLE_00_REGISTER_ADDRESS														0x12
#define FULL_SOC_THRESHOLD_REGISTER_ADDRESS											0x13           
#define RCELL_REGISTER_ADDRESS 																	0X14
//RESERVED// 													                       // 0x15  //
#define AVERAGE_TEMPERATURE_REGISTER_ADDRESS 										0X16
#define CYCLE_COUNT_REGISTER 																		0X17
#define DESIGN_CAPACITY_REGISTER_ADDRESS 												0X18
#define AVERAGE_VOLTAGE_CELL_REGISTER_ADDRESS 									0X19
#define VCELL_REGISTER_ADDRESS 																	0X1A
#define TEMPERATURE_REGISTER_ADDRESS 														0X1B
#define CURRENT_REGISTER_ADDRESS 																0X1C
#define AVERAGE_CURRENT_REGISTER_ADDRESS 												0X1D
#define CHARGE_TERMINATION_REGISTER_ADDRESS                     0X1E  //not implemented
#define AVERAGE_CAPACITY_REGISTER 															0X1F

void MAX17320_FULL_CAPACITY_REPORT_R(void);    									//read	//same as the design capacity
void MAX17320_TIME_TO_EMPTY_REGISTER_R(void);										//read  //102  //multiply the bits by converting and multiply by 0.00515
void MAX17320_QR_TABLE_00_REGISTER_R(void);                     //READ  //not so imp
void MAX17320_FULL_SOC_THRESHOLD_REGISTER_R(void); 							//read
void MAX17320_FULL_SOC_THRESHOLD_REGISTER_W(uint16_t);					//write
void MAX17320_RCELL_REGISTER_R(void); 													//read  //not so imp
void MAX17320_AVERAGE_TEMPERATURE_REGISTER_R(void);							//read  //average timings at which it will tahe the readings do not change
void MAX17320_CYCLE_COUNT_REGISTER_R(void);   									//read  //give the number of charge and discharge cycles happebed in the battery
void MAX17320_DESIGN_CAPACITY_REGISTER_R(void);									//read
void MAX17320_DESIGN_CAPACITY_REGISTER_W(uint16_t);  						//write  //same as full capacity
void MAX17320_AVERAGE_VOLTAGE_CELL_REGISTER_R(void);            //read   //not so imp
void MAX17320_VCELL_REGISTER_R(void);														//read   //low voltage
void MAX17320_TEMPERATURE_REGISTER_R(void);             				//read   //high temperature
void MAX17320_CURRENT_REGISTER(void);														//read
void MAX17320_AVERAGE_CURRENT_REGISTER_R(void);                 //read   //not important
void MAX17320_CHARGE_TERMINATION_REGISTER_R(void);							//read
void MAX17320_CHARGE_TERMINATION_REGISTER_W(uint16_t);					//write  //important charge termination (charge_termination / 0.208)
void MAX17320_AVERAGE_CAPACITY_REGISTER_R(void);                //read   //not important
#endif
