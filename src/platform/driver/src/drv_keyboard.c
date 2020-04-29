/*********************************************************************
*
*	Copyright (c) 2009,北京奥特美克科技股份股份公司
*	All rights reserved.
*
*      Filename:	drv_keyboard.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_keyboard.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-06-08 09:14:38
*   Description:	修改说明
*
*
*********************************************************************/

#include "drv_keyboard.h"
#include "gpio.h"
#include "gpio_define.h"
#include <stdio.h>

//gpio_dev_t key_line_1 = {.port = GPIO_KEY_LINE_1,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_line_2 = {.port = GPIO_KEY_LINE_2,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_line_3 = {.port = GPIO_KEY_LINE_3,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_line_4 = {.port = GPIO_KEY_LINE_4,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_line_5 = {.port = GPIO_KEY_LINE_5,.config = OUTPUT_PUSH_PULL,.priv = NULL};

//gpio_dev_t key_row_1 = {.port = GPIO_KEY_ROW_1,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_row_2 = {.port = GPIO_KEY_ROW_2,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_row_3 = {.port = GPIO_KEY_ROW_3,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_row_4 = {.port = GPIO_KEY_ROW_4,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//gpio_dev_t key_row_5 = {.port = GPIO_KEY_ROW_5,.config = OUTPUT_PUSH_PULL,.priv = NULL};
//获取行值
int32_t keyboard_get_line(void)
{
	uint8_t tmp8 = 0;
	uint32_t tmp32 = 0;
	
	gpio_dev_t key_line_1 = {.port = GPIO_KEY_LINE_1,.config = INPUT_PULL_UP,.priv = NULL};
	gpio_dev_t key_line_2 = {.port = GPIO_KEY_LINE_2,.config = INPUT_PULL_UP,.priv = NULL};
	gpio_dev_t key_line_3 = {.port = GPIO_KEY_LINE_3,.config = INPUT_PULL_UP,.priv = NULL};
	gpio_dev_t key_line_4 = {.port = GPIO_KEY_LINE_4,.config = INPUT_PULL_UP,.priv = NULL};

	gpio_dev_t key_row_1 = {.port = GPIO_KEY_ROW_1,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	gpio_dev_t key_row_2 = {.port = GPIO_KEY_ROW_2,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	gpio_dev_t key_row_3 = {.port = GPIO_KEY_ROW_3,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	gpio_dev_t key_row_4 = {.port = GPIO_KEY_ROW_4,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	gpio_dev_t key_row_5 = {.port = GPIO_KEY_ROW_5,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	
	
	gpio_init(&key_line_1);
	gpio_init(&key_line_2);
	gpio_init(&key_line_3);
	gpio_init(&key_line_4);
	
	gpio_init(&key_row_1);
	gpio_init(&key_row_2);
	gpio_init(&key_row_3);
	gpio_init(&key_row_4);
	gpio_init(&key_row_5);
	
	tmp32 = (gpio_input_get(&key_line_1) <<0)  | (gpio_input_get(&key_line_2) <<1)  
			| (gpio_input_get(&key_line_3) <<2)  | (gpio_input_get(&key_line_4) <<3);
	return tmp32;
}
//获取列值	
int32_t keyboard_get_row(void)
{
	uint8_t tmp8 = 0;
	uint32_t tmp32 = 0;
	
	gpio_dev_t key_line_1 = {.port = GPIO_KEY_LINE_1,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	gpio_dev_t key_line_2 = {.port = GPIO_KEY_LINE_2,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	gpio_dev_t key_line_3 = {.port = GPIO_KEY_LINE_3,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};
	gpio_dev_t key_line_4 = {.port = GPIO_KEY_LINE_4,.config = OUTPUT_PUSH_PULL,.priv = &tmp8};

	gpio_dev_t key_row_1 = {.port = GPIO_KEY_ROW_1,.config = INPUT_PULL_UP,.priv = NULL};
	gpio_dev_t key_row_2 = {.port = GPIO_KEY_ROW_2,.config = INPUT_PULL_UP,.priv = NULL};
	gpio_dev_t key_row_3 = {.port = GPIO_KEY_ROW_3,.config = INPUT_PULL_UP,.priv = NULL};
	gpio_dev_t key_row_4 = {.port = GPIO_KEY_ROW_4,.config = INPUT_PULL_UP,.priv = NULL};
	gpio_dev_t key_row_5 = {.port = GPIO_KEY_ROW_5,.config = INPUT_PULL_UP,.priv = NULL};
	
	
	gpio_init(&key_line_1);
	gpio_init(&key_line_2);
	gpio_init(&key_line_3);
	gpio_init(&key_line_4);
	
	gpio_init(&key_row_1);
	gpio_init(&key_row_2);
	gpio_init(&key_row_3);
	gpio_init(&key_row_4);
	gpio_init(&key_row_5);
	
	tmp32 = (gpio_input_get(&key_row_1) <<0)  | (gpio_input_get(&key_row_2) <<1)  
			| (gpio_input_get(&key_row_3) <<2)  | (gpio_input_get(&key_row_4) <<3)  | (gpio_input_get(&key_row_5) <<4);
	return (int32_t)tmp32;
}


