/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	sdio.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	sdio.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-06-09 13:40:15
*   Description:	修改说明
*
*
*********************************************************************/

#include "sdio.h"

#include "stm32f2xx_ll_bus.h"
#include "stm32f2xx_hal.h"
#include "stm32f2xx_hal_sd.h"

#include <stdio.h>

#include "sd_diskio.h"

SD_HandleTypeDef hsd;

//支持的SD卡定义
#define SDIO_STD_CAPACITY_SD_CARD_V1_1             (0x00000000)
#define SDIO_STD_CAPACITY_SD_CARD_V2_0             (0x00000001)
#define SDIO_HIGH_CAPACITY_SD_CARD                 (0x00000002)
#define SDIO_MULTIMEDIA_CARD                       (0x00000003)
#define SDIO_SECURE_DIGITAL_IO_CARD                (0x00000004)
#define SDIO_HIGH_SPEED_MULTIMEDIA_CARD            (0x00000005)
#define SDIO_SECURE_DIGITAL_IO_COMBO_CARD          (0x00000006)
#define SDIO_HIGH_CAPACITY_MMC_CARD                (0x00000007)

void sdio_init(void)
{
	HAL_SD_CardInfoTypeDef s_sd_info = {0};
//	uint8_t buf[4096] = {0};
	
	hsd.Instance = SDIO;
	hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
	hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
	hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
	hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
	hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
	hsd.Init.ClockDiv = 140;
	
	
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SDIO);

	
	//SD_PowerON(&hsd);
	HAL_SD_InitCard(&hsd);
//	HAL_SD_GetCardState(&hsd);
	HAL_SD_GetCardInfo(&hsd,&s_sd_info);
	
	switch(s_sd_info.CardType){
	case SDIO_STD_CAPACITY_SD_CARD_V1_1:
		printf("Card Type:SDSC V1.1\r\n");
		break;
	
	case SDIO_STD_CAPACITY_SD_CARD_V2_0:
		printf("Card Type:SDSC V2.0\r\n");
		break;
	
	case SDIO_HIGH_CAPACITY_SD_CARD:
		printf("Card Type:SDHC V2.0\r\n");
		break;
	
	case SDIO_MULTIMEDIA_CARD:
		printf("Card Type:MMC Card\r\n");
		break;
	
	default:
		printf("");
		break;
	}	
// 	printf("Card ManufacturerID:%d\r\n",s_sd_info);	//制造商ID
 	printf("Card RCA:%d\r\n",s_sd_info.RelCardAdd);								//卡相对地址
	printf("Card Block Number:%u \r\n",s_sd_info.BlockNbr);	//显示容量
	printf("Card Capacity:%u MB\r\n",(s_sd_info.BlockSize*s_sd_info.BlockNbr)/1000/1000);	//显示容量
 	printf("Card BlockSize:%d\r\n\r\n",s_sd_info.BlockSize);
	HAL_SD_ConfigWideBusOperation(&hsd,SDIO_BUS_WIDE_4B);
//	HAL_SD_InitCard(&hsd);
//	HAL_SD_ReadBlocks(&hsd,buf,0,512,1000);
//	SD_read(0,buf,0,1);
	
}

