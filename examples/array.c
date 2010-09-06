#include <stdio.h>

void dump(const int* data, int count) {
  int i = 0;
  for (; i < count; ++i) {
    printf("Field %d: %d\n", i + 1, *(data + i));
  }
}

int main() {
  int const primes[] = {2, 3, 5, 7, 11};
  dump(primes, sizeof(primes) / sizeof(int));
  return 0;
}
