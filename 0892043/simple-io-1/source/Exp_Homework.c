/*
 * Exp_Homework.c
 *
 *  Created on: 2011. 9. 22.
 *      Author: Minsuk Lee
 */

#include <stdio.h>			// C-Standard Header
#include <time.h>
#include <stdlib.h>

#include "FreeRTOS.h"		// Free RTOS Headers
#include "task.h"

#include <nds.h>			// NDS / Sevencore Board Headers
#include <sevencore_io.h>
#include "realio.h"

// LED Bar Left-and-Right (BARLED 1)
// LEFT key - going left, RIGHT key - going right
void Exp_1_Homework_A(void) {

	u16 sw;
	u8 i = 0x80; // LED 상태 값
	u8 key_pressed = FALSE; // 버튼이 눌러진 상태 확인

	writeb_virtual_io(BARLED1, 0); // 초기화
	writeb_virtual_io(BARLED2, 0); // 초기화

	while (1) {

		sw = NDS_SWITCH();

		// 손이 버튼에서 떼진 상태이고 왼쪽 방향키를 눌렀을 경우
		// 그리고 BARLED1 상태가 제일 왼쪽 LED가 켜지지 않은 경우
		if ((key_pressed == FALSE) && (sw & KEY_LEFT) && (i < 0x80)) {
			key_pressed = TRUE;

			i = i << 1; // 왼쪽으로 LED 하나 이동

			writeb_virtual_io(BARLED1, i); // BARLED1 상태 변경 표시
		}

		// 손이 버튼에서 떼진 상태이고 오른쪽 방향키를 눌렀을 경우
		// 그리고 BARLED1 상태가 제일 오른쪽 LED가 켜지지 않은 경우
		else if ((key_pressed == FALSE) && (sw & KEY_RIGHT) && (i > 0x01)) {
			key_pressed = TRUE;

			i = i >> 1; // 오른쪽으로 LED 하나 이동

			writeb_virtual_io(BARLED1, i); // BARLED1 상태 변경 표시
		}

		// 손이 버튼에서 떼졌는지 확인
		if ((key_pressed == TRUE) && (!(sw & KEY_LEFT)) && (!(sw & KEY_RIGHT)))
			key_pressed = FALSE;

		vTaskDelay(50);

		if (NDS_SWITCH() & KEY_START) // START 버튼을 누르면 종료
			break;
	}

	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(10); // Wait while START KEY is being pressed
}

// LED Bar Left-and-Right & Round (BARLED 1 and BARLED 2)
// L key - going left, R key - going right

void Exp_1_Homework_B(void) {

	u16 sw;
	u16 i = 0x8000; // LED 상태 값
	u8 key_pressed = FALSE; // 버튼이 눌러진 상태 확인

	writeb_virtual_io(BARLED1, 0); // 초기화
	writeb_virtual_io(BARLED2, 0); // 초기화

	while (1) {
		sw = NDS_SWITCH();

		// 손이 버튼에서 떼진 상태이고 왼쪽 방향키를 눌렀을 경우
		if ((key_pressed == FALSE) && (NDS_SWITCH() & KEY_L)) {
			key_pressed = TRUE;

			if (i == 0x8000) // BARLED1에서 제일 왼쪽 LED가 켜진 상태인 경우
				i = 0x0001; // BARLED2의 제일 오른쪽 LED로 이동

			else if (i == 0x0080)
				i = 0x0100;

			else
				i = i << 1; // 왼쪽으로 LED 하나 이동
		}

		// 손이 버튼에서 떼진 상태이고 오른쪽 방향키를 눌렀을 경우
		else if ((key_pressed == FALSE) && (NDS_SWITCH() & KEY_R)) {
			key_pressed = TRUE;

			if (i == 0x0001) // BARLED2에서 제일 오른쪽 LED가 켜진 상태인 경우
				i = 0x8000; // BARLED1의 제일 왼쪽 LED로 이동

			else if (i == 0x0100)
				i = 0x0080;

			else
				i = i >> 1; // 오른쪽으로 LED 하나 이동
		}

		// 손이 버튼에서 떼졌는지 확인
		if ((key_pressed == TRUE) && (!(NDS_SWITCH() & KEY_L))
		&& (!(NDS_SWITCH() & KEY_R))) {
			key_pressed = FALSE;
		}

		// 현재 LED 상태 값이 BARLED1에 속해 있을 경우
		if (i <= 0x8000 && i >= 0x0100) {
			// I >> 8 : 현재 LED 상태 값이 16진수이기 때문에 8진수로 변경
			writeb_virtual_io(BARLED1, i >> 8); // BARLED1의 LED 상태 표시
			writeb_virtual_io(BARLED2, 0x0000); // 꺼짐
		}

		// 현재 LED 상태 값이 BARLED2에 속해 있을 경우
		else {
			writeb_virtual_io(BARLED1, 0x0000); // 꺼짐
			writeb_virtual_io(BARLED2, i); // BARLED2의 LED 상태 표시
		}

		vTaskDelay(50);
	}

	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(10);
}
