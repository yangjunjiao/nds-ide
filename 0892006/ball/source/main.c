// Free RTOS Headers
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sevencore_io.h"

#include "card_spi.h"
#include "gdbStub.h"
#include "gdbStubAsm.h"
#define COLOR_RED       RGB(31,  0,  0) /* Bright Red  	*/
#define COLOR_WHITE     RGB(31, 31, 31) /* Bright White */
#define COLOR_GREEN     RGB(0,31,0)
#define COLOR_BLACK     RGB( 0,  0,  0)

#define BOX_WIDTH	16
#define BOX_HEIGHT	16
#define MAX_X		(SCREEN_WIDTH / BOX_WIDTH)
#define MAX_Y		(SCREEN_HEIGHT / BOX_HEIGHT)

// define added 11/10/2011
#define BG_GFX			((u16*)0x6000000)
#define SCREEN_WIDTH	256
#define SCREEN_HEIGHT 192

#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT 2
#define DIRECTION_DOWN 3
#define DIRECTION_UP 4

#define NUM_TASK 6

struct parameters {
	char *taskname;
	int direction;
	int basePoint;
	u32 color;
	int delay;
};
struct parameters Param[NUM_TASK] = {
		{ "1", DIRECTION_RIGHT, 3, COLOR_RED, 50 },
		{ "2", DIRECTION_RIGHT, 6,COLOR_RED, 10 },
		{ "3", DIRECTION_RIGHT, 9, COLOR_RED, 100 },
		{"4", DIRECTION_DOWN, 4, COLOR_GREEN, 20 },
		{ "5",DIRECTION_DOWN, 8, COLOR_GREEN, 70 },
		{ "6", DIRECTION_DOWN, 12,COLOR_GREEN, 150 } };

static portTASK_FUNCTION(Exp_Task, pvParameters);

void Exp_Sample(struct parameters *p);

void InitDebug(void);

int main(void) {
	struct parameters *p;
	int i;
	InitDebug();
	init_virtual_io(ENABLE_SW | ENABLE_MATRIX);

	videoSetMode(MODE_5_2D);
	vramSetBankA(VRAM_A_MAIN_BG);
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);

	for (i = 0, p = Param; i < NUM_TASK; i++, p++)
		xTaskCreate(Exp_Task, (const signed char *)(p->taskname), 1024,
				(void *)p, tskIDLE_PRIORITY + 5, NULL);

	vTaskStartScheduler();		// Never returns
	while (1)
		;
	return 0;
}

void InitDebug(void) {
#ifdef DEBUG
	irqInit();
	initSpi();
	initDebug();
	BreakPoint();
#endif
}

static
portTASK_FUNCTION(Exp_Task, pvParameters) {
	struct parameters *p = (struct parameters *) pvParameters;

	while (1) {
		Exp_Sample(p);
	}
}
// task add
