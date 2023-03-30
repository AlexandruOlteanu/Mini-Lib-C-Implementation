// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size) {
	
	if (!size) {
        return NULL;
    }

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    
    if (ptr == MAP_FAILED) {
        return NULL;
    }

    if (mem_list_add(ptr, size) < 0) {
        munmap(ptr, size);
        return NULL;
    }

    return ptr;
}

void *calloc(size_t nmemb, size_t size) {

	int mem_sz = nmemb * size;
    short value = 0;

    if (mem_sz < nmemb || mem_sz < size) {
        return NULL;
    }

    void *ptr = malloc(mem_sz);
    if (ptr == NULL) {
        return NULL;
    }

    memset(ptr, value, mem_sz);

    return ptr;
}

typedef struct mem_list mem_list;
void free(void *ptr) {

	if (ptr == NULL) {
        return;
    }

    mem_list *value = mem_list_find(ptr);
    if (value == NULL) {
        return;
    }

    int size = value->len;

    if (mem_list_del(ptr) < 0)
        return;

    munmap(ptr, size);

}

void *realloc(void *ptr, size_t size) {
	if (ptr == NULL) {
        return malloc(size);
    }

    if (!size) {
        free(ptr);
        return NULL;
    }

    mem_list *value = mem_list_find(ptr);
    if (value == NULL) {
        return NULL;
    }

    int old_size = value->len;

    if (old_size == size) {
        return ptr;
    }

    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }
    int mini = old_size;
    if (size < mini) {
        mini = size;
    }
    memcpy(new_ptr, ptr, mini);
    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
	int mem_sz = nmemb * size;

    if (!nmemb || !size) {
        if (ptr != NULL) {
            free(ptr);
        }
        return NULL;
    }

    void *new_ptr = realloc(ptr, mem_sz);

    if (new_ptr == NULL) {
        return NULL;
    }

    return new_ptr;
}