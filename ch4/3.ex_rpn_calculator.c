// ch4 / 4.3 External Variables
// Reverse Polish (postfix) calculator, single-file version.
// Infix (1 - 2) * (4 + 5) is entered as:   1 2 - 4 5 + *
// The result is printed at the end of each line.
// The stack (sp, val) and the pushback buffer (buf, bufp) are external
// variables: push/pop and getch/ungetch share them, main never touches them.
#include <stdio.h>
#include <stdlib.h>   // atof()
#include <ctype.h>    // isdigit()

#define MAXOP   100   // max size of operand or operator
#define NUMBER  '0'   // signal that a number was found
#define MAXVAL  100   // max depth of val stack
#define BUFSIZE 100   // size of the ungetch buffer

int getop(char s[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int c);

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
        case '-':   // order matters: pop the right operand first
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

int sp = 0;           // next free stack position
double val[MAXVAL];   // value stack

void push(double f) {
    if (sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0) return val[--sp];
    printf("error: stack empty\n");
    return 0.0;
}

int getop(char s[]) {   // next operator or numeric operand
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')   // skip blanks
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') return c;   // not a number
    i = 0;
    if (isdigit(c))   // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')     // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) ungetch(c);   // read one char too far: push it back
    return NUMBER;
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
