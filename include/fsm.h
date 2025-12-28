#ifndef FSM_H
#define FSM_H

typedef enum {
    STATE_INIT, // Led robi test do 20$ jasności.
    STATE_IDLE, // Led zgaszony.
    STATE_RUN, // Led świeci.
    STATE_FAULT // Błąd, led mruga.
} system_state_t;

void fsm_init(void);
void fsm_update(void);

#endif