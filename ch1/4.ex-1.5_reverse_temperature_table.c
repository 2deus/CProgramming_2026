// ch1 / 1.3 The for statement, 1.4 Symbolic Constants
// Ex 1-5: print the temperature table in reverse order, from 300 degrees to 0.
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STAIR 20   // step size

main() {
    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STAIR)
        printf("%3d %6.1f\n", fahr, 5.0 * (fahr - 32) / 9);
    return 0;
}
