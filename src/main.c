#include "simba.h"
#include "util.h"
#include "threads.h"
#include "servo.h"

struct pin_driver_t led;

void v(void *arg) {
    pin_toggle(&led);
}

int main() {
    struct event_t event;
    
    struct timer_t timer;
    struct time_t time;
    time.seconds = 1;
    time.nanoseconds = 0;
    
    check_status(sys_start, 0);
    check_status(thrd_module_init, 0);
    check_status(pwm_module_init, 0);
    timer_init(&timer,&time,v,NULL,TIMER_PERIODIC);
    pin_init(&led, &pin_led_dev, PIN_OUTPUT);
    //timer_start(&timer);
    //timer_
    /* Initialize the LED pin as output and set its value to 1. */
    pin_toggle(&pin_led_dev);
    thrd_spawn(
        servo_thread,
        thrd_self(),
        SERVO_PRIORITY,
        robot_stack,
        sizeof(robot_stack)
    );
    //thrd_yield();
    while (1) {
        /* Wait half a second. */
        //servo_thread(NULL);
       
         thrd_sleep(1);
         pin_toggle(&pin_led_dev);
        

        /* Toggle the LED on/off. */
        
    }

    return (0);
}