/*********************************************************************
*
*	Copyright (c)dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	system_clock.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	system_clock.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-07 10:41:48
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __SYSTEM_CLOCK_H__
#define __SYSTEM_CLOCK_H__
#include <stdint.h>

void system_clock_init(void);

void system_tick_init(void);

uint32_t get_msec(void);
#endif //__SYSTEM_CLOCK_H__

