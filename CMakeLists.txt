cmake_minimum_required(VERSION 3.20.0)
project(mini-c-lib)

enable_testing()
include(CTest)

add_library(mini-c-lib
    "src/str.c"
    "src/vec.c"
)
target_include_directories(mini-c-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(str-test-bin
    "test/str_test.c"
)
target_link_libraries(str-test-bin PRIVATE mini-c-lib)
add_test(NAME str-test COMMAND str-test-bin)

add_executable(vec-test-bin
    "test/vec_test.c"
)
target_link_libraries(vec-test-bin PRIVATE mini-c-lib)
add_test(NAME vec-test COMMAND vec-test-bin)
