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
        vorl1/vorl1.c
        dastr/recursive/recursive.c
        ueb4/datentypen.c
        ueb4/datentypen.h
        dastr/primzahlen/primzahlen.h
        dastr/primzahlen/primzahlen.c
        ueb5/helper.c
        ueb5/helper.h
        ueb5/calculator.c
        ueb5/calculator.h
        dastr/primfactorZerlegung/primfactorZerlegung.c
        dastr/primfactorZerlegung/primfactorZerlegung.h
        vorl2/vorl2.c
        vorl2/vorl2.h
        ueb6/rational.c
        ueb6/rational.h
        ueb6/bruchrechnung.c
        ueb6/bruchrechnung.h
        ueb7/loops.c
        ueb7/loops.h
        ueb9/prime.c
        ueb9/prime.h
        ueb9/vectors.c
        ueb9/vectors.h
        ueb9/ueb9.c
        ueb9/ueb9.h
        vorl3/matrix.c
        vorl3/matrix.h
        vorl3/vorl3.c
        vorl3/vorl3.h
)
