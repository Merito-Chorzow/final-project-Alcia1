#ifndef LED_PWM_H
#define LED_PWM_H

#include <stdint.h>

void led_pwm_init(void);
void led_pwm_set_brightness(uint8_t percentage);

#endif