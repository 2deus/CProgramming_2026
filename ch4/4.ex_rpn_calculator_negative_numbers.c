// ch4 / 4.3 External Variables
// Reverse Polish calculator, version that also accepts negative numbers
// (part of Ex 4-3). A '-' directly followed by a digit is the sign of a
// number; a '-' on its own is the subtraction operator.
// Example input:  10 -5 + 100 + 2 *   prints 210
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>   // atof()
#include <string.h>   // strcmp()

#define MAXOP   100   // max size of operand or operator
#define NUMBER  '0'   // signal that a number was found
#define BUFSIZE 100
#define MAXVAL  100   // max depth of val stack

int sp = 0;           // stack pointer: outside any function, so main
int bufp = 0;         // does not see the stack representation

double val[MAXVAL];   // value stack
char buf[BUFSIZE];    // buffer for ungetch

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
double pop(void);

main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop() / op2);
            else printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void push(double f) {
    if (sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0) return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

int getop(char s[]) {   // numbers may start with '-'
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') return c;   // not a number
    i = 0;
    if (c == '-' || isdigit(c))   // collect integer part along with '-'
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')                 // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    if (strcmp(s, "-") == 0) return '-';   // lone '-' is the minus operator
    return NUMBER;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}

int getch(void) {   // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}
