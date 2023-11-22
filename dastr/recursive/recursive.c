int fib(int n) {
    return n == 0 ? 0 : n == 1 ? 0 : fib(n-1) + fib(n-2);
}

int hanoi(int n) {
    return n == 0 ? 0 : 2 * hanoi(n - 1) + 1;
}