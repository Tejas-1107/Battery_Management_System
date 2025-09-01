#ifndef __MAX_PAGE_020h_02Fh_H
#define __MAX_PAGE_020h_02Fh_H

#include "main.h"
#include "i2c.h"
#include "MAX17320.h"

								//START OF PAGE 020h TO 02Fh //
#define TIME_TO_FULL_REGISTER_ADDRESS  													0x20
#define DEVICE_NAME_REGISTER_ADDRESS 														0X21//yes - r
#define QR_TABLE_10_REGISTER_ADDRESS 														0X22//
#define FULL_CAPACITY_NOMINAL_REGISTER_ADDRESS                  0X23
//RESERVED// 													                       // 0x24  //
//RESERVED// 													                       // 0x25  //
//RESERVED// 													                       // 0x26  //
//RESERVED// 													                       // 0x27  //
#define CHARGING_CURRENT_REGISTER_ADDRESS												0x28
#define FILTER_CONFIGURATION_REGISTER_ADDRESS										0x29
#define CHARGING_VOLTAGE_REGISTER_ADDRESS												0X2A
#define MIX_CAPACITY_REGISTER_ADDRESS														0X2B
//RESERVED// 													                       // 0x2C  //
//RESERVED// 													                       // 0x2D  //
//RESERVED// 													                       // 0x2E  //
//RESERVED// 													                       // 0x2F  //

void MAX17320_TIME_TO_FULL_REGISTER_R(void);					          //read  102
void MAX17320_DEVICE_NAME_REGISTER_R(void);											//read  119
void MAX17320_QR_TALBE_10_REGISTER_R(void);											//READ  not imp
void MAX17320_FULL_CAPACITY_NOMINAL_REGISTER_R(void);           //read
void MAX17320_CHARGING_CURRENT_REGISTER_R(void);								//read  
void MAX17320_FILTER_CONFIGURATION_REGISTER_R(void);            //read  //set the timing constant for the average curret and the average cell voltage ,mixing algorithm,average temperature
void MAX17320_CHARGING_VOLTAGE_REGISTER_R(void);								//read
void MAX17320_MIX_CAPACITY_REGISTER_R(void);										//read   118
#endif
