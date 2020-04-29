/*********************************************************************
*
*	Copyright (c) 2009,北京奥特美克科技股份股份公司
*	All rights reserved.
*
*      Filename:	task_keyboard.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	task_keyboard.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-06-08 09:50:22
*   Description:	修改说明
*
*
*********************************************************************/

#include "task_keyboard.h"

#include "drv_keyboard.h"
#include "bsp.h"
#include "fifo.h"

#include <stdio.h>

const uint32_t KEY_NUM[6] = {0x0f,0x17,0x1b,0x1d,0x1e};
const uint32_t KEY_NUM_LINE[4] = {0x0e,0x0d,0x0b,0x07};
const uint32_t KEY_NUM_ROW[6] = {0x1e,0x1d,0x1b,0x17,0x0f,0x1f};

const uint8_t KEY[4][6] = {{13,17,16,14,15,0},
			{1,4,7,10,0,0},
			{2,5,8,11,0,0},
			{3,6,9,12,0,0}};

extern SYS_FUNC sys_func;
extern fifo_t key_fifo;
			
void task_keyboard(void)
{
	static uint32_t _sec_key = 0;
	int32_t line = 0,row = 0;
	
	uint32_t i = 0,j = 0;
	
	if(300 < sys_func.sys_get_msec() - _sec_key){
		_sec_key = sys_func.sys_get_msec();
		line = keyboard_get_line();
		row = keyboard_get_row();
		
		for(i = 0;i<4;i++){
			if(line == KEY_NUM_LINE[i]){
				break;
			}
		}
		for(j = 0;j<6;j++){
			if(row == KEY_NUM_ROW[j]){
				break;
			}
		}

		
		
//		printf("line = %02X\r\n",keyboard_get_line());
//		printf("row = %02X\r\n",keyboard_get_row());
		if((i < 4) &&(j < 6)){
			printf("key[%d][%d] = %d\r\n",i,j,KEY[i][j]);
			fifo_write(&key_fifo,&KEY[i][j],1);
		}else {
//			printf("input nothing!\r\n");
		}
	}
	
}
