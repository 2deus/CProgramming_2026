// ch4 / 4.5 Header Files
// calc.h: shared definitions for the multi-file calculator.
// Every .c file includes "calc.h" so they all agree on the constants and
// function prototypes. The #ifndef guard stops it being included twice (4.11.3).
#ifndef CALC_H
#define CALC_H

#define NUMBER '0'   // signal that a number was found
#define NAME   'n'   // signal that a name (sin, exp, pow) was found

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);

#endif // CALC_H
