#include <stdio.h>

void demo_deep(int * const *a) {
  a[1][2] *= 2;
}

void demo_flat(int a[][3]) {
  a[1][2] *= 2;
}

int main() {
  int f[][3] = {
    {0, 1, 2},
    {3, 4, 5}
  };
  int * const d[] = {f[0], f[1]};
  demo_deep(d);
  demo_flat(f);
  printf("d[1][2] = %d\n", d[1][2]);
  printf("f[1][2] = %d\n", f[1][2]);
  return 0;
}
