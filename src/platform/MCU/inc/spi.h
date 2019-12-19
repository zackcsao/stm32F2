/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.

*      Filename:	spi.h
*        Author:	caozhaofei
*         Email:	caozhaofei@live.cn
*        Create:	2016-12-05 11:01:39
*
* Last modified:	2016-12-05 11:01:39
*
*
*  Description:	
*
*********************************************************************/

#ifndef _SPI_H__
#define _SPI_H__
#include <stdint.h>


/***********************SPI start**************************/

/*******************************************************************
*Mode 0 CPOL=0, CPHA=0 
*Mode 1 CPOL=0, CPHA=1
*Mode 2 CPOL=1, CPHA=0 
*Mode 3 CPOL=1, CPHA=1
*******************************************************************/

typedef enum {
	E_SPI1 = 0,
	E_SPI2 = 1,
	E_SPI3 = 2,
	E_SPI4 = 3,
	E_SPI5 = 4,
	E_SPI6 = 5
}SPI_PORT;

typedef enum {
	MODE0 = 0,
	MODE1,
	MODE2,
	MODE3
}SPI_MODE;

typedef enum {
	E_SPI_BAUD_1_2_FPCLK,
	E_SPI_BAUD_1_4_FPCLK,
	E_SPI_BAUD_1_8_FPCLK,
	E_SPI_BAUD_1_16_FPCLK,
	E_SPI_BAUD_1_32_FPCLK,
	E_SPI_BAUD_1_64_FPCLK,
	E_SPI_BAUD_1_128_FPCLK,
	E_SPI_BAUD_1_256_FPCLK,
}SPI_BAUD;

typedef enum {
	E_SPI_LSB_FIRST,
	E_SPI_MSB_FIRST
}SPI_BIT_ORDER;

typedef enum {
	E_SPI_NSS_SOFT,
	E_SPI_NSS_HARD_INPUT,
	E_SPI_NSS_HARD_OUTPUT
}SPI_NSS_MODE;

typedef enum {
	E_SPI_FULL_DUPLEX,
	E_SPI_SIMPLEX_RX,
	E_SPI_HALF_DUPLEX_RX,
	E_SPI_HALF_DUPLEX_TX
}SPI_TRANSFER;

typedef enum {
	E_SPI_MODE_MASTER,
	E_SPI_MODE_SLAVE
}E_SPI_WORK_MODE;

typedef enum {
	E_SPI_DATAWIDTH_8BIT,
	E_SPI_DATAWIDTH_16BIT
}E_SPI_DATA_WIDTH;


typedef struct {
	uint32_t type;			/* spi communication mode */
	uint32_t freq;			/* communication frequency Hz */
	uint32_t mode;			//相位和极性
	uint32_t bit_order;
	uint32_t cs_type;
	uint32_t transfer_mode;
	uint32_t data_length;
} spi_config_t;

typedef struct {
	uint8_t      port;    /* spi port */
	spi_config_t config;  /* spi config */
	void        *priv;    /* priv data */
} spi_dev_t;
/***********************SPI end**************************/



/**
 * Initialises the SPI interface for a given SPI device
 *
 * @param[in]  spi  the spi device
 *
 * @return  0 : on success, EIO : if the SPI device could not be initialised
 */
int32_t spi_init(spi_dev_t *spi);

/**
 * Spi send
 *
 * @param[in]  spi      the spi device
 * @param[in]  data     spi send data
 * @param[in]  size     spi send data size
 *
 * @return  0 : on success, EIO : if the SPI device could not be initialised
 */
int32_t spi_send(spi_dev_t *spi, const uint8_t *data, uint32_t size);

/**
 * spi_recv
 *
 * @param[in]   spi      the spi device
 * @param[out]  data     spi recv data
 * @param[in]   size     spi recv data size
 *
 * @return  0 : on success, EIO : if the SPI device could not be initialised
 */
int32_t spi_recv(spi_dev_t *spi, uint8_t *data, uint32_t size);

/**
 * spi send data and recv
 *
 * @param[in]  spi      the spi device
 * @param[in]  tx_data  spi send data
 * @param[in]  rx_data  spi recv data
 * @param[in]  size     spi data to be sent and recived
 *
 * @return  0, on success;  EIO : if the SPI device could not be initialised
 */
int32_t spi_send_recv(spi_dev_t *spi, uint8_t tx_data);

/**
 * De-initialises a SPI interface
 *
 *
 * @param[in]  spi the SPI device to be de-initialised
 *
 * @return  0 : on success, EIO : if an error occurred
 */
int32_t spi_finalize(spi_dev_t *spi);

#endif //SPI_H__

