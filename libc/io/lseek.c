// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#define ZERO 0

off_t lseek(int file_descriptor, off_t offset, int whence)
{
    off_t returned_value;
    do {
        returned_value = (off_t) syscall(__NR_lseek, file_descriptor, offset, whence);
    } while (returned_value < 0 && errno == EINTR);
    
    if (returned_value < 0) {
        errno = -returned_value;
        returned_value = -1;
    }

    return returned_value;
}