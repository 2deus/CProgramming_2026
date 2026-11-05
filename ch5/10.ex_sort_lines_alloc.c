// ch5 / 5.6 Pointer Arrays; Pointers to Pointers
// Sort input lines into alphabetic order.
// lineptr[] is an array of pointers to char: lineptr[i] points to the i-th
// line. Sorting exchanges the pointers, not the text of the lines.
// Storage for the lines comes from alloc(), a simple static memory
// allocator (allocbuf + allocp) shown in the slides.
// Input ends with EOF (Ctrl+Z then Enter on Windows).
#define _CRT_SECURE_NO_WARNINGS   // allow strcpy in Visual Studio
#include <stdio.h>
#include <string.h>

#define MAXLINES  5000    // max #lines to be sorted
#define MAXLEN    1000    // max length of any input line
#define ALLOCSIZE 10000   // size of available space

char *lineptr[MAXLINES];  // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *v[], int left, int right);
int mgetline(char *s, int lim);
char *alloc(int n);

main() {
    int nlines;           // number of input lines read

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myqsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines) {   // store each line with alloc
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';   // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j) {   // only the pointers move
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// K&R qsort, renamed so it does not clash with qsort from <stdlib.h>
void myqsort(char *v[], int left, int right) {
    int i, last;

    if (left >= right) return;   // fewer than two elements
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; ++i)
        if (strcmp(v[i], v[left]) < 0) swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}

int mgetline(char *s, int lim) {   // newline is always kept
    int c = 0, i;

    for (i = 0; i < lim - 2 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n' || (c == EOF && i > 0)) s[i++] = '\n';   // also accept last line without '\n'
    s[i] = '\0';
    return i;
}

static char allocbuf[ALLOCSIZE];   // storage for alloc
static char *allocp = allocbuf;    // next free position

char *alloc(int n) {               // pointer to n chars, or NULL if no room
    if (allocbuf + ALLOCSIZE - allocp >= n) {   // it fits
        allocp += n;
        return allocp - n;                      // old p
    } else return NULL;
}

void afree(char *p) {              // must be freed in reverse order
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) allocp = p;
}
