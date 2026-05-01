#include "vuln.h"

int add_nums(int a, int b) {
    return a + b;
}

int sum_bytes(const char* input, int len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += (unsigned char)input[i];
    }
    return total;
}

int copy_into_fixed_buf(const char* input, int len) {
    char buf[16];

    for (int i = 0; i < len; i++) {
        buf[i] = input[i];   // intentionally unsafe
    }

    return (unsigned char)buf[0];
}