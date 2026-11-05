// ch5 / 5.4 Character Pointers and Functions
// Ex 5-3: pointer version of strcat(s, t), which copies the string t to the
// end of s. Uses the main routine from the slides: type s, then t.
#include <stdio.h>

#define MAXLINE 1000

int mgetline(char line[], int lim);
void mystrcat(char *s, char *t);

main() {
    char s[MAXLINE * 2], t[MAXLINE];

    putchar('s'); putchar(':');
    mgetline(s, MAXLINE);
    putchar('t'); putchar(':');
    mgetline(t, MAXLINE);

    mystrcat(s, t);
    printf("%s\n", s);
    return 0;
}

void mystrcat(char *s, char *t) {   // s must be big enough
    while (*s) s++;                 // find end of s
    while ((*s++ = *t++) != '\0')   // copy t
        ;
}

int mgetline(char s[], int lim) {   // without the newline
    int c = 0, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}
