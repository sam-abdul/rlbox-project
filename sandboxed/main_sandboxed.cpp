#define RLBOX_WASM2C_MODULE_NAME vuln

#define w2c_0x24vuln0x2Ewasm w2c_vuln
#define wasm2c_0x24vuln0x2Ewasm_instantiate wasm2c_vuln_instantiate
#define wasm2c_0x24vuln0x2Ewasm_free wasm2c_vuln_free
#define wasm2c_0x24vuln0x2Ewasm_get_func_type wasm2c_vuln_get_func_type
#define w2c_0x24vuln0x2Ewasm_malloc w2c_vuln_malloc
#define w2c_0x24vuln0x2Ewasm_free w2c_vuln_free
#define w2c_0x24vuln0x2Ewasm_memory w2c_vuln_memory
#define w2c_0x24vuln0x2Ewasm_0x5F_indirect_function_table w2c_vuln_0x5F_indirect_function_table
#define w2c_0x24vuln0x2Ewasm_add_nums w2c_vuln_add_nums
#define w2c_0x24vuln0x2Ewasm_sum_bytes w2c_vuln_sum_bytes
#define w2c_0x24vuln0x2Ewasm_copy_into_fixed_buf w2c_vuln_copy_into_fixed_buf

#include <iostream>
#include <cstring>

#define RLBOX_SINGLE_THREADED_INVOCATIONS
#define RLBOX_USE_STATIC_CALLS() rlbox_wasm2c_sandbox_lookup_symbol

#include "../generated/vuln.wasm.h"
#include "rlbox.hpp"
#include "rlbox_wasm2c_sandbox.hpp"

extern "C" {
#include "../libvuln/vuln.h"
}

using namespace rlbox;
RLBOX_DEFINE_BASE_TYPES_FOR(vuln, wasm2c);

int main() {
    rlbox_sandbox_vuln sandbox;
    sandbox.create_sandbox();

    std::cout << "=== RLBox Sandboxed Demo ===" << std::endl;

    auto add_result = sandbox.invoke_sandbox_function(add_nums, 10, 20);
    int add_value = add_result.unverified_safe_because(
        "add_nums only returns a demo integer"
    );

    std::cout << "Sandboxed add_nums result: " << add_value << std::endl;

    const char* small = "hello";
    int small_len = 5;

    auto sandbox_small = sandbox.malloc_in_sandbox<char>(small_len + 1);
    rlbox::strncpy(sandbox, sandbox_small, small, small_len + 1);

    auto sum_result = sandbox.invoke_sandbox_function(
        sum_bytes,
        sandbox_small,
        small_len
    );

    int sum_value = sum_result.unverified_safe_because(
        "sum_bytes returns a bounded demo integer"
    );

    std::cout << "Sandboxed sum_bytes result: " << sum_value << std::endl;

    auto safe_copy_result = sandbox.invoke_sandbox_function(
        copy_into_fixed_buf,
        sandbox_small,
        small_len
    );

    int safe_copy_value = safe_copy_result.unverified_safe_because(
        "copy_into_fixed_buf returns first byte of safe input"
    );

    std::cout << "Sandboxed unsafe function with safe input: "
              << safe_copy_value << std::endl;

    sandbox.free_in_sandbox(sandbox_small);

    const char* large = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    int large_len = 40;

    auto sandbox_large = sandbox.malloc_in_sandbox<char>(large_len + 1);
    rlbox::strncpy(sandbox, sandbox_large, large, large_len + 1);

    std::cout << "Overflow test prepared but skipped in main demo because wasm2c traps abort the process." << std::endl;
    std::cout << "Use native_app to show the crash baseline." << std::endl;

    sandbox.free_in_sandbox(sandbox_large);

    sandbox.destroy_sandbox();

    std::cout << "Host program survived sandboxed execution." << std::endl;

    return 0;
}