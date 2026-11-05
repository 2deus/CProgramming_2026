// ch1 / 1.5.4 Word Counting
// Count lines, words and characters in the input, using a state variable
// that remembers whether we are currently inside a word.
// Input ends with EOF (Ctrl+Z then Enter on Windows, Ctrl+D on Linux).
#include <stdio.h>

main() {
    int c, nl, nw, nc, inword;

    nl = nw = nc = inword = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            inword = 0;
        else if (inword == 0) {   // first character of a new word
            inword = 1;
            ++nw;
        }
    }
    printf("\n\nlines  = %d, words = %d, chars = %d\n", nl, nw, nc);
    return 0;
}
