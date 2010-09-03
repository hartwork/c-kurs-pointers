#include <stdio.h>

int main() {
    char a[] = "hallo";
    char b[] = "hallo";
    char * c = "hallo";
    char * d = "hallo";

    printf("sizeof(a)=%u, a=%p\n"
           "sizeof(b)=%u, b=%p\n"
           "sizeof(c)=%u, c=%p\n"
           "sizeof(d)=%u, d=%p\n\n",
           sizeof(a), a, sizeof(b), b,
           sizeof(c), c, sizeof(d), d);

    a[0] = 'X';
    printf("a = '%s'\n"
           "b = '%s'\n", a, b);
    c[0] = 'X';
    printf("c = '%s'\n", c);

    return 0;
}
