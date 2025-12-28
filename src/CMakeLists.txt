idf_component_register(
    SRCS 
        "main.c"
        "../app/fsm.c"
        "../app/logic.c"
        "../drivers/led_pwm.c"
        "../drivers/button.c"
        "../drivers/uart_protocol.c"
    INCLUDE_DIRS 
        "../include"
        "."
    REQUIRES driver
)