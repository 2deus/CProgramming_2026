// ch5 / 5.4 Character Pointers and Functions
// Ex 5-5: versions of the library functions strncpy, strncat and strncmp,
// which work on at most the first n characters of their argument strings.
#include <stdio.h>

void mystrncpy(char *s, char *t, int n) {   // pad with '\0' if t is shorter
    while (n > 0 && *t != '\0') {
        *s++ = *t++;
        n--;
    }
    while (n-- > 0) *s++ = '\0';
}

void mystrncat(char *s, char *t, int n) {   // always ends with '\0'
    while (*s) s++;
    while (n-- > 0 && *t != '\0') *s++ = *t++;
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n) {
    for (; n > 0; s++, t++, n--) {
        if (*s != *t) return *s - *t;
        if (*s == '\0') return 0;
    }
    return 0;
}

main() {
    char buf[50] = "";
    char s[50] = "hello";

    mystrncpy(buf, "programming", 7);
    buf[7] = '\0';   // strncpy does not always add '\0'
    printf("mystrncpy(\"programming\", 7) = \"%s\"\n", buf);   // program

    mystrncat(s, ", world!!!", 7);
    printf("mystrncat(\"hello\", \", world!!!\", 7) = \"%s\"\n", s);   // hello, world

    printf("mystrncmp(\"abcdef\", \"abcxyz\", 3) = %d\n", mystrncmp("abcdef", "abcxyz", 3));  // 0
    printf("mystrncmp(\"abcdef\", \"abcxyz\", 4) = %d\n", mystrncmp("abcdef", "abcxyz", 4));  // <0
    return 0;
}
