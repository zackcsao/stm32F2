/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	adc.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	adc.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-01-14 13:34:27
*   Description:	修改说明
*
*
*********************************************************************/

#include "adc.h"
#include "stm32f2xx_ll_adc.h"
#include "stm32f2xx_ll_bus.h"
#include <stdio.h>

#include "bsp.h"

#include "errno-base.h"

const uint32_t ADC_CNANNEL[] = {
	LL_ADC_CHANNEL_0,
	LL_ADC_CHANNEL_1,
	LL_ADC_CHANNEL_2,
	LL_ADC_CHANNEL_3,
	LL_ADC_CHANNEL_4,
	LL_ADC_CHANNEL_5,
	LL_ADC_CHANNEL_6,
	LL_ADC_CHANNEL_7,
	LL_ADC_CHANNEL_8,
	LL_ADC_CHANNEL_9,
	LL_ADC_CHANNEL_10,
	LL_ADC_CHANNEL_11,
	LL_ADC_CHANNEL_12,
	LL_ADC_CHANNEL_13,
	LL_ADC_CHANNEL_14,
	LL_ADC_CHANNEL_15
};
static uint32_t _adc_channel_num[3] = {0,0,0};
static uint16_t adc_result[3][16] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

static uint32_t _adc_real_num[3] = {0,0,0};

uint32_t ADC_CLOCK[3] = {
			LL_APB2_GRP1_PERIPH_ADC1,
			LL_APB2_GRP1_PERIPH_ADC2,
			LL_APB2_GRP1_PERIPH_ADC3
};

ADC_TypeDef * ADC_BASE_ADDR[3] = {ADC1,ADC2,ADC3};

const uint8_t ADC_RANK[3] = {1,2,3};


void ADC_IRQHandler(void)
{
	if( SET == LL_ADC_IsActiveFlag_EOCS(ADC1)){
		adc_result[0][_adc_real_num[0]] = LL_ADC_REG_ReadConversionData12(ADC1);
		LL_ADC_ClearFlag_EOCS(ADC1);
		_adc_real_num[0]++;
		if(_adc_real_num[0] == _adc_channel_num[0]){
			LL_ADC_DeInit(ADC1);
		}
	}
	if( SET == LL_ADC_IsActiveFlag_EOCS(ADC2)){
		adc_result[1][_adc_real_num[1]] = LL_ADC_REG_ReadConversionData12(ADC2);
		LL_ADC_ClearFlag_EOCS(ADC2);
		_adc_real_num[1]++;
		if(_adc_real_num[1] == _adc_channel_num[1]){
			LL_ADC_DeInit(ADC2);
		}
	}
	if( SET == LL_ADC_IsActiveFlag_EOCS(ADC3)){
		adc_result[2][_adc_real_num[2]] = LL_ADC_REG_ReadConversionData12(ADC3);
		LL_ADC_ClearFlag_EOCS(ADC3);
		_adc_real_num[2]++;
		if(_adc_real_num[2] == _adc_channel_num[2]){
			LL_ADC_DeInit(ADC3);
		}
	}
}

int32_t adc_init(adc_dev_t *adc)
{
	int32_t ret = -EPERM;
	uint32_t i = 0;
	LL_ADC_InitTypeDef ADC_InitStructure;
	LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0};
	LL_ADC_CommonInitTypeDef ADC_CommonInitStruct = {0};
	
	if(adc == NULL){
		return ret;
	}
	
	LL_ADC_DeInit(ADC_BASE_ADDR[adc->port]);
	LL_APB2_GRP1_EnableClock(ADC_CLOCK[adc->port]);

	ADC_InitStructure.Resolution = LL_ADC_RESOLUTION_12B;
	ADC_InitStructure.SequencersScanMode = LL_ADC_SEQ_SCAN_ENABLE;
	ADC_InitStructure.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
	LL_ADC_Init(ADC_BASE_ADDR[adc->port], &ADC_InitStructure);

	ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
	ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
	ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
	ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
	ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_LIMITED;
	LL_ADC_REG_Init(ADC_BASE_ADDR[adc->port], &ADC_REG_InitStruct);
	LL_ADC_REG_SetFlagEndOfConversion(ADC_BASE_ADDR[adc->port], LL_ADC_REG_FLAG_EOC_UNITARY_CONV);
	LL_ADC_DisableIT_EOCS(ADC_BASE_ADDR[adc->port]);
	ADC_CommonInitStruct.CommonClock = LL_ADC_CLOCK_SYNC_PCLK_DIV4;
	ADC_CommonInitStruct.Multimode = LL_ADC_MULTI_INDEPENDENT;
	LL_ADC_CommonInit(__LL_ADC_COMMON_INSTANCE(ADC_BASE_ADDR[adc->port]), &ADC_CommonInitStruct);
	
	_adc_channel_num[adc->port] = 0;
	for(i = 0;i < 16 ;i++){
		if( adc->config.channel&(1<<i)){
			_adc_channel_num[adc->port]++;
			LL_ADC_REG_SetSequencerRanks(ADC_BASE_ADDR[adc->port], LL_ADC_REG_RANK_1, ADC_CNANNEL[i]);
			LL_ADC_SetChannelSamplingTime(ADC_BASE_ADDR[adc->port], ADC_CNANNEL[i], LL_ADC_SAMPLINGTIME_3CYCLES);
	
		}
	}
	LL_ADC_EnableIT_EOCS(ADC_BASE_ADDR[adc->port]);
	
	return 0;
	
}


int32_t adc_start(adc_dev_t *adc)
{
	int32_t ret = -EPERM;
	
	if(adc == NULL){
		return ret;
	}
	_adc_real_num[adc->port] = 0;
	LL_ADC_REG_StartConversionSWStart(ADC_BASE_ADDR[adc->port]);
	
	return 0;
}

int32_t adc_value_get(adc_dev_t *adc, uint16_t *output,uint32_t size)
{
	int32_t ret = -EPERM;
	int32_t i = 0;
	uint32_t tmp = 0;
	
	if(adc == NULL){
		return ret;
	}
	
	if(_adc_real_num[adc->port] > size){
		tmp = size;
	}else{
		tmp = _adc_real_num[adc->port];
	}
	for(i = 0;i < tmp;i++){
		output[i] = adc_result[adc->port][i];
	}
	if(_adc_real_num[adc->port] == _adc_channel_num[adc->port]){
		ret = 0;
	}
	
	
	return ret;
}

int32_t adc_finalize(adc_dev_t *adc)
{
	int32_t ret = -EPERM;
	
	if(adc == NULL){
		return ret;
	}
	
	NVIC_DisableIRQ(ADC_IRQn);
	LL_ADC_DeInit(ADC_BASE_ADDR[adc->port]);
	LL_APB2_GRP1_DisableClock(ADC_CLOCK[adc->port]);
	
	return 0;
}


