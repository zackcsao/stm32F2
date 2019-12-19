/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	timer.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	timer.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 13:10:55
*   Description:	修改说明
*
*
*********************************************************************/

#include "timer.h"
#include "stm32f2xx_ll_tim.h"
#include "stm32f2xx_ll_bus.h"
#include "errno-base.h"
#include "bsp.h"
#include <stdio.h>



static timer_cb_t _timer_back[11] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

const uint32_t timer_clock[] = {
	LL_APB2_GRP1_PERIPH_SYSCFG,
	LL_APB2_GRP1_PERIPH_TIM1,
	LL_APB1_GRP1_PERIPH_TIM2,
#if defined(TIM3)
	LL_APB1_GRP1_PERIPH_TIM3,
#else
	0,
#endif
#if defined(TIM4)
	LL_APB1_GRP1_PERIPH_TIM4,
#else
	0,
#endif
#if defined(TIM5)
	LL_APB1_GRP1_PERIPH_TIM5,
#else
	0,
#endif
#if defined(TIM6)
	LL_APB1_GRP1_PERIPH_TIM6,
#else
	0,
#endif
#if defined(TIM7)
	LL_APB1_GRP1_PERIPH_TIM7,
#else
	0,
#endif
#if defined(TIM8)
	LL_APB2_GRP1_PERIPH_TIM8,
#else
	0,
#endif
};

const IRQn_Type tim_irq[] = {
		SysTick_IRQn,
		TIM1_UP_TIM10_IRQn,
		TIM2_IRQn,
#if defined(TIM3)
		TIM3_IRQn,
#else
		UsageFault_IRQn,
#endif
#if defined(TIM4)
		TIM4_IRQn,
#else
		UsageFault_IRQn,
#endif
#if defined(TIM5)
		TIM5_IRQn,
#else
		UsageFault_IRQn,
#endif
#if defined(TIM6)
		TIM6_DAC_IRQn,
#else
		UsageFault_IRQn,
#endif
#if defined(TIM7)
		TIM7_IRQn,
#else
		UsageFault_IRQn,
#endif
#if defined(TIM8)
		TIM8_UP_TIM13_IRQn,
#else
		UsageFault_IRQn,
#endif
};

TIM_TypeDef * tim_type[] = {
	0,
	TIM1,
	TIM2,
#if defined(TIM3)
	TIM3,
#else 
	0,
#endif
#if defined(TIM4)
	TIM4,
#else
	0,
#endif
#if defined(TIM5)
	TIM5,
#else
	0,
#endif
#if defined(TIM6)
	TIM6,
#else
	0,
#endif
#if defined(TIM7)
	TIM7,
#else 
	0,
#endif
#if defined(TIM8)
	TIM8,
#else 
	0,
#endif

};

void TIM2_IRQHandler(void);
#if defined(TIM3)
void TIM3_IRQHandler(void);
#endif
#if defined(TIM4)
void TIM4_IRQHandler(void);
#endif
#if defined(TIM5)
void TIM5_IRQHandler(void);
#endif
#if defined(TIM6)
void TIM6_IRQHandler(void);
#endif
#if defined(TIM7)
void TIM7_IRQHandler(void);
#endif
int32_t timer_init(timer_dev_t *tim)
{
	LL_TIM_InitTypeDef  TIM_TimeBaseStructure;
	
	int32_t ret = -EPERM;
	
	if(NULL == tim){
		return ret;
	}
	switch(tim->port){
	case E_TIMER2:
	case E_TIMER3:
	case E_TIMER4:
	case E_TIMER5:
	case E_TIMER6:
	case E_TIMER7:
		LL_APB1_GRP1_EnableClock(timer_clock[tim->port]);
		TIM_TimeBaseStructure.Autoreload = (tim->config.period)*2;//0xffffffff;
		TIM_TimeBaseStructure.Prescaler = 42000;
		break;
		
	case E_SYS_TICK:
	case E_TIMER1:
	case E_TIMER8:
		LL_APB2_GRP1_EnableClock(timer_clock[tim->port]);
		TIM_TimeBaseStructure.Autoreload = (tim->config.period)*4;//0xffffffff;
		TIM_TimeBaseStructure.Prescaler = 42000;
		break;
		
	default:
		break;
	}
	 
	
	
	NVIC_SetPriority(tim_irq[tim->port], 6);
	NVIC_EnableIRQ(tim_irq[tim->port]);
	
	TIM_TimeBaseStructure.ClockDivision = LL_TIM_CLOCKDIVISION_DIV4;
	TIM_TimeBaseStructure.CounterMode = LL_TIM_COUNTERMODE_UP;
	LL_TIM_Init(tim_type[tim->port], &TIM_TimeBaseStructure);
	
	LL_TIM_EnableARRPreload(tim_type[tim->port]);
	LL_TIM_EnableIT_UPDATE(tim_type[tim->port]);
	
	LL_TIM_SetClockSource(tim_type[tim->port], LL_TIM_CLOCKSOURCE_INTERNAL);
	LL_TIM_SetTriggerOutput(tim_type[tim->port], LL_TIM_TRGO_RESET);
	LL_TIM_DisableMasterSlaveMode(tim_type[tim->port]);
	
	if(tim->priv != NULL){
		_timer_back[tim->port] = (timer_cb_t)tim->priv;
	}
	
	LL_TIM_EnableCounter(tim_type[tim->port]);
	ret = 0;
	return ret;
}

int32_t timer_start(timer_dev_t *tim)
{
	int32_t ret = -EPERM;
	
	if(NULL == tim){
		return ret;
	}
		
	LL_TIM_EnableCounter(tim_type[tim->port]);
	
	if(tim->priv != NULL){
		_timer_back[tim->port] = (timer_cb_t)tim->priv;
	}
	
	
	ret = 0;
	return ret;
}

int32_t timer_stop(timer_dev_t *tim)
{
	int32_t ret = -EPERM;
	
	if(NULL == tim){
		return ret;
	}

	LL_TIM_DisableCounter(tim_type[tim->port]);

	
	ret = 0;
	return ret;
}

int32_t timer_finalize(timer_dev_t *tim)
{
	int32_t ret = -EPERM; 
	
	if(NULL == tim){
		return ret;
	}
	NVIC_DisableIRQ(tim_irq[tim->port]);
	LL_TIM_DeInit(tim_type[tim->port]);
	ret = 0;
	return ret;
}

void TIM2_IRQHandler(void)
{
	if(SET == LL_TIM_IsActiveFlag_UPDATE (TIM2)){
		LL_TIM_ClearFlag_UPDATE(TIM2);
		if(_timer_back[E_TIMER2] != NULL){
			_timer_back[E_TIMER2]();
		}
	}
}

#if defined(TIM3)
void TIM3_IRQHandler(void)
{
	if(SET == LL_TIM_IsActiveFlag_UPDATE (TIM3)){
		LL_TIM_ClearFlag_UPDATE(TIM3);
		if(_timer_back[E_TIMER3] != NULL){
			_timer_back[E_TIMER3]();
		}
	}
}

#endif
#if defined(TIM4)
void TIM4_IRQHandler(void)
{
	if(SET == LL_TIM_IsActiveFlag_UPDATE (TIM4)){
		LL_TIM_ClearFlag_UPDATE(TIM4);
		if(_timer_back[E_TIMER4] != NULL){
			_timer_back[E_TIMER4]();
		}
	}
}

#endif
#if defined(TIM5)
void TIM5_IRQHandler(void)
{
	if(SET == LL_TIM_IsActiveFlag_UPDATE (TIM5)){
		LL_TIM_ClearFlag_UPDATE(TIM5);
		if(_timer_back[E_TIMER5] != NULL){
			_timer_back[E_TIMER5]();
		}
	}
}

#endif
#if defined(TIM6)
void TIM6_IRQHandler(void)
{
	if(SET == LL_TIM_IsActiveFlag_UPDATE (TIM6)){
		LL_TIM_ClearFlag_UPDATE(TIM6);
		if(_timer_back[E_TIMER6] != NULL){
			_timer_back[E_TIMER6]();
		}
	}
}

#endif
#if defined(TIM7)
void TIM7_IRQHandler(void)
{
	if(SET == LL_TIM_IsActiveFlag_UPDATE (TIM7)){
		LL_TIM_ClearFlag_UPDATE(TIM7);
		if(_timer_back[E_TIMER7] != NULL){
			_timer_back[E_TIMER7]();
		}
	}
}

#endif
