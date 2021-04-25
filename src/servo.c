#include "servo.h"
#include "util.h"

#define PWM_MIN 57 //full right
#define PWM_MAX 218 //full left
#define PWM_DELAY 50000 //delay between servo positioning
#define PWM_FREQUENCY 255 //standard frequency for arduino PWM


void *servo_thread(void *thrd_args) {
    /*
        continuously run servo left to right with sensor on top
    */
    check_status(pwm_module_init, 0);
    struct pin_driver_t pwm;

    struct analog_output_pin_t servo;

    servo_val_t duty_cycle = PWM_MIN;

    pwm_init(
        &pwm,
        &pwm_d3_dev,
        PWM_FREQUENCY,
        PWM_MIN
    );
    pwm_start(&pwm);

    for (;;) {
        while (duty_cycle < PWM_MAX) {
            thrd_sleep_us(PWM_DELAY);
            pwm_set_duty_cycle(&pwm, duty_cycle);
            duty_cycle ++;
        }
        thrd_yield();
        while (duty_cycle > PWM_MIN) {
            thrd_sleep_us(PWM_DELAY);
            pwm_set_duty_cycle(&pwm, duty_cycle);
            duty_cycle --;
        }
        thrd_yield();
    }  
}