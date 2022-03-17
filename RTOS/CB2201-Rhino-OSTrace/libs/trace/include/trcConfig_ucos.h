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
#ifndef __TRCCONFIG_H__
#define __TRCCONFIG_H__

/******************************************************************************
 * SELECTED_PORT
 *
 * Macro that specifies what hardware port that should be used. 
 * Available ports are:
 *
 * Port Name							Code
 * PORT_CSKY_ABIV1	   		1
 *****************************************************************************/

// Set the port setting here!
#define SELECTED_PORT PORT_CSKY_ABIV2

#if (SELECTED_PORT == PORT_NOT_SET)
	#error "You need to define SELECTED_PORT here!"
#endif

#define EVENT_BUFFER_SIZE 2000

/*******************************************************************************
 * SYMBOL_TABLE_SIZE
 *
 * Macro which should be defined as an integer value.
 *
 * This defines the capacity of the symbol table, in bytes. This symbol table 
 * stores User Events labels and names of deleted tasks, queues, or other kernel
 * objects. If you don't use User Events or delete any kernel 
 * objects you set this to a very low value. The minimum recommended value is 4.
 * A size of zero (0) is not allowed since a zero-sized array may result in a 
 * 32-bit pointer, i.e., using 4 bytes rather than 0.
 *
 * Default value is 800.
 ******************************************************************************/
#define SYMBOL_TABLE_SIZE 800

#if (SYMBOL_TABLE_SIZE == 0)
#error "SYMBOL_TABLE_SIZE may not be zero!"
#endif

#define CONFIG_OS_TRACE_TRIGGER 1
#define CONFIG_TRACE_MAX_TRIGS 3

#endif

