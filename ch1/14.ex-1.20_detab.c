// ch1 / 1.9 Character Arrays
// Ex 1-20: detab - replace tabs in the input with the proper number of
// blanks to space to the next tab stop (every TABSTOP columns).
#include <stdio.h>

#define TABSTOP 8
#define BLANK '_'   // spaces in tab get replaced with this

main() {
    int c, n, col = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            n = TABSTOP - (col % TABSTOP);  // n more blanks needed to count as tabstop
            while (n-- > 0) {
                putchar(BLANK);
                ++col;
            }
        } else {
            putchar(c);
            if (c == '\n')  col = 0;
            else            ++col;
        }
    }
    return 0;
}
