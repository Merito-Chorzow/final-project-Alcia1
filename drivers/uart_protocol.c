#include "uart_protocol.h"
#include "logic.h"
#include "driver/uart.h"
#include <string.h>
#include <stdio.h>

#define UART_PORT UART_NUM_0
#define BUF_SIZE 128

static uart_stats_t stats = {0, 0};
// Bufor do gromadzenia znaków aż do napotkania znaku nowej linii.
static char input_buffer[BUF_SIZE];
static int buffer_index = 0;

// Konfiguracja UART.
void uart_protocol_init(void) {
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_PORT, &uart_config);
    uart_driver_install(UART_PORT, BUF_SIZE * 2, 0, 0, NULL, 0);
}

// Parser komend.
void process_command(char* line) {
    if (strlen(line) == 0) return;
    stats.commands_received++;
    
    if (strcmp(line, "ON") == 0) {
        logic_set_target(100);
        printf("\nUART: Aktywowano rozjasnianie (100%%)\n");
    } 
    else if (strcmp(line, "OFF") == 0) {
        logic_set_target(0);
        printf("\nUART: Aktywowano gaszenie (0%%)\n");
    }
    else if (strncmp(line, "SET:", 4) == 0) {
        int val = atoi(&line[4]);
        if (val >= 0 && val <= 100) {
            logic_set_target(val);
            printf("\nUART: Ustawiono cel na %d%%\n", val);
        } else {
            stats.errors_count++;
            printf("\nUART ERROR: Wartosc poza zakresem 0-100\n");
        }
    }
    else if (strcmp(line, "STATS") == 0) {
        printf("\nTELEMETRIA: Komendy: %lu, Bledy: %lu, Aktualna Jasnosc: %d%%\n", 
                stats.commands_received, stats.errors_count, logic_get_current_level());
    }
    else {
        stats.errors_count++;
        printf("\nUART ERROR: Nieznana komenda [%s]. Dostepne: ON, OFF, SET:val, STATS\n", line);
    }
}

// Odczytywanie komend.
void uart_protocol_tick(void) {
    uint8_t byte;
    while (uart_read_bytes(UART_PORT, &byte, 1, 0) > 0) {
        // Koniec komendy to koniec lini.
        if (byte == '\n' || byte == '\r') {
            if (buffer_index > 0) {
                input_buffer[buffer_index] = '\0';
                process_command(input_buffer);
                buffer_index = 0;
            }
        } 
        else if (buffer_index < BUF_SIZE - 1) {
            input_buffer[buffer_index++] = (char)byte;
            // Wypisz znak, żeby było widać co się pisze.
            putchar(byte);
            fflush(stdout);
        }
    }
}

// Wypisz statystyki.
uart_stats_t uart_get_stats(void) {
    return stats;
}