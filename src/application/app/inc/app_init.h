/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	app_init.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	app_init.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-20 15:13:11
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __APP_INIT_H__
#define __APP_INIT_H__
#include <stdint.h>

#define  APP_TASK_START_PRIO			2u
#define  FLASH_DEBUG_TASK_PRIO			5u
#define  LED_TASK_PRIO				7u

#define PRIO_SYSTEM_MAINTAIN			10u
#define PRIO_DEAL_DATA				11u
#define PRIO_DISPLAY				18u
#define PRIO_GSM				16u
#define PRIO_GATHER_DEV_STATUS			13u
#define PRIO_CONTROL_MOTOR			12u
#define PRIO_POWER_MANAGEMENT			13u
#define PRIO_GATHER_WATER_LEVEL			14u
#define PRIO_LOG_HISTORY			19U
#define PRIO_TEST				19U


#define	APP_TASK_START_STK_SIZE			128u
#define	FLASH_DEBUG_TASK_STK_SIZE		128u
#define	LED_TASK_STK_SIZE			128u

#define STK_SYSTEM_MAINTAIN_SIZE		128u
#define STK_DEAL_DATA_SIZE			128u
#define STK_DISPLAY_SIZE			128u
#define STK_GSM_SIZE				128u
#define STK_GATHER_DEV_STATUS_SIZE		128u
#define STK_CONTROL_MOTOR_SIZE			128u
#define STK_POWER_MANAGEMENT_SIZE		128u
#define STK_GATHER_WATER_LEVEL_SIZE		128u
#define STK_LOG_HISTORY_SIZE			128u
#define STK_TEST_SIZE				8196u
typedef struct{
	uint8_t h_ver[3];
	uint8_t s_ver[3];
}S_VERSION;

void app_init(void);

#endif //__APP_INIT_H__

