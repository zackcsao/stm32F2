/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	common_tools.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	common_tools.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-10 16:25:52
*   Description:	修改说明
*
*
*********************************************************************/

#include "common_tools.h"

const uint16_t c_crc16_table[256] ={
	0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
	0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
	0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
	0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
	0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
	0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
	0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
	0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
	0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
	0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
	0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
	0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
	0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
	0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
	0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
	0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
	0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
	0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
	0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
	0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
	0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
	0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
	0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
	0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
	0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
	0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
	0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
	0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
	0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
	0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
	0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
	0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
};

uint8_t bcd2bin(uint8_t val)
{
	return (val & 0x0f) + (val >> 4) * 10;
}

uint8_t bin2bcd(uint8_t val)
{
	return ((val / 10) << 4) + val % 10;
}

uint8_t crc8_check(const uint8_t *ucPtr, uint8_t ucLen,uint8_t ucCrcStartValue)
{
	uint8_t crc;
	uint8_t i= 0,j = 0;

	crc = ucCrcStartValue;

	while(ucLen-- != 0){
		crc = crc ^ ( ucPtr[j]);
		for(i = 0; i < 8; i++){
			if((crc & 0x80) == 0x80){
				crc *= 2;
				crc ^= 0xE5;
			}else{
				crc *= 2;
			}
		}
		j++;
	}
	return crc;
}

uint16_t crc16_check_FF(uint8_t *ucBuf, uint16_t ucSize)
{
	uint16_t x;
	uint16_t crc;
	uint16_t i;

	crc = 0xFFFF;     /* start with all 1's for a reverse CRC */

	for( i = 0; i < ucSize; ++i){
		x = crc ^ ucBuf[i];
		crc = (crc >> 8) ^ c_crc16_table[x & 0x00FF];
	}

	return crc ;
}

uint16_t Crc16_Check_00(uint8_t *ucBuf, uint16_t ucSize)
{
	uint16_t x;
	uint16_t crc;
	uint16_t i;

	crc = 0x0000;     /* start with all 0's for a reverse CRC */

	for( i = 0; i < ucSize; ++i){
		x = crc ^ ucBuf[i];
		crc = (crc >> 8) ^ c_crc16_table[x & 0x00FF];
	}

	return crc ;
}


uint16_t crc16_check(uint8_t *ucPtr, uint16_t ucLen,uint16_t ucCrcStartValue)
{
	uint16_t crc;
	uint16_t i;

	crc = ucCrcStartValue;
	while(ucLen-- != 0){
		for(i = 0x80; i != 0; i /= 2){
			if((crc	& 0x8000) != 0){
				crc *= 2;
				crc ^= 0x1021;
			}else{
				crc *= 2;
			}

			if((*ucPtr & i)	!=0)
				crc ^= 0x1021;
		}
		ucPtr++;
	}

	return(crc);
}

uint16_t cal_crc16(uint8_t *ptr, uint16_t len,uint16_t crc_s)
{
	uint16_t crc;
	uint8_t i;

	crc = crc_s;
	while(len-- != 0) {
		crc = crc^(*ptr);
		for(i = 0; i < 8; i++) {
			if((crc & 0x0001) == 0x0001) {
				crc >>= 1;
				crc ^= 0xA001;
			}
			else crc >>= 1;
		}
		ptr++;
	}

	return(crc);
}

uint8_t crc76520(uint8_t *ucBuf, uint16_t ucLen)
{
	uint16_t uiMaxBit;
	uint16_t uiRsb;
	uint8_t crc_reg;

	uint16_t uiMesIndex;
	uint16_t uiLsb;

	uint16_t i;
	uint8_t crcreturn = 0;

	uiMaxBit = ucLen * 8 - 1;
	uiRsb = 0;
	crc_reg = ucBuf[0] ^ 0xE5;
	while(uiRsb < uiMaxBit){
		if(crc_reg & 0x80){
			crc_reg = crc_reg ^ 0xE5;
		}else{
			crc_reg = crc_reg<<1;
			uiMesIndex = uiRsb/8+1;
			uiLsb = uiRsb % 8;
			if(uiMesIndex < ucLen){
				if(ucBuf[uiMesIndex] & (0x01 << uiLsb)){
					crc_reg = crc_reg | 0x80;
				}
			}
				uiRsb++;
		}
	}

	for(i = 0;i < 7;i++){
		if(crc_reg & (0x01 << i)){
			crcreturn = crcreturn | (0x01 << (7 - i));
		}
	}

	return crcreturn;
}

uint8_t check_sum(uint8_t *buf,uint8_t len)
{
	uint8_t i = 0;
	uint8_t sum = 0;

	for(i = 0; i < len;i++){
		sum += buf[i];
	}

	return sum;
}

uint16_t check_xor(const uint8_t *buf,uint8_t len)
{
	uint8_t i = 0;
	uint8_t xor_tmp = 0;
	uint16_t xor = 0;

	if (len > 2) {
		xor_tmp = buf[1];
		for (i = 2; i < len; i++) {
			xor_tmp ^= buf[i];
		}
		xor = ((((uint16_t)xor_tmp >> 4) + '0') << 8) + (((uint16_t)xor_tmp & 0x0f) + '0');
	} else {
		xor = 0;
	}

	return xor;
}

uint8_t is_bcd(const uint8_t *code, uint8_t size)
{
	uint8_t i = 0;

	for (i = 0; i < size; i++) {
		if (((code[i]&0x0f) > 0x09) || ((code[i]>>4) > 0x09)) {
			return 0;
		}
	}
	return 1;
}


uint16_t mid_value_average_filter(uint16_t *ucValue,uint8_t num)
{
	uint16_t temp;
	uint32_t l_temp = 0;
	uint8_t  i, j;
	uint16_t result;

	if(num < 3) {
		return ucValue[0];
	}


	for(i=0; i<num; i++)   {
		for(j=i; j<num; j++){
			if(ucValue[i] > ucValue[j]){
			temp = ucValue[i];
			ucValue[i] = ucValue[j];
			ucValue[j] = temp;
			}
		}
	}

	for(j=1; j<(num-1); j++){
		l_temp += ucValue[j];
	}
	
	result = (uint16_t)((l_temp*1.0)/(num-2)); 
	
	return result;
}



