// ch1 / 1.2 Variables and Arithmetic Expressions
// Ex 1-3: print a Fahrenheit-Celsius table with a heading above it.
// C = 5 * (F - 32) / 9
#include <stdio.h>

#define FLOOR   0
#define CEILING 300
#define STAIR   20   // step size

double f2c(double fahr) {   // Fahrenheit -> Celsius
    return 5 * (fahr - 32) / 9;
}

main() {
    double fahr, cels;
    int lower, upper, step;

    lower = FLOOR;
    upper = CEILING;
    step = STAIR;

    fahr = (double) lower;

    printf("fahrenheit\tcelsius\n\n");   // header
    printf("----------------------------------\n\n");

    while (fahr <= (double) upper) {
        cels = f2c(fahr);
        printf("%g F\t\t%g C\n", fahr, cels);
        fahr += (double) step;
    }
    return 0;
}
