#ifndef __TIME_H__
#define __TIME_H__    1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
typedef unsigned long long ull;
typedef struct timespec timespec;
struct timespec {
    ull tv_sec;
    long tv_nsec;
};

int nanosleep(const timespec *needed_sleep_time, timespec *remaining_sleep_time);

#ifdef __cplusplus
}
#endif

#endif