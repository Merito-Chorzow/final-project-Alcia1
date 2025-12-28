#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "fsm.h"
#include "led_pwm.h"
#include "button.h"
#include "uart_protocol.h"
#include "logic.h"

void main_control_loop(void *pvParameters) {
    while (1) {
        // Aktualizacja stanu.
        fsm_update();
        // Sprawdzanie czy jest jakaś komenda do przetworzenia.
        uart_protocol_tick();

        // Odczekanie 100ms.
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void app_main(void) {
    printf("--- SYSTEM START: Sterownik Oswietlenia ---\n");

    // Inicjalizacja sterowników.
    button_init();
    led_pwm_init();
    uart_protocol_init();

    // Inicjalizacja logiki.
    logic_init();
    fsm_init();

    // Uruchomienie głównej pętli.
    xTaskCreate(main_control_loop, "main_fsm_task", 4096, NULL, 5, NULL);

    printf("--- SYSTEM READY ---\n");
}