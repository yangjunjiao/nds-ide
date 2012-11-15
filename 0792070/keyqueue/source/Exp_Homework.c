#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

extern xQueueHandle KeyQueue;
#define MAX_KEY_LOG		10
#define TO_LEFT 0
#define TO_RIGHT 1

#define TRUE 1
#define FALSE 0

u8 keypressed = FALSE;

void key_init(void) {
	int i;
	u8 key;

	for (i = 0; i < MAX_KEY_LOG; i++)
		xQueueReceive(KeyQueue, &key, 0);
}

int kbhit(void) {
	u8 key;
	int ret = xQueuePeek(KeyQueue, &key, 0);
	return (ret == pdPASS);
}
u8 getkey(void) {
	u8 key;
	xQueueReceive(KeyQueue, &key, portMAX_DELAY);
	//while (pdPASS != xQueueReceive(KeyQueue, &key, 0))
	//		vTaskDelay(MSEC2TICK(5));
	return key;
}

void init7SEG() {
	int i;
	for (i = 0; i < NUM_7SEG_LED; i++)					// Turn Off All
		writeb_virtual_io(SEG7LED, 0x80 + (i << 4));
}

void initseg7pos(u16 *seg7pos) { // seg Array init
	int i;
	for (i = 0; i < 8; i++) {
		seg7pos[i] = 1 << 7;
	}
}

void leftShift(u16 *seg7pos) {
	int i;
	for (i = 0; i < 7; i++) {
		seg7pos[i] = seg7pos[i + 1];
	}
}

void Exp_5_Homework_A(void) {
	u8 key;
	u16 seg7pos[8];
	int i;

	init7SEG();
	initseg7pos(seg7pos);

	while (1) {

		if (!keypressed) {
			key = getkey();

			if (key == 0) {
				init7SEG();
				initseg7pos(seg7pos);
				break;
			}

			leftShift(seg7pos);
			seg7pos[7] = key;

			for (i = 0; i < NUM_7SEG_LED; i++)
				writeb_virtual_io(SEG7LED, (i << 4) + seg7pos[i]);
		}
	}

	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(MSEC2TICK(10) );
}

void Exp_5_Homework_B(void) {
	u8 led = 0x80, state = TO_RIGHT;
	u8 key;
	u16 seg7pos[8];
	int i;

	init7SEG();
	initseg7pos(seg7pos);

	portTickType xLastWakeTime = xTaskGetTickCount();

	while (1) {
		writeb_virtual_io(BARLED1, led);
		if (xLastWakeTime + MSEC2TICK(450) < xTaskGetTickCount()) {
			if (state == TO_RIGHT) {
				led = led >> 1;
				if (led == 0x01)
					state = TO_LEFT;
			} else if (state == TO_LEFT) {
				led = led << 1;
				if (led == 0x80)
					state = TO_RIGHT;
			}
			vTaskDelayUntil(&xLastWakeTime, MSEC2TICK(500) );
		}
		if (kbhit()) {
			key = getkey();

			leftShift(seg7pos);
			seg7pos[7] = key;

			for (i = 0; i < NUM_7SEG_LED; i++)
				writeb_virtual_io(SEG7LED, (i << 4) + seg7pos[i]);

		}

		if (NDS_SWITCH() & KEY_START) {
			init7SEG();
			initseg7pos(seg7pos);
			break;
		}
	}

	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(MSEC2TICK(10) );
}

u8 readKey(u8 key, u8 scan, u8 *inkey) {
	key = scan * 4;

	*inkey = readb_virtual_io(KEY_MATRIX);
	switch (*inkey) {
	case 8:
		key += 1;
		break;
	case 4:
		key += 2;
		break;
	case 2:
		key += 3;
		break;
	case 1:
		key += 4;
		if (key == 16)
			key = 0;
		break;
	default:
		key = 255;
		break;
	}

	return key;
}

portTASK_FUNCTION(Key_Task, pvParameters) {
	u8 key, scan = 0, prevkey;

	portTickType xLastWakeTime = xTaskGetTickCount();

	while (1) {
		if (keypressed == TRUE
				&& (readb_virtual_io(KEY_MATRIX) != prevkey
						|| !readb_virtual_io(KEY_MATRIX)))
			keypressed = FALSE;

		if (!keypressed) {
			writeb_virtual_io(KEY_MATRIX, 0x80 >> scan);
			key = readKey(key, scan, &prevkey);
			scan++;
			if (scan == 4)
				scan = 0;
			if (key < 16) {
				xQueueSend(KeyQueue, &key, 0);
				keypressed = TRUE;
			}
		}

		vTaskDelayUntil(&xLastWakeTime, MSEC2TICK(10) );
	}
}
