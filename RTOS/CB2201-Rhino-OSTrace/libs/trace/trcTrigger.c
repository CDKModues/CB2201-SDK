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
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <csi_kernel.h>
#include <os_port.h>
#include <trcTrig.h>
#include <trcUser.h>
#include <trcTrig.h>

#include "trcKernelPort.h"

#if CONFIG_OS_TRACE_TRIGGER > 0


struct trig_manager g_trig_manager;

void trace_stop_hook(void);

void trig_init()
{
    int i = 0;

    printf("Trigger Init\n");
    for (uint8_t id = 1; i < CONFIG_TRACE_MAX_TRIGS; i++, id++) {
        g_trig_manager.trigs[i].enable = 0;
        g_trig_manager.trigs[i].id = id;
    }
    g_trig_manager.cur_trig = 0;

    trace_init_data();

    trace_set_stop_hook(trace_stop_hook);

    printf("trig manager status: trig init.\r\n");
    /* Create trig manager task.  */
//    OS_CREATE_TASK (os_trig_manager, "os trigger service", 0, OS_TRIG_STACK_SIZE, NULL, OS_TRIG_PRIO, 0);
}


void trig_start(uint8_t id)
{
    TRACE_SR_ALLOC_CRITICAL_SECTION();
    TRACE_ENTER_CRITICAL_SECTION();

    if (g_trig_manager.trigs[id].enable) {
        trace_start();
    }
    TRACE_EXIT_CRITICAL_SECTION();
}

void trig_set_enable(uint8_t id, uint8_t enable)
{
    TRACE_SR_ALLOC_CRITICAL_SECTION();
    TRACE_ENTER_CRITICAL_SECTION();
    g_trig_manager.trigs[id].enable = enable;
    TRACE_EXIT_CRITICAL_SECTION();
}
struct trig *trig_get_trigs(void)
{
    return g_trig_manager.trigs;
}
size_t trig_count(void)
{
    return CONFIG_TRACE_MAX_TRIGS;
}
void trace_stop_hook(void)
{
    g_trig_manager.cur_trig = 0;

    for (uint8_t i = 1; i < CONFIG_TRACE_MAX_TRIGS; i++) {
        g_trig_manager.trigs[i].enable = 0;
    }
}


#endif /* CONFIG_OS_TRACE_TRIGGER */


