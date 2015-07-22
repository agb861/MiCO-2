/**
******************************************************************************
* @file    MICOEntrance.c 
* @author  William Xu
* @version V1.0.0
* @date    05-May-2014
* @brief   MICO system main entrance.
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

#include "time.h"
#include "MicoPlatform.h"
#include "platform.h"
#include "MICOAppDefine.h"
#include "mico_system.h"

#include "MICONotificationCenter.h"
#include "MICOSystemMonitor.h"
#include "MicoCli.h"
#include "StringUtils.h"
#include "mico_system/mico_system_internal.h"

/* ========================================
User provide callback functions 
======================================== */

int application_start(void)
{
  OSStatus err = kNoErr;
  mico_Context_t* context;

  /* Read mico context that holds all system configurations and runtime status */
  err = mico_system_context_init( &context );
  require_noerr( err, exit ); 

  /* Initialize power management daemen */
  err = mico_system_power_daemon_start( context );
  require_noerr( err, exit ); 

  /* Initialize mico system */
  err = mico_system_notification_init( context );
  require_noerr( err, exit ); 

#ifdef MICO_SYSTEM_MONITOR_ENABLE
  /* MiCO system monitor */
  err = mico_system_monitor_daemen_start( context );
  require_noerr( err, exit ); 
#endif

#ifdef MICO_CLI_ENABLE
  /* MiCO command line interface */
  MicoCliInit();
#endif

  /* wlan driver and tcpip init */
  err = mico_system_network_daemen_start( context );
  require_noerr( err, exit ); 

  if( context->flashContentInRam.micoSystemConfig.configured == wLanUnConfigured ||
      context->flashContentInRam.micoSystemConfig.configured == unConfigured){
    system_log("Empty configuration. Starting configuration mode...");

#if (MICO_CONFIG_MODE == CONFIG_MODE_EASYLINK) || \
    (MICO_CONFIG_MODE == CONFIG_MODE_SOFT_AP) ||  \
    (MICO_CONFIG_MODE == CONFIG_MODE_EASYLINK_WITH_SOFTAP) || \
    (MICO_CONFIG_MODE == CONFIG_MODE_AIRKISS)
    err = mico_easylink_start( context );
    require_noerr( err, exit );
#elif (MICO_CONFIG_MODE == CONFIG_MODE_WPS) || MICO_CONFIG_MODE == defined (CONFIG_MODE_WPS_WITH_SOFTAP)
    err = mico_easylink_wps_tart( context );
    require_noerr( err, exit );
#elif ( MICO_CONFIG_MODE == CONFIG_MODE_WAC)
    err = mico_easylink_start( context );
    require_noerr( err, exit );
#else
    #error "Wi-Fi configuration mode is not defined"
#endif
  }
  else{
    system_log("Available configuration. Starting Wi-Fi connection...");
    mico_system_connect_wifi_fast( context );
  }

#ifdef MFG_MODE_AUTO
  if( context->flashContentInRam.micoSystemConfig.configured == mfgConfigured ){
    system_log( "Enter MFG mode automatically" );
    mico_mfg_test(context);
    mico_thread_sleep(MICO_NEVER_TIMEOUT);
  }
#endif
 
  /*Local configuration server*/
#ifdef MICO_CONFIG_SERVER_ENABLE
  MICOStartConfigServer(context);
#endif

#ifdef MICO_NTP_CLIENT_ENABLE
  struct tm currentTime;
  mico_system_current_time_get( &currentTime );
  system_log("Current Time: %s",asctime(&currentTime));
  err =  MICOStartNTPClient(context);
  require_noerr_string( err, exit, "ERROR: Unable to start the NTP client thread." );
#endif

  /*Start mico application*/
  err = MICOStartApplication( context );
  require_noerr( err, exit );
    
  require_noerr_action( err, exit, system_log("Closing main thread with err num: %d.", err) );
exit:
  mico_rtos_delete_thread(NULL);
  return kNoErr;
}

