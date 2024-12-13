cmake_minimum_required(VERSION 3.10)
project(Task_5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-fsanitize=address")

include_directories(include)
add_executable(Task_5 Task_5.cpp funcs.cpp Header.h)