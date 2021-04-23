#ifndef __SERVO_H
#define __SERVO_H

#define SERVO_PRIORITY -127

#include "simba.h"

typedef unsigned short servo_val_t;

void *servo_thread(void *thrd_args);



#endif