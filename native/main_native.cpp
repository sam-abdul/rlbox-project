#include <iostream>
#include "../libvuln/vuln.h"

int main() {
    const char* small = "hello";
    const char* large = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

    std::cout << "Safe function result: "
              << sum_bytes(small, 5) << std::endl;

    std::cout << "Unsafe function (safe input): "
              << copy_into_fixed_buf(small, 5) << std::endl;

    std::cout << "Unsafe function (overflow input): "
              << copy_into_fixed_buf(large, 40) << std::endl;

    return 0;
}