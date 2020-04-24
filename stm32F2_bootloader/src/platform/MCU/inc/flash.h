/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	flash.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	flash.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 10:14:02
*   Description:	修改说明
*
*
*********************************************************************/
#ifndef __FLASH_H__
#define __FLASH_H__
#include <stdint.h>

#define APP_FLASH_ADD		0x08010000


typedef struct {
    void (*init)(void);
    uint32_t (*ioctrl)(uint32_t cmd,uint8_t * buf);
    uint32_t (*write)(uint32_t add,const uint8_t *pbuf,uint32_t size);
    uint32_t (*read)(uint32_t add, uint8_t *pbuf,uint32_t size);
    void (*jump2app)(void);
}FLASH_ROM_FUNC;
#define IOCTRL_ROM_LOCK			1
#define IOCTRL_ROM_UNLOCK		2
#define IOCTRL_ROM_ERASE_SECTOR		3

void stm32f429_flash_init(void);
uint32_t read_ROM_multibyte(uint32_t add,uint8_t *buf,uint32_t n);
uint32_t write_ROM_multibyte(uint32_t add,const uint8_t *buf,uint32_t n);
uint32_t flash_ROM_ioctrl(uint32_t cmd,uint8_t *buf);
void jump_to_app(void);
void get_mcu_id(uint8_t *buf);
#endif //__FLASH_H__
