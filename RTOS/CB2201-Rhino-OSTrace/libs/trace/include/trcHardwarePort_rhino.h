/*
 * Copyright (C) 2016 YunOS Project. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*******************************************************************************
 * IRQ_PRIORITY_ORDER
 *
 * Macro which should be defined as an integer of 0 or 1.
 *
 * This should be 0 if lower IRQ priority values implies higher priority
 * levels, such as on ARM Cortex M. If the opposite scheme is used, i.e.,
 * if higher IRQ priority values means higher priority, this should be 1.
 *
 * This setting is not critical. It is used only to sort and colorize the
 * interrupts in priority order, in case you record interrupts using
 * the trace_store_isr_begin and trace_store_isr_end routines.
 *
 ******************************************************************************
 *
 * HWTC Macros
 *
 * These four HWTC macros provides a hardware isolation layer representing a
 * generic hardware timer/counter used for driving the operating system tick
 *
 * HWTC_COUNT: The current value of the counter. This is expected to be reset
 * a each tick interrupt. Thus, when the tick handler starts, the counter has
 * already wrapped.
 *
 * The HWTC macros and trace_port_get_time_stamp is the main porting issue
 * or the trace recorder library. Typically you should not need to change
 * the code of trace_port_get_time_stamp if using the HWTC macros.
 *
 ******************************************************************************/

#include <k_config.h>
#include "trcConfig.h"
extern uint32_t csi_coret_get_value(void);

#if (SELECTED_PORT == PORT_CSKY_ABIV1)
    #define HWTC_PERIOD                         (drv_get_sys_freq()/RHINO_CONFIG_TICKS_PER_SECOND - 1)
    #define HWTC_COUNT                          (HWTC_PERIOD - csi_coret_get_value())
    #define HWTC_COUNT_FREQ                     drv_get_sys_freq()

#elif (SELECTED_PORT == PORT_CSKY_ABIV2)
    #define HWTC_PERIOD                         (drv_get_sys_freq()/RHINO_CONFIG_TICKS_PER_SECOND - 1)
    #define HWTC_COUNT                          (HWTC_PERIOD - csi_coret_get_value())
    #define HWTC_COUNT_FREQ                     drv_get_sys_freq()

#elif (SELECTED_PORT == PORT_APPLICATION_DEFINED)

	#if !( defined (HWTC_COUNT_DIRECTION) && defined (HWTC_COUNT) && defined (HWTC_PERIOD) && defined (HWTC_DIVISOR) && defined (IRQ_PRIORITY_ORDER) )
		#error SELECTED_PORT is PORT_APPLICATION_DEFINED but not all of the necessary constants have been defined.
	#endif

#elif (SELECTED_PORT != PORT_NOT_SET)

	#error "SELECTED_PORT had unsupported value!"
	#define SELECTED_PORT PORT_NOT_SET

#endif

