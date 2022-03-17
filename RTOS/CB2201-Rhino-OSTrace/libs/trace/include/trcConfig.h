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

#ifndef __TRC_CONFIG_H__
#define __TRC_CONFIG_H__
#include "csi_config.h"

/****** Port Name ********************** Code ***** Official ** OS Platform *********/
#define PORT_CSKY_ABIV1                        1    /*	Yes			Any					*/
#define PORT_CSKY_ABIV2                        2    /*	Yes			Any					*/

/**
 * ENABLE_DEBUG_PRINT
 *
 * 1 means enable trace_printf
 * 0 means disable trace_printf
 * default is 0
 */
#define ENABLE_DEBUG_PRINT                     0

#ifdef CONFIG_KERNEL_UCOS
#include "trcConfig_ucos.h"
#elif CONFIG_KERNEL_FREERTOS
#include "trcConfig_freertos.h"
#elif CONFIG_KERNEL_RHINO
#include "trcConfig_rhino.h"
#endif

#endif
