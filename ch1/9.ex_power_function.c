// ch1 / 1.7 Functions, 1.8 Arguments - Call by Value
// power(m, n) raises integer m to a positive integer power n.
// n is a copy of the caller's value (call by value), so changing it
// inside power() does not affect the caller.
#include <stdio.h>

int power(int base, int n);   // prototype

main() {
    int i;

    for (i = 0; i < 10; ++i) printf("%d %3d %6d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int n) {
    int p;

    for (p = 1; n > 0; --n) p = p * base;
    return p;
}
