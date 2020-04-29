/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_x5043.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_x5043.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2020-04-27 13:48:46
*   Description:	修改说明
*
*
*********************************************************************/

#include "drv_x5043.h"
#include "errno-base.h"
#include "gpio.h"
#include "spi.h"

#include <stdio.h>

#define CMD_WREN		0x06
#define CMD_WRDI		0x04
#define CMD_RSDR		0x05
#define CMD_WRSR		0x01
#define CMD_READ_L		0x03
#define CMD_READ_H		0x0B
#define CMD_WRITE_L		0x02
#define CMD_WRITE_H		0x0A

typedef struct {
	uint8_t reservd:2;
	uint8_t wd:2;
	uint8_t bl:2;
	uint8_t wel:1;
	uint8_t wip:1;
}X5043_REG_STATUS;


static int32_t x5043_enable_write(x5043_dev_t *dev)
{
	int32_t ret = - EPERM;
	
	if(NULL == dev){
		return ret;
	}
	
	if((NULL == dev->config.cs) || (NULL == dev->config.spi) || (NULL == dev->config.wp)){
		return ret;
	}
	
	gpio_output_low(dev->config.cs);
	spi_send_recv(dev->config.spi,CMD_WREN);
	gpio_output_high(dev->config.cs);
	
	ret = 0;
	
	return ret;
}

static int32_t x5043_disable_write(x5043_dev_t *dev)
{
	int32_t ret = - EPERM;
	
	if(NULL == dev){
		return ret;
	}
	
	if((NULL == dev->config.cs) || (NULL == dev->config.spi) || (NULL == dev->config.wp)){
		return ret;
	}
	
	gpio_output_high(dev->config.wp);
	
	ret = 0;
	
	return ret;
}

static int32_t x5043_read_status(x5043_dev_t *dev,uint8_t *pbuf)
{	
	int32_t ret = - EPERM;
	uint8_t tmp8 = 0;
	
	if(NULL == dev){
		return ret;
	}
	
	if((NULL == dev->config.cs) || (NULL == dev->config.spi) || (NULL == dev->config.wp)){
		return ret;
	}
	
	gpio_output_low(dev->config.cs);
	spi_send_recv(dev->config.spi,CMD_RSDR);
	tmp8 = spi_send_recv(dev->config.spi,0xff);
	gpio_output_high(dev->config.cs);
	printf("status = 0x%02x\r\n",tmp8);
	
	*pbuf = tmp8;
	ret = 0;
	
	return ret;
}

static int32_t x5043_write_status(x5043_dev_t *dev,uint8_t data)
{
	int32_t ret = - EPERM;
	
	if(NULL == dev){
		return ret;
	}
	
	if((NULL == dev->config.cs) || (NULL == dev->config.spi) || (NULL == dev->config.wp)){
		return ret;
	}
	
	x5043_enable_write(dev);
	gpio_output_high(dev->config.wp);
	gpio_output_low(dev->config.cs);
	spi_send_recv(dev->config.spi,CMD_WRSR);
	spi_send_recv(dev->config.spi,data);
	gpio_output_high(dev->config.cs);
	x5043_disable_write(dev);
	ret = 0;
	
	return ret;
}


int32_t x5043_init(x5043_dev_t *dev)
{
	int32_t ret = - EPERM;
	
	if(NULL == dev){
		return ret;
	}
	
	if((NULL == dev->config.cs) || (NULL == dev->config.spi) || (NULL == dev->config.wp)){
		return ret;
	}
	
	gpio_init(dev->config.wp);
	gpio_init(dev->config.cs);
	spi_init(dev->config.spi);
	
	gpio_output_high(dev->config.cs);
	gpio_output_low(dev->config.wp);
	
	return ret;
}
	
int32_t x5043_write(x5043_dev_t *dev,uint16_t address,uint8_t byte)
{
	int32_t ret = - EPERM;
	
	if(NULL == dev){
		return ret;
	}
	x5043_enable_write(dev);
	
	gpio_output_low(dev->config.cs);
	gpio_output_high(dev->config.wp);
	if( address&0x0001 ){
		spi_send_recv(dev->config.spi,CMD_WRITE_H);
	}else{
		spi_send_recv(dev->config.spi,CMD_WRITE_L);
	}
	spi_send_recv(dev->config.spi,(uint8_t)(address>>1));
	spi_send_recv(dev->config.spi,byte);
	gpio_output_low(dev->config.wp);
	gpio_output_high(dev->config.cs);
	
	ret = 0;
	return ret;
}

int32_t x5043_read(x5043_dev_t *dev,uint16_t address,uint8_t *pbuf)
{
	int32_t ret = - EPERM;
	
	if(NULL == dev){
		return ret;
	}
	gpio_output_low(dev->config.cs);
	if( address&0x0001 ){
		spi_send_recv(dev->config.spi,CMD_READ_H);
	}else{
		spi_send_recv(dev->config.spi,CMD_READ_L);
	}
	spi_send_recv(dev->config.spi,(uint8_t)(address>>1));
	*pbuf = spi_send_recv(dev->config.spi,0xff);
	gpio_output_high(dev->config.cs);
	
	ret = 0;
	return ret;
}


int32_t x5043_ioctrl(x5043_dev_t *dev,uint8_t cmd,uint8_t *pbuf)
{
	int32_t ret = - EPERM;
	X5043_REG_STATUS tmp8 = {0};
	
	if(NULL == dev){
		return ret;
	}
	
	if((NULL == dev->config.cs) || (NULL == dev->config.spi) || (NULL == dev->config.wp)){
		return ret;
	}
	
	switch(cmd){
	case E_CMD_ENALBE_WR:
		x5043_enable_write(dev);
		break;

	case E_CMD_DISABLE_WR:
		x5043_disable_write(dev);
		break;

	case E_CMD_PROTECT:
		x5043_read_status(dev,(uint8_t *)&tmp8);
		if( *pbuf != tmp8.bl){
			tmp8.bl = *pbuf;
			x5043_write_status(dev,*(uint8_t*)&tmp8);
		}
		break;

	case E_CMD_SET_WDG:
		x5043_read_status(dev,(uint8_t *)&tmp8);
		if( *pbuf != tmp8.wd){
			tmp8.bl = *pbuf;
			x5043_write_status(dev,*(uint8_t*)&tmp8);
		}
		break;

	case E_CMD_GET_STATUS:
		x5043_read_status(dev,pbuf);
		break;

	default:
		break;
	}
	
	ret = 0;
	return ret;
}
