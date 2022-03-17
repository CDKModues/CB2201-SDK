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
#ifndef __TRCKERNELPORT_H__
#define __TRCKERNELPORT_H__

#include <csi_config.h>
#if (CONFIG_OS_TRACE == 1)
    #define USE_TRACEALYZER_RECORDER   1
#else
    #define USE_TRACEALYZER_RECORDER   0
#endif

#ifdef CONFIG_KERNEL_UCOS
#include "trcRecorder_ucos.h"
#elif CONFIG_KERNEL_FREERTOS
#include "trcRecorder_freertos.h"
#elif CONFIG_KERNEL_RHINO
#include "trcKernelPort_rhino.h"
#endif

#endif //__TRCKERNELPORT_H__
