#include <stdio.h>
#define T(x)  puts(">>> " #x); x

int main() {
  int i = 3;
  int * p = &i;

  printf("i == %d, p == %p\n", i, p);
  T(*p = 0;)
  printf("i == %d, p == %p\n", i, p);
  T(p = 0;)
  printf("i == %d, p == %p\n", i, p);

  return 0;
}
