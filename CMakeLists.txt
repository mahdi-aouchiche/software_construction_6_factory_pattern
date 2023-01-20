cmake_minimum_required(VERSION 3.0.0)
project(CS100_Lab6 VERSION 6.0.0)

add_subdirectory(${CMAKE_BINARY_DIR}/../googletest)

set(CMAKE_CXX_STANDARD 11)

# Composit pattern
add_executable(composite_tests
    ../src/lab3_unit_tests.cpp
)
add_executable(composite_pattern
    src/main_lab3.cpp
)

# Strategy pattern
add_executable(strategy_tests
    ../src/lab4_unit_tests.cpp
)
add_executable(strategy_pattern
    src/main_lab4.cpp
    src/container.cpp
)

# Decorator pattern
add_executable(decorator_tests
    ../src/lab5_unit_tests.cpp
)
add_executable(decorator_pattern
    src/main_lab5.cpp
)

# Factory pattern
add_executable(factory_tests
    ../src/lab6_unit_tests.cpp
)
add_executable(calculator
    ../src/main_lab6.cpp
)

target_link_libraries(composite_tests gtest)
target_link_libraries(strategy_tests  gtest)
target_link_libraries(decorator_tests gtest)
target_link_libraries(factory_tests   gtest)

target_compile_definitions(composite_tests PRIVATE gtest_disable_pthreads=ON)
target_compile_definitions(strategy_tests  PRIVATE gtest_disable_pthreads=ON)
target_compile_definitions(decorator_tests PRIVATE gtest_disable_pthreads=ON)
target_compile_definitions(factory_tests   PRIVATE gtest_disable_pthreads=ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)