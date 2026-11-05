// ch1 / 1.2 Variables and Arithmetic Expressions
// Ex 1-4: print the corresponding Celsius to Fahrenheit table.
// F = 9 * C / 5 + 32 (floating point, written as C * 1.8 + 32)
#include <stdio.h>

#define FLOOR   0
#define CEILING 300
#define STAIR   20   // step size

double c2f(double cels) {   // Celsius -> Fahrenheit
    return (cels * 1.8) + 32;
}

main() {
    double fahr, cels;
    int lower, upper, step;

    lower = FLOOR;
    upper = CEILING;
    step = STAIR;

    cels = (double) lower;

    printf("celsius\t\tfahrenheit\n\n");   // header
    printf("----------------------------------\n\n");

    while (cels <= (double) upper) {
        fahr = c2f(cels);
        printf("%g C\t\t%g F\n", cels, fahr);
        cels += (double) step;
    }
    return 0;
}
