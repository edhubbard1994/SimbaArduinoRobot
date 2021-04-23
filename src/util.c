#include "util.h"
void check_status(int(*operation)(void), int success) {
    if (operation() != success) {
        sys_reboot();
    }
}