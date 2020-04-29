/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_x5043.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_x5043.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2020-04-27 13:48:46
*   Description:	修改说明
*
*
*********************************************************************/


#ifndef __DRV_X5043_H__
#define __DRV_X5043_H__

#include <stdint.h>

typedef enum {
	E_TIMEOUT_1_6S,
	E_TIMEOUT_600MS,
	E_TIMEOUT_200MS,
	E_WDG_DISABLE
}WDG_STATUS;

typedef enum {
	E_PROTECT_NONE,
	E_PROTECT_HIGH,
	E_PROTECT_MIDDLE,
	E_PROTECT_LOW
}PROTECT_ARRAY;

typedef enum {
	E_CMD_ENALBE_WR,		//使能写入数据
	E_CMD_DISABLE_WR,		//关闭写入数据
	E_CMD_PROTECT,			//设置保护区域
	E_CMD_SET_WDG,			//配置看门狗状态
	E_CMD_GET_STATUS		//获取寄存器状态
}IOCTRL_X5043;

typedef struct {
	uint8_t wdg;
	uint8_t protect;
	void *wp;
	void *cs;
	void *spi;
} x5043_config_t;

typedef struct {
	uint8_t port;		/* rtc port */
	x5043_config_t config;	/* rtc config */
	void   *priv;		/* priv data */
} x5043_dev_t;

int32_t x5043_init(x5043_dev_t *dev);
int32_t x5043_write(x5043_dev_t *dev,uint16_t address,uint8_t byte);
int32_t x5043_read(x5043_dev_t *dev,uint16_t address,uint8_t *pbuf);
int32_t x5043_ioctrl(x5043_dev_t *dev,uint8_t cmd,uint8_t *buf);

#endif
