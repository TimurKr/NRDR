cmake_minimum_required(VERSION 3.24)
project(projekt C)

set(CMAKE_C_STANDARD 11)


add_executable(EEM EEM.c)
add_executable(RK2 RK2.c)
add_executable(RK3 RK3.c)
add_executable(RK4 RK4.c)
add_executable(AM3 AM3.c)

