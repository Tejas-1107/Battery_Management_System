#ifndef __MAX_PAGE_040h_04Fh_H
#define __MAX_PAGE_040h_04Fh_H

#include "main.h"
#include "i2c.h"
#include "MAX17320.h"

									//START OF PAGE 040h TO 04Fh //
#define AVERAGE_DIETEMPERATURE_REGISTER_ADDRESS									0X40
//RESERVED// 													                       // 0x41  //
#define QR_TABLE_30_REGISTER_ADDRESS					          				0X42
//RESERVED// 													                       // 0x43  //
//RESERVED// 													                       // 0x44  //
//RESERVED// 													                       // 0x45  //
//RESERVED// 													                       // 0x46  //
//RESERVED// 													                       // 0x47  //
//RESERVED// 													                       // 0x48  //
//RESERVED// 													                       // 0x49  //
#define VOLTAGE_FUEL_REMAINING_CAPACITY_REGISER_ADDRESS					0X4A
//RESERVED// 													                       // 0x4B  //
//RESERVED// 													                       // 0x4C  //
#define QH_REGISTER_ADDRESS																			0X4D
#define QL_REGISTER_ADDRESS																			0X4E
//RESERVED// 													                       // 0x4F  //

void MAX17320_AVERAGE_DIE_REGISTER_R(void);                  // read  //not important
void MAX17320_QR_TABLE_30_REGISTER_R(void);									 // read  //not importat
void MAX17320_VOLTAGE_FUEL_REMAINING_CAPACITY_R(void);       // read  //118
void MAX17320_QH_REGISTER_R(void);													 // read  //charge count high
void MAX17320_QL_REGISTER_R(void);                           //	read	//charge count low

#endif
