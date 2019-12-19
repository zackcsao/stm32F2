/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	bsp.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	bsp.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 09:58:20
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __BSP_H__
#define __BSP_H__
#include <stdint.h>
#include <time.h>
#include "gpio_define.h"
// <<< Use Configuration Wizard in Context Menu >>>
// <c1> Opening or closing printing information
// <i> printing information by uart
#define DEBUG_PRINTF
// </c>

// <<< end of configuration section >>>

typedef struct {
	uint32_t (*sys_get_sec)(void);
	uint32_t (*sys_get_msec)(void);
	uint8_t (*sys_get_calendar)(struct tm *prtc);
	uint8_t (*sys_set_calendar)(struct tm *prtc);
	void (*feed_wdg)(void);
	void (*maintain_soft_rtc)(void);
}SYS_FUNC;

void bsp_init(void);
void flash_gpio_cs(uint32_t status);
uint32_t get_sec(void);
int32_t fram_enable(uint8_t status);

#endif //__BSP_H__

