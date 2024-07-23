cmake_minimum_required(VERSION 3.10)

project(Conpyrus C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(my_executable src/main.c)

target_include_directories(my_executable PRIVATE include)