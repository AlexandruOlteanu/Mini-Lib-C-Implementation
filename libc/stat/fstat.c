// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>

#define ERROR -1
#define ZERO 0

int fstat(int file_descriptor, struct stat *st)
{
    if (st == NULL) {
        return ERROR; 
    }

    int returned_value;
    do {
        returned_value = syscall(__NR_fstat, file_descriptor, st);
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