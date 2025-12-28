#ifndef UART_PROTOCOL_H
#define UART_PROTOCOL_H

#include <stdint.h>

typedef struct {
    uint32_t commands_received;
    uint32_t errors_count;
} uart_stats_t;

void uart_protocol_init(void);
void uart_protocol_tick(void); 
uart_stats_t uart_get_stats(void);

#endif