/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	uart.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	uart.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 10:14:02
*   Description:	修改说明
*
*
*********************************************************************/
#define BSP_INT_MODULE

#include "uart.h"
#include "stm32f2xx_ll_usart.h"
#include "stm32f2xx_ll_bus.h"
#include "errno-base.h"
#include <stdio.h>
#include <string.h>
#include "bsp.h"


#define UART1_IRQChannelPreemptionPriority	3
#define UART2_IRQChannelPreemptionPriority	3
#define UART3_IRQChannelPreemptionPriority	3
#define UART4_IRQChannelPreemptionPriority	3
#define UART5_IRQChannelPreemptionPriority	3
#define UART6_IRQChannelPreemptionPriority	3
#define UART7_IRQChannelPreemptionPriority	3
#define UART8_IRQChannelPreemptionPriority	3

#define UART1_IRQChannelSubPriority		1
#define UART2_IRQChannelSubPriority		2
#define UART3_IRQChannelSubPriority		3
#define UART4_IRQChannelSubPriority		4
#define UART5_IRQChannelSubPriority		5
#define UART6_IRQChannelSubPriority		6
#define UART7_IRQChannelSubPriority		7
#define UART8_IRQChannelSubPriority		8

typedef struct {
    uint8_t * buf;
    uint32_t mask;		//掩码，2的整数幂减一
    uint32_t rd;
    uint32_t wr;
} fifo_t;

#define IS_MASK_OF_BUF(A) 	(((A) != 0) && ((((A) - 1)& (A)) == 0))
const uint32_t COM_CLOCK[8] = {
			LL_APB2_GRP1_PERIPH_USART1,
			LL_APB1_GRP1_PERIPH_USART2,
			LL_APB1_GRP1_PERIPH_USART3,
			LL_APB1_GRP1_PERIPH_UART4,
			LL_APB1_GRP1_PERIPH_UART5,
			LL_APB2_GRP1_PERIPH_USART6,
#if defined(UART7)
			LL_APB1_GRP1_PERIPH_UART7,
#else
			0,
#endif /* UART7 */
#if defined(UART8)
			LL_APB1_GRP1_PERIPH_UART8,
#else
			0,
#endif /* UART8 */
			};
			
USART_TypeDef * COM_TYPE[8] = {
			USART1,
			USART2,
			USART3,
			UART4,
			UART5,
			USART6,
#if defined(UART7)
			UART7,
#else
			0,
#endif
#if defined(UART8)
			UART8
#else
			0,
#endif
			};

const IRQn_Type COM_IRQ[8] = {
		USART1_IRQn,
		USART2_IRQn,
		USART3_IRQn,
		UART4_IRQn,
		UART5_IRQn,
		USART6_IRQn,
#if defined(UART7)
		UART7_IRQn,
#else
		UsageFault_IRQn,
#endif
#if defined(UART8)
		UART8_IRQn
#else
		UsageFault_IRQn
#endif
};

const uint8_t COM_IRQChannelPreemptionPriority[8] = {
		UART1_IRQChannelPreemptionPriority,
		UART2_IRQChannelPreemptionPriority,
		UART3_IRQChannelPreemptionPriority,
		UART4_IRQChannelPreemptionPriority,
		UART5_IRQChannelPreemptionPriority,
		UART6_IRQChannelPreemptionPriority,
		UART7_IRQChannelPreemptionPriority,
		UART8_IRQChannelPreemptionPriority
};

const uint8_t COM_IRQChannelSubPriority[8] = {
		UART1_IRQChannelSubPriority,
		UART2_IRQChannelSubPriority,
		UART3_IRQChannelSubPriority,
		UART4_IRQChannelSubPriority,
		UART5_IRQChannelSubPriority,
		UART6_IRQChannelSubPriority,
		UART7_IRQChannelSubPriority,
		UART8_IRQChannelSubPriority
};

static fifo_t _com_fifo[8];

void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);
void USART6_IRQHandler(void);
#if defined(UART7)
void UART7_IRQHandler(void);
#endif
#if defined(UART8)
void UART8_IRQHandler(void);
#endif
int32_t uart_init(uart_dev_t *uart)
{
	int32_t ret = -EPERM;
	LL_USART_InitTypeDef s_uart_init;
	
	if((uart == NULL) || (uart->config.buf == NULL) || (! IS_MASK_OF_BUF(uart->config.buf_size) )){
		return ret;
	}
	uart->priv = &_com_fifo[uart->port];
	_com_fifo[uart->port].buf = uart->config.buf;
	_com_fifo[uart->port].mask = uart->config.buf_size - 1;
	
	
	LL_USART_Disable(COM_TYPE[uart->port]);
	
	switch(uart->port){
	case E_COM2:
	case E_COM3:
	case E_COM4:
	case E_COM5:
	case E_COM7:
	case E_COM8:
		LL_APB1_GRP1_EnableClock(COM_CLOCK[uart->port]);
		break;
		
	case E_COM1:
	case E_COM6:
		LL_APB2_GRP1_EnableClock(COM_CLOCK[uart->port]);
		break;
		
	default:
		break;
	}
	
	s_uart_init.BaudRate = uart->config.baud_rate;
	
	switch(uart->config.data_width){
			
	case DATA_WIDTH_8BIT:
		s_uart_init.DataWidth = LL_USART_DATAWIDTH_8B;
		break;
	
	case DATA_WIDTH_9BIT:
		s_uart_init.DataWidth = LL_USART_DATAWIDTH_9B;
		break;
	
	default:
		break;
	}
	
	switch(uart->config.flow_control){
	case FLOW_CONTROL_DISABLED:
		s_uart_init.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
		break;
		
	case FLOW_CONTROL_CTS:
		s_uart_init.HardwareFlowControl = LL_USART_HWCONTROL_CTS;
		break;
		
	case FLOW_CONTROL_RTS:
		s_uart_init.HardwareFlowControl = LL_USART_HWCONTROL_RTS;
		break;
		
	case FLOW_CONTROL_CTS_RTS:
		s_uart_init.HardwareFlowControl = LL_USART_HWCONTROL_RTS_CTS;
		break;
		
	default:
		s_uart_init.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
		break;
	}

	switch(uart->config.parity){
	case NO_PARITY:
		s_uart_init.Parity = LL_USART_PARITY_NONE;
		break;
		
	case ODD_PARITY:
		s_uart_init.Parity = LL_USART_PARITY_ODD;
		break;
		
	case EVEN_PARITY:
		s_uart_init.Parity = LL_USART_PARITY_EVEN;
		break;
		
	default:
		s_uart_init.Parity = LL_USART_PARITY_NONE;
		break;
	}
	
	switch(uart->config.stop_bits){
	case STOP_BITS_0_5:
		s_uart_init.StopBits = LL_USART_STOPBITS_0_5;
		break;
		
	case STOP_BITS_1:
		s_uart_init.StopBits = LL_USART_STOPBITS_1;
		break;
		
	case STOP_BITS_1_5:
		s_uart_init.StopBits = LL_USART_STOPBITS_1_5;
		break;
	case STOP_BITS_2:
		s_uart_init.StopBits = LL_USART_STOPBITS_2;
		break;
		
	default:
		s_uart_init.StopBits = LL_USART_STOPBITS_1;
		break;
	}
		
	switch(uart->config.mode){
	case MODE_TX:
		s_uart_init.TransferDirection = LL_USART_DIRECTION_TX;
		break;
		
	case MODE_RX:
		s_uart_init.TransferDirection = LL_USART_DIRECTION_RX;
		break;
	
	case MODE_TX_RX:
		s_uart_init.TransferDirection = LL_USART_DIRECTION_TX_RX;
		break;
		
	default:
		s_uart_init.TransferDirection = LL_USART_DIRECTION_TX_RX;
		break;
	}
	
	s_uart_init.OverSampling = LL_USART_OVERSAMPLING_16;

	memset(((fifo_t *)(uart->priv))->buf, 0 ,(((fifo_t *)(uart->priv))->mask + 1));
	((fifo_t *)(uart->priv))->rd = 0;
	((fifo_t *)(uart->priv))->wr = 0;


	/*interrupt Init */
	NVIC_SetPriority(COM_IRQ[uart->port], COM_IRQChannelPreemptionPriority[uart->port]);
	NVIC_EnableIRQ(COM_IRQ[uart->port]);

	
	LL_USART_Init(COM_TYPE[uart->port], &s_uart_init);
	LL_USART_ConfigAsyncMode(COM_TYPE[uart->port]);
	LL_USART_EnableIT_RXNE(COM_TYPE[uart->port]);
	
	LL_USART_Enable(COM_TYPE[uart->port]);

	ret = 0;
	return ret;
}

int32_t uart_finalize(uart_dev_t *uart)
{
	int32_t ret = -EPERM;
	
	if(uart == NULL){
		return ret;
	}
	
	NVIC_DisableIRQ(COM_IRQ[uart->port]);
	
	LL_USART_DisableIT_RXNE(COM_TYPE[uart->port]);
	LL_USART_Disable(COM_TYPE[uart->port]);
	
	switch(uart->port){
	case E_COM2:
	case E_COM3:
	case E_COM4:
	case E_COM5:
	case E_COM7:
	case E_COM8:
		LL_APB1_GRP1_DisableClock(COM_CLOCK[uart->port]);
		break;
		
	case E_COM1:
	case E_COM6:
		LL_APB2_GRP1_DisableClock(COM_CLOCK[uart->port]);
		break;
		
	default:
		break;
	}
	
	ret = 0;
	
	return ret;
}

int32_t uart_send(uart_dev_t *uart,const uint8_t *data,uint32_t size)
{
	int32_t ret = -EPERM;
	uint32_t i = 0;
	
	
	if(uart == NULL){
		return ret;
	}

	for(i = 0;i<size;i++){
		LL_USART_TransmitData8(COM_TYPE[uart->port],*(data+i));
		while(RESET == LL_USART_IsActiveFlag_TXE(COM_TYPE[uart->port]));		
	}

	if(size > 0){
		while(RESET == LL_USART_IsActiveFlag_TC(COM_TYPE[uart->port]));
	}
	

	return i;
}

int32_t get_recv_size(uart_dev_t *uart)
{
	int32_t ret = -EPERM;
	
	if(uart == NULL){
		return ret;
	}
	
	ret = ((fifo_t *)(uart->priv))->wr - ((fifo_t *)(uart->priv))->rd;
	
	return ret;
}

int32_t del_recv_size(uart_dev_t *uart,uint32_t expect_size)
{
	int32_t len = 0;
	int32_t ret = -EPERM;
	
	if(uart == NULL){
		return ret;
	}
	
	len = get_recv_size(uart);
	
	if(len > expect_size){
		len = expect_size;
	}
	
	((fifo_t *)(uart->priv))->rd += len;
	ret = len;
	
	return ret;
}

int32_t uart_recv(uart_dev_t *uart, uint8_t *data, uint32_t expect_size)
{
	int32_t len = 0;
	uint32_t i = 0;
	int32_t ret = -EPERM;
	
	if(uart == NULL){
		return ret;
	}
	
	len = get_recv_size(uart);
	if(0 > len){
		return ret;
	}
	
	if(len > expect_size){
		len = expect_size;
	}
	
	
	for(i = 0;i < len;i++){
		data[i] = ((fifo_t *)(uart->priv))->buf[(((fifo_t *)(uart->priv))->rd + i) & (((fifo_t *)(uart->priv))->mask)];
	}
	((fifo_t *)(uart->priv))->rd += i;
	
	ret = i;
	
	return ret;
	
}

int32_t uart_pre_recv(uart_dev_t *uart, uint8_t *data, uint32_t expect_size)
{
	int32_t len = 0;
	uint32_t i = 0;
	int32_t ret = -EPERM;
	
	if(uart == NULL){
		return ret;
	}
	
	len = get_recv_size(uart);
	if(0 > len){
		return ret;
	}
	
	if(len > expect_size){
		len = expect_size;
	}
	
	for(i = 0;i < len;i++){
		data[i] = ((fifo_t *)(uart->priv))->buf[(((fifo_t *)(uart->priv))->rd + i) & (((fifo_t *)(uart->priv))->mask)];
	}
	
	ret = i;
	
	return ret;
	
}


void USART1_IRQHandler(void)
{
	
	if((LL_USART_IsActiveFlag_RXNE(USART1) == SET) || (LL_USART_IsActiveFlag_ORE(USART1) == SET)){
		_com_fifo[E_COM1].buf[_com_fifo[E_COM1].wr&_com_fifo[E_COM1].mask] = LL_USART_ReceiveData8(USART1);
		_com_fifo[E_COM1].wr++;
		if((_com_fifo[E_COM1].wr - _com_fifo[E_COM1].rd) > (_com_fifo[E_COM1].mask + 1)){
			_com_fifo[E_COM1].rd++;
		}
		LL_USART_ClearFlag_RXNE(USART1);
	}else if(LL_USART_IsActiveFlag_ORE(USART1) == SET){
		LL_USART_ReceiveData8(USART1);
		LL_USART_ClearFlag_ORE(USART1);
	}
}

void USART2_IRQHandler(void)
{
	
	if((LL_USART_IsActiveFlag_RXNE(USART2) == SET) || (LL_USART_IsActiveFlag_ORE(USART2) == SET)){
		_com_fifo[E_COM2].buf[_com_fifo[E_COM2].wr&_com_fifo[E_COM2].mask] = LL_USART_ReceiveData8(USART2);
		_com_fifo[E_COM2].wr++;
		if((_com_fifo[E_COM2].wr - _com_fifo[E_COM2].rd) > (_com_fifo[E_COM2].mask + 1)){
			_com_fifo[E_COM2].rd++;
		}
		LL_USART_ClearFlag_RXNE(USART2);
	}else if(LL_USART_IsActiveFlag_ORE(USART2) == SET){
		LL_USART_ReceiveData8(USART2);
		LL_USART_ClearFlag_ORE(USART2);
	}	
}


void USART3_IRQHandler(void)
{
		
	if((LL_USART_IsActiveFlag_RXNE(USART3) == SET) || (LL_USART_IsActiveFlag_ORE(USART3) == SET)){
		_com_fifo[E_COM3].buf[_com_fifo[E_COM3].wr&_com_fifo[E_COM3].mask] = LL_USART_ReceiveData8(USART3);
		_com_fifo[E_COM3].wr++;
		if((_com_fifo[E_COM3].wr - _com_fifo[E_COM3].rd) > (_com_fifo[E_COM3].mask + 1)){
			_com_fifo[E_COM3].rd++;
		}
		LL_USART_ClearFlag_RXNE(USART3);
	}else if(LL_USART_IsActiveFlag_ORE(USART3) == SET){
		LL_USART_ReceiveData8(USART3);
		LL_USART_ClearFlag_ORE(USART3);
	}	
}

void UART4_IRQHandler(void)
{
		
	if((LL_USART_IsActiveFlag_RXNE(UART4) == SET) || (LL_USART_IsActiveFlag_ORE(UART4) == SET)){
		_com_fifo[E_COM4].buf[_com_fifo[E_COM4].wr&_com_fifo[E_COM4].mask] = LL_USART_ReceiveData8(UART4);
		_com_fifo[E_COM4].wr++;
		if((_com_fifo[E_COM4].wr - _com_fifo[E_COM4].rd) > (_com_fifo[E_COM4].mask + 1)){
			_com_fifo[E_COM4].rd++;
		}
		LL_USART_ClearFlag_RXNE(UART4);
	}else if(LL_USART_IsActiveFlag_ORE(UART4) == SET){
		LL_USART_ReceiveData8(UART4);
		LL_USART_ClearFlag_ORE(UART4);
	}	
}

void UART5_IRQHandler(void)
{
	
	if((LL_USART_IsActiveFlag_RXNE(UART5) == SET) || (LL_USART_IsActiveFlag_ORE(UART5) == SET)){
		_com_fifo[E_COM5].buf[_com_fifo[E_COM5].wr&_com_fifo[E_COM5].mask] = LL_USART_ReceiveData8(UART5);
		_com_fifo[E_COM5].wr++;
		if((_com_fifo[E_COM5].wr - _com_fifo[E_COM5].rd) > (_com_fifo[E_COM5].mask + 1)){
			_com_fifo[E_COM5].rd++;
		}
		LL_USART_ClearFlag_RXNE(UART5);
	}else if(LL_USART_IsActiveFlag_ORE(UART5) == SET){
		LL_USART_ReceiveData8(UART5);
		LL_USART_ClearFlag_ORE(UART5);
	}	
}

void USART6_IRQHandler(void)
{
	
	if((LL_USART_IsActiveFlag_RXNE(USART6) == SET) || (LL_USART_IsActiveFlag_ORE(USART6) == SET)){
		_com_fifo[E_COM6].buf[_com_fifo[E_COM6].wr&_com_fifo[E_COM6].mask] = LL_USART_ReceiveData8(USART6);
		_com_fifo[E_COM6].wr++;
		if((_com_fifo[E_COM6].wr - _com_fifo[E_COM6].rd) > (_com_fifo[E_COM6].mask + 1)){
			_com_fifo[E_COM6].rd++;
		}
		LL_USART_ClearFlag_RXNE(USART6);
	}else if(LL_USART_IsActiveFlag_ORE(USART6) == SET){
		LL_USART_ReceiveData8(USART6);
		LL_USART_ClearFlag_ORE(USART6);
	}	
}
#if defined(UART7)
void UART7_IRQHandler(void)
{
	
	if((LL_USART_IsActiveFlag_RXNE(UART7) == SET) || (LL_USART_IsActiveFlag_ORE(UART7) == SET)){
		_com_fifo[E_COM7].buf[_com_fifo[E_COM7].wr&_com_fifo[E_COM7].mask] = LL_USART_ReceiveData8(UART7);
		_com_fifo[E_COM7].wr++;
		if((_com_fifo[E_COM7].wr - _com_fifo[E_COM7].rd) > (_com_fifo[E_COM7].mask + 1)){
			_com_fifo[E_COM7].rd++;
		}
		LL_USART_ClearFlag_RXNE(UART7);
	}else if(LL_USART_IsActiveFlag_ORE(UART7) == SET){
		LL_USART_ReceiveData8(UART7);
		LL_USART_ClearFlag_ORE(UART7);
	}
}
#endif
#if defined(UART8)
void UART8_IRQHandler(void)
{
		
	if((LL_USART_IsActiveFlag_RXNE(UART8) == SET) || (LL_USART_IsActiveFlag_ORE(UART8) == SET)){
		_com_fifo[E_COM8].buf[_com_fifo[E_COM8].wr&_com_fifo[E_COM8].mask] = LL_USART_ReceiveData8(UART8);
		_com_fifo[E_COM8].wr++;
		if((_com_fifo[E_COM8].wr - _com_fifo[E_COM8].rd) > (_com_fifo[E_COM8].mask + 1)){
			_com_fifo[E_COM8].rd++;
		}
		LL_USART_ClearFlag_RXNE(UART8);
	}else if(LL_USART_IsActiveFlag_ORE(UART8) == SET){
		LL_USART_ReceiveData8(UART8);
		LL_USART_ClearFlag_ORE(UART8);
	}	
}
#endif
