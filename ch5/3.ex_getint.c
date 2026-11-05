// ch5 / 5.2 Pointers and Function Arguments
// getint(pn): free-format input conversion. Breaks the input stream into
// integers, one per call. The number is returned through the pointer pn;
// the return value is EOF, 0 (not a number) or positive (a number was read).
// Example input:  12 -7 +30 abc 4   (stops at "abc")
#include <stdio.h>
#include <ctype.h>

#define SIZE    10
#define BUFSIZE 100

int getch(void);
void ungetch(int);

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))   // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                // not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF) ungetch(c);
    return c;
}

main() {
    int n, i, count, array[SIZE];

    // &array[n] is the address where getint stores the next number
    for (n = 0; n < SIZE && getint(&array[n]) > 0; ++n)
        ;
    count = n;
    printf("read %d numbers:", count);
    for (i = 0; i < count; ++i) printf(" %d", array[i]);
    printf("\n");
    return 0;
}

char buf[BUFSIZE];   // buffer for ungetch
int bufp = 0;        // next free position in buf

int getch(void) {    // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}
