#include "driver/gpio.h"
#include "button.h"

#define BUTTON_GPIO 4

// Ustawienie konfiguracji przycisku w wokwi.
void button_init(void) {
    printf("INIT BUTTON\n");
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << BUTTON_GPIO),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);
}

// Zwróć czy przycisk jest wciśnięty w tym momencie.
bool button_is_pressed(void) {
    if (gpio_get_level(BUTTON_GPIO) == 0) {
        printf("DEBUG: Przycisk wciśnięty!\n");
        return true;
    }
    return false;
}