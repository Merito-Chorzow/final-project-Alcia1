#ifndef LOGIC_H
#define LOGIC_H

#include <stdint.h>

typedef struct {
    uint32_t uptime_cycles; // Licznik cykli sterownika.
    uint32_t last_rise_time_ms; // Czas rozjaśniania, latency.
    uint32_t start_tick;
} logic_metrics_t;

void logic_init(void);
void logic_set_target(int target);
void logic_update(void);
void logic_set_scene(const char* scene_name);
int logic_get_current_level(void);
logic_metrics_t logic_get_metrics(void);

#endif