/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	common_tools.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	common_tools.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-10 16:26:34
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __COMMON_TOOLS_H__
#define __COMMON_TOOLS_H__



#include <stdint.h>

uint8_t bcd2bin(uint8_t val);
uint8_t bin2bcd(uint8_t val);
uint8_t crc8_check(const uint8_t *ucPtr, uint8_t ucLen,uint8_t ucCrcStartValue);
uint16_t crc16_check_FF(uint8_t *ucBuf, uint16_t ucSize);
uint8_t crc76520(uint8_t *ucBuf, uint16_t ucLen);
uint16_t crc16_check_00(uint8_t *ucBuf, uint16_t ucSize);
uint16_t crc16_check(uint8_t *ucPtr, uint16_t ucLen,uint16_t ucCrcStartValue);
uint16_t cal_crc16(uint8_t *ptr, uint16_t len,uint16_t crc_s);
uint8_t crc76520(uint8_t *ucBuf, uint16_t ucLen);

uint8_t check_sum(uint8_t *buf,uint8_t len);
uint16_t check_xor(const uint8_t *buf,uint8_t len);

uint8_t is_bcd(const uint8_t *code, uint8_t size);
uint16_t mid_value_average_filter(uint16_t *ucValue,uint8_t num);
#endif
