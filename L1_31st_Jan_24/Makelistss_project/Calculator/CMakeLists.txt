cmake_minimum_required(VERSION 3.10)
project(MyCalculator)

add_subdirectory(my_add_lib)
add_subdirectory(my_mul_lib)

add_executable(Calc
main.cpp)

target_link_libraries(Calc my_add my_mul)