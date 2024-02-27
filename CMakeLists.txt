cmake_minimum_required(VERSION 3.23)
project(tre_dev)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(
        data_structures
        STATIC
        linked_list.h
        linked_list.cpp
)

add_executable(tre_dev main.cpp)
target_link_libraries(
        tre_dev
        PRIVATE
        data_structures
)

enable_testing()

add_executable(
        test_linked_list
        test_linked_list.cpp
)
target_link_libraries(
        test_linked_list
        PRIVATE
        GTest::gtest_main
        data_structures
)

include(GoogleTest)
gtest_discover_tests(test_linked_list)

