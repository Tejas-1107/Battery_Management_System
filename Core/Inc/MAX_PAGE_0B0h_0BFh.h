#ifndef __MAX_PAGE_0B0h_0BFh_H
#define __MAX_PAGE_0B0h_0BFh_H

#include "main.h"
#include "i2c.h"
#include "MAX17320.h"

								//START OF PAGE 0B0h TO 0BFh //
#define STATUS_2_REGISTER_ADDRESS																0XB0
#define POWER_REGISTER_ADDRESS																	0XB1
#define VOLTAGE_RIPPLE_REGISTER_ADDRESS													0XB2
#define AVERAGE_POWER_REGISTER_ADDRESS													0XB3
//RESERVED// 													                       // 0xB4  //
#define TIME_TO_FULL_CONFIGURATION_REGISTER_ADDRESS
#define CV_MIX_CAPACITY_REGISTER_ADDRESS
#define CV_HALF_TIME_REGISTER_ADDRESS
#define CG_TEMP_CO_REGISTER_ADDRESS
#define AGE_FORECAST_REGISTER_ADDRESS														0XB9
//RESERVED// 													                       // 0xBA  //
//RESERVED// 													                       // 0xBB  //
//RESERVED// 													                       // 0xBC  //
//RESERVED// 													                       // 0xBD  //
#define TIMERH_REGISTER_ADDRESS																	0XBE												
//RESERVED// 													                       // 0xBF  //

void MAX17320_STATUS_2_REGISTER_R(void);
void MAX17320_POWER_REGISTER_R(void);
void MAX17320_VOLTAGE_RIPPLE_REGISTER_R(void);
void MAX17320_AVERAGE_POWER_REGISTER_R(void);
void MAX17320_AGE_FORECAST_REGISTER_R(void);
void MAX17320_TIMER_H_REGISTER_R(void);

#endif
