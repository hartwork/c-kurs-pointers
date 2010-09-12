#include <stdio.h>

void by_value    (int  j) {  j += 3; }
void by_reference(int* p) { *p += 4; }

int main() {
  int i = 0;

  by_value(i);
  printf("i == %d\n", i);
  by_reference(&i);
  printf("i == %d\n", i);

  return 0;
}
