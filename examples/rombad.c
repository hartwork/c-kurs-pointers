#include <stdio.h>

int main() {
  char * a = "hallo";
  char * b = "hallo";

  printf("a=%p\n"
         "b=%p\n", a, b);

  a[0] = 'X';

  return 0;
}
