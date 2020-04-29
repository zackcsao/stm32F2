/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	app_init.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	app_init.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-20 15:12:28
*   Description:	修改说明
*
*
*********************************************************************/

#include "app_init.h"
#include "fifo.h"

#include <stdio.h>


const S_VERSION gs_ver = {
	{0,0,1},   //X.Y.ZZ 硬件版本号
	{0,0,1}     //X.Y.ZZ 软件版本号
};

#define KEY_FIFO_MAX		64
static uint8_t _key_buf[KEY_FIFO_MAX];

fifo_t key_fifo;

void system_init_info(void)
{
	printf("\r\n\r\n");
	printf("System Start\r\n");
	printf("Build:%s %s\r\n",__DATE__,__TIME__); //获取编译日期、时间
	printf("Software Ver :%d.%d.%d\r\n",gs_ver.s_ver[0],gs_ver.s_ver[1],gs_ver.s_ver[2]);
	printf("Hardware Ver :%d.%d.%d\r\n",gs_ver.h_ver[0],gs_ver.h_ver[1],gs_ver.h_ver[2]);
	printf("Device UUID:\r\n");
}

void app_init(void)
{
	system_init_info();
	fifo_init(&key_fifo,_key_buf,KEY_FIFO_MAX);
}

