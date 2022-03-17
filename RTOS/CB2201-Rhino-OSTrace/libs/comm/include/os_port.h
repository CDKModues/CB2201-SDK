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
#ifndef __OS_PORT_H__
#define __OS_PORT_H__

#ifndef NULL
#define NULL 0
#endif

/* The Followinga are OS porting macros.  */

#include <stdlib.h>
#include <csi_config.h>
#include <csi_kernel.h>
//#include <csi_core.h>

/* Create Task Macro.  */

#define OS_CREATE_TASK(entry, name, stack, stack_size, args, prio, perr)   \
          do {                                                             \
               void *phandle = NULL;                                       \
               if (csi_kernel_task_new((k_task_entry_t)entry,              \
                      name, 0,                                             \
                      prio,                                                \
                      0, 0, stack_size,                                    \
                      &phandle))                                           \
              printf ("Create task failed\r\n"); \
          } while (0)

#define OS_SEM_CREATE(psem)                                                \
          do {                                                             \
            psem = csi_kernel_sem_new(1, 0);                               \
          } while (0)

#define OS_SEM_WAIT(sem)                                                   \
          do {                                                             \
            csi_kernel_sem_wait(sem, -1);                                  \
          } while (0)

#define OS_SEM_POST(sem)                                                   \
          do {                                                             \
            csi_kernel_sem_post(sem);                                      \
          } while (0)

#define OS_TASK_DELAY(ntick)                                               \
          do {                                                             \
            csi_kernel_delay(ntick);                                       \
          } while (0)

#define OS_ALLOC_CRITICAL_SECTION()        uint32_t cpustatus;
#define OS_ENTER_CRITICAL()                cpustatus = csi_irq_save();
#define OS_EXIT_CRITICAL()                 csi_irq_restore(cpustatus);


#endif
