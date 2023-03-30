// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

#define ZERO 0

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    long returned_value;
    do {
        returned_value = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
    } while (returned_value < 0 && errno == EINTR);
    
    if (returned_value < 0) {
        errno = -returned_value;
        returned_value = -1;
    }
    
    return (void *) returned_value;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
    long returned_value;
    do {
        returned_value = syscall(__NR_mremap, old_address, old_size, new_size, flags);
    } while (returned_value < 0 && errno == EINTR);
    
    if (returned_value < 0) {
        errno = -returned_value;
        returned_value = -1;
    }
    
    return (void *) returned_value;
}

int munmap(void *addr, size_t length) {
    long returned_value;
    do {
        returned_value = syscall(__NR_munmap, addr, length);
    } while (returned_value < 0 && errno == EINTR);
    
    if (returned_value < 0) {
        errno = -returned_value;
        returned_value = -1;
    }
    else {
        returned_value = ZERO;
    }
    
    return (void *) returned_value;
}