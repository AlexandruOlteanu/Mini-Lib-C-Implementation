// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>


int close(int file_descriptor) {

    int returned_value;
    do {
        returned_value = syscall(__NR_close, file_descriptor);
    } while (returned_value == -1 && errno == EINTR);
    switch (returned_value) {
        case -1:
            return -1;
            break;
        default:
            return 0;
            break;
    }

    return 0;
}
