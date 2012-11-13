/*
 * Exp_Homework.c
 *
 *  Created on: 2011. 9. 22.
 *      Author: Minsuk Lee
 */

#include "FreeRTOS.h"
#include "task.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

u16 barled;
portTickType start_time_c = 0;

#define NUM_STATE	9
#define NUM_INPUT	3

// Actions
struct state_machine_x {
	int check_timer;
	int next_state[NUM_INPUT];
	void (* action[NUM_INPUT])(void *p);
};

static
void
f_led0(void *p) //초기상태
{
	printf("< L - L >\n");
	barled = 0;
	writeb_virtual_io(BARLED1, 0);
	writeb_virtual_io(BARLED2, 0);
}

static
void
f_led1(void *p) //Short
{
	printf("< S >\n");
	if(barled != 0xFFFF){
		barled |= (barled >> 1);
		if(barled == 0)
			barled = 0x8000;
	}
	writeb_virtual_io(BARLED1, barled >> 8);
	writeb_virtual_io(BARLED2, barled & 0xFF);
}

static
void
f_led2(void *p) //Long
{
	printf("< L >\n");
	barled = 0xff00;
	writeb_virtual_io(BARLED1, 0xFF);
	writeb_virtual_io(BARLED2, 0);
}

static
void
f_led3(void *p)
{
	printf("< S - S >\n");
	if(barled != 0){
		barled = barled << 1;
	}
	writeb_virtual_io(BARLED1, barled >> 8);
	writeb_virtual_io(BARLED2, barled & 0xFF);
}

static
void
f_led4(void *p)
{
	printf("< S - L >\n");
	barled = 0xFc00;
	writeb_virtual_io(BARLED1, 0xFc);
	writeb_virtual_io(BARLED2, 0);
}

static
void
f_led5(void *p)
{
	printf("< L - S >\n");
	barled = 0xFFFF;
	writeb_virtual_io(BARLED1, 0xFF);
	writeb_virtual_io(BARLED2, 0xFF);
}

static
void
f_ts(void *p)
{
	start_time_c = xTaskGetTickCount();
}

enum { SW_ON, SW_OFF, TO };

struct state_machine_x SM[NUM_STATE] = {
	// Fill here
		{0, {4, 0, 0}, {f_ts, NULL, NULL}}, //상태 0
		{1, {2, 1, 0}, {f_ts, NULL, f_led1}}, //상태 1
		{1, {2, 0, 3}, {NULL, f_led3, NULL}}, //상태 2
		{0, {3, 0, 3}, {NULL, f_led4, NULL}}, //상태 3
		{1, {4, 1, 5}, {NULL, f_ts, NULL}}, //상태 4
		{0, {5, 6, 5}, {NULL, f_ts, NULL}}, //상태 5
		{1, {7, 6, 0}, {f_ts, NULL, f_led2}}, //상태 6
		{1, {7, 0, 8}, {NULL, f_led5, NULL}}, //상태 7
		{0, {8, 0, 8}, {NULL, f_led0, NULL}}, //상태 8
};

void
Exp_3_Homework(void)
{
    // variables
	int state;
	int input;

	printf("Exp_3_Homework\n");

	state = 0;							// Initial State 0 : All LED Off
	writeb_virtual_io(BARLED1, 0);
	writeb_virtual_io(BARLED2, 0);

	while (1) {
		/* Step 0: Generate Input Event */
		if (SM[state].check_timer) {
			if ((xTaskGetTickCount() - start_time_c) >= MSEC2TICK(200)) {
				input = TO;
				goto do_action;		// Input happens
			}
		}
		if (NDS_SWITCH() & KEY_A)
			input = SW_ON;
		else
			input = SW_OFF;

		/* Step 1: Do Action */
do_action:
		if (SM[state].action[input])
			SM[state].action[input](NULL);

		/* Step 2: Set Next State */
		state = SM[state].next_state[input];

		if (NDS_SWITCH() & KEY_START)
			break;
		vTaskDelay(MSEC2TICK(50));
	}
	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(MSEC2TICK(10));		// Wait while START KEY is being pressed
}