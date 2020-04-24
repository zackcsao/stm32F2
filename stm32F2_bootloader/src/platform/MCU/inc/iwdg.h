/*********************************************************************
*
*	Copyright (c)dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	iwdg.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	iwdg.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-20 16:55:28
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __IWDG_H__
#define __IWDG_H__
#include <stdint.h>

/*************************WDG start****************************/
typedef struct {
    uint32_t timeout;  /* Watchdag timeout ms*/
} wdg_config_t;

typedef struct {
    uint8_t      port;   /* wdg port */
    wdg_config_t config; /* wdg config */
    void        *priv;   /* priv data */
} wdg_dev_t;
/*************************WDG end******************************/

/**
 * This function will initialize the on board CPU hardware watch dog
 *
 * @param[in]  wdg  the watch dog device
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t wdg_init(wdg_dev_t *wdg);

/**
 * Reload watchdog counter.
 *
 * @param[in]  wdg  the watch dog device
 */
int32_t wdg_reload(wdg_dev_t *wdg);

/**
 * This function performs any platform-specific cleanup needed for hardware watch dog.
 *
 * @param[in]  wdg  the watch dog device
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t wdg_finalize(wdg_dev_t *wdg);
#endif //__IWDG_H__

