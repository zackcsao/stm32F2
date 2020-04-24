/*********************************************************************
*
*	Copyright (c)dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	i2c.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	i2c.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-03-19 14:01:33
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __I2C_H__
#define __I2C_H__

#include <stdint.h>
#include "gpio.h"

/*************************I2C start****************************/

typedef enum {
	REAL_I2C,
	SIMULATION_I2C
}i2c_mode_t;

typedef struct {
	uint32_t address_width;
	uint32_t freq;
	i2c_mode_t  mode;
	uint16_t dev_addr;
} i2c_config_t;

typedef struct {
	uint8_t      port;    /* i2c port */
	i2c_config_t config;  /* i2c config */
	void        *priv;    /* priv data */
} i2c_dev_t;

typedef struct {
	gpio_dev_t scl;
	gpio_dev_t sda;
} i2c_gpio_t;

typedef struct {
	uint16_t mem_addr;
	uint8_t *data;
}i2c_mem_t;
/*******************I2C end************************************/


/**
* Initialises an I2C interface
* Prepares an I2C hardware interface for communication as a master or slave
*
* @param[in]  i2c  the device for which the i2c port should be initialised
*
* @return  0 : on success, EIO : if an error occurred during initialisation
*/
int32_t i2c_init(i2c_dev_t *i2c);

/**
* I2c master send
*
* @param[in]  i2c       the i2c device
* @param[in]  dev_addr  device address
* @param[in]  data      i2c send data
* @param[in]  size      i2c send data size
*
* @return  0 : on success, EIO : if an error occurred during initialisation
*/
int32_t i2c_master_send(i2c_dev_t *i2c, const uint8_t *data,uint32_t size);

/**
* I2c master recv
*
* @param[in]   i2c       the i2c device
* @param[in]   dev_addr  device address
* @param[out]  data      i2c receive data
* @param[in]   size      i2c receive data size
*
* @return  0 : on success, EIO : if an error occurred during initialisation
*/
int32_t i2c_master_recv(i2c_dev_t *i2c, uint8_t *data,uint32_t size);

/**
* I2c mem write
*
* @param[in]  i2c            the i2c device
* @param[in]  dev_addr       device address
* @param[in]  mem_addr       mem address
* @param[in]  mem_addr_size  mem address
* @param[in]  data           i2c master send data
* @param[in]  size           i2c master send data size
*
* @return  0 : on success, EIO : if an error occurred during initialisation
*/
int32_t i2c_mem_write(i2c_dev_t *i2c, i2c_mem_t *i2c_mem, uint32_t size);

/**
* I2c master mem read
*
* @param[in]   i2c            the i2c device
* @param[in]   dev_addr       device address
* @param[in]   mem_addr       mem address
* @param[in]   mem_addr_size  mem address
* @param[out]  data           i2c master send data
* @param[in]   size           i2c master send data size
*
* @return  0 : on success, EIO : if an error occurred during initialisation
*/
int32_t i2c_mem_read(i2c_dev_t *i2c, i2c_mem_t *i2c_mem, uint32_t size);

/**
* Deinitialises an I2C device
*
* @param[in]  i2c  the i2c device
*
* @return  0 : on success, EIO : if an error occurred during deinitialisation
*/
int32_t i2c_finalize(i2c_dev_t *i2c);
 


#endif //__I2C_H__

