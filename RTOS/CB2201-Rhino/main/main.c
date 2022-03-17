/*
 * Copyright (C) 2017 C-SKY Microsystems Co., Ltd. All rights reserved.
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

/******************************************************************************
 * @file     main.c
 * @brief    CSI Source File for main
 * @version  V1.0
 * @date     12. June 2018
 ******************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <csi_kernel.h>

#define EXAMPLE_PRIO    5
#define EXAMPLE_TASK_STK_SIZE 1024

k_task_handle_t example_main_task;

void example_main(void)
{
    int i = 0;

    while (1) {
        printf("Hello World! %d\n", i++);
        csi_kernel_delay_ms(1000);
    }
}

int main(void)
{
    csi_kernel_init();

    csi_kernel_task_new((k_task_entry_t)example_main, "example_main",
                        0, EXAMPLE_PRIO, 0, 0, EXAMPLE_TASK_STK_SIZE, &example_main_task);

    csi_kernel_start();

    return 0;
}
