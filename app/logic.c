#include "logic.h"
#include "led_pwm.h"
#include <stdio.h>
#include <string.h>

static float current_brightness = 0.0f;
static int target_brightness = 0;
static logic_metrics_t metrics = {0, 0, 0};

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
    metrics.uptime_cycles++;

    float old_val = current_brightness;

    if (current_brightness < (float)target_brightness) {
        if (current_brightness == 0) metrics.start_tick = metrics.uptime_cycles; // Zacznij liczyć latency.

        current_brightness += BRIGHTNESS_STEP;
        if (current_brightness > (float)target_brightness) {
            current_brightness = (float)target_brightness;
        }

        if (current_brightness == target_brightness) {
            metrics.last_rise_time_ms = (metrics.uptime_cycles - metrics.start_tick) * 100; // Skończ liczyć latency (ms).
        }
    } 
    else if (current_brightness > (float)target_brightness) {
        if (current_brightness == 100) metrics.start_tick = metrics.uptime_cycles; // Zacznij liczyć latency.

        current_brightness -= BRIGHTNESS_STEP;
        if (current_brightness < (float)target_brightness) {
            current_brightness = (float)target_brightness;
        }

        if (current_brightness == target_brightness) {
            metrics.last_rise_time_ms = (metrics.uptime_cycles - metrics.start_tick) * 100; // Skończ liczyć latency (ms).
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

// Ustaw scenę.
void logic_set_scene(const char* scene_name) {
    if (strcmp(scene_name, "SUNSET") == 0) {
        logic_set_target(50);
        printf("LOGIC: Uruchomiono scene SUNSET (50%%)\n");
    } 
    else if (strcmp(scene_name, "NIGHT") == 0) {
        logic_set_target(0);
        printf("LOGIC: Uruchomiono scene NIGHT (0%%)\n");
    }
    else if (strcmp(scene_name, "DAY") == 0) {
        logic_set_target(100);
        printf("LOGIC: Uruchomiono scene DAY (100%%)\n");
    }
}

// Zwróć aktualny stan jasności.
int logic_get_current_level(void) {
    return (int)current_brightness;
}

// Zwróć aktualne metryki działania.
logic_metrics_t logic_get_metrics(void) {
    return metrics;
}