/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	fifo.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	fifo.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-07-01 18:27:36
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __FIFO_H__
#define __FIFO_H__
#include <stdint.h>


typedef struct {
    uint8_t * buf;
    uint32_t mask;		//掩码，2的整数幂减一
    uint32_t rd;
    uint32_t wr;
} fifo_t;
int32_t  fifo_init(fifo_t *pfifo,uint8_t *buf,uint32_t size);
int32_t fifo_get_free_size(fifo_t *pfifo);
int32_t fifo_get_data_size(fifo_t *pfifo);
int32_t fifo_del_data(fifo_t *pfifo,uint32_t size);
int32_t fifo_read(fifo_t *pfifo,uint8_t *buf,uint32_t len);
int32_t fifo_pre_read(fifo_t *pfifo,uint8_t *buf,uint32_t len);
int32_t fifo_write(fifo_t *pfifo,const uint8_t *buf,uint32_t len);
#endif
