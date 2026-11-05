// ch1 / 1.9 Character Arrays
// Read a set of text lines and print the longest.
// while (there's another line)
//  if (it's longer than the previous longest)
//      save it and its length
// print longest line
#include <stdio.h>

#define MAXLINE 1000 // max line length

int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

main() {
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = mgetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) printf("%s", longest); // non-empty line
    return 0;
}

int mgetline(char line[], int maxline) {
    int c = 0, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0'; // mark string end
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
