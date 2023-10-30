#include <stdio.h>

int vorl1() {
    float a, b, tmp;
    printf("Bitte geben Sie zwei Zahlen ein: \n");
    scanf("%f %f", &a, &b);
    printf("a = %f, b = %f\n", a, b);
    tmp = a;
    a = b;
    b = tmp;
    printf("a = %f, b = %f\n", a, b);
    return 0;
}