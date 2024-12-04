/********************************************************************************************************
 * @file     app_config.h
 *
 * @brief    application configuration
 *
 * @author
 * @date     Dec. 1, 2016
 *
 * @par      Copyright (c) 2016, Telink Semiconductor (Shanghai) Co., Ltd.
 *           All rights reserved.
 *
 *			 The information contained herein is confidential and proprietary property of Telink
 * 		     Semiconductor (Shanghai) Co., Ltd. and is available under the terms
 *			 of Commercial License Agreement between Telink Semiconductor (Shanghai)
 *			 Co., Ltd. and the licensee in separate contract or the terms described here-in.
 *           This heading MUST NOT be removed from this file.
 *
 * 			 Licensees are granted free, non-transferable use of the information in this
 *			 file under Mutual Non-Disclosure Agreement. NO WARRENTY of ANY KIND is provided.
 *
 *******************************************************************************************************/

#pragma once

/* Enable C linkage for C++ Compilers: */
#if defined(__cplusplus)
extern "C" {
#endif

#define _USER_CONFIG_DEFINED_	1	// must define this macro to make others known
#define	__LOG_RT_ENABLE__		0

//////////// product  Information  //////////////////////////////
#define TOUCHLINK_SUPPORT		1
#define FIND_AND_BIND_SUPPORT	0

/* debug mode config */
#define	UART_PRINTF_MODE		0
#define USB_PRINTF_MODE         0

#define PM_ENABLE				1
#define BLE_APP_PM_ENABLE		1
#define PA_ENABLE				0

/* board ID */
#define BOARD_8258_EVK			1
#define BOARD_8258_EVK_V1P2		2
#define BOARD_8258_DONGLE		3
#define BOARD_8258_DONGLE_1M	4

/* board define */
#define BOARD					BOARD_8258_DONGLE_1M  //BOARD_8258_EVK
/* system clock config */
#define CLOCK_SYS_CLOCK_HZ  	48000000


#if(BOARD == BOARD_8258_DONGLE || BOARD == BOARD_8258_DONGLE_1M)
	#include "board_8258_dongle.h"
#elif(BOARD == BOARD_8258_EVK)
	#include "board_8258_evk.h"
#elif(BOARD == BOARD_8258_EVK_V1P2)
	#include "board_8258_evk_v1p2.h"
#else
	#include "board_8258_dongle.h"
#endif


#define MODULE_BUFM_ENABLE        1
#define MODULE_PRIQ_ENABLE        1
#define EV_POST_TASK_ENABLE       1

/* interrupt */
#define IRQ_TIMER1_ENABLE         1
#define	IRQ_GPIO_ENABLE			  0

/* module selection */
#define MODULE_WATCHDOG_ENABLE	0
#define	MODULE_UART_ENABLE		0

/* Rf mode: 250K */
#define	RF_MODE_250K				1

//BLE��Configuration
#define	BLE_REMOTE_SECURITY_ENABLE	1
#define USED_DEEP_ANA_REG                   DEEP_ANA_REG0 //u8,can save 8 bit info when deep
#define	LOW_BATT_FLG					    BIT(0)
#define CONN_DEEP_FLG	                    BIT(1) //if 1: conn deep, 0: adv deep
#define IR_MODE_DEEP_FLG	 				BIT(2) //if 1: IR mode, 0: BLE mode
#define LOW_BATT_SUSPEND_FLG	 			BIT(3)

/**
 *  @brief ZCL cluster support setting
 */
#define ZCL_ON_OFF_SUPPORT							1
#define ZCL_LEVEL_CTRL_SUPPORT						1
#define ZCL_LIGHT_COLOR_CONTROL_SUPPORT				1
#define ZCL_GROUP_SUPPORT							1
#define ZCL_OTA_SUPPORT								0
#if TOUCHLINK_SUPPORT
#define ZCL_ZLL_COMMISSIONING_SUPPORT				1
#endif

/**
 *  @brief  Security
 */
#define ZB_SECURITY_ENABLE                          1

///////////////////  Zigbee Profile Configuration /////////////////////////////////
#include "stack_cfg.h"

typedef enum{
	EV_EVENT_MAX = 1,
} ev_event_e;

enum{
	EV_FIRED_EVENT_MAX = 1
};


typedef enum{
	EV_POLL_ED_DETECT,
	EV_POLL_PM,
	EV_POLL_HCI,
    EV_POLL_IDLE,
	EV_POLL_MAX,
}ev_poll_e;

    /* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
}
#endif
