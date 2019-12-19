/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.

*      Filename:	gpio.h
*        Author:	caozhaofei
*         Email:	caozhaofei@live.cn
*        Create:	2016-11-28 14:11:03
*
* Last modified:	2016-11-28 14:11:03
*
*
*  Description:	
*
*********************************************************************/

#ifndef _GPIO_H__
#define _GPIO_H__

#include <stdint.h>



/*************************GPIO start*******************************/
/*
 * Pin configuration
 */
typedef enum {
	ANALOG_MODE,               /* Used as a function pin, input and output analog */
	IRQ_MODE,                  /* Used to trigger interrupt */
	ALTERNATE_MODE,			/*!< Select alternate function mode */
	INPUT_PULL_UP,             /* Input with an internal pull-up resistor - use with devices
				  that actively drive the signal low - e.g. button connected to ground */
	INPUT_PULL_DOWN,           /* Input with an internal pull-down resistor - use with devices
				  that actively drive the signal high - e.g. button connected to a power rail */
	INPUT_HIGH_IMPEDANCE,      /* Input - must always be driven, either actively or by an external pullup resistor */
	OUTPUT_PUSH_PULL,          /* Output actively driven high and actively driven low -
				  must not be connected to other active outputs - e.g. LED output */
	OUTPUT_OPEN_DRAIN_NO_PULL, /* Output actively driven low but is high-impedance when set high -
				  can be connected to other open-drain/open-collector outputs.
				  Needs an external pull-up resistor */
	OUTPUT_OPEN_DRAIN_PULL_UP, /* Output actively driven low and is pulled high
				  with an internal resistor when set high -
				  can be connected to other open-drain/open-collector outputs. */
				  
} gpio_config_t;

/*
 * GPIO dev struct
 */
typedef struct {
	uint8_t       port;    /* gpio port */
	gpio_config_t config;  /* gpio config */
	void         *priv;    /* priv data */
} gpio_dev_t;

/*
 * GPIO interrupt trigger
 */
typedef enum {
	IRQ_TRIGGER_RISING_EDGE  = 0x1, /* Interrupt triggered at input signal's rising edge  */
	IRQ_TRIGGER_FALLING_EDGE = 0x2, /* Interrupt triggered at input signal's falling edge */
	IRQ_TRIGGER_BOTH_EDGES   = IRQ_TRIGGER_RISING_EDGE | IRQ_TRIGGER_FALLING_EDGE,
} gpio_irq_trigger_t;


typedef enum {
	APP_AF_0 = 0x00,
	APP_AF_1,
	APP_AF_2,
	APP_AF_3,
	APP_AF_4,
	APP_AF_5,
	APP_AF_6,
	APP_AF_7,
	APP_AF_8,
	APP_AF_9,
	APP_AF_10,
	APP_AF_11,
	APP_AF_12,
	APP_AF_13,
	APP_AF_14,
	APP_AF_15
}APP_GPIO_ALTERNATE;
/*
 * GPIO interrupt callback handler
 */
typedef void (*gpio_irq_handler_t)(void);

typedef struct {
	int32_t (*init)(gpio_dev_t *gpio);
	int32_t (*output_high)(gpio_dev_t *gpio);
	int32_t (*output_low)(gpio_dev_t *gpio);
	int32_t (*input)(gpio_dev_t *gpio);
	int32_t (*enable_irq)(gpio_dev_t *gpio,gpio_irq_trigger_t trigger, gpio_irq_handler_t handler);
	int32_t (*disable_irq)(gpio_dev_t *gpio);
	int32_t (*clear_irq)(gpio_dev_t *gpio);
	int32_t (*deinit)(gpio_dev_t *gpio);	
	int32_t (*port_disable)(gpio_dev_t *gpio);
}GPIO_FUNC;

/*************************GPIO end*******************************/



/**
 * Initialises a GPIO pin
 *
 * @note  Prepares a GPIO pin for use.
 *
 * @param[in]  gpio           the gpio pin which should be initialised
 * @param[in]  configuration  A structure containing the required gpio configuration
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_init(gpio_dev_t *gpio);

/**
 * Sets an output GPIO pin high
 *
 * @note  Using this function on a gpio pin which is set to input mode is undefined.
 *
 * @param[in]  gpio  the gpio pin which should be set high
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_output_high(gpio_dev_t *gpio);

/**
 * Sets an output GPIO pin low
 *
 * @note  Using this function on a gpio pin which is set to input mode is undefined.
 *
 * @param[in]  gpio  the gpio pin which should be set low
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_output_low(gpio_dev_t *gpio);



/**
 * Get the state of an input GPIO pin. Using this function on a
 * gpio pin which is set to output mode will return an undefined value.
 *
 * @param[in]  gpio   the gpio pin which should be read
 * @param[in]  value  gpio value
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_input_get(gpio_dev_t *gpio);

/**
 * Enables an interrupt trigger for an input GPIO pin.
 * Using this function on a gpio pin which is set to
 * output mode is undefined.
 *
 * @param[in]  gpio     the gpio pin which will provide the interrupt trigger
 * @param[in]  trigger  the type of trigger (rising/falling edge)
 * @param[in]  handler  a function pointer to the interrupt handler
 * @param[in]  arg      an argument that will be passed to the interrupt handler
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_enable_irq(gpio_dev_t *gpio, gpio_irq_trigger_t trigger,
                            gpio_irq_handler_t handler);

/**
 * Disables an interrupt trigger for an input GPIO pin.
 * Using this function on a gpio pin which has not been set up
 * using @ref hal_gpio_input_irq_enable is undefined.
 *
 * @param[in]  gpio  the gpio pin which provided the interrupt trigger
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_disable_irq(gpio_dev_t *gpio);

/**
 * Disables an interrupt trigger for an input GPIO pin.
 * Using this function on a gpio pin which has not been set up
 * using @ref hal_gpio_input_irq_enable is undefined.
 *
 * @param[in]  gpio  the gpio pin which provided the interrupt trigger
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_clear_irq(gpio_dev_t *gpio);

/**
 * Set a GPIO pin in default state.
 *
 * @param[in]  gpio  the gpio pin which should be deinitialised
 *
 * @return  0 : on success, EIO : if an error occurred with any step
 */
int32_t gpio_finalize(gpio_dev_t *gpio);
int32_t gpio_disable_port_clk(gpio_dev_t *gpio);

#endif //GPIO_H__

