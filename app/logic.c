#include "logic.h"
#include "led_pwm.h"
#include <stdio.h>

static float current_brightness = 0.0f;
static int target_brightness = 0;

#define BRIGHTNESS_STEP 5.0f 

// Ustaw jasność leda na 0%.
void logic_init(void) {
    led_pwm_set_brightness(0);
    printf("LOGIC: Zainicjalizowano na 0%% jasności\n");
}

// Ustaw target jasności.
void logic_set_target(int target) {
    if (target > 100) target = 100;
    if (target < 0) target = 0;
    target_brightness = target;
}

// Żeby jasność się zwiększała/zmniejszała płynnie.
void logic_update(void) {
    float old_val = current_brightness;

    if (current_brightness < (float)target_brightness) {
        current_brightness += BRIGHTNESS_STEP;
        if (current_brightness > (float)target_brightness) {
            current_brightness = (float)target_brightness;
        }
    } 
    else if (current_brightness > (float)target_brightness) {
        current_brightness -= BRIGHTNESS_STEP;
        if (current_brightness < (float)target_brightness) {
            current_brightness = (float)target_brightness;
        }
    }

    // Wyślij aktualną jasność do leda.
    led_pwm_set_brightness((uint8_t)current_brightness);

    // Wyświetl jasność w konsoli.
    if (old_val != current_brightness) {
        int current_int = (int)current_brightness;
        if (current_int % 10 == 0 || current_int == target_brightness) {
            printf("LOGIC: Jasność LED: %d%% (Cel: %d%%)\n", current_int, target_brightness);
        }
    }
}

// Getter.
int logic_get_current_level(void) {
    return (int)current_brightness;
}