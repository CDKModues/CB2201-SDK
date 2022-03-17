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
#include "trcHardwarePort.h"
#include "trcKernelPort.h"

#if (USE_TRACEALYZER_RECORDER == 1)

#include <stdint.h>
#include <trcHardwarePort.h>


/*******************************************************************************
 * uiTraceTickCount
 *
 * updated by the kernel tick interrupt.
 ******************************************************************************/
uint32_t uiTraceTickCount = 0;


static uint32_t last_traceTickCount = 0;
static uint32_t last_hwtc_count = 0;

static uint32_t _get_trace_tick_count();

/******************************************************************************
 * trace_port_get_time_stamp
 *
 * Returns the time span form the the last call this function, unit is timer count
 *
 ******************************************************************************/
void trace_get_time_dts(uint32_t *pts)
{
    static uint32_t traceTickCount = 0;
    static uint32_t hwtc_count = 0;

    hwtc_count = HWTC_COUNT;

    traceTickCount = _get_trace_tick_count();

    /* Check if the return address is OK, then we perform the calculation. */
    if (pts) {
        /* Get timestamp from trace ticks. Scale down the period to avoid unwanted overflows. */
        *pts = (traceTickCount - last_traceTickCount) * HWTC_PERIOD + hwtc_count;
//        *pts = traceTickCount;
    }

    /* Store the previous values. */
    last_traceTickCount = traceTickCount;
    last_hwtc_count = hwtc_count;
}
static uint32_t _get_trace_tick_count()
{
    static uint32_t traceTickCount = 0;
    traceTickCount = uiTraceTickCount;
    if (traceTickCount == last_traceTickCount && HWTC_COUNT < last_hwtc_count) {
        /* A trace tick has occurred but not been executed by the kernel, so we compensate manually. */
        traceTickCount++;
    }
    return traceTickCount;
}
int32_t trace_get_timer_freq()
{
    return HWTC_COUNT_FREQ;
}
void trace_time_init()
{
    uiTraceTickCount = 0;
    last_traceTickCount = 0;
    last_hwtc_count = HWTC_COUNT;
}

#endif
