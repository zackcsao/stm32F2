/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	i2c.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	i2c.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-03-19 14:01:27
*   Description:	修改说明
*
*
*********************************************************************/


#include "i2c.h"
#include "errno-base.h"
//#include "stm32l0xx_ll_bus.h" 
#include <stdio.h>
#include "gpio.h"

#include "stm32f2xx.h"
static void delay_5us(void)
{
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
}


static int32_t I2CStart(i2c_gpio_t *i2c_gpio)
{
	int32_t ret = -EPERM;
	gpio_dev_t *scl,*sda;
	
	if(i2c_gpio == NULL){
		return ret;
	}
	
	scl = &i2c_gpio->scl;
	sda = &i2c_gpio->sda;
	
	scl->config = OUTPUT_PUSH_PULL;
	sda->config = OUTPUT_PUSH_PULL;
	gpio_init(scl);
	gpio_output_high(scl);
	gpio_init(sda);
	gpio_output_high(sda);
	
	gpio_output_high(scl);
	
	delay_5us();
	gpio_output_low(sda);
	delay_5us();
	gpio_output_low(scl);
	
	ret = 0;
	
	return ret;

}

static int32_t I2CStop(i2c_gpio_t *i2c_gpio)
{
	int32_t ret = -EPERM;
	gpio_dev_t *scl,*sda;
	
	if(i2c_gpio == NULL){
		return ret;
	}
	scl = &i2c_gpio->scl;
	sda = &i2c_gpio->sda;
	
	scl->config = OUTPUT_PUSH_PULL;
	sda->config = OUTPUT_PUSH_PULL;
	gpio_init(sda);
	gpio_init(scl);
	gpio_output_low(sda);
	gpio_output_low(scl);
	
	delay_5us();
	gpio_output_high(scl);
	delay_5us();
	gpio_output_high(sda);
	
	ret = 0;
	
	return ret;
}

static int32_t I2CWriteByte(i2c_gpio_t *i2c_gpio,uint8_t WriteData)
{
	uint8_t i;
	int32_t ret = -EPERM;
	gpio_dev_t *scl,*sda;
	uint32_t tmp = 0;
	
	if(i2c_gpio == NULL){
		return ret;
	}
	scl = &i2c_gpio->scl;
	sda = &i2c_gpio->sda;
	
	scl->config = OUTPUT_PUSH_PULL;
	sda->config = OUTPUT_PUSH_PULL;
	gpio_init(sda);
	gpio_init(scl);

	for(i = 0;i < 8;i++){
		gpio_output_low(scl);
		delay_5us();
		if(WriteData&0x80)
			gpio_output_high(sda);
		else {
			gpio_output_low(sda);
		}
		WriteData<<=1;
		gpio_output_high(scl);
		delay_5us();
	}
	gpio_output_low(scl);
	delay_5us();
	sda->config = INPUT_PULL_UP;
	gpio_init(sda);
	gpio_output_high(scl);
	i=0;
	while(1){
		tmp = gpio_input_get(sda);
		if(tmp == 0){
			ret = 0;
			break;
		}
		if(++i>20){
			break;
		}
	}
	gpio_output_low(scl);
	
	return ret;

}

static int32_t I2CReadByte(i2c_gpio_t *i2c_gpio,uint8_t *WriteData)
{

	uint8_t i = 0;
	int32_t ret = -EPERM;
	gpio_dev_t *scl,*sda;
	uint32_t tmp = 0;
	
	if(i2c_gpio == NULL){
		return ret;
	}
	
	*WriteData = 0;
	scl = &i2c_gpio->scl;
	sda = &i2c_gpio->sda;
	
//	scl->config = OUTPUT_PUSH_PULL;
//	scl->priv = &tmp;
	sda->config = INPUT_PULL_UP;
//	gpio_init(scl);
	gpio_init(sda);

	gpio_output_low(scl);

	for(i=0;i<8;i++){
		delay_5us();
		gpio_output_high(scl);
		delay_5us();
		(*WriteData)<<=1;
		tmp = gpio_input_get(sda);
		if(tmp == 1)
			(*WriteData) |= 1;
		gpio_output_low(scl);
	}
	gpio_output_low(scl);
	sda->config = OUTPUT_PUSH_PULL;
	gpio_init(sda);
	gpio_output_low(sda);
//	delay_5us();
//	
//	gpio_output_high(scl);
//	
//	delay_5us();
//	gpio_output_low(scl);

	ret = 0;
	
	return ret;
}

static int32_t I2C_Ack(i2c_gpio_t *i2c_gpio)
{
	int32_t ret = -EPERM;
	gpio_dev_t *scl,*sda;
	
	if(i2c_gpio == NULL){
		return ret;
	}
	
	scl = &i2c_gpio->scl;
	sda = &i2c_gpio->sda;
//	
//	scl->config = OUTPUT_PUSH_PULL;
//	sda->config = OUTPUT_PUSH_PULL;
//	gpio_init(sda);
//	gpio_init(scl);
//	gpio_output_low(scl);
	delay_5us();
	
	gpio_output_low(sda);
	gpio_output_high(scl);
	delay_5us();
	gpio_output_low(scl);
	delay_5us();
	gpio_output_high(sda);
//	gpio_output_high(scl);
	
	ret = 0;
	
	return ret;
}

static int32_t I2C_NAck(i2c_gpio_t *i2c_gpio)
{
	int32_t ret = -EPERM;
	gpio_dev_t *scl,*sda;
	
	if(i2c_gpio == NULL){
		return ret;
	}
	
	scl = &i2c_gpio->scl;
	sda = &i2c_gpio->sda;
	
//	scl->config = OUTPUT_PUSH_PULL;
	sda->config = INPUT_PULL_UP;
	gpio_init(sda);
//	gpio_init(scl);
	
	delay_5us();
	gpio_output_high(scl);
	
	ret = 0;
	
	return ret;
}




int32_t i2c_init(i2c_dev_t *i2c)
{
	int32_t ret = -EPERM;
	
	if(i2c == NULL){
		return ret;
	}
	
	switch(i2c->config.mode){
	case REAL_I2C:
		break;
		
	case SIMULATION_I2C:
		if(i2c->priv == NULL){
			return ret;
		}else{
			ret = 0;
		}
		break;
		
	default:
		break;
	}
	
	return ret;
}

int32_t i2c_master_send(i2c_dev_t *i2c, const uint8_t *data,uint32_t size)
{
	int32_t ret = -EPERM;
	uint32_t i = 0;
	uint32_t len = size;
	
	if(i2c == NULL){
		return ret;
	}
	
	if(i2c->priv == NULL){
		return ret;
	}
	
	I2CStart((i2c_gpio_t*)i2c->priv);
	
	I2CWriteByte((i2c_gpio_t*)i2c->priv,i2c->config.dev_addr<<1);
	for(i = 0;i < len;i++){
		I2CWriteByte((i2c_gpio_t*)i2c->priv,data[i]);
	}

	ret = i;
	I2CStop((i2c_gpio_t*)i2c->priv);
	delay_5us();
	delay_5us();
	delay_5us();
	delay_5us();

	return ret;
}

int32_t i2c_master_recv(i2c_dev_t *i2c, uint8_t *data,uint32_t size)
{
	int32_t ret = -EPERM;
	uint32_t i = 0;
	uint32_t len = size;
	
	if(i2c == NULL){
		return ret;
	}
	
	if(i2c->priv == NULL){
		return ret;
	}
	
	I2CStart((i2c_gpio_t*)i2c->priv);
	
	I2CWriteByte((i2c_gpio_t*)i2c->priv,(i2c->config.dev_addr<<1) + 1);
	
	for(i = 0;i < len;i++){
		I2CReadByte((i2c_gpio_t*)i2c->priv,&data[i]);
		//I2C_Ack((i2c_gpio_t*)i2c->priv);
	}
	
//	I2C_NAck((i2c_gpio_t*)i2c->priv);
	
	ret = i;
	I2CStop((i2c_gpio_t*)i2c->priv);
	delay_5us();
	delay_5us();
	delay_5us();
	delay_5us();
	
	return ret;
}

int32_t i2c_mem_write(i2c_dev_t *i2c, i2c_mem_t *i2c_mem, uint32_t size)
{
	int32_t ret = -EPERM;
	uint32_t i = 0;
	uint32_t len = size;
	
	if(i2c == NULL){
		return ret;
	}
	
	if(i2c->priv == NULL){
		return ret;
	}
	
	I2CStart((i2c_gpio_t*)i2c->priv);
	
	I2CWriteByte((i2c_gpio_t*)i2c->priv,i2c->config.dev_addr<<1);
	
//	I2CStart((i2c_gpio_t*)i2c->priv);
	I2CWriteByte((i2c_gpio_t*)i2c->priv,(uint8_t)i2c_mem->mem_addr);
	for(i = 0;i < len;i++){
		I2CWriteByte((i2c_gpio_t*)i2c->priv,i2c_mem->data[i]);
	}
	
	ret = i;
	I2CStop((i2c_gpio_t*)i2c->priv);
	delay_5us();
	delay_5us();
	delay_5us();
	delay_5us();
	
	
	return ret;
}


int32_t i2c_mem_read(i2c_dev_t *i2c, i2c_mem_t *i2c_mem, uint32_t size)
{
	int32_t ret = -EPERM;
	uint32_t i = 0;
	uint32_t len = size;
	
	if(i2c == NULL){
		return ret;
	}
	
	if(i2c->priv == NULL){
		return ret;
	}
	if(len == 0){
		return ret;
	}
	
	I2CStart((i2c_gpio_t*)i2c->priv);
	
	I2CWriteByte((i2c_gpio_t*)i2c->priv,(i2c->config.dev_addr<<1));
	I2CWriteByte((i2c_gpio_t*)i2c->priv,(uint8_t)i2c_mem->mem_addr);
	
	I2CStart((i2c_gpio_t*)i2c->priv);
	I2CWriteByte((i2c_gpio_t*)i2c->priv,(i2c->config.dev_addr<<1) + 1);
	for(i = 0;i < (len - 1);i++){
		I2CReadByte((i2c_gpio_t*)i2c->priv,i2c_mem->data + i);
		I2C_Ack((i2c_gpio_t*)i2c->priv);
	}
	
//	
	I2CReadByte((i2c_gpio_t*)i2c->priv,i2c_mem->data + i);
	I2C_NAck((i2c_gpio_t*)i2c->priv);
	ret = i+1;
	I2CStop((i2c_gpio_t*)i2c->priv);
	delay_5us();
	delay_5us();
	delay_5us();
	delay_5us();
	
	
	return ret;

}






