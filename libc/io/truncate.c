// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#define ZERO 0

int truncate(const char *path, off_t length)
{
    int returned_value;
    do {
        returned_value = syscall(__NR_truncate, path, length);
    } while (returned_value < 0 && errno == EINTR);
    
    if (returned_value < 0) {
        errno = -returned_value;
        returned_value = -1;
    }
    else {
        returned_value = ZERO;
    }

    return returned_value;
}
