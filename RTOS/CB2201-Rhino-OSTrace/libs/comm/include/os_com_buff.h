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
#ifndef __OS_COM_BUFF_H__
#define __OS_COM_BUFF_H__

#include <stdint.h>
#include <os_com_cfg.h>

#ifndef OS_COM_BUFF_SIZE
#define OS_COM_BUFF_SIZE 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

enum os_com_buff_status
{
  OS_COM_BUFF_STATUS_IDLE,
  OS_COM_BUFF_STATUS_BUSY,
};

typedef struct os_com_buff
{
  uint32_t rx_idx;
  uint32_t tx_idx;
  void     *info;
  uint32_t status;
  char     buff[OS_COM_BUFF_SIZE];
}os_com_buff_t;

extern os_com_buff_t *g_com_rx_buff_handle;
extern os_com_buff_t *g_com_tx_buff_handle;

extern void os_com_buff_init (void);

extern int os_com_buff_read (os_com_buff_t *pbuff, uint8_t *ptr, int32_t length);

extern int os_com_buff_write (os_com_buff_t *pbuff, uint8_t *ptr, int32_t length);

extern int os_com_buff_size (os_com_buff_t *pbuff);

extern int os_com_buff_clear (os_com_buff_t *pbuff);

#ifdef __cplusplus
}
#endif

#endif
