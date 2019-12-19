/*********************************************************************
*
*	Copyright (c)dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	adc.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	adc.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-01-14 13:34:33
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __ADC_H__
#define __ADC_H__
#include <stdint.h>

/************************ADC start ****************************/
typedef enum {
	E_ADC1 = 0,
	E_ADC2,
	E_ADC3
}ADC_PORT;
typedef struct {
	uint16_t channel;	//bit0-bit15
	uint32_t sampling_cycle;  /* sampling period in number of ADC clock cycles */
	
} adc_config_t;

typedef struct {
	uint8_t      port;   /* adc port */
	adc_config_t config; /* adc config */
	void        *priv;   /* priv data */
} adc_dev_t;
/*********************ADC end *********************************/


int32_t adc_init(adc_dev_t *adc);
int32_t adc_start(adc_dev_t *adc);
int32_t adc_value_get(adc_dev_t *adc, uint16_t *output,uint32_t size);
int32_t adc_finalize(adc_dev_t *adc);
#endif //__ADC_H__

