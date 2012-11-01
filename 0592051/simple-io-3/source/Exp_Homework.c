/* Exp_Homework.c
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

portTickType start_time = 0;
u8 barled = 0x00;
u8 led = 0x80;
u8 Barled2_on = FALSE;

#define NUM_STATE 9
#define NUM_INPUT 3

static void f_sClick(void *p) {
	printf("<<Short Click>>\n");
	if (Barled2_on == FALSE) {

		barled = (barled >> 1) + led;
		writeb_virtual_io(BARLED1, barled);
		writeb_virtual_io(BARLED2, 0x00);

		if (barled == 0xFF) {
			Barled2_on = TRUE;
			barled = 0x00;
		}

	} else {

		barled = (barled >> 1) + led;
		writeb_virtual_io(BARLED1, 0xFF);
		writeb_virtual_io(BARLED2, barled);

		if (barled == 0xFF) {
			writeb_virtual_io(BARLED1, 0xFF);
			writeb_virtual_io(BARLED2, 0xFF);
		}

	}

}

static void f_lClick(void *p) {
	printf("<<Long Click>>\n");
	barled = 0xFF;
	Barled2_on = TRUE;
	writeb_virtual_io(BARLED1, barled);
	writeb_virtual_io(BARLED2, 0);
	barled = 0x00;

}

static void f_ssdClick(void *p) {
	printf("<<Short Short Double Click>>\n");

	if (Barled2_on == TRUE) {

		if (barled == 0x00) {

			barled = 0xFF;
			Barled2_on = FALSE;
			barled = barled << 1;
			writeb_virtual_io(BARLED1, barled);
			writeb_virtual_io(BARLED2, 0x00);

		} else {

			barled = barled << 1;
			writeb_virtual_io(BARLED1, 0xFF);
			writeb_virtual_io(BARLED2, barled);
		}

	} else {
		barled = barled << 1;
		writeb_virtual_io(BARLED1, barled);
		writeb_virtual_io(BARLED2, 0x00);
	}

}

static void f_sldClick(void *p) {
	printf("<<Short Long Double Click>>\n");
	barled = 0xFC;
	Barled2_on = FALSE;
	writeb_virtual_io(BARLED1, barled);
	writeb_virtual_io(BARLED2, 0);
}

static void f_lsdClick(void *p) {
	printf("<<Long Short Double Click>>\n");
	barled = 0xFF;
	Barled2_on = TRUE;
	writeb_virtual_io(BARLED1, barled);
	writeb_virtual_io(BARLED2, barled);
}

static void f_lldClick(void *p) {
	printf("<<Long Long Double Click>>\n");
	barled = 0x00;
	Barled2_on = FALSE;
	writeb_virtual_io(BARLED1, barled);
	writeb_virtual_io(BARLED2, barled);
}

static void f_ts(void *p) {
	start_time = xTaskGetTickCount();
}

struct state_machine_x {
	int check_timer;
	int next_state[NUM_INPUT];
	void (*action[NUM_INPUT])(void *p);
};

enum {
	SW_ON, SW_OFF, TO
};

struct state_machine_x SM[NUM_STATE] = {
		{ 0, { 1, 0, 0 }, { f_ts, NULL, NULL } },
		{ 1, { 1, 3, 2 }, { NULL, f_ts, NULL } },
		{ 0, { 2, 4, 0 }, { NULL, f_ts, NULL } },

		{ 1, { 5, 3, 0 }, { f_ts, NULL, f_sClick } },
		{ 1, { 7, 4, 0 }, { f_ts, NULL, f_lClick } },

		{ 1, { 5, 0, 6 }, { NULL, f_ssdClick, NULL } },
		{ 0, { 6, 0, 0 }, { NULL, f_sldClick, NULL } },
		{ 1, { 7, 0, 8 }, { NULL, f_lsdClick, NULL } },
		{ 0, { 8, 0, 0 }, { NULL, f_lldClick, NULL } }

};

void Exp_3_Homework(void) {

	int state;
	int input;

	printf("EXP_3_Homework\n");

	state = 0;
	writeb_virtual_io(BARLED1, 0);
	writeb_virtual_io(BARLED2, 0);

	while (1) {
		/* Step 0: Generate Input Event */
		if (SM[state].check_timer) {
			if ((xTaskGetTickCount() - start_time) >= MSEC2TICK(200) ) {
				input = TO;
				goto do_action;
			}
		}

		if (NDS_SWITCH() & KEY_A) {
			input = SW_ON;
		} else {
			input = SW_OFF;
		}

		/* Step 1: Do Action */
		do_action: if (SM[state].action[input]) {
			SM[state].action[input](NULL);
		}
		/* Step 2: Set Next State */
		state = SM[state].next_state[input];

		if (NDS_SWITCH() & KEY_START)
			break;
		vTaskDelay(MSEC2TICK(50) );
	}

	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(MSEC2TICK(10) );		// Wait while START KEY is being pressed
}