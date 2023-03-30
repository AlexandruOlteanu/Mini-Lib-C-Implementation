#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

#define ZERO 0
typedef struct timespec timespec;

int nanosleep(const timespec *needed_sleep_time, timespec *remaining_sleep_time) {

    int response = ZERO;
    do {
        errno = ZERO;
        response = syscall(__NR_nanosleep, needed_sleep_time, remaining_sleep_time);
    } while (errno == EINTR && response == -1);
    
    return response;
}