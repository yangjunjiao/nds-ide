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

#define NUM_TASK 6

#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT 2
#define DIRECTION_UP 3
#define DIRECTION_DOWN 4

#define COLOR_RED		RGB(31,  0,  0) /* Bright Red  	*/
#define COLOR_WHITE	RGB(31, 31, 31) /* Bright White */
#define COLOR_BLACK	RGB( 0,  0,  0)
#define COLOR_GREEN	RGB(0,  31,  0)

struct parameters{
	char *taskname;
	int direction;
	int basePoint;
	int color;
	int delay;
};

struct parameters Param[NUM_TASK] = {
		{"1", DIRECTION_RIGHT, 3, COLOR_RED, 50},
		{"2", DIRECTION_RIGHT, 6, COLOR_RED, 10},
		{"3", DIRECTION_RIGHT, 9, COLOR_RED, 100},
		{"4", DIRECTION_DOWN, 4, COLOR_GREEN, 20},
		{"5", DIRECTION_DOWN, 8, COLOR_GREEN, 70},
		{"6", DIRECTION_DOWN, 12, COLOR_GREEN, 150}
};

static portTASK_FUNCTION(Exp_Task, pvParameters);
portTASK_FUNCTION(Key_Task, pvParameters);
static portTASK_FUNCTION(Ball_Task, pvParameters);

void Exp_Sample(void);

void InitDebug(void);

int
main(void)
{
	int i;
	struct parameters *p;
	InitDebug();
	init_virtual_io(ENABLE_SW | ENABLE_MATRIX);	// Enable Virtual LED's on Top Screen

	for(i=0, p=Param;i<NUM_TASK;i++, p++){
		xTaskCreate(Ball_Task,
				(const signed char * const)(p->taskname),
				1024,
				(void *)p,
				tskIDLE_PRIORITY + 5,
				NULL);
	}

	vTaskStartScheduler();		// Never returns
	while(1)
		;
	return 0;
}

void
InitDebug(void)
{
#ifdef DEBUG
	irqInit();
	initSpi();
	initDebug();
	BreakPoint();
#endif
}

static
portTASK_FUNCTION(Ball_Task, pvParameters)
{
    videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG);
    bgInit(3,BgType_Bmp16, BgSize_B16_256x256, 0, 0);

    struct parameters *p = (struct parameters *)pvParameters;
    int count = 0;

	while (1) {
		for(i=0;i<NUM_TASK;i++, p++){
			Exp_Homework(p);
		}
	}
}