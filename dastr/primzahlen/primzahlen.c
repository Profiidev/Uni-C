#include <stdio.h>

int primzahlen() {
    int i, j, n = 200000;
    int prim[n];
    for (i = 0; i < n; i++) {
        prim[i] = 1;
    }
    for (i = 2; i < n; i++) {
        if (prim[i]) {
            for (j = i + i; j < n; j += i) {
                prim[j] = 0;
            }
            if(i * i > n) break;
        }
    }
    for (i = 2; i < n; i++) {
        if (prim[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}

#include "primzahlen.h"
