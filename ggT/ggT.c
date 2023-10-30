#include <stdio.h>

int ggT(int x, int y) {
    if(y == 0) {
        return x;
    } else {
        return ggT(y, x % y);
    }
}

int ggTTest() {
    int x = 235;
    int y = 15;
    int result = ggT(x, y);
    printf("ggT(%d, %d) = %d\n", x, y, result);
}