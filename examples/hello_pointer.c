#include <stdio.h>

int main() {
  int i = 3;
  int* p = &i;

  printf("i == %d, p == %p\n", i, p);

  *p = 14;
  printf("i == %d\n", i);

  return 0;
}
