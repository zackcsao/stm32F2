/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_test.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	task_test.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 13:10:55
*   Description:	修改说明
*
*
*********************************************************************/

#include "task_test.h"
#include "bsp.h"
#include <stdio.h>
#include <string.h>

#include "driver.h"
#include "usbh_def.h"
#include "usbh_msc.h"
#include "fatfs.h"
#include "flash.h"

extern const SYS_FUNC sys_func;

extern gpio_dev_t led_run;
extern gpio_dev_t sys_led_run;
extern gpio_dev_t sys_led_fault;
		
			
extern uart_dev_t lcd_uart;
typedef enum {
	APPLICATION_IDLE = 0,  
	APPLICATION_READY,    
	APPLICATION_DISCONNECT,
}MSC_ApplicationTypeDef;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USBH_HandleTypeDef hUSBHost;
MSC_ApplicationTypeDef Appli_state = APPLICATION_IDLE;

extern FATFS USBH_fatfs;
extern void MSC_File_Operations(void);
/* Private function prototypes -----------------------------------------------*/
static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id);

void task_test_init(void)
{
	/* Init Host Library */
	USBH_Init(&hUSBHost, USBH_UserProcess, 0);

	/* Add Supported Class */
	USBH_RegisterClass(&hUSBHost, USBH_MSC_CLASS);

	/* Start Host Process */
	USBH_Start(&hUSBHost);
	  /* Register the file system object to the FatFs module */

}
/**
  * @brief  User Process
  * @param  phost: Host Handle
  * @param  id: Host Library user message ID
  * @retval None
  */
static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id)
{
	switch(id){ 
	case HOST_USER_SELECT_CONFIGURATION:
		break;

	case HOST_USER_DISCONNECTION:
		Appli_state = APPLICATION_DISCONNECT;
		break;

	case HOST_USER_CLASS_ACTIVE:
		Appli_state = APPLICATION_READY;
		break;

	case HOST_USER_CONNECTION:
		break;

	default:
		break; 
	}
}			
void task_test(void)
{
	static uint32_t _sec_maintian = 0;

	sys_func.feed_wdg();
	
	/* USB Host Background task */
	USBH_Process(&hUSBHost);
	if(_sec_maintian != sys_func.sys_get_sec()){
		_sec_maintian = sys_func.sys_get_sec();
		//周期性显示LED的开关
		if(_sec_maintian%2){
			gpio_output_low(&led_run);
			gpio_output_low(&sys_led_run);
			gpio_output_low(&sys_led_fault);
		}else{
			gpio_output_high(&led_run);
			gpio_output_high(&sys_led_run);
			gpio_output_high(&sys_led_fault);
		}

	}
		
}
