/*
* main.c
*
* Created on: 2011. 9. 24.
* Author: Minsuk Lee
*/

#include <stdio.h> // C-Standard Header
#include <time.h>
#include <stdlib.h>

#include <FreeRTOS.h> // Free RTOS Headers
#include <task.h>
#include <queue.h>
#include <semphr.h>

#include <nds.h> // NDS / Sevencore Board Headers
#include <sevencore_io.h>

#include "card_spi.h"
#include "gdbStub.h"
#include "gdbStubAsm.h"

static portTASK_FUNCTION(Homework_1, pvParameters);
static portTASK_FUNCTION(Homework_2, pvParameters);

void InitDebug(void);

int
main(void)
{
    InitDebug();
    init_virtual_io(ENABLE_LED); // Enable Virtual IO Devices
    init_printf(); // Initialize Bottom Screen for printf()

    xTaskCreate(Homework_1,
            (const signed char * const)"Homework_1",
            2048,
            (void *)NULL,
            tskIDLE_PRIORITY + 2,
            NULL);

    xTaskCreate(Homework_2,
            (const signed char * const)"Homework_2",
            2048,
            (void *)NULL,
            tskIDLE_PRIORITY + 1,
            NULL);
    vTaskStartScheduler(); // Never returns

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
portTASK_FUNCTION(Homework_1, pvParameters) {
    u16 sw;
    u16 led_state = 0x01;
    u8 key_pressed = FALSE;

    writeb_virtual_io(BARLED1, led_state);
    writeb_virtual_io(BARLED2, 0);

    while (1) {
         sw = NDS_SWITCH();

        if (key_pressed == FALSE && (sw & KEY_L) && led_state != (0x01 << 7)) {
            key_pressed = TRUE;
            led_state = led_state << 1;
            writeb_virtual_io(BARLED1, led_state);
        }

        if (key_pressed == FALSE && (sw & KEY_R) && led_state != 0x01) {
            key_pressed = TRUE;
            led_state = led_state >> 1;
            writeb_virtual_io(BARLED1, led_state);
        }

        if ((key_pressed == TRUE) && (!(sw & KEY_L)) && (!(sw & KEY_R)))
            key_pressed = FALSE;

        vTaskDelay(50);
}
    while (NDS_SWITCH() & KEY_START)
        vTaskDelay(10);
}

static
portTASK_FUNCTION(Homework_2, pvParameters)
{
    u16 led_state=(0x01 << 7);
    u8 state = TRUE;
    portTickType xLastWakeTime=xTaskGetTickCount();

    while (1) {
        if(led_state==(0x01 << 7)){
            state= FALSE;
        led_state=0x01;
        }
        else if(led_state==0x01)
            state=TRUE;

        if(state)
            led_state=led_state<<1;

        writeb_virtual_io(BARLED2, led_state);

    vTaskDelayUntil(&xLastWakeTime, MSEC2TICK(500));
    }
}
