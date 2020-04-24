/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	spi.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	spi.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-08 14:22:28
*   Description:	修改说明
*
*
*********************************************************************/

#include "spi.h"
#include "bsp.h"
#include "stm32f2xx_ll_spi.h"
#include "stm32f2xx_ll_bus.h"
#include "errno-base.h"

#include <stdio.h>

#define SPI_NUM_MAX 6

SPI_TypeDef* spi_port[SPI_NUM_MAX] = {
		SPI1,
#if defined(SPI2)
		SPI2,
#else
		0,
#endif
#if defined(SPI3)
		SPI3,
#else
		0,
#endif
#if defined(SPI4)
		SPI4,
#else
		0,
#endif
#if defined(SPI5)
		SPI5,
#else
		0,
#endif
#if defined(SPI6)
		SPI6
#else
		0
#endif
	};
const uint32_t SPI_CLOCK[SPI_NUM_MAX] = {
		LL_APB2_GRP1_PERIPH_SPI1,
#if defined(SPI2)
		LL_APB1_GRP1_PERIPH_SPI2,
#else 
		0,
#endif
#if defined(SPI3)
		LL_APB1_GRP1_PERIPH_SPI3,
#else
		0,
#endif
#if defined(SPI4)
		LL_APB2_GRP1_PERIPH_SPI4,
#else 
		0,
#endif
#if defined(SPI5)
		LL_APB2_GRP1_PERIPH_SPI5,
#else
		0,
#endif
#if defined(SPI6)
		LL_APB2_GRP1_PERIPH_SPI6
#else	
		0,
#endif
		};

const uint32_t BAUDRATE[] = {
		LL_SPI_BAUDRATEPRESCALER_DIV2,
		LL_SPI_BAUDRATEPRESCALER_DIV4,
		LL_SPI_BAUDRATEPRESCALER_DIV8,
		LL_SPI_BAUDRATEPRESCALER_DIV16,
		LL_SPI_BAUDRATEPRESCALER_DIV32,
		LL_SPI_BAUDRATEPRESCALER_DIV64,
		LL_SPI_BAUDRATEPRESCALER_DIV128,
		LL_SPI_BAUDRATEPRESCALER_DIV256
		};	
		
const uint32_t BITORDER[] = {
		LL_SPI_LSB_FIRST,
		LL_SPI_MSB_FIRST
};


const uint32_t SPI_CLOCK_POLARITY[][2] = {
		{LL_SPI_PHASE_1EDGE,LL_SPI_POLARITY_LOW},
		{LL_SPI_PHASE_2EDGE,LL_SPI_POLARITY_LOW},
		{LL_SPI_PHASE_1EDGE,LL_SPI_POLARITY_HIGH},
		{LL_SPI_PHASE_2EDGE,LL_SPI_POLARITY_HIGH}
};

const uint32_t SPI_DATA_WIDTH[] = {
		LL_SPI_DATAWIDTH_8BIT,
		LL_SPI_DATAWIDTH_16BIT
};

const uint32_t SPI_WORK_MODE[] = {
		LL_SPI_MODE_MASTER,
		LL_SPI_MODE_SLAVE
};
const uint32_t SPI_TRANSFER_MODE[] = {
		LL_SPI_FULL_DUPLEX,
		LL_SPI_SIMPLEX_RX,
		LL_SPI_HALF_DUPLEX_RX,
		LL_SPI_HALF_DUPLEX_TX
};

const uint32_t SPI_NSS_TYPE[] = {
		LL_SPI_NSS_SOFT,
		LL_SPI_NSS_HARD_OUTPUT
};

int32_t spi_init(spi_dev_t *spi)
{
	int32_t ret = -EPERM;
	LL_SPI_InitTypeDef spi_param;
	

	if (spi == NULL) {
		return ret;
	}
	
	switch(spi->port){
	case E_SPI2:
	case E_SPI3:
		LL_AHB1_GRP1_EnableClock(SPI_CLOCK[spi->port]);
		break;
	case E_SPI1:
	case E_SPI4:
	case E_SPI5:
	case E_SPI6:
		LL_APB2_GRP1_EnableClock(SPI_CLOCK[spi->port]);
		break;
	default:
		break;
	}
	
	
	spi_param.BaudRate = BAUDRATE[spi->config.freq];
	
	switch(spi->config.bit_order){
	case E_SPI_LSB_FIRST:
		spi_param.BitOrder = LL_SPI_LSB_FIRST;
		break;
	case E_SPI_MSB_FIRST:
		spi_param.BitOrder = LL_SPI_MSB_FIRST;
		break;
	default:
		spi_param.BitOrder = LL_SPI_MSB_FIRST;
		break;
		
	}
	switch(spi->config.mode){
	case MODE0:
		spi_param.ClockPhase = LL_SPI_PHASE_1EDGE;
		spi_param.ClockPolarity = LL_SPI_POLARITY_LOW;
		break;
		
	case MODE1:
		spi_param.ClockPhase = LL_SPI_PHASE_2EDGE;
		spi_param.ClockPolarity = LL_SPI_POLARITY_LOW;
		break;
		
	case MODE2:
		spi_param.ClockPhase = LL_SPI_PHASE_1EDGE;
		spi_param.ClockPolarity = LL_SPI_POLARITY_HIGH;
		break;
		
	case MODE3:
		spi_param.ClockPhase = LL_SPI_PHASE_2EDGE;
		spi_param.ClockPolarity = LL_SPI_POLARITY_HIGH;
		break;
		
	default:
		spi_param.ClockPhase = LL_SPI_PHASE_1EDGE;
		spi_param.ClockPolarity = LL_SPI_POLARITY_LOW;
		break;
	}
	spi_param.DataWidth = SPI_DATA_WIDTH[spi->config.data_length];//param->data_length;
	spi_param.Mode = SPI_WORK_MODE[spi->config.type];//SPI_Mode_Master;
	
	spi_param.TransferDirection = SPI_TRANSFER_MODE[spi->config.transfer_mode];//SPI_Direction_2Lines_FullDuplex;
	spi_param.NSS = SPI_NSS_TYPE[spi->config.cs_type];
	
	spi_param.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	spi_param.CRCPoly = 10;
	
	LL_SPI_Init(spi_port[spi->port],&spi_param);
	LL_SPI_SetStandard(SPI1, LL_SPI_PROTOCOL_MOTOROLA);
	
	
	
	LL_SPI_Enable(spi_port[spi->port]);
	
	return 0;
	

}


int32_t spi_send(spi_dev_t *spi, const uint8_t *data, uint32_t size)
{
	int32_t ret = -EPERM;
	int32_t i = 0;

	if (spi == NULL) {
		return ret;
	}	
	
	for(i = 0;i < size;i++){
		while (LL_SPI_IsActiveFlag_TXE(spi_port[spi->port]) == RESET);
		LL_SPI_TransmitData8(spi_port[spi->port],*(data + i));
	}
	
	return i;
	
	
}

int32_t spi_recv(spi_dev_t *spi, uint8_t *data, uint32_t size)
{
	int32_t ret = -EPERM;
	int32_t i = 0;

	if (spi == NULL) {
		return ret;
	}
	
	for(i = 0;i < size;i++){
		while (LL_SPI_IsActiveFlag_RXNE(spi_port[spi->port]) == RESET);
	
		*(data + i) = LL_SPI_ReceiveData8 (spi_port[spi->port]);
	}
	
	return i;
}

int32_t spi_send_recv(spi_dev_t *spi, uint8_t tx_data)
{
	int32_t ret = -EPERM;
	

	if (spi == NULL) {
		return ret;
	}
	
	
	while (LL_SPI_IsActiveFlag_TXE(spi_port[spi->port]) == RESET);
	LL_SPI_TransmitData8(spi_port[spi->port],tx_data);


	while (LL_SPI_IsActiveFlag_RXNE(spi_port[spi->port]) == RESET);
	
	ret = LL_SPI_ReceiveData8 (spi_port[spi->port]);

	
	return ret;
}

int32_t spi_finalize(spi_dev_t *spi)
{
	int32_t ret = -EPERM;

	if (spi == NULL) {
		return ret;
	}
	
	LL_SPI_Disable(spi_port[spi->port]);
	
	ret = 0;
	
	return ret;
}

