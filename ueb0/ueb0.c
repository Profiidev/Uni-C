#include <stdio.h>
#include <math.h>

//pow function
int pow_(int base, int exp) {
    int result = 1;
    while (exp) {
        result *= base;
        exp--;
    }
    return result;
}

//pow recursive function
int pow_rec_(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * pow_rec_(base, exp - 1);
}

//main function
int main_() {
    int base = 2;
    int exp = 3;
    int result = pow_(base, exp);
    printf("%d^%d = %d\n", base, exp, result);
    result = pow_rec_(base, exp);
    printf("%d^%d = %d\n", base, exp, result);
    return 0;
}