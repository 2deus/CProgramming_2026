// ch1 / 1.5.3 Line Counting
// Ex 1-8: count blanks, tabs and newlines in the input.
// Input ends with EOF (Ctrl+Z then Enter on Windows).
#include <stdio.h>

main() {
    int c, nl, t, sp;   // c, newline, tab, space

    nl = t = sp = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') ++nl;
        else if (c == '\t') ++t;
        else if (c == ' ')  ++sp;
    }
    printf("\n\nnewlines = %d, tabs = %d, spaces = %d\n", nl, t, sp);
    return 0;
}
