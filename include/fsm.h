typedef enum {
    STATE_INIT, //jeszcze nie działa
    STATE_IDLE,  // Led zgaszony.
    STATE_RUN,   // Led świeci.
    STATE_FAULT  // Błąd
} system_state_t;

void fsm_init(void);
void fsm_update(void);