// ch1 / 1.10 External Variables and Scope
// Longest-line program, specialized version: line, longest and max are
// external (global) variables shared by all functions instead of arguments.
#include <stdio.h>

#define MAXLINE 1000   // max line length

int max;
char line[MAXLINE], longest[MAXLINE];

int mgetline(void);
void copy(void);

main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = mgetline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0) printf("%s", longest); // non-empty line
    return 0;
}

int mgetline(void) {
    int c = 0, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(void) {
    int i = 0;
    extern char line[], longest[];

    while ((longest[i] = line[i]) != '\0') ++i;
}
