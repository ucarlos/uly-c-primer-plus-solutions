cmake_minimum_required(VERSION 3.6)
project(chapter9)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(main main.c)
add_executable(testing test.c)
add_executable(pointertest pointertest.c)
add_executable(printcolumns printcolumns.c)
add_executable(reportchar reportchar.c)
add_executable(mult mutidimarray.c)
add_executable(arrayf arrayfunction.c)