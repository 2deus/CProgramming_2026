// ch4 / 4.4 Scope Rules
// stack.c: the value stack of the calculator.
// sp and val are external variables, but only used in this file,
// so the other files never see how the stack is stored.
#include <stdio.h>
#include "calc.h"

#define MAXVAL 100    // max depth of val stack

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
