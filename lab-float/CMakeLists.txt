cmake_minimum_required(VERSION 3.30)
project(laba2 C)

set(CMAKE_C_STANDARD 23)

add_executable(laba2 main.c
        round.c
        round.h
        types.h
        tests.c
        tests.h)
