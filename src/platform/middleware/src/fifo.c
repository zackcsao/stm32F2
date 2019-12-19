/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*      Filename:	fifo.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	fifo.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-07-01 18:25:54
*   Description:	修改说明
*
*
*********************************************************************/

#include "fifo.h"

#include <string.h>



#define IS_MASK_OF_BUF(A) 	(((A) != 0) && ((((A) - 1)& (A)) == 0))

int32_t  fifo_init(fifo_t *pfifo,uint8_t *buf,uint32_t size)
{
	if( (pfifo == NULL) || (buf == NULL)){
		return -1;
	}
	
	if(!IS_MASK_OF_BUF(size)){
		return -2;
	}
	
	pfifo->rd = 0;
	pfifo->wr = 0;
	pfifo->mask = size -1;
	pfifo->buf = buf;
	
	memset(pfifo->buf,0,pfifo->mask+1);
	
	return 0;
}

int32_t fifo_get_free_size(fifo_t *pfifo)
{
	return (pfifo->mask+1) - (pfifo->wr - pfifo->rd);
}

int32_t fifo_get_data_size(fifo_t *pfifo)
{
	return pfifo->wr - pfifo->rd;
}
int32_t fifo_del_data(fifo_t *pfifo,uint32_t size)
{
	uint32_t tmp = 0;
	
	tmp = fifo_get_data_size(pfifo);
	
	if(size < tmp){
		tmp = size;
	}
	pfifo->rd += tmp;

	return tmp;
}
int32_t fifo_read(fifo_t *pfifo,uint8_t *buf,uint32_t len)
{
	uint32_t i = 0;
	uint32_t tmp = 0;
	
	tmp = fifo_get_data_size(pfifo);
	
	if(len < tmp){
		tmp = len;
	}
	for(i = 0; i < tmp;i++){
		buf[i] = pfifo->buf[(pfifo->rd +i)&pfifo->mask];
	}
	pfifo->rd += i;
	
	return i;
}

int32_t fifo_pre_read(fifo_t *pfifo,uint8_t *buf,uint32_t len)
{
	uint32_t i = 0;
	uint32_t tmp = 0;
	
	tmp = fifo_get_data_size(pfifo);
	
	if(len < tmp){
		tmp = len;
	}
	for(i = 0; i < tmp;i++){
		buf[i] = pfifo->buf[(pfifo->rd +i)&pfifo->mask];
	}
	
	return i;
}

int32_t fifo_write(fifo_t *pfifo,const uint8_t *buf,uint32_t len)
{
	uint32_t i = 0;
	
	for(i = 0; i < len;i++){
		pfifo->buf[(pfifo->wr +i)&pfifo->mask] =buf[i];
	}
	pfifo->wr += i;
	
	if(pfifo->wr - pfifo->rd > (pfifo->mask + 1)){
		pfifo->rd = pfifo->wr - pfifo->mask;
	}
	
	return i;
}
