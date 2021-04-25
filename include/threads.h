#ifndef __THREADS_H
#define __THREADS_H

#include "simba.h"

static THRD_STACK(robot_stack, 128);
static THRD_STACK(led_stack,128);

#endif