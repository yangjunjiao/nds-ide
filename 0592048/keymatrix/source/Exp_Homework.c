#include "FreeRTOS.h"
#include "task.h"
#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sevencore_io.h"

void
Exp_4_Homework_A(void)
{
	u8 key, scan = 0;
    int i;
    u8  key_pressed = FALSE;
    u8  mode = FALSE;
    u8 seg7led[NUM_7SEG_LED];

    for (i = 0; i < NUM_7SEG_LED; i++){			// Turn Off All
    	writeb_virtual_io(SEG7LED, 0x80 + (i << 4));
    	seg7led[i] = 0x80;
    }

	while (1) {
		if(key_pressed == FALSE && readb_virtual_io(PUSH_SW) == VIRTUAL_SW_1) {
			for (i = 0; i < NUM_7SEG_LED; i++){			// Turn Off All
				writeb_virtual_io(SEG7LED, 0x80 + (i << 4));
				seg7led[i] = 0x80;
			}
			key_pressed = TRUE;
			mode = !mode;
		}

		if(key_pressed == FALSE){
			//스캔
			writeb_virtual_io(KEY_MATRIX, 0x80 >> scan);
			key = scan * 4;
			switch (readb_virtual_io(KEY_MATRIX)) {
			  case 8 :
				  key += 1;
				  break;
			  case 4 :
				  key += 2;
				  break;
			  case 2 :
				  key += 3;
				  break;
			  case 1 :
				  key += 4;

				  if (key == 16)
					  key = 0;
				  break;
			  default :
				  key = 255;
				  break;
			}

			scan++;
			if (scan == 4)
				scan = 0;
			if (key < 16){
				if(mode == FALSE){
					for(i=NUM_7SEG_LED-1;i>0;i--){
						seg7led[i] = seg7led[i-1];
					}
					seg7led[0] = key;
				}else{
					for(i=0;i<NUM_7SEG_LED;i++){
						seg7led[i] = seg7led[i+1];
					}
					seg7led[NUM_7SEG_LED-1] = key;
				}
				for (i = 0; i < NUM_7SEG_LED; i++){
					writeb_virtual_io(SEG7LED, seg7led[i] + (i << 4) );
				}
				key_pressed = TRUE;
			}
		}

		if (key_pressed == TRUE){
			if(readb_virtual_io(PUSH_SW) != VIRTUAL_SW_1 && readb_virtual_io(KEY_MATRIX) == 0)
				key_pressed = FALSE;
		}

		if (NDS_SWITCH() & KEY_START)
			break;
		vTaskDelay(MSEC2TICK(20));
	}

	while (NDS_SWITCH() & KEY_START)
		vTaskDelay(MSEC2TICK(10));		// Wait while START KEY is being pressed
}

