/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	gpio.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	gpio.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 10:15:18
*   Description:	修改说明
*
*
*********************************************************************/

#include "gpio.h"
#include "stm32f2xx_ll_gpio.h"
#include "stm32f2xx_ll_bus.h"
#include "stm32f2xx_ll_system.h"
#include "stm32f2xx_ll_exti.h"
#include <stdio.h>
#include "bsp.h"

#define GPIO_IRQ_SLOP_MAX	(16)

#define LL_PINS_IN_GROUP	(16)

typedef struct gpio_irq_slop {
	gpio_irq_handler_t handler;
	gpio_irq_trigger_t trigger;
} gpio_irq_slop_t;

static gpio_irq_slop_t gGpioSlop[GPIO_IRQ_SLOP_MAX]= {
	{.handler=NULL},{.handler=NULL},{.handler=NULL},{.handler=NULL},
	{.handler=NULL},{.handler=NULL},{.handler=NULL},{.handler=NULL},
	{.handler=NULL},{.handler=NULL},{.handler=NULL},{.handler=NULL},
	{.handler=NULL},{.handler=NULL},{.handler=NULL},{.handler=NULL},
};

const uint32_t SYSCFG_EXTI_LINE[16] = {
	LL_EXTI_LINE_0,
	LL_EXTI_LINE_1,
	LL_EXTI_LINE_2,
	LL_EXTI_LINE_3,
	LL_EXTI_LINE_4,
	LL_EXTI_LINE_5,
	LL_EXTI_LINE_6,
	LL_EXTI_LINE_7,
	LL_EXTI_LINE_8,
	LL_EXTI_LINE_9,
	LL_EXTI_LINE_10,
	LL_EXTI_LINE_11,
	LL_EXTI_LINE_12,
	LL_EXTI_LINE_13,
	LL_EXTI_LINE_14,
	LL_EXTI_LINE_15	
};

const uint32_t PIN_LINE_NUM[16] = {
	LL_GPIO_PIN_0,
	LL_GPIO_PIN_1,
	LL_GPIO_PIN_2,
	LL_GPIO_PIN_3,
	LL_GPIO_PIN_4,
	LL_GPIO_PIN_5,
	LL_GPIO_PIN_6,
	LL_GPIO_PIN_7,
	LL_GPIO_PIN_8,
	LL_GPIO_PIN_9,
	LL_GPIO_PIN_10,
	LL_GPIO_PIN_11,
	LL_GPIO_PIN_12,
	LL_GPIO_PIN_13,
	LL_GPIO_PIN_14,
	LL_GPIO_PIN_15
};

//const uint32_t gpio_alternate[] = {GPIO_AF_0,LL_GPIO_AF_1,LL_GPIO_AF_2,LL_GPIO_AF_3,LL_GPIO_AF_4,LL_GPIO_AF_5,LL_GPIO_AF_6,LL_GPIO_AF_7};


static int32_t gpio_para_transform(gpio_dev_t *gpio, LL_GPIO_InitTypeDef * init_str);
static uint32_t get_gpio_pin(uint8_t pin);
static int32_t gpio_has_priv(gpio_dev_t *gpio);


GPIO_TypeDef * gpio_port[] = {
	GPIOA,
	GPIOB,
	GPIOC,
#if defined(GPIOD)
	GPIOD,
#else
	0,
#endif

#if defined(GPIOE)
	GPIOE,
#else
	0,
#endif
#if defined(GPIOF)
	GPIOF,
#else
	0,
#endif
#if defined(GPIOG)
	GPIOG,
#else
	0,
#endif
#if defined(GPIOH)
	GPIOH,
#else
	0,
#endif
#if defined(GPIOI)
	GPIOI,
#else
	0,
#endif
};

const uint32_t gpio_clock[] = {
	LL_AHB1_GRP1_PERIPH_GPIOA,
	LL_AHB1_GRP1_PERIPH_GPIOB,
	LL_AHB1_GRP1_PERIPH_GPIOC,
#if defined(GPIOD)
	LL_AHB1_GRP1_PERIPH_GPIOD,
#else
	0,
#endif
#if defined(GPIOE)
	LL_AHB1_GRP1_PERIPH_GPIOE,
#else
	0,
#endif
#if defined(GPIOF)
	LL_AHB1_GRP1_PERIPH_GPIOF,
#else 
	0,
#endif
#if defined(GPIOG)
	LL_AHB1_GRP1_PERIPH_GPIOG,
#else 
	0,
#endif
#if defined(GPIOH)
	LL_AHB1_GRP1_PERIPH_GPIOH,
#else 
	0,
#endif
#if defined(GPIOI)
	LL_AHB1_GRP1_PERIPH_GPIOI,
#else 
	0,
#endif
#if defined(GPIOJ)
	LL_AHB1_GRP1_PERIPH_GPIOJ,
#else 
	0,
#endif
#if defined(GPIOK)
	LL_AHB1_GRP1_PERIPH_GPIOK,
#else 
	0,
#endif
};
const IRQn_Type irq_type[] = {
	EXTI0_IRQn,
	EXTI1_IRQn,
	EXTI2_IRQn,
	EXTI3_IRQn,
	EXTI4_IRQn,
	EXTI9_5_IRQn,
	EXTI9_5_IRQn,
	EXTI9_5_IRQn,
	EXTI9_5_IRQn,
	EXTI9_5_IRQn,
	EXTI15_10_IRQn,
	EXTI15_10_IRQn,
	EXTI15_10_IRQn,
	EXTI15_10_IRQn,
	EXTI15_10_IRQn,
	EXTI15_10_IRQn
};

const uint32_t SYSTEM_EXTI_PORT[] ={
	LL_SYSCFG_EXTI_PORTA,
	LL_SYSCFG_EXTI_PORTB,
	LL_SYSCFG_EXTI_PORTC,
	LL_SYSCFG_EXTI_PORTD,
	LL_SYSCFG_EXTI_PORTE,
	LL_SYSCFG_EXTI_PORTF,
	LL_SYSCFG_EXTI_PORTG,
	LL_SYSCFG_EXTI_PORTH,
	LL_SYSCFG_EXTI_PORTI
};

const uint32_t SYSTEM_EXTI_PIN[] = {
	LL_SYSCFG_EXTI_LINE0,
	LL_SYSCFG_EXTI_LINE1,
	LL_SYSCFG_EXTI_LINE2,
	LL_SYSCFG_EXTI_LINE3,
	LL_SYSCFG_EXTI_LINE4,
	LL_SYSCFG_EXTI_LINE5,
	LL_SYSCFG_EXTI_LINE6,
	LL_SYSCFG_EXTI_LINE7,
	LL_SYSCFG_EXTI_LINE8,
	LL_SYSCFG_EXTI_LINE9,
	LL_SYSCFG_EXTI_LINE10,
	LL_SYSCFG_EXTI_LINE11,
	LL_SYSCFG_EXTI_LINE12,
	LL_SYSCFG_EXTI_LINE13,
	LL_SYSCFG_EXTI_LINE14,
	LL_SYSCFG_EXTI_LINE15
};
void EXTI0_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_0) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
		if (NULL == gGpioSlop[0].handler){
			return;
		}
		
		gGpioSlop[0].handler();
	}
}

void EXTI1_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_1) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_1);
		if (NULL == gGpioSlop[1].handler){
			return;
		}
		
		gGpioSlop[1].handler();
	}
}

void EXTI2_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_2) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_2);
		if (NULL == gGpioSlop[2].handler){
			return;
		}
		
		gGpioSlop[2].handler();
	}
}

void EXTI3_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
		if (NULL == gGpioSlop[3].handler){
			return;
		}
		
		gGpioSlop[3].handler();
	}
}

void EXTI4_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_4) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_4);
		if (NULL == gGpioSlop[4].handler){
			return;
		}
		
		gGpioSlop[4].handler();
	}
}

void EXTI9_5_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_5) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_5);
		if (NULL == gGpioSlop[5].handler){
			return;
		}
		
		gGpioSlop[5].handler();
	}
	
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_6) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_6);
		if (NULL == gGpioSlop[6].handler){
			return;
		}
		
		gGpioSlop[6].handler();
	}
	
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_7) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_7);
		if (NULL == gGpioSlop[7].handler){
			return;
		}
		
		gGpioSlop[7].handler();
	}
	
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_8) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_8);
		if (NULL == gGpioSlop[8].handler){
			return;
		}
		
		gGpioSlop[8].handler();
	}
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_9) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_9);
		if (NULL == gGpioSlop[9].handler){
			return;
		}
		
		gGpioSlop[9].handler();
	}
}

void EXTI15_10_IRQHandler(void)
{

	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_10) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_10);
		if (NULL == gGpioSlop[10].handler){
			return;
		}
		
		gGpioSlop[10].handler();
	}
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_11) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_11);
		if (NULL == gGpioSlop[11].handler){
			return;
		}
		
		gGpioSlop[11].handler();
	}
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_12) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_12);
		if (NULL == gGpioSlop[12].handler){
			return;
		}
		
		gGpioSlop[12].handler();
	}
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_13) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_13);
		if (NULL == gGpioSlop[13].handler){
			return;
		}
		
		gGpioSlop[13].handler();
	}
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_14) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_14);
		if (NULL == gGpioSlop[14].handler){
			return;
		}
		
		gGpioSlop[14].handler();
	}
	
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_15) != RESET){
		LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_15);
		if (NULL == gGpioSlop[15].handler){
			return;
		}
		
		gGpioSlop[15].handler();
	}
}


static int32_t gpio_has_priv(gpio_dev_t *gpio)
{
	int32_t ret = 0;
	LL_EXTI_InitTypeDef exti_struct;
	uint16_t group = 0;
	uint16_t pin = 0;

	group = gpio->port / LL_PINS_IN_GROUP;
	pin = gpio->port % LL_PINS_IN_GROUP;
	
	switch (gpio->config) {
	case IRQ_MODE:
//		LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
		LL_SYSCFG_SetEXTISource(SYSTEM_EXTI_PORT[group],SYSTEM_EXTI_PIN[pin]);
		exti_struct.Mode = LL_EXTI_MODE_IT;
		exti_struct.Line_0_31 = SYSCFG_EXTI_LINE[pin];
		exti_struct.LineCommand    = ENABLE;
		switch (gGpioSlop[pin].trigger) {
		case IRQ_TRIGGER_RISING_EDGE:
			exti_struct.Trigger = LL_EXTI_TRIGGER_RISING;
			break;
	
		case IRQ_TRIGGER_FALLING_EDGE:
			exti_struct.Trigger = LL_EXTI_TRIGGER_FALLING;
			break;
	
		case IRQ_TRIGGER_BOTH_EDGES:
			exti_struct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
			break;
		
		default:
			ret = -1;
			break;
		}
		LL_EXTI_Init(&exti_struct);
		

		if (ret == 0) {

			NVIC_SetPriority(irq_type[pin], 15);
			NVIC_EnableIRQ(irq_type[pin]);
		}
		break;

	case OUTPUT_PUSH_PULL:
	case OUTPUT_OPEN_DRAIN_NO_PULL:
	case OUTPUT_OPEN_DRAIN_PULL_UP:
		if(gpio->priv != NULL){
			switch (*(uint8_t *)gpio->priv) {
			case 1:
				gpio_output_high(gpio);
				break;
		
			case 0:
				gpio_output_low(gpio);
				break;
			
			default:
				ret = -1;
				break;
			}
		}
		break;
		
	case ALTERNATE_MODE:
	case ANALOG_MODE:
	case INPUT_PULL_UP:
	case INPUT_PULL_DOWN:
	case INPUT_HIGH_IMPEDANCE:
		ret = 0;
		break;
	
	default:
		break;
	}

	return ret;
}

static int32_t gpio_para_transform(gpio_dev_t *gpio, LL_GPIO_InitTypeDef * init_str)
{
	int32_t ret = 0;
//	uint16_t group = 0;
//	uint32_t pin = 0;

//	group = gpio->port / LL_PINS_IN_GROUP;
//	pin = gpio->port % LL_PINS_IN_GROUP;
	
	switch (gpio->config) {
	case ANALOG_MODE:
		init_str->Mode = LL_GPIO_MODE_ANALOG;
		break;
	
	case IRQ_MODE:
		init_str->Mode = LL_GPIO_MODE_INPUT;
		init_str->Pull = LL_GPIO_PULL_NO;
		break;

	case ALTERNATE_MODE:
		init_str->Mode = LL_GPIO_MODE_ALTERNATE;
		init_str->Alternate = *(uint8_t *)gpio->priv;//gpio_alternate[*(uint8_t *)gpio->priv];
		init_str->OutputType = LL_GPIO_OUTPUT_PUSHPULL;
		init_str->Pull = LL_GPIO_PULL_UP;
		init_str->Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
		break;

	case INPUT_PULL_UP:
		init_str->Mode = LL_GPIO_MODE_INPUT;
		init_str->Pull = LL_GPIO_PULL_UP;
		break;

	case INPUT_PULL_DOWN:
		init_str->Mode = LL_GPIO_MODE_INPUT;
		init_str->Pull = LL_GPIO_PULL_DOWN;
		break;

	case INPUT_HIGH_IMPEDANCE:
		init_str->Mode = LL_GPIO_MODE_ANALOG;
		init_str->Pull = LL_GPIO_PULL_NO;
		break;

	case OUTPUT_PUSH_PULL:
		init_str->Mode = LL_GPIO_MODE_OUTPUT;
		init_str->Pull = LL_GPIO_PULL_NO;
		init_str->OutputType = LL_GPIO_OUTPUT_PUSHPULL;
		init_str->Speed = LL_GPIO_SPEED_FREQ_LOW;
		break;

	case OUTPUT_OPEN_DRAIN_NO_PULL:
		init_str->Mode = LL_GPIO_MODE_OUTPUT;
		init_str->Pull = LL_GPIO_PULL_NO;
		init_str->OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
		init_str->Speed = LL_GPIO_SPEED_FREQ_LOW;
		break;

	case OUTPUT_OPEN_DRAIN_PULL_UP:
		init_str->Mode = LL_GPIO_MODE_OUTPUT;
		init_str->Pull = LL_GPIO_PULL_UP;
		init_str->OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
		init_str->Speed = LL_GPIO_SPEED_FREQ_LOW;
		break;

	default:
		ret = -1;
		break;
	}

	return ret;
}

static uint32_t get_gpio_pin(uint8_t pin)
{
	uint32_t result = 1;
	uint8_t pin_t = pin % LL_PINS_IN_GROUP;

	result = 1u << pin_t;

	return result;
}

int32_t gpio_init(gpio_dev_t *gpio)
{
	int32_t ret = -1;
	LL_GPIO_InitTypeDef  GPIO_InitStruct;
	uint8_t test_port;

	if (gpio == NULL) {
		return ret;
	}
	
	test_port = gpio->port/LL_PINS_IN_GROUP;

	LL_AHB1_GRP1_EnableClock(gpio_clock[test_port]);

	ret = gpio_para_transform(gpio, &GPIO_InitStruct);
	if (ret) {
		return ret;
	}

	GPIO_InitStruct.Pin = get_gpio_pin(gpio->port);
	LL_GPIO_Init(gpio_port[test_port], &GPIO_InitStruct);

	ret |= gpio_has_priv(gpio);

	return ret;
}

int32_t gpio_output_high(gpio_dev_t *gpio)
{
	uint16_t pin = 0;
	int32_t ret = 0;

	if (gpio == NULL) {
		return -1;
	}
	
	pin = get_gpio_pin(gpio->port);
	LL_GPIO_SetOutputPin(gpio_port[gpio->port/LL_PINS_IN_GROUP], pin);

	return ret;
}

int32_t gpio_output_low(gpio_dev_t *gpio)
{
	uint32_t pin = 0;
	int32_t ret = 0;

	if (gpio == NULL) {
		return -1;
	}
	
	pin = get_gpio_pin(gpio->port);
	LL_GPIO_ResetOutputPin(gpio_port[gpio->port/LL_PINS_IN_GROUP], pin);

	return ret;
}

int32_t gpio_input_get(gpio_dev_t *gpio)
{
	uint32_t pin = 0;

	if (gpio == NULL) {
		return -1;
	}
	pin = get_gpio_pin(gpio->port);
	return (LL_GPIO_ReadInputPort(gpio_port[gpio->port/LL_PINS_IN_GROUP])&pin)>>(gpio->port% LL_PINS_IN_GROUP);
}

int32_t gpio_enable_irq(gpio_dev_t *gpio, gpio_irq_trigger_t trigger,gpio_irq_handler_t handler)
{

	int32_t ret = -1;
	gpio_irq_slop_t * slop = &gGpioSlop[gpio->port% LL_PINS_IN_GROUP];

	if(NULL == slop) {
		return ret;
	}

	slop->trigger = trigger;

	slop->handler = handler;
	ret = 0;
	return ret;
}

int32_t gpio_disable_irq(gpio_dev_t *gpio)
{

	int32_t ret = -1;
	gpio_irq_slop_t * slop = &gGpioSlop[gpio->port% LL_PINS_IN_GROUP];
	if(NULL == slop) {
		return ret;
	}

	NVIC_DisableIRQ(irq_type[gpio->port% LL_PINS_IN_GROUP]);
	ret = 0;
	
	return ret;
}

int32_t gpio_clear_irq(gpio_dev_t *gpio)
{

	gpio_irq_slop_t * slop = &gGpioSlop[gpio->port% LL_PINS_IN_GROUP];
	if(NULL == slop){
		return(-1);
	}
	slop->handler = NULL;
	return 0;
}

int32_t gpio_finalize(gpio_dev_t *gpio)
{
	int32_t ret = -1;
	LL_GPIO_InitTypeDef  GPIO_InitStruct;
	
	if (gpio == NULL) {
		return ret;
	}

	LL_AHB1_GRP1_EnableClock(gpio_clock[gpio->port/LL_PINS_IN_GROUP]);
	
	GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pin = get_gpio_pin(gpio->port);
	LL_GPIO_Init(gpio_port[gpio->port/LL_PINS_IN_GROUP], &GPIO_InitStruct);
	
//	LL_IOP_GRP1_DisableClock(gpio_clock[gpio->port/LL_PINS_IN_GROUP]);
//	RCC_AHB1PeriphClockCmd(gpio_clock[gpio->port/LL_PINS_IN_GROUP],DISABLE);
	
	ret = 0;
	return ret;
}

int32_t gpio_disable_port_clk(gpio_dev_t *gpio)
{
	int32_t ret = -1;
	
	if (gpio == NULL) {
		return ret;
	}
	LL_AHB1_GRP1_DisableClock(gpio_clock[gpio->port/LL_PINS_IN_GROUP]);
	
	ret = 0;
	return ret;
}
