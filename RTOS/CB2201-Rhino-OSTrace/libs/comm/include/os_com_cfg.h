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
#ifndef __OS_COM_CFG_H__
#define __OS_COM_CFG_H__

/* The macro OS_COMMUNICATION is used to enable/disable os communication.  */
#define OS_COMMUNICATION          1

/* The macro OS_COM_BUFF_SIZE defines the os communication buffer's size.  */
#define OS_COM_BUFF_SIZE          256

/* The macro OS_COM_BUFF_MALLOC means buffer is static(0) or dynomic(1).  */
#define OS_COM_BUFF_MALLOC        0

/* The followings are RS232 configurations.  */
#define OS_COM_RS232              1         /* Enable/Disable RS232.  */
#define OS_COM_RS232_BAUDRATE     19200
#define OS_COM_RS232_BITS         USART_DATA_BITS_8
#define OS_COM_RS232_STOP         USART_STOP_BITS_1
#define OS_COM_RS232_PARITY       USART_PARITY_NONE

/* OS communication service task's priority.  */
#define OS_COM_SERVICE_PRIO       KPRIO_NORMAL6

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif /* __OS_COM_CFG_H__  */
