#include "simba.h"
#include "util.h"
#include "threads.h"
#include "servo.h"




int main() {
    struct pin_driver_t led;
    check_status(sys_start, 0);
    check_status(thrd_module_init, 0);
    check_status(pwm_module_init, 0);
    /* Initialize the LED pin as output and set its value to 1. */
    thrd_spawn(
        servo_thread,
        thrd_self(),
        SERVO_PRIORITY,
        robot_stack,
        sizeof(robot_stack)
    );

    while (1) {
        /* Wait half a second. */
        //servo_thread(NULL);
        thrd_yield();
        

        /* Toggle the LED on/off. */
        
    }

    return (0);
}