#include <stdio.h>

int
main() {
  int i = 3;
  int *p = &i;

  printf(" p == %#p\n"
         "*p == %d\n"
         " i == %d\n", p, *p, i);

  *p = 14;
  printf(" i == %d\n\n", i);
  return 0;
}
