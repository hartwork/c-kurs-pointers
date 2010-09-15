#include <stdio.h>
#define T(x)  puts(">>> " #x); x

int main() {
  int i = 3;
  int * p = &i;

  printf("i == %d, p == %p\n", i, p);
  T(*p = 4;)
  printf("i == %d, p == %p\n", i, p);
  T(p = 5;)
  printf("i == %d, p == %p\n", i, p);

  return 0;
}
