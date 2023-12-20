#include "vectors.h"
#include <math.h>
#include <stdio.h>


double normL2(struct Vector2_s * vec) {
    return sqrt(vec->x * vec->x + vec->y * vec->y);
}

int argMin(struct Vector2_s * data, int start, int end) {
    int min = start;
    for (int i = start; i <= end; i++) {
        if (normL2(&data[i]) < normL2(&data[min])) {
            min = i;
        }
    }

    return min;
}


void swap(struct Vector2_s * a, struct Vector2_s * b) {
    struct Vector2_s tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(struct Vector2_s data[], int n) {
    for (int i = 0; i < n; i++) {
        int min = argMin(data, i, n - 1);
        swap(&data[i], &data[min]);
    }
}


void printVectorArray(struct Vector2_s data[], int n) {
    printf("\nVectorArray:\n");
    for(int i = 0; i < n; i++) {
        printf("Index: %d\t [Vector2f x = %4.1f\t y = %4.1f\t normL2 = %4.1f]\n", i, data[i].x, data[i].y, normL2(&data[i]));
    }
}