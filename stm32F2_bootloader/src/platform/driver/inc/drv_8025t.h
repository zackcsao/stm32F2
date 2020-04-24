/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_8025t.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_8025t.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-07 13:49:10
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __DRV_8025T_H__
#define __DRV_8025T_H__

#include <time.h>
#include <stdint.h>

/*******************RTC start *********************************/

typedef struct {
	uint32_t year_base;  
} rtc_config_t;

typedef struct {
	uint8_t port;		/* rtc port */
	rtc_config_t config;	/* rtc config */
	void   *priv;		/* priv data */
} rtc_dev_t;


/**
 * This function will initialize the on board CPU real time clock
 *
 *
 * @param[in]  rtc  rtc device
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t rtc_init(rtc_dev_t *rtc);


/**
 * This function will return the value of time read from the on board CPU real time clock.
 *
 * @param[in]   rtc   rtc device
 * @param[out]  time  pointer to a time structure
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t rtc_get_time(rtc_dev_t *rtc, struct tm *time);

/**
 * This function will set MCU RTC time to a new value.
 *
 * @param[in]   rtc   rtc device
 * @param[out]  time  pointer to a time structure
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t rtc_set_time(rtc_dev_t *rtc, struct tm *time);

int32_t rtc_8025t_ioctl(rtc_dev_t *rtc,uint32_t cmd,uint8_t *data);

/**
 * De-initialises an RTC interface, Turns off an RTC hardware interface
 *
 * @param[in]  RTC  the interface which should be de-initialised
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t rtc_finalize(rtc_dev_t *rtc);
#endif //__DRV_8025T_H__

