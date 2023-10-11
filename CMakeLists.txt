cmake_minimum_required(VERSION 3.26)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C main.c
        ggT/ggT.c
        ggT/ggT.h
        ueb0/ueb0.c
        ueb0/ueb0.h)
