/*********************************************************************
*
*	Copyright (c)dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	uart.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	uart.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 10:14:14
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>

typedef enum {
	E_COM1 = 0,
	E_COM2,
	E_COM3,
	E_COM4,
	E_COM5,
	E_COM6,
	E_COM7,
	E_COM8
}COM_PORT;


/*
  * UART data width
  */
 typedef enum {
	DATA_WIDTH_7BIT,
	DATA_WIDTH_8BIT,
	DATA_WIDTH_9BIT
} uart_data_width_t;

 /*
  * UART stop bits
  */
typedef enum {
	STOP_BITS_0_5,
	STOP_BITS_1,
	STOP_BITS_1_5,
	STOP_BITS_2
} uart_stop_bits_t;

 /*
  * UART flow control
  */
typedef enum {
	FLOW_CONTROL_DISABLED,
	FLOW_CONTROL_CTS,
	FLOW_CONTROL_RTS,
	FLOW_CONTROL_CTS_RTS
} uart_flow_control_t;


 /*
  * UART parity
  */
typedef enum {
	NO_PARITY,
	ODD_PARITY,
	EVEN_PARITY
} uart_parity_t;

 /*
  * UART mode
  */
 typedef enum {
	MODE_TX,
	MODE_RX,
	MODE_TX_RX
} uart_mode_t;

 /*
  * UART configuration
  */
 typedef struct {
	uint32_t            baud_rate;
	uart_data_width_t   data_width;
	uart_parity_t       parity;
	uart_stop_bits_t    stop_bits;
	uart_flow_control_t flow_control;
	uart_mode_t         mode;
	uint8_t 	    *buf;
	uint32_t 	     buf_size;
} uart_config_t;


typedef struct {
	uint8_t       port;    /* uart port */
	uart_config_t config;  /* uart config */
	void         *priv;    /* priv data */
} uart_dev_t;


typedef struct {
	int32_t (*init)(uart_dev_t *uart);
	int32_t (*deinit)(uart_dev_t *uart);
	int32_t (*get_size)(uart_dev_t *uart);
	int32_t (*del_data)(uart_dev_t *uart,uint32_t size);
	int32_t (*read)(uart_dev_t *uart,uint8_t *pdata,uint32_t size);
	int32_t (*pre_read)(uart_dev_t *uart,uint8_t *pdata,uint32_t size);
	int32_t (*write)(uart_dev_t *uart,const uint8_t *pdata,uint32_t szie);
}COM_FUNC;
/***************************uart end********************************************/
/**
* Initialises a UART interface
*
*
* @param[in]  uart  the interface which should be initialised
*
* @return  0 : on success, EIO : if an error occurred with any step
*/
int32_t uart_init(uart_dev_t *uart);
 

/**
* Transmit data on a UART interface
*
* @param[in]  uart     the UART interface
* @param[in]  data     pointer to the start of data
* @param[in]  size     number of bytes to transmit
*
* @return  0 or positive numbe : on success, EIO : if an error occurred with any step
*/
int32_t uart_send(uart_dev_t *uart, const uint8_t *data, uint32_t size);
 

/**
* Receive data on a UART interface
*
* @param[in]   uart         the UART interface
* @param[out]  data         pointer to the buffer which will store incoming data
* @param[in]   expect_size  number of bytes to receive
*
* @return  0 or positive numbe : on success, EIO : if an error occurred with any step
*/
int32_t uart_recv(uart_dev_t *uart, uint8_t *data, uint32_t expect_size);
 

/**
* Receive data on a UART interface
*
* @param[in]   uart         the UART interface
* @param[out]  data         pointer to the buffer which will store incoming data
* @param[in]   expect_size  number of bytes to receive
* @param[out]  recv_size    number of bytes received
*
* @return  0 or positive numbe : on success, EIO : if an error occurred with any step
*/
int32_t uart_pre_recv(uart_dev_t *uart, uint8_t *data, uint32_t expect_size);

int32_t get_recv_size(uart_dev_t *uart);
int32_t del_recv_size(uart_dev_t *uart,uint32_t expect_size);

/**
* Deinitialises a UART interface
*
* @param[in]  uart  the interface which should be deinitialised
*
* @return  0 : on success, EIO : if an error occurred with any step
*/
int32_t uart_finalize(uart_dev_t *uart);
#endif //__UART_H__

