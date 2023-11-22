#include "helper.h"

// TODO: Funktionsdefinitionen hier einfügen






















double csum(double a, double b) {
    return a + b;
}

double negate(double a) {
    return -a;
}

double cpow2(int exp, double basis, double acc) {
    if(exp > 0) {
        acc = basis * acc;
        exp = exp - 1;
        return cpow2(exp, basis, acc);
    }
    return acc;
}
