/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_8025t.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_8025t.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-07 13:48:46
*   Description:	修改说明
*
*
*********************************************************************/

#include "drv_8025t.h"
#include "i2c.h"
#include "common_tools.h"

#include "errno-base.h"
//#include "stm32l0xx_ll_i2c.h"


#define SLAVE_ADDRESS			0x64
#define RTC_8025_GET_TIME		0x65
#define RTC_8025_SET_TIME		0x64


#define RTC_8025_REG_SECOND		0x00
#define RTC_8025_REG_MINUTES		0x01
#define RTC_8025_REG_HOUR		0x02
#define RTC_8025_REG_WEEK		0x03
#define RTC_8025_REG_DAY		0x04
#define RTC_8025_REG_MONTH		0x05
#define RTC_8025_REG_YEAR		0x06
#define RTC_8025_REG_RAM		0x07
#define RTC_8025_REG_ALARM_M		0x08
#define RTC_8025_REG_ALARM_H		0x09
#define RTC_8025_REG_ALARM_WD		0x0A
#define RTC_8025_REG_TIMER_C0		0x0B
#define RTC_8025_REG_TIMER_C1		0x0C
#define RTC_8025_REG_EXT		0x0D
#define RTC_8025_REG_FLAG		0x0E
#define RTC_8025_REG_CTL		0x0F


int32_t rtc_set_it(rtc_dev_t *rtc);
int32_t rtc_init(rtc_dev_t *rtc)
{
	int32_t ret = -EPERM;

	if(rtc == NULL){
		return ret;
	}
	
	if(rtc->priv == NULL){
		return ret;
	}
	
	rtc_set_it(rtc);

	ret = 0;
	
	return ret;
}

int32_t rtc_get_time(rtc_dev_t *rtc, struct tm *time)
{
	int32_t ret = -EPERM;
	uint8_t buf[16];
	i2c_mem_t i2c_mem = {RTC_8025_REG_SECOND,buf};
	uint32_t size = 7;

	if(rtc == NULL){
		return ret;
	}
	
	if(0 > i2c_mem_read((i2c_dev_t*)rtc->priv,&i2c_mem,size)){
		return ret;
	}
	
	time->tm_sec = bcd2bin(buf[0]&0x7f);
	time->tm_min = bcd2bin(buf[1]&0x7f);
	time->tm_hour = bcd2bin(buf[2]&0x3f);
	time->tm_mday = bcd2bin(buf[4]&0x3f);
	time->tm_wday = bcd2bin(buf[3]&0x07);
	time->tm_mon = bcd2bin(buf[5]&0x1f) - 1;
	time->tm_year = (100 + bcd2bin(buf[6]&0xff));
	
	if(!(buf[0] & 0x80)){
		ret = 0;
	}
	
	return ret;
}

int32_t rtc_set_time(rtc_dev_t *rtc, struct tm *time)
{
	int32_t ret = -EPERM;
	uint8_t buf[16];
	i2c_mem_t i2c_mem = {RTC_8025_REG_SECOND,buf};
	uint32_t size = 7;

	if(rtc == NULL){
		return ret;
	}
	
	buf[0] = bin2bcd(time->tm_sec)&0x7f;
	buf[1] = bin2bcd(time->tm_min)&0x7f;
	buf[2] = bin2bcd(time->tm_hour)&0x3f;
	buf[4] = bin2bcd(time->tm_mday)&0x3f;
	buf[3] = bin2bcd(time->tm_wday)&0x07;
	buf[5] = bin2bcd(time->tm_mon + 1)&0x1f;
	buf[6] = bin2bcd((uint8_t)(time->tm_year - 100))&0xff;
	
	if(0 > i2c_mem_write((i2c_dev_t*)rtc->priv,&i2c_mem,size)){
		return ret;
	}
	
	ret = 0;
	
	return ret;
}

int32_t rtc_set_it(rtc_dev_t *rtc)
{
	int32_t ret = -EPERM;
	uint8_t buf[16];
	i2c_mem_t i2c_mem = {RTC_8025_REG_RAM,buf};
	uint32_t size = 9;

	if(rtc == NULL){
		return ret;
	}
	
	buf[0] = 0x00;
	buf[1] = 0x00;
	buf[2] = 0x00;
	buf[3] = 0x00;
	buf[4] = 0x01;
	buf[5] = 0x00;
	buf[6] = 0x12;
	buf[7] = 0x00;
	buf[8] = 0x10;
	
	if(0 > i2c_mem_write((i2c_dev_t*)rtc->priv,&i2c_mem,size)){
		return ret;
	}
	
	ret = 0;
	
	return ret;
}
