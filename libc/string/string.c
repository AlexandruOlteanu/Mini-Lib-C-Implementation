// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

#define ZERO 0

char *strcpy(char *destination, const char *source) {
    int i = -1;
    do {
        ++i;
        destination[i] = source[i];
    } while (source[i] != '\0');

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {

    int i = -1;
    if (len > 0)
    do {
        --len;
        ++i;
        destination[i] = source[i];
    } while (len != 0 && source[i] != '\0');

    while (len != 0) {
        destination[i] = '\0';
        ++i;
        --len;
    }

    return destination;
}

char *strcat(char *destination, const char *source) {

    int i = -1;
    do {
        ++i;
    }while (destination[i] != '\0');

    int nr = -1;
    do {
        ++nr;
        destination[i] = source[nr];
        ++i;
    } while (source[nr] != '\0');

    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {

    int i = -1;
    do {
        ++i;
    }while (destination[i] != '\0');

    int nr = -1;
    if (len > 0) {
        do {
            ++nr;
            --len;
            destination[i] = source[nr];
            ++i;
        } while (source[nr] != '\0' && len > 0);
    }

    destination[i] = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2) {
    int i = -1;
    short ok = 1;
    do {
        ++i;
        if (str1[i] != str2[i]) {
            ok = 0;
        }
    } while (str1[i] != '\0' && str2[i] != '\0' && ok);
    
    if (ok) {
        return 0;
    }
    else {
        return *(str1 + i) - *(str2 + i);
    }
}

int strncmp(const char *str1, const char *str2, size_t len) {

    int i = -1;
    short ok = 1;
    do {
        ++i;
        --len;
        if (str1[i] != str2[i]) {
            ok = 0;
        }
    } while (str1[i] != '\0' && str2[i] != '\0' && ok && len > 0);
    
    if (ok) {
        return 0;
    }
    else {
        return *(str1 + i) - *(str2 + i);
    }
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c) {

    int i = -1;
    short ok = 0;
    do {
        ++i;
        if (str[i] == (char) c) {
            ok = 1;
        }
    } while (str[i] != '\0' && !ok);

    if (!ok) {
        return NULL;
    }

    return (str + i);
}

char *strrchr(const char *str, int c) {

    int i = -1;
    int last = -1;
    short ok = 0;
    do {
        ++i;
        if (str[i] == (char) c) {
            last = i;
        }
    } while (str[i] != '\0');

    if (last < 0) {
        return NULL;
    }

    return (str + last);
}

char *strstr(const char *haystack, const char *needle) {

    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    
    for (int i = 0; i < l1 - l2 + 1; ++i) {
        if (strncmp(haystack + i, needle, l2) == 0) {
            return (haystack + i);
        }
    }
    
    return NULL;
}
char *strrstr(const char *haystack, const char *needle) {

    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    
    for (int i = l1 - l2 + 1; i >= 0; --i) {
        if (strncmp(haystack + i, needle, l2) == 0) {
            return (haystack + i);
        }
    }
    
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {

    int i = 0;
    do {
        ((char *)destination)[i] = ((char *)source)[i];
        ++i;
    }while (i < num);
    
    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {

    char *dst = (char*) destination;
    char *src = (char*) source;
    
    if (dst == source) {
        return dst;
    }

    if (dst < source) {
        while (num-- > 0) {
            *dst++ = *src++;
        }
    } else {
        while (num-- > 0) {
            *(dst + num) = *(src + num);
        }
    }
    
    return dst;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    char *p1 = (char *)ptr1;
    char *p2 = (char *)ptr2;
    
    for (int i = 0; i < num; ++i) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }
    
    return 0;
}

void *memset(void *source, int value, size_t num)
{
    char *ptr = (char *)source;
    
    for (int i = 0; i < num; ++i) {
        ptr[i] = value;
    }
    
    return source;
}