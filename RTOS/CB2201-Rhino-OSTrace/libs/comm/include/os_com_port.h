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
#ifndef __OS_COM_KERNEL_PORT_H__
#define __OS_COM_KERNEL_PORT_H__

#include "os_com_cfg.h"
#include <os_port.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The Followings are RS232 port interfaces.  */

/* Init RS232 as the configs in os_com_cfg.h.  */
extern int32_t os_com_rs232_init(void);

/* RS232 Transmit data.  */
extern int32_t os_com_rs232_transmit(uint8_t*pucData, uint32_t ulNumBytes);

/* Get transmit function from communication type.  */
extern os_com_service_tx_func_t os_com_get_tx_func (enum os_com_type_t type);


#ifdef __cplusplus
}
#endif

#endif
