#include "FreeRTOS.h"
#include "task.h"
#include "queue.h" // Queue 우선 순위를 위한 헤더
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

extern xQueueHandle KeyQueue;
#define MAX_KEY_LOG		10

void
key_init(void)
{
	int i;
	u8 key;

	for (i = 0; i < MAX_KEY_LOG; i++)
		xQueueReceive(KeyQueue, &key, 0);
}

int
kbhit(void)
{
	u8 key;
	int ret = xQueuePeek(KeyQueue, &key, 0);
	return (ret == pdPASS);
}
u8
getkey(void)
{
	u8 key;
	xQueueReceive(KeyQueue, &key, portMAX_DELAY);
	//while (pdPASS != xQueueReceive(KeyQueue, &key, 0))
	//		vTaskDelay(MSEC2TICK(5));
	return key;
}

void
Exp_5_Homework_A(void)
{
	/*
	 * needs - sample// matrix랑 반대?
	 *
	 *
	 * */
}

void
Exp_5_Homework_B(void)
{
	/*
	 * LED1을 0.5초마다 왼->오른쪽 이동
	 * 오른쪽 끝 에 도달 -> 왼쪽
	 * 왼쪽 틍 도달 -> 오른쪽
	 *
	 * kbhit() 필요 - 리턴값 0/1 - 0도 스크롤
	 * start누르면 실험 종료
	 * 반응 빠르게 구현하면 됨 - 이건 키 안눌려도 되나
	 * */
}

portTASK_FUNCTION(Key_Task, pvParameters)
{
}
