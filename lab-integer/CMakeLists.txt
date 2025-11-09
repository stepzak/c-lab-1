cmake_minimum_required(VERSION 3.30)
project(lab1 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab1 main.c
        tests.c
        tests.h
        calc.c
        calc.h
        types.h
)

target_link_libraries(lab1 m)
