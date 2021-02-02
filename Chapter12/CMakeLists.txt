cmake_minimum_required(VERSION 3.6)
project(Chapter12)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(stringer string.c)
add_executable(main main.c)
add_executable(testcommand testcommand.c)
add_executable(sizea sizea.c)
