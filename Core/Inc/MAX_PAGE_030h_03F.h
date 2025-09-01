#ifndef __MAX_PAGE_030h_03Fh_H
#define __MAX_PAGE_030h_03Fh_H

#include "main.h"
#include "i2c.h"
#include "MAX17320.h"

									//START OF PAGE 030h TO 03Fh //
//RESERVED// 													                       // 0x30  //
//RESERVED// 													                       // 0x31  //
#define QR_TALBE_20_REGISTER_ADDRESS												    0X32
//RESERVED// 													                       // 0x33  //
#define DIE_TEMPERATURE_REGISTER_ADDRESS												0X34
// implement #define DIE_TEMPERATURE_REGISTER_ADDRESS												0X35
// implement #define DIE_TEMPERATURE_REGISTER_ADDRESS												0X36
//RESERVED// 													                       // 0x37  //
//RESERVED// 													                       // 0x38  //
//RESERVED// 													                       // 0x39  //
#define VOLTAGE_EMPTY_REGISTER_ADDRESS													0X3A
//RESERVED// 													                       // 0x3B  //
//RESERVED// 													                       // 0x3C  //
#define FSTATUS_REGISTER_ADDRESS																0x3D
#define TIMER_REGISTER_ADDRESS																	0X3E
//RESERVED// 													                       // 0x3F  //

void MAX17320_QR_TABLE_20_REGISTER_R(void);                   // read
void MAX17320_DIE_TEMPERATURE_REGISTER_R(void);								// read //shows the iternal temperatuer i degree celsius  
void MAX17320_VOLTAGE_EMPTY_REGISTER_W(uint16_t);							// write // gine the empty voltage ad the recovery voltage  // (ve * 0.01) (vr * 0.04)
void MAX17320_VOLTAGE_EMPTY_REGISTER_R(void);                 // read the values at which the fuel gauge consider as the voltage is empty ad the recovery voltage
void MAX17320_FSTATUS_REGISTER_R(void);                       // read  //118  //give the relaxed state
void MAX17320_TIMER_REGISTER_R(void);                         // read only //give timer  //103

#endif
