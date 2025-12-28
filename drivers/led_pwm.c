#include "driver/ledc.h"
#include "led_pwm.h"

#define LEDC_OUTPUT_IO          (12) 
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT 
#define LEDC_TIMER              LEDC_TIMER_0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_FREQUENCY          (5000) 

// Ustawienie konfiguracji led w wokwi.
void led_pwm_init(void) {
    printf("LED PWM INIT\n");
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .timer_num        = LEDC_TIMER,
        .duty_resolution  = LEDC_DUTY_RES,
        .freq_hz          = LEDC_FREQUENCY,
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel = {
        .speed_mode     = LEDC_MODE,
        .channel        = LEDC_CHANNEL,
        .timer_sel      = LEDC_TIMER,
        .intr_type      = LEDC_INTR_DISABLE,
        .gpio_num       = LEDC_OUTPUT_IO,
        .duty           = 0,
        .hpoint         = 0
    };
    ledc_channel_config(&ledc_channel);
}

// Ustaw jasność leda.
void led_pwm_set_brightness(uint8_t percentage) {
    if (percentage > 100) percentage = 100;

    // Przeliczenie procentów na wartość 13-bitową.
    // Wzór: (procent * (2^13 - 1)) / 100
    uint32_t duty = (percentage * 8191) / 100;

    ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, duty);
    ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
}