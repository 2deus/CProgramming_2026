// ch5 / 5.4 Character Pointers and Functions
// Ex 5-4: strend(s, t) returns 1 if the string t occurs at the end of the
// string s, and 0 otherwise. Uses the main routine from the slides.
#include <stdio.h>

#define MAXLINE 1000

int mgetline(char s[], int lim);
int strend(char *s, char *t);
int mystrlen(char *t);

main() {
    char s[MAXLINE], t[MAXLINE];
    int ret;

    putchar('s'); putchar(':');
    mgetline(s, MAXLINE);
    putchar('t'); putchar(':');
    mgetline(t, MAXLINE);

    ret = strend(s, t);
    printf("%d\n", ret);
    return 0;
}

int strend(char *s, char *t) {
    int ls = mystrlen(s), lt = mystrlen(t);

    if (lt > ls) return 0;
    s += ls - lt;   // point s at the last lt characters
    while (*t != '\0')
        if (*s++ != *t++) return 0;
    return 1;
}

int mystrlen(char *t) {
    char *p = t;

    while (*p) p++;
    return (int)(p - t);
}

int mgetline(char s[], int lim) {   // without the newline
    int c = 0, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}
