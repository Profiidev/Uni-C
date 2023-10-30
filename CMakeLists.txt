cmake_minimum_required(VERSION 3.26)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C main.c
        ggT/ggT.c
        ggT/ggT.h
        ueb0/ueb0.c
        ueb0/ueb0.h
        vorl0/vorl0.h
        vorl0/vorl0.c
        ueb1/benzin.c
        ueb1/benzin.h
        dastr/sin/sinDataTable.c
        dastr/sin/sinDataTable.h
        vorl1/vorl1.c)
