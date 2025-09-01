#ifndef __SBS_PAGE_100h_10fh_H
#define __SBS_PAGE_100h_10fh_H

#include "main.h"
#include "MAX17320_SBS_PROTOCOL.h"

#define sMANUFACTURE_ACCES_REGISTER_ADDRESS    					0X00     //R   		//150
#define sREMAINING_CAPACITY_ALARM_REGISTER_ADDRESS			0X01		 //R W		//150
#define sREMIANING_TIME_ALARM_REGISTER_ADDRESS					0X02		 //R W    //150
#define sBATTERY_MODE_REGISTER_ADDRESS									0X03		 //R W    //150
#define sAT_RATE_REGISTER_ADDRESS												0X04//n
#define sAT_TIME_TO_FULL_REGISTER_ADDRESS								0X05//n
#define sAT_TIME_TO_EMPTY_REGISTER_ADDRESS							0X06//n
#define sAT_RATE_OK_REGISTER_ADDRESS										0X07//n
#define sTEMPERATURE_REGISTER_ADDRESS										0X08		 //R			//152
#define sPACK_VOLTAGE_REGISTER_ADDRESS									0X09		 //R			//152
#define sCURRENT_REGISTER_ADDRESS   										0X0A		 //R      //152
#define sAVERAGE_CURRENT_REGISTER_ADDRESS								0X0B		 //R      
#define sMAXIMUM_ERROR_REGISTER_ADDRESS									0X0C
#define sRELATED_SOC_REGISTER_ADDRESS										0X0D
#define sABS_SOC_REGISTER_ADDRESS	    									0X0E
#define sREMAINING_CAPACITY_REGISTER_ADDRESS						0X0F

typedef struct
{
	uint16_t s_manufacture_access;
	uint16_t s_remaining_capacity_alarm;
	uint16_t s_remaining_time_alarm;
	uint16_t s_battery_mode;
	uint16_t s_at_rate;
	uint16_t s_temperature;
	float sbs_temperature;
	uint16_t s_pack_voltage;
	float sbs_voltage;
	uint16_t s_current;
	uint16_t s_average_current;

}struct_SBS_page1;

extern struct_SBS_page1 SBS_page1;

void MAX17320_SBS_sMANUFACTURE_ACCESS_REGISTER(void);
void MAX17320_SBS_sREMAINING_CAPACITY_ALARM_REGISTER_R(void);
void MAX17320_SBS_sREMAINING_CAPACITY_ALARM_REGISTER_W(uint16_t);   //set the remaining_capacity
void MAX17320_SBS_sREMIANING_TIME_ALARM_REGISTER_R(void);
void MAX17320_SBS_sREMIANING_TIME_ALARM_REGISTER_W(uint16_t);       //set the remaining_time_to_TTE
void MAX17320_SBS_sBATTERY_MODE_REGISTER_R(void);
void MAX17320_SBS_sBATTERY_MODE_REGISTER_W(uint16_t);       				//set only the 15th bit (1 - mWh) or (0 - mah)
void MAX17320_SBS_sTEMPERATURE_REGISTER_R(void);    								//get the temperature
void MAX17320_SBS_sPACK_VOLTAGE_REGISTER_R(void);										//get the pack voltage
void MAX17320_SBS_sCURRENT_REGISTER_R(void);												//get the current value
void MAX17320_SBS_sAVERAGE_CURRENT_REGISTER_R(void);
#endif
