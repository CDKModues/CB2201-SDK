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
#ifndef __OS_COM_SERVICE_H__
#define __OS_COM_SERVICE_H__

#include "os_com_cfg.h"
#include "os_com_buff.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OS_COM_VERSION                     0x00000001u


/* The followings are data format from PC.  */
/* Get some infomation about communications. Such as buff size, version ...  */
#define OS_COM_FMT_RX_QUERY                0x0001u
/* Read data from an address.  */
#define OS_COM_FMT_RX_RD                   0x0002u
/* Write data to an address.  */
#define OS_COM_FMT_RX_WR                   0x0003u
/* Read multi datas from multi addresses.  */
#define OS_COM_FMT_RX_RD_MULTI             0x0007u
/* Write multi datas to multi addresses.  */
#define OS_COM_FMT_RX_WR_MULTI             0x0008u
/* OS trace sub format.  */
#define OS_COM_FMT_RX_OS_TRACE             0x0010u

#define OS_COM_FMT_RX_OS_TRACE_SYS_INFO         0x01u
#define OS_COM_FMT_RX_OS_TRACE_STOP             0x03u
#define OS_COM_FMT_RX_OS_TRACE_SET_TRIG         0x04u
#define OS_COM_FMT_RX_OS_TRACE_GET_TRIG         0x05u
#define OS_COM_FMT_RX_OS_TRACE_GET_TRIG_COUNT   0x06u
#define OS_COM_FMT_RX_OS_TRACE_IS_READY         0x07u

/* The followings are the response format.  */
/* Error pagket.  */
#define OS_COM_FMT_TX_ERR                  0x8000u
/* The response format of OS_COM_FMT_RX_QUERY.  */
#define OS_COM_FMT_TX_QUERY                0x8001u
/* The response format of OS_COM_FMT_RX_RD.  */
#define OS_COM_FMT_TX_RD                   0x8002u
/* The response format of OS_COM_FMT_RX_WR.  */
#define OS_COM_FMT_TX_WR                   0x8003u
/* The response format of OS_COM_FMT_RX_RD_MULTI.  */
#define OS_COM_FMT_TX_RD_MULTI             0x8007u
/* The response format of OS_COM_FMT_RX_WR_MULTI.  */
#define OS_COM_FMT_TX_WR_MULTI             0x8008u
/* The response format of OS_COM_FMT_RX_OSTRACE */
#define OS_COM_FMT_TX_OS_TRACE              0x8010u

#define OS_COM_FMT_TX_OS_TRACE_SYS_INFO         0x81
#define OS_COM_FMT_TX_OS_TRACE_STOP             0x83
#define OS_COM_FMT_TX_OS_TRACE_SET_TRIG         0x84
#define OS_COM_FMT_TX_OS_TRACE_GET_TRIG         0x85
#define OS_COM_FMT_TX_OS_TRACE_GET_TRIG_COUNT   0x86
#define OS_COM_FMT_TX_OS_TRACE_IS_READY         0x8b
#define OS_COM_FMT_TX_OS_TRACE_BUF_INFO         0x87
#define OS_COM_FMT_TX_OS_TRACE_BUF_NAME         0x88
#define OS_COM_FMT_TX_OS_TRACE_BUF_EVENT        0x89

/* The followings are the query type.  */
#define OS_COM_QUERY_MAX_RX_SIZE           0x0001u
#define OS_COM_QUERY_MAX_TX_SIZE           0x0002u
#define OS_COM_QUERY_VERSION               0x0003u
#define OS_COM_QUERY_FMT_SUPPORT           0x0004u
#define OS_COM_QUERY_ENDIANNESS_TEST       0x0005u
#define OS_COM_QUERY_OS                    0x0006u

/* The followings are the error infomations.  */
#define OS_COM_ERR_NONE                    0x00u
#define OS_COM_ERR_UNKNOWN                 0x01u
#define OS_COM_ERR_FMT                     0x02u
#define OS_COM_ERR_PKT_SIZE                0x03u
#define OS_COM_ERR_QUERY                   0x04u
#define OS_COM_ERR_RD_SIZE                 0x05u
#define OS_COM_ERR_CHKSUM                  0x06u
#define OS_COM_ERR_END                     0x07u

typedef int (*os_com_service_tx_func_t) (uint8_t *data, uint32_t length);

enum os_com_type_t
{
  OS_COM_TYPE_RS232,
  OS_COM_TYPE_JTAG,
  OS_COM_TYPE_USB,
  OS_COM_TYPE_TCPIP,
};

extern int os_com_service_rx_data (enum os_com_type_t type, uint8_t *data, int32_t len);
extern void os_com_service_init (void);
#ifdef __cplusplus
}
#endif

#endif /* End of __OS_COM_SERVICE_H__  */
