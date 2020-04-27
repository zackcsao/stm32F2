/*********************************************************************
*
*	Copyright (c) 2009,北京奥特美克科技股份股份公司
*	All rights reserved.
*
*      Filename:	task_deal_update_fatfs.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	task_deal_update_fatfs.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2020-04-22 13:40:36
*   Description:	修改说明
*
*
*********************************************************************/

#include "task_deal_update_fatfs.h"
#include "app_init.h"
#include "bsp.h"
#include <stdio.h>
#include "gpio.h"
#include "flash.h"
//#include "app_save.h"

#include "fatfs.h"
#include "usbh_def.h"
#include "usbh_msc.h"

typedef enum {
	E_USB_INIT,
	E_USB_INSERT,
	E_USB_MOUNT,
	E_USB_OPEN_FILE,
	E_USB_ERASE_ROM,
	E_USB_READ_FILE,
	E_USB_SUCCESS,
	E_USB_QUIT
}UPDATE_FROM_FATFS_STATUS;

#include "ff.h"
#include "uart.h"
FATFS fs;													/* FatFs文件系统对象 */
FIL fnew;													/* 文件对象 */
//BYTE WriteBuffer[] =              /* 写缓冲区*/
//"欢迎使用野火STM32 F429开发板 今天是个好日子，新建文件系统测试文件\r\n";  
//MKFS_PARM opt, *popt = 0;
//uint8_t work[4096];

//extern TASK_FLAG task_flag;
extern const FLASH_ROM_FUNC flash_ROM_func;
extern USBH_HandleTypeDef hUSBHost;
extern FATFS USBH_fatfs;
extern uart_dev_t lcd_uart;
extern const SYS_FUNC sys_func;

void task_deal_update_fatfs(void)
{
	static uint32_t _status = E_USB_INIT;
	static uint32_t _file_size = 0;
	static uint32_t _file_size_tmp = 0;
	static uint32_t _packet_num = 4;
	UINT fnum;						/* 文件成功读写数量 */
	BYTE ReadBuffer[1024]={0};				/* 读缓冲区 */
	FRESULT res_sd = FR_NO_FILESYSTEM;			/* 文件操作结果 */

	static uint32_t _sec_maintian = 0;
	
	switch(_status){
	case E_USB_INIT:
		_status = E_USB_INSERT;
		break;
	
	case E_USB_INSERT:
		if(1 == USBH_MSC_IsReady(&hUSBHost)){
			_status = E_USB_MOUNT;
		}else{
			if(1 < sys_func.sys_get_sec()- _sec_maintian){
				_status = E_USB_QUIT;
			}
		}
		break;
		
	case E_USB_MOUNT:
		if(f_mount(&USBH_fatfs, "", 0) != FR_OK){  
			printf("ERROR : Cannot Initialize FatFs! \n");
		}else{
			printf("mount USB flash disk is OK!\r\n");
			
			uart_send(&lcd_uart,(uint8_t *)"DC16(0,20,'mount USB flash disk is OK!',1);\r\n",
				strlen("DC16(0,20,'mount USB flash disk is OK!',1);\r\n"));
			_status = E_USB_OPEN_FILE;
		}
		break;
		
	case E_USB_OPEN_FILE:
		res_sd = f_open(&fnew, "update.bin", FA_OPEN_EXISTING | FA_READ); 
		if(FR_OK == res_sd){
			_file_size = f_size(&fnew);
			printf("file is OK,%d!r\n",_file_size);
			
			uart_send(&lcd_uart,(uint8_t *)"DC16(0,40,'Open file update.bin!',1);\r\n",
				strlen("DC16(0,40,'Open file update.bin!',1);\r\n"));
//			uart_send(&lcd_uart,(uint8_t *)"CLR(0);SBC(3);DC16(0,40,'find file update.bin!',1);\r\n",
//				strlen("CLR(0);SBC(3);DC16(0,40,'find file update.bin!',1);\r\n"));
			_status = E_USB_ERASE_ROM;
			flash_ROM_func.init();
			flash_ROM_func.ioctrl(IOCTRL_ROM_UNLOCK,NULL);
		}else{
			printf("can't find file!\r\n");
			uart_send(&lcd_uart,(uint8_t *)"DC16(0,40,'Can't find file!',1);\r\n",
				strlen("DC16(0,40,'Can't find file!',1);\r\n"));
			_status = E_USB_QUIT;
		}
		break;
		
	case E_USB_ERASE_ROM:
		if(_packet_num >= 4){
			flash_ROM_func.ioctrl(IOCTRL_ROM_ERASE_SECTOR,(uint8_t*)&_packet_num);
			printf("Erase sector %d\r\n",_packet_num);
			memset(ReadBuffer,0,sizeof(ReadBuffer));
			sprintf((char *)ReadBuffer,"DC16(0,60,'Erase Flash Sector!',1);\r\n");
			uart_send(&lcd_uart,ReadBuffer,strlen((char *)ReadBuffer));
		}else{
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>error\r\n");
		}
		_packet_num++;
		if(_packet_num >= 5){
			_packet_num = 0;
			_status = E_USB_READ_FILE;	
		}
		break;
	
	case E_USB_READ_FILE:
		res_sd = f_read(&fnew, ReadBuffer, sizeof(ReadBuffer), &fnum); 
		if(res_sd==FR_OK){
			
			flash_ROM_func.write(APP_FLASH_ADD + _file_size_tmp,ReadBuffer,fnum);
			_file_size_tmp += fnum;
			if(_file_size_tmp >= _file_size){
				f_close(&fnew);
				_status = E_USB_SUCCESS;
				flash_ROM_func.ioctrl(IOCTRL_ROM_LOCK,NULL);
//				jump_to_app();
			}
			memset(ReadBuffer,0,sizeof(ReadBuffer));
			sprintf((char *)ReadBuffer,"DC16(0,80,'Updating......',1);\r\n");
			uart_send(&lcd_uart,ReadBuffer,strlen((char *)ReadBuffer));
			printf("all read size is %d,now read size is %d\r\n",_file_size_tmp,fnum);
//			for(int i = 0;i < fnum;i++){
//				printf("%02x ",ReadBuffer[i]);
//			}
//			printf("\r\n");
		}else{
			f_close(&fnew);
			printf("read fail\n");
			_status = E_USB_QUIT;
		}
		break;
	
	case E_USB_SUCCESS:
		memset(ReadBuffer,0,sizeof(ReadBuffer));
		sprintf((char *)ReadBuffer,"DC16(0,100,'Success......',1);\r\n");
		uart_send(&lcd_uart,ReadBuffer,strlen((char *)ReadBuffer));
		res_sd = f_mount(NULL,"0:",1);
		_status = E_USB_QUIT;
		break;
	
	case E_USB_QUIT:
		printf("quit\n");
		memset(ReadBuffer,0,sizeof(ReadBuffer));
		sprintf((char *)ReadBuffer,"CLR(0);\r\n");
		uart_send(&lcd_uart,ReadBuffer,strlen((char *)ReadBuffer));
		USBH_Stop(&hUSBHost);
		USBH_DeInit(&hUSBHost);
		jump_to_app();
		break;
	
	default:
		break;
	}
	
}

