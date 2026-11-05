// ch5 / 5.2 Pointers and Function Arguments
// swap_wrong(x, y) gets copies of the values (call by value), so the caller's
// variables do not change. swap(px, py) gets their addresses (call by
// reference) and exchanges the values through the pointers.
#include <stdio.h>

void swap_wrong(int x, int y) {   // only swaps the local copies
    int temp;

    temp = x;
    x = y;
    y = temp;
}

void swap(int *px, int *py) {     // interchange *px and *py
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

main() {
    int a = 1, b = 2;

    swap_wrong(a, b);
    printf("after swap_wrong(a, b): a=%d b=%d\n", a, b);   // unchanged
    swap(&a, &b);                                          // pass addresses
    printf("after swap(&a, &b):     a=%d b=%d\n", a, b);   // a=2 b=1
    return 0;
}
