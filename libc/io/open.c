// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

#define ZERO 0

int open(const char *filename, int flags, ...)
{
    mode_t open_mode = ZERO;
    int returned_value;
    va_list open_values;

    short and_bits = flags & O_CREAT;

    switch(and_bits) {
        case ZERO:
            va_start(open_values, flags);
            open_mode = (mode_t) va_arg(open_values, int);
            va_end(open_values);
            break;
        default :
            open_mode = ZERO;
            break;
    }

    returned_value = syscall(__NR_open, filename, flags, open_mode);
    if(returned_value < ZERO) {
        errno = -returned_value;
        returned_value = -1;
    }
    
    return returned_value;
}
