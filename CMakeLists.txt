cmake_minimum_required(VERSION 3.0.0)
project(CS100_Lab6 VERSION 6.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

# Composit pattern
add_executable(lab3_tests
    ../src/lab3_unit_tests.cpp
)
add_executable(lab3
    src/main_lab3.cpp
)

# Strategy pattern
add_executable(lab4_tests
    ../src/lab4_unit_tests.cpp
)
add_executable(lab4
    src/main_lab4.cpp
    src/container.cpp
)

# Decorator pattern
add_executable(lab5_tests
    ../src/lab5_unit_tests.cpp
)
add_executable(lab5
    src/main_lab5.cpp
)

# Factory pattern
add_executable(lab6_tests
    ../src/lab6_unit_tests.cpp
)
add_executable(calculator
    ../src/main_lab6.cpp
)

target_link_libraries(lab3_tests gtest)
target_link_libraries(lab4_tests gtest)
target_link_libraries(lab5_tests gtest)
target_link_libraries(lab6_tests gtest)

target_compile_definitions(lab3_tests PRIVATE gtest_disable_pthreads=ON)
target_compile_definitions(lab4_tests PRIVATE gtest_disable_pthreads=ON)
target_compile_definitions(lab5_tests PRIVATE gtest_disable_pthreads=ON)
target_compile_definitions(lab6_tests PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)