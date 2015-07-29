/**
  ******************************************************************************
  * @file    user_config.h 
  * @author  Eshen Wang
  * @version V1.0.0
  * @date    14-May2015
  * @brief   User configuration file.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MXCHIP Inc. SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2014 MXCHIP Inc.</center></h2>
  ******************************************************************************
  */ 

#ifndef __USER_CONFIG_H_
#define __USER_CONFIG_H_

#include "mico_config.h"

/*******************************************************************************
 *                             APP INFO
 ******************************************************************************/

/*------------------------------ product -------------------------------------*/
#ifdef MICOKIT_3288
// wes' product
  #define PRODUCT_ID                   "df7a9706"
  #define PRODUCT_KEY                  "9c748c29-e60c-4227-8d5e-243aa78fae58"
#elif  MICOKIT_3165
  #define PRODUCT_ID                   "5b8820c0"
  #define PRODUCT_KEY                  "333865e4-6859-48d4-acc0-29fb5de0fc02"
#else

#endif

#define DEFAULT_ROM_VERSION            FIRMWARE_REVISION
#define DEFAULT_DEVICE_NAME            MODEL   // device name upload to cloud defined in platform_config.h


/*******************************************************************************
 *                             FOGCLOUD
 ******************************************************************************/

/* MICO cloud service */
#define MICO_CLOUD_TYPE               CLOUD_FOGCLOUD

/* Firmware update check
 * If need to check new firmware on server after wifi on, comment out this macro
 */
#define DISABLE_FOGCLOUD_OTA_CHECK


/*******************************************************************************
 *                             USER RESOURCES
 ******************************************************************************/

/* stack size of the user_main thread */
#define STACK_SIZE_USER_MAIN_THREAD    0x800

/* User provided configurations seed
 * If user configuration(params in flash) is changed, update this number to
 * indicate the bootloader to clean params in flash next time restart.
 */
#define CONFIGURATION_VERSION          0x00000001


#endif  // __USER_CONFIG_H_

