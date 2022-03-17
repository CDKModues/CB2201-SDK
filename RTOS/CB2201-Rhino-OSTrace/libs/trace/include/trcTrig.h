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
#ifndef __TRCTRIG_H__
#define __TRCTRIG_H__

#include <stdint.h>
#include <trcConfig.h>

#ifndef CONFIG_TRACE_MAX_TRIGS
#define CONFIG_TRACE_MAX_TRIGS 3
#endif

struct trig
{
  uint8_t id;                /* Trigger ID.  */
  uint8_t enable;             /* Flag set by PC to enable/disable trigger.  */
};

struct trig_manager
{
  struct trig trigs[CONFIG_TRACE_MAX_TRIGS];   /* All triggers infomations.  */
  uint8_t cur_trig;                            /* Current trigger index.  */
};


#if CONFIG_OS_TRACE_TRIGGER > 0
void trig_init(void);
void trig_start(uint8_t id);
void trig_set_enable(uint8_t id, uint8_t enable);
struct trig* trig_get_trigs(void);
size_t trig_count(void);
#else
#define trig_init()
#define trig_start(id)
#define trig_set_enable(id, enable)
#define trig_disable_all(id)
#define trig_get_trigs()    NULL
#define trig_count()    0
#endif

#endif /* __TRCTRIG_H__ */
