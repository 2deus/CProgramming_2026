// ch1 / 1.7 Functions
// Ex 1-15: rewrite the temperature conversion program of section 1.2
// to use a function for the conversion.
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STAIR  20

float f2c(float fahr);

main() {
    float fahr;

    printf("Fahrenheit  Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STAIR)
        printf("%10.0f %8.1f\n", fahr, f2c(fahr));
    return 0;
}

float f2c(float fahr) {
    return 5.0f * (fahr - 32.0f) / 9.0f;
}
