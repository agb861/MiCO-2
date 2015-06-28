/**
******************************************************************************
* @file    platform.h
* @author  William Xu
* @version V1.0.0
* @date    05-May-2014
* @brief   This file provides all MICO Peripherals defined for current platform.
******************************************************************************
*
*  The MIT License
*  Copyright (c) 2014 MXCHIP Inc.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy 
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights 
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is furnished
*  to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
*  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************
*/ 

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/


   
/******************************************************
 *                   Enumerations
 ******************************************************/

typedef enum
{
  MICO_SYS_LED,
  BOOT_SEL,
  MFG_SEL,
  EasyLink_BUTTON,
  STDIO_UART_RX,
  STDIO_UART_TX,
  USB_DETECT,  
  APP_UART_RX,
  APP_UART_TX,
  MICO_GPIO_MAX, /* Denotes the total number of GPIO port aliases. Not a valid GPIO alias */
  MICO_GPIO_NONE,
} mico_gpio_t;

typedef enum
{
    MICO_SPI_MAX, /* Denotes the total number of SPI port aliases. Not a valid SPI alias */
    MICO_SPI_NONE,
} mico_spi_t;

typedef enum
{
    MICO_I2C_1,
    MICO_I2C_MAX, /* Denotes the total number of I2C port aliases. Not a valid I2C alias */
    MICO_I2C_NONE,
} mico_i2c_t;

typedef enum
{
    MICO_PWM_MAX, /* Denotes the total number of PWM port aliases. Not a valid PWM alias */
    MICO_PWM_NONE,
} mico_pwm_t;

typedef enum
{
    MICO_ADC_MAX, /* Denotes the total number of ADC port aliases. Not a valid ADC alias */
    MICO_ADC_NONE,
} mico_adc_t;

typedef enum
{
    MICO_UART_1,
    MICO_UART_2,
    MICO_UART_MAX, /* Denotes the total number of UART port aliases. Not a valid UART alias */
    MICO_UART_NONE,
} mico_uart_t;

typedef enum
{
  MICO_FLASH_SPI,
  MICO_FLASH_MAX,
  MICO_FLASH_NONE,
} mico_flash_t;

typedef enum
{
  MICO_PARTITION_1,
  MICO_PARTITION_2,
  MICO_PARTITION_3,
  MICO_PARTITION_4,
  MICO_PARTITION_5,
  MICO_PARTITION_6,
  MICO_PARTITION_MAX,
  MICO_PARTITION_NONE,
} mico_partition_t;

#define MICO_PARTITION_BOOTLOADER   MICO_PARTITION_1
#define MICO_PARTITION_APPLICATION  MICO_PARTITION_2
#define MICO_PARTITION_ATE          MICO_PARTITION_3
#define MICO_PARTITION_OTA_TEMP     MICO_PARTITION_4
#define MICO_PARTITION_RF_DRIVER    MICO_PARTITION_NONE
#define MICO_PARTITION_PARAMETER_1  MICO_PARTITION_5
#define MICO_PARTITION_PARAMETER_2  MICO_PARTITION_6

#ifdef BOOTLOADER
#define STDIO_UART       MICO_UART_2
#define STDIO_UART_BAUDRATE (115200) 
#else
#define STDIO_UART       MICO_UART_1
#define STDIO_UART_BAUDRATE (115200) 
#endif

#define UART_FOR_APP     MICO_UART_2
#define MFG_TEST         MICO_UART_2
#define CLI_UART         MICO_UART_1

#define USE_MICO_SPI_FLASH
//#define SFLASH_SUPPORT_MACRONIX_PARTS 
//#define SFLASH_SUPPORT_SST_PARTS
//#define SFLASH_SUPPORT_WINBOND_PARTS
#define SFLASH_SUPPORT_GD_PARTS

/* Components connected to external I/Os*/
/* I/O connection <-> Peripheral Connections */
#define MICO_I2C_CP         (MICO_I2C_NONE)

#define MICO_RF_LED         (MICO_GPIO_NONE)

#define FUNC_USB_EN					   
//#define FUNC_CARD_EN					

#ifdef FUNC_USB_EN
  #define UDISK_PORT_NUM		        2		// USB端口定义
#endif

#ifdef FUNC_CARD_EN
  #define	SD_PORT_NUM                 1		// SD卡端口定义
#endif

#ifdef __cplusplus
} /*extern "C" */
#endif

