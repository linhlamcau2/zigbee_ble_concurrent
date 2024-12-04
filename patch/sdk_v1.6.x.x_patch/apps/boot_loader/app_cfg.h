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
#define TOUCHLINK_SUPPORT		0
#define FIND_AND_BIND_SUPPORT	0

#define COLOR_RGB_SUPPORT		0
#define COLOR_CCT_SUPPORT		1


/* debug mode config */
#define	UART_PRINTF_MODE		1
#define USB_PRINTF_MODE         0


#define FLASH_SIZE_1M			1
/* Running chip flash size select. If '1' - 1M, otherwise (or undefined) - 512K. */
#if (DUAL_MODE_SW_BOOT || DUAL_MODE_HW_BOOT)
#define FLASH_SIZE_1M			1
#define DUAL_MODE				1
#endif

/* board ID */
#define BOARD_826x_EVK			0
#define BOARD_826x_DONGLE		1
#define BOARD_8258_EVK			2
#define BOARD_8258_EVK_V1P2		3
#define BOARD_8258_DONGLE		4


/* board define */
#ifdef MCU_CORE_8258
	#define BOARD					BOARD_8258_DONGLE//BOARD_8258_EVK
	/* system clock config */
	#define CLOCK_SYS_CLOCK_HZ  	32000000
#else
	#define BOARD					BOARD_826x_DONGLE
	/* system clock config */
	#define CLOCK_SYS_CLOCK_HZ  	32000000
#endif


#if	(BOARD == BOARD_826x_DONGLE)
	#include "board_826x_dongle.h"
#elif(BOARD == BOARD_8258_DONGLE)
	#include "board_8258_dongle.h"
#elif(BOARD == BOARD_8258_EVK)
	#include "board_8258_evk.h"
#elif(BOARD == BOARD_8258_EVK_V1P2)
	#include "board_8258_evk_v1p2.h"
#else
	#include "board_826x_evk.h"
#endif


#define 	MODULE_BUFM_ENABLE        1
#define 	MODULE_PRIQ_ENABLE        1
#define 	EV_POST_TASK_ENABLE       1

/* interrupt */
#define IRQ_TIMER1_ENABLE         1
#define	IRQ_GPIO_ENABLE			  0

/* module selection */
#define MODULE_WATCHDOG_ENABLE	0
#define	MODULE_UART_ENABLE		0

/* Rf mode: 250K */
#define	RF_MODE_250K			1

#define VOLTAGE_DETECT_ENABLE						0
#define VOLTAGE_DETECT_ADC_PIN					GPIO_PC5

/**
 *  @brief ZCL cluster support setting
 */
#define ZCL_ON_OFF_SUPPORT							1
#define ZCL_LEVEL_CTRL_SUPPORT						1
#if (COLOR_RGB_SUPPORT || COLOR_CCT_SUPPORT)
#define ZCL_LIGHT_COLOR_CONTROL_SUPPORT				1
#endif
#define ZCL_GROUP_SUPPORT							1
#define ZCL_SCENE_SUPPORT							1
#define ZCL_OTA_SUPPORT								1
#if TOUCHLINK_SUPPORT
#define ZCL_ZLL_COMMISSIONING_SUPPORT				1
#endif
#define ZCL_WWAH_SUPPORT							1

#define AF_TEST_ENABLE			1

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
	EV_POLL_FACTORY_RST,
	EV_POLL_HCI,
    EV_POLL_IDLE,
	EV_POLL_MAX,
}ev_poll_e;

#define	IRQ_USB_PWDN_ENABLE  	0

//////////// product  Information  //////////////////////////////
#define ID_VENDOR				0x248a			// for report
#define ID_PRODUCT_BASE			0x880C
#define STRING_VENDOR			L"Telink"
#define STRING_PRODUCT			L"BLE Remote KMA Dongle"
#define STRING_SERIAL			L"TLSR8258"

#define		BLE_REMOTE_SECURITY_ENABLE		1

    /* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
}
#endif
