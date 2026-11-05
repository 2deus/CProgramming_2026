// ch4 / 4.1 Basics of Functions
// Print each input line that contains the pattern "ould".
// The job is split into three functions:
//   while (there's another line)           -> mgetline
//       if (the line contains the pattern) -> strindex
//           print it                       -> printf
// main returns the number of matching lines.
#include <stdio.h>

#define MAXLINE 1000   // max input line length

int mgetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";   // pattern to search for

main() {
    char line[MAXLINE];
    int found = 0;

    while (mgetline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int mgetline(char s[], int lim) {
    int c = 0, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[]) {   // index of t in s, -1 if none
    int i, j, k;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0') return i;   // whole of t matched
    }
    return -1;
}
