#include "fsm.h"
#include "button.h"
#include "led_pwm.h"
#include "logic.h"
#include <stdio.h>

static system_state_t current_state = STATE_INIT;
static bool last_button_state = false; 
static int fault_timer = 0;

// Ustaw stan i wyłącz leda.
void fsm_init(void) {
    current_state = STATE_INIT;
    logic_set_target(0);
    printf("FSM: System zainicjalizowany w stanie INIT\n");
}

// Zmień stan maszyny i wywołaj odpowiednią logikę.
void fsm_update(void) {
    // Sprawdzanie czy przycisk był kliknięty. Trzeba było zrobić porównanie stanów, bo inaczej był cały czas wciśnięty.
    bool current_button_state = button_is_pressed();
    bool just_pressed = (current_button_state == true && last_button_state == false);

    // Licznik bezpieczeństwa dla stanu FAULT.
    // Stan FAULT się włączy jak przycisk będzie przez 3 sekundy wciśnięty.
    if (current_button_state) {
        fault_timer++;
        if (fault_timer > 30) {
            if (current_state != STATE_FAULT) {
                printf("FSM: [ERROR] Przycisk zablokowany zbyt długo! Zmiana na STATE_FAULT\n");
                current_state = STATE_FAULT;
            }
        }
    } else {
        fault_timer = 0;
    }

    switch (current_state) {
        case STATE_INIT:
            // Krótki test na starcie, żeby sterownik był przez chwilę na stanie INIT, bo nie mam pomysłu co innego można robić w tym stanie.
            logic_set_target(20);
            if (logic_get_current_level() >= 20) {
                logic_set_target(0);
                current_state = STATE_IDLE;
                printf("FSM: Test inicjalizacyjny zakończony. Zmiana na STATE_IDLE\n");
            }
            break;

        case STATE_IDLE:
            if (just_pressed) {
                printf("FSM: [EVENT] Przycisk naciśnięty. Start rozjaśniania\n");
                current_state = STATE_RUN;
                logic_set_target(100); // Włącz leda
            }
            break;

        case STATE_RUN:
            if (just_pressed) {
                printf("FSM: [EVENT] Przycisk naciśnięty. Start gaszenia\n");
                current_state = STATE_IDLE;
                logic_set_target(0); // Zgaś leda
            }
            break;

        case STATE_FAULT:
            static int blink_counter = 0;
            if (blink_counter++ % 5 == 0) {
                int level = logic_get_current_level();
                logic_set_target(level == 0 ? 50 : 0);
            }
            
            
            if (just_pressed && fault_timer < 50) {
                printf("FSM: Resetowanie błędu -> STATE_IDLE\n");
                current_state = STATE_IDLE;
                logic_set_target(0);
            }
            break;
        
        default:
            break;
    }

    last_button_state = current_button_state;

    // Slew rate
    logic_update();
}