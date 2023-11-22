#include "primfactorZerlegung.h"
#include <stdio.h>
#include <stdlib.h>

int *primfactorZerlegung(int i) {
    int *result = malloc(sizeof(int) * 100);
    for (int j = 0; j < 100; ++j) {
        result[j] = 0;
    }
    int j = 0;
    int k = 2;
    while (i > 1) {
        if (i % k == 0) {
            result[j] = k;
            j++;
            i = i / k;
        } else {
            k++;
        }
    }
    return (result);
}

int test() {
    int *result = primfactorZerlegung(100);
    int i = 0;
    while (result[i] != 0) {
        printf("%d\n", result[i]);
        i++;
    }
    free(result);
    return 0;
}