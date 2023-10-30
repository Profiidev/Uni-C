#include <stdio.h>
#include <math.h>

void sinDataTable() {
    double x = -M_PI_2;
    while (x <= M_PI_2) {
        printf("sin(%f) = %f\n", x, sin(x));
        //printf("arcsin(%f) = %f\n", sin(x), asin(sin(x)));
        x += 0.1;
    }
}