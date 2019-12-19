/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	iwdg.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	iwdg.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-20 16:54:20
*   Description:	修改说明
*
*
*********************************************************************/

#include "iwdg.h"
#include "stm32f2xx_ll_iwdg.h"
#include "errno-base.h"


#include <stdio.h>

int32_t wdg_init(wdg_dev_t *wdg)
{
	int32_t ret = -EPERM;
	
	if (wdg == NULL) {
		return ret;
	}
	 LL_IWDG_Enable(IWDG);
	LL_IWDG_SetReloadCounter(IWDG,wdg->config.timeout&0xffff);
	LL_IWDG_EnableWriteAccess(IWDG);
	LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_32);
	while (LL_IWDG_IsReady(IWDG) != 1);
	
	LL_IWDG_ReloadCounter(IWDG);
	
	return 0;
}

int32_t wdg_reload(wdg_dev_t *wdg)
{
	int32_t ret = -EPERM;
	

	if (wdg == NULL) {
		return ret;
	}
	
	LL_IWDG_ReloadCounter(IWDG);
	return 0;
}


int32_t wdg_finalize(wdg_dev_t *wdg)
{
	return -EPERM;
}


