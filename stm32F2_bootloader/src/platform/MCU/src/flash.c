/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	flash.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	flash.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 10:14:02
*   Description:	修改说明
*
*
*********************************************************************/

#include "flash.h"
#include "stm32f2xx_hal.h"
#include "stm32f2xx_ll_system.h"

const FLASH_ROM_FUNC flash_ROM_func = {
	stm32f429_flash_init,
	flash_ROM_ioctrl,
	write_ROM_multibyte,
	read_ROM_multibyte,
	jump_to_app
};


const uint16_t flash_sector[] = {
	FLASH_SECTOR_0  ,	//   ((uint16_t)0x0000) /*!< Sector Number 0   */
	FLASH_SECTOR_1  ,	//   ((uint16_t)0x0008) /*!< Sector Number 1   */
	FLASH_SECTOR_2  ,	//   ((uint16_t)0x0010) /*!< Sector Number 2   */
	FLASH_SECTOR_3  ,	//   ((uint16_t)0x0018) /*!< Sector Number 3   */
	FLASH_SECTOR_4  ,	//   ((uint16_t)0x0020) /*!< Sector Number 4   */
	FLASH_SECTOR_5  ,	//   ((uint16_t)0x0028) /*!< Sector Number 5   */
	FLASH_SECTOR_6  ,	//   ((uint16_t)0x0030) /*!< Sector Number 6   */
	FLASH_SECTOR_7  ,	//   ((uint16_t)0x0038) /*!< Sector Number 7   */
	FLASH_SECTOR_8  ,	//   ((uint16_t)0x0040) /*!< Sector Number 8   */
	FLASH_SECTOR_9  ,	//   ((uint16_t)0x0048) /*!< Sector Number 9   */
	FLASH_SECTOR_10 ,	//   ((uint16_t)0x0050) /*!< Sector Number 10  */
	FLASH_SECTOR_11 	//   ((uint16_t)0x0058) /*!< Sector Number 11  */

};
void stm32f429_flash_init(void)
{
	LL_FLASH_SetLatency(LL_FLASH_LATENCY_7);

	if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_7){
		while(1);//Error_Handler();  
	}
}

static void stm32f429_flash_lock(void)
{
	HAL_FLASH_Lock();
}

static void stm32f429_flash_unlock(void)
{
	HAL_FLASH_Unlock();
}

static uint32_t stm32f429_flash_erase_sector(uint32_t sector)
{
	FLASH_EraseInitTypeDef flash_erase;
	uint32_t tmp = 0;
	
	flash_erase.TypeErase = FLASH_TYPEERASE_SECTORS;
	flash_erase.Banks = FLASH_BANK_1;
	flash_erase.Sector = flash_sector[sector];
	flash_erase.NbSectors = 1;
	flash_erase.VoltageRange = FLASH_VOLTAGE_RANGE_3;
	if(3 < sector){
		return (uint32_t)HAL_FLASHEx_Erase(&flash_erase,&tmp);
	}else{
		return 0;
	}
}

static uint32_t stm32f429_flash_program_byte(uint32_t add,uint8_t data)
{
	return HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,add,data);
}

static uint8_t flash_read(uint32_t flash_addr)
{
	return (uint8_t)*(uint32_t *)(flash_addr);
}

uint32_t read_ROM_multibyte(uint32_t add,uint8_t *buf,uint32_t n)
{
	uint32_t i = 0;   
	
	for (i = 0; i < n; i++) {
		buf[i] = flash_read(add+i);                                   // send byte to be programmed
	}
	
	return i;
}

uint32_t write_ROM_multibyte(uint32_t add,const uint8_t *buf,uint32_t n)
{
	uint32_t i = 0;
	
	for(i = 0;i < n;i++){
		stm32f429_flash_program_byte(add+i,buf[i]);
	}
	
	return i;
}

uint32_t flash_ROM_ioctrl(uint32_t cmd,uint8_t *buf)
{
	uint32_t tmp = 0;
	
	switch(cmd){
	case IOCTRL_ROM_LOCK:
		stm32f429_flash_lock();
		break;
		
	case IOCTRL_ROM_UNLOCK:
		stm32f429_flash_unlock();
		break;
		
	case IOCTRL_ROM_ERASE_SECTOR:
		stm32f429_flash_erase_sector(*buf);
		break;
		
	default:
		break;
	}
	
	return tmp;
}
typedef  void (*pFunction)(void);

void jump_to_app(void)
{
	pFunction pfunc;
	uint32_t app_add_tmp;
	
	if (((*(__IO uint32_t*)0x8000000) & 0x2FFE0000 ) == 0x20000000){
		app_add_tmp = *(__IO uint32_t*) (APP_FLASH_ADD + 4);;
		pfunc = (pFunction)app_add_tmp;

		__set_CONTROL(0);
		__set_MSP(*(__IO uint32_t*)APP_FLASH_ADD);
		__disable_irq();
		pfunc();
		while (1);
	}
}
