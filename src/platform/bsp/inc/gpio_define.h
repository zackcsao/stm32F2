/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	gpio_define.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	gpio_define.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-03-14 14:50:47
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __GPIO_DEFINE_H__
#define __GPIO_DEFINE_H__
// <<< Use Configuration Wizard in Context Menu >>>
// <e1> 串口配置


// <h> UART1_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART1_TX		22
#define GPIO_UART1_TX_AF	7

// <h> UART1_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART1_RX		23
#define GPIO_UART1_RX_AF	7

// <h> UART2_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART2_TX		53
#define GPIO_UART2_TX_AF	7

// <h> UART2_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART2_RX		54
#define GPIO_UART2_RX_AF	7

// <h> UART3_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART3_TX		56
#define GPIO_UART3_TX_AF	7

// <h> UART3_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART3_RX		57
#define GPIO_UART3_RX_AF	7


// <h> UART4_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART4_TX		42
#define GPIO_UART4_TX_AF	8

// <h> UART4_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART4_RX		43
#define GPIO_UART4_RX_AF	8


// <h> UART5_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART5_TX		44
#define GPIO_UART5_TX_AF	8

// <h> UART5_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART5_RX		50
#define GPIO_UART5_RX_AF	8


// <h> UART6_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART6_TX		38
#define GPIO_UART6_TX_AF	8

// <h> UART6_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART6_RX		39
#define GPIO_UART6_RX_AF	8


// <h> UART7_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART7_TX		72
#define GPIO_UART7_TX_AF	8

// <h> UART7_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART7_RX		71
#define GPIO_UART7_RX_AF	8

// <h> UART8_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART8_RX		64
#define GPIO_UART8_RX_AF	8

// <h> UART8_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART8_TX		65
#define GPIO_UART8_TX_AF	8
// </e>

// <e2> SPI配置
// <h> SPI1_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI1_MOSI		21
#define GPIO_SPI1_MOSI_AF	5

// <h> SPI1_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI1_MISO		6
#define GPIO_SPI1_MISO_AF	5

// <h> SPI1_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI1_SCK		5
#define GPIO_SPI1_SCK_AF	5

// <h> SPI2_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI2_MOSI		105
#define GPIO_SPI2_MOSI_AF	8

// <h> SPI2_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI2_MISO		87
#define GPIO_SPI2_MISO_AF	8

// <h> SPI2_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI2_SCK		86
#define GPIO_SPI2_SCK_AF	8

// <h> SPI3_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI3_MOSI		105
#define GPIO_SPI3_MOSI_AF	8

// <h> SPI3_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI3_MISO		87
#define GPIO_SPI3_MISO_AF	8

// <h> SPI3_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI3_SCK		86
#define GPIO_SPI3_SCK_AF	8

// <h> SPI4_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI4_MOSI		70
#define GPIO_SPI4_MOSI_AF	5

// <h> SPI4_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI4_MISO		69
#define GPIO_SPI4_MISO_AF	5

// <h> SPI4_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI4_SCK		66
#define GPIO_SPI4_SCK_AF	5

// <h> SPI5_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI5_MOSI		89
#define GPIO_SPI5_MOSI_AF	5


// <h> SPI5_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI5_MISO		88
#define GPIO_SPI5_MISO_AF	5

// <h> SPI5_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI5_SCK		118
#define GPIO_SPI5_SCK_AF	5
// </e>

// <e1> gpio配置

// <h> SYS_RUN
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_SYS_RUN		63

// <h> SYS_FAULT
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_SYS_FAULT		62

// <h> KEY_OUT1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_OUT1		105


// <h> KEY_OUT2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_OUT2		106


// <h> KEY_OUT3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_OUT3		107


// <h> KEY_OUT4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_OUT4		108


// <h> KEY_OUT5
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_OUT5		109


// <h> KEY_IN1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_IN1		101

// <h> KEY_IN2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_IN2		102

// <h> KEY_IN3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_IN3		103

// <h> KEY_IN4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_KEY_IN4		104

// <h> 运行灯
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RUN_LED		19


// <h> PWR_LCD
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_PWR_LCD		48

// <h> 第一路485收发使能
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_485_1		24
// <h> 第二路485收发使能
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_485_2		51


// <h> EEPROM_CS
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_EEPROM_CS		4

// <h> BUZZ
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_BUZZ		110

// <h> SD_DETECT
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_SD_DETECT		32

// <h> PWR_USB
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_PWR_USB		15

// <h> 电源检测
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_PWR_DECTECT		30

// <h> RVS1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RVS1		84

// <h> FWD1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FWD1		83

// <h> RVS2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RVS2		86

// <h> FWD2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FWD2		85


// <h> RVS3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RVS3		88

// <h> FWD3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FWD3		87

// <h> RVS4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RVS4		90

// <h> FWD4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FWD4		89

// <h> RVS5
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RVS5		92

// <h> FWD5
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FWD5		91

// <h> K1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_K1		64

// <h> K2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_K2		65

// <h> K3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_K3		66

// <h> K4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_K4		67

// <h> K5
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_K5		68

// <h> K6
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_K6		69

// <h> K7
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_K7		70

// <h> DI1_1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI1_1		45

// <h> DI1_2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI1_2		46

// <h> DI1_3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI1_3		47

// <h> DI2_1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI2_1		71

// <h> DI2_2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI2_2		72

// <h> DI2_3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI2_3		73


// <h> DI3_1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI3_1		74

// <h> DI3_2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI3_2		75

// <h> DI3_3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI3_3		76


// <h> DI4_1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI4_1		77

// <h> DI4_2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI4_2		78

// <h> DI4_3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI4_3		79

// <h> DI5_1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI5_1		58

// <h> DI5_2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI5_2		59

// <h> DI5_3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI5_3		60

// </e>



// <e1> I2C 配置
// <h> I2C1_SCL
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_I2C1_SCL		81
// <h> I2C1_SDA
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_I2C1_SDA		80
// </e>

// <h> RTC_INT
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RTC_INT		82



// <e2> ETH配置
// <h> ETH_RMII_RXD0
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_RXD0		36
#define GPIO_ETH_RMII_RXD0_AF		11

// <h> ETH_RMII_RXD1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_RXD1		37
#define GPIO_ETH_RMII_RXD1_AF		11

// <h> ETH_RMII_TXD0
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_TXD0		28
#define GPIO_ETH_RMII_TXD0_AF		11

// <h> ETH_RMII_TXD1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_TXD1		29
#define GPIO_ETH_RMII_TXD1_AF		11

// <h> ETH_RMII_TX_EN
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_TX_EN		27
#define GPIO_ETH_RMII_TX_EN_AF		11


// <h> ETH_RMII_CRS_DV
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_CRS_DV		7
#define GPIO_ETH_RMII_CRS_DV_AF		11


// <h> ETH_RMII_REF_CLK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_REF_CLK		1
#define GPIO_ETH_RMII_REF_CLK_AF		11


// <h> ETH_MDC
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_MDC		33
#define GPIO_ETH_MDC_AF		11

// <h> ETH_MDIO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_MDIO		2
#define GPIO_ETH_MDIO_AF		11

// <h> ETH_nRST
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_NRST		26
#define GPIO_ETH_NRST_AF		8
// </e>


// <e2> SDIO配置

// <h> SDIO_CMD
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SDIO_CMD		50
#define GPIO_SDIO_CMD_AF	12

// <h> SDIO_CK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SDIO_CK		44
#define GPIO_SDIO_CK_AF		12

// <h> SDIO_D0
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SDIO_D0		40
#define GPIO_SDIO_D0_AF	12

// <h> SDIO_D1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SDIO_D1		41
#define GPIO_SDIO_D1_AF	12

// <h> SDIO_D2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SDIO_D2		42
#define GPIO_SDIO_D2_AF	12

// <h> SDIO_D3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SDIO_D3		43
#define GPIO_SDIO_D3_AF	12
// </e>


// <e2> USB配置

// <h> USB_DM
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_USB_DM		11
#define GPIO_USB_DM_AF	10

// <h> USB_DP
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_USB_DP		12
#define GPIO_USB_DP_AF		10

// <h> USB_ID
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_USB_ID		10
#define GPIO_USB_ID_AF		10
// </e>

// <<< end of configuration section >>>
#endif //__GPIO_DEFINE_H__

