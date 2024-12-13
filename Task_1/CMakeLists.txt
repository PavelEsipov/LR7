cmake_minimum_required(VERSION 3.5.1)

project(Task_1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

add_executable(Task_1 Task_1.cpp perevod.cpp Header.h)
