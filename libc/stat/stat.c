// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>

#define ZERO 0

int stat(const char *restrict path, struct stat *restrict buf)
{
    int returned_value;
    do {
        returned_value = syscall(__NR_stat, path, buf);
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