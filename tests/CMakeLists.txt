cmake_minimum_required(VERSION 3.2)

## Usage: add_unique_test(<test_name> <source_files>)
macro(add_unique_test arg1 arg2)
    add_executable(test_${arg1} ${arg2})
    target_link_libraries(test_${arg1})
endmacro(add_unique_test)

## Compiler Flags
add_compile_options(-std=c++11)


add_unique_test("circular_array" "containers/circular_array/test_circular_array.cpp")

add_unique_test("filter_core"   "filter/core/test_core.cpp")
add_unique_test("filter_kalman" "filter/kalman/test_kalman.cpp")

add_unique_test("hash_core"     "hash/core/test_core.cpp")
add_unique_test("hash_cexpr"    "hash/cexpr/test_cexpr.cpp")

add_unique_test("log_core"      "log/core/test_core.cpp")

add_unique_test("math_core"     "math/core/test_core.cpp")

add_unique_test("singleton"     "singleton/test_singleton.cpp")

add_unique_test("terminal_style"    "terminal/style/test_style.cpp")
add_unique_test("terminal_commands" "terminal/commands/test_commands.cpp")
