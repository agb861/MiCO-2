/**
  ******************************************************************************
  * @file    MicoDriverAdc.h 
  * @author  William Xu
  * @version V1.0.0
  * @date    05-May-2014
  * @brief   This file provides all the headers of ADC operation functions.
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

#ifndef __MICODRIVERADC_H__
#define __MICODRIVERADC_H__

#pragma once
#include "Common.h"
#include "platform.h"

/** @addtogroup MICO_PLATFORM
* @{
*/


/******************************************************
 *                   Macros
 ******************************************************/  


/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

 /******************************************************
 *                    Structures
 ******************************************************/


/******************************************************
 *                     Variables
 ******************************************************/

/******************************************************
 * @endcond           Function Declarations
 ******************************************************/

/** @defgroup MICO_ADC MICO ADC Driver
* @brief  Analog to Digital Converter (ADC) Functions
* @{
*/

/** Initialises an ADC interface
 *
 * Prepares an ADC hardware interface for sampling
 *
 * @param adc            : the interface which should be initialised
 * @param sampling_cycle : sampling period in number of ADC clock cycles. If the
 *                         MCU does not support the value provided, the closest
 *                         supported value is used.
 *
 * @return    kNoErr        : on success.
 * @return    kGeneralErr   : if an error occurred with any step
 */
OSStatus MicoAdcInitialize( mico_adc_t adc, uint32_t sampling_cycle );



/** Takes a single sample from an ADC interface
 *
 * Takes a single sample from an ADC interface
 *
 * @param adc    : the interface which should be sampled
 * @param output : pointer to a variable which will receive the sample
 *
 * @return    kNoErr        : on success.
 * @return    kGeneralErr   : if an error occurred with any step
 */
OSStatus MicoAdcTakeSample( mico_adc_t adc, uint16_t* output );


/** Takes multiple samples from an ADC interface
 *
 * Takes multiple samples from an ADC interface and stores them in
 * a memory buffer
 *
 * @param adc           : the interface which should be sampled
 * @param buffer        : a memory buffer which will receive the samples
 *                        Each sample will be uint16_t little endian.
 * @param buffer_length : length in bytes of the memory buffer.
 *
 *
 * @return    kNoErr        : on success.
 * @return    kGeneralErr   : if an error occurred with any step
 */
OSStatus MicoAdcTakeSampleStreram( mico_adc_t adc, void* buffer, uint16_t buffer_length );


/** De-initialises an ADC interface
 *
 * Turns off an ADC hardware interface
 *
 * @param  adc : the interface which should be de-initialised
 *
 * @return    kNoErr        : on success.
 * @return    kGeneralErr   : if an error occurred with any step
 */
OSStatus  MicoAdcFinalize( mico_adc_t adc );

/** @} */
/** @} */
#endif