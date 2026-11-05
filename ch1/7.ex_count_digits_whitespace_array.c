// ch1 / 1.6 Arrays
// Count the occurrences of each digit, of white space characters
// (blank, tab, newline) and of all other characters.
#include <stdio.h>

main() {
    int c, i, nwhite, nother;
    int ndigit[10] = {0};   // zero the array

    nwhite = nother = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];   // index array with char code
        else if (c == ' ' || c == '\n' || c == '\t') ++nwhite;
        else ++nother;
    }

    printf("digits (ascending order) = ");
    for (i = 0; i < 10; ++i) printf(" %d", ndigit[i]);

    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}