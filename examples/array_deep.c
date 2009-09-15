void demo_deep(int * const *a) {
  a[1][2] *= 2;
}

int main() {
  int row0[] = {0, 1, 2};
  int row1[] = {3, 4, 5};
  int * const d[] = {row0, row1};
  demo_deep(d);
  return 0;
}
