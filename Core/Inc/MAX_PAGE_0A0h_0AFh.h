#ifndef __MAX_PAGE_0A0h_0AFh_H
#define __MAX_PAGE_0A0h_0AFh_H

#include "main.h"
#include "i2c.h"
#include "MAX17320.h"

								//START OF PAGE 0A0h TO 0AFh //
#define RELAX_CONFIGURATION_REGISTER_ADDRESS										0XA0
#define LEARNING_CONFIGURATION_REGISTER_ADDRESS 								0XA1
//RESERVED// 													                       // 0xA2  //
//RESERVED// 													                       // 0xA3  //
//#define MAX_PEAK_POWER_REGISTER_ADDRESS													0XA4   not implemented      
//#define SUSTAIN_PEAK_POWER_REGISTER_ADDRESS											0XA5   not implemented   
//#define PACK_RESISTANCE_REGISTER_ADDRESS												0XA6   not implemented
//#define SYSTEM_RESISTANCE_REGISTER_ADDRESS											0XA7   not implemented
//#define MINIMUM_SYSYTEM_VOLTAGE_REGISTER_ADDRESS								0XA8   not implemented
//#define MPP_CURRENT_REGISTER_ADDRESS														0XA9   not implemented
//#define SPP_CURRENT_REGISTER_ADDRESS														0XAA   not implemented
//#define CONFIGURATION_2_REGISTER_ADDRESS    										0XAB   not implemented
#define CURRENT_ALERT_THRESHOLD_REGISTER_ADDRESS								0XAC
//#define MINIMUM_VOLTAGE_REGISTER_ADDRESS    										0XAD   not implemented
//#define MINIMUM_CURRENT_REGISTER_ADDRESS    										0XAE   not implemented
#define PROTECTION_ALERT_REGISTER_ADDRESS												0XAF

void MAX17320_RELAX_CONFIGURATION_REGISTER_R(void);                       //important
void MAX17320_RELAX_CONFIGURATION_REGISTER_W(uint16_t);
void MAX17320_LEARNING_CONFIGURATION_REGISTER_R(void);
void MAX17320_LEARNING_CONFIGURATION_REGISTER_W(uint16_t);
void MAX17320_CURRENT_LIMIT_ALERT_THRESHOLD_REGISTER_R(void);
void MAX17320_CURRENT_LIMIT_ALERT_THRESHOLD_REGISTER_W(uint16_t);
void MAX17320_PROTECTION_ALERT_REGISTER_R(void);

#endif
