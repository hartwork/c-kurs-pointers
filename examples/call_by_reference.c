#include <stdio.h>

void by_value    (int  x) {  x += 3; }
void by_reference(int* x) { *x += 4; }

int main() {
  int i = 0;

  by_value(i);
  printf("i == %d\n", i);
  by_reference(&i);
  printf("i == %d\n", i);

  return 0;
}
