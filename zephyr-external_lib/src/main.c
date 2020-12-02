/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* hello world example: calling functions from a static library */


#include <zephyr.h>
#include <stdio.h>
// #include <sys/util.h>
// #include <sys/printk.h>
#include <mylib.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

void main(void)
{
	while (1)
	{
		printf("fanck Hello World!\n");
		mylib_hello_world();
		k_msleep(SLEEP_TIME_MS);
	}

}
