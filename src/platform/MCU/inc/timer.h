/*********************************************************************
*
*	Copyright (c)dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	timer.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	timer.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 13:11:07
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __TIMER_H__
#define __TIMER_H__
#include <stdint.h>



/*************************TIMER start****************************/

typedef enum {
	E_SYS_TICK,
	E_TIMER1,
	E_TIMER2,
	E_TIMER3,
	E_TIMER4,
	E_TIMER5,
	E_TIMER6,
	E_TIMER7,
	E_TIMER8,
	E_TIMER9,
	E_TIMER10,
	E_TIMER11,
	E_TIMER12,
	E_TIMER13,
	E_TIMER14
}TIMER_PORT;

typedef void (*timer_cb_t)(void);

typedef struct {
    uint32_t       period;   /*ms*/
} timer_config_t;

typedef struct {
    uint8_t port;   /* timer port */
    timer_config_t config; /* timer config */
    void          *priv;   /* priv data */
} timer_dev_t;
/*************************TIMER end****************************/
/**
 * init a hardware timer
 *
 * @param[in]  tim  timer device
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t timer_init(timer_dev_t *tim);

/**
 * start a hardware timer
 *
 * @param[in]  tim  timer device
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t timer_start(timer_dev_t *tim);

/**
 * stop a hardware timer
 *
 * @param[in]  tim  timer device
 *
 * @return  none
 */
int32_t timer_stop(timer_dev_t *tim);

/**
 * De-initialises an TIMER interface, Turns off an TIMER hardware interface
 *
 * @param[in]  tim  timer device
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t timer_finalize(timer_dev_t *tim);
#endif //__TIMER_H__

