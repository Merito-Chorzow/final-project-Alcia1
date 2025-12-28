#include "fsm.h"
#include "button.h"
#include "led_pwm.h"
#include "logic.h"
#include <stdio.h>

static system_state_t current_state = STATE_IDLE;
static bool last_button_state = false; 

// Ustaw stan i wyłącz leda.
void fsm_init(void) {
    current_state = STATE_IDLE;
    logic_set_target(0);
    printf("FSM: System zainicjalizowany w stanie IDLE\n");
}

// Zmień stan maszyny i wywołaj odpowiednią logikę.
void fsm_update(void) {
    // Sprawdzanie czy przycisk był kliknięty. Trzeba było zrobić porównanie stanów, bo inaczej był cały czas wciśnięty.
    bool current_button_state = button_is_pressed();
    bool just_pressed = (current_button_state == true && last_button_state == false);

    switch (current_state) {
        case STATE_IDLE:
            if (just_pressed) {
                printf("FSM: [EVENT] Przycisk naciśnięty -> Start rozjaśniania\n");
                current_state = STATE_RUN;
                logic_set_target(100); // Włącz leda
            }
            break;

        case STATE_RUN:
            if (just_pressed) {
                printf("FSM: [EVENT] Przycisk naciśnięty -> Start gaszenia\n");
                current_state = STATE_IDLE;
                logic_set_target(0); // Zgaś leda
            }
            break;
        
        // inne stany do dodania
        default:
            break;
    }

    last_button_state = current_button_state;

    // Slew rate
    logic_update();
}