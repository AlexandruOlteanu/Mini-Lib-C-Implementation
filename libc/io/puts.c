#include <stddef.h>
#include <internal/syscall.h>
#include <unistd.h>

#define ZERO 0
#define true 1

int puts(const char *str) {

    size_t length = ZERO;
    do {
        if (str[length] != '\0') {
            ++length;
        }
        else {
            break;
        }
    } while (true);


    int result = syscall(__NR_write, 1, str, length);

    int inter_value = syscall(__NR_write, 1, "\n", 1);

    result += inter_value;

    return result;

}