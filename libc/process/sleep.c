#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

#define ZERO 0
typedef struct timespec timespec;

int sleep(int seconds) {
    
    timespec needed_sleep_time;
    needed_sleep_time.tv_sec = seconds;
    needed_sleep_time.tv_nsec = ZERO;
    int value = nanosleep(&needed_sleep_time, &needed_sleep_time);
    while (value != ZERO) {
        if (errno == EINTR) {
            continue;
        }
        else {
            return needed_sleep_time.tv_sec;
        }
        value = nanosleep(&needed_sleep_time, &needed_sleep_time);
    }

    return ZERO;
}
