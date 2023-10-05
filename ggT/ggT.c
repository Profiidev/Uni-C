int ggT(int x, int y) {
    if(y == 0) {
        return x;
    } else {
        return ggT(y, x % y);
    }
}
