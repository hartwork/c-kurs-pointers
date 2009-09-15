void demo_flat(int a[][3]) {
  a[1][2] *= 2;
}

int main() {
  int f[][3] = { {0, 1, 2},
                 {3, 4, 5} };
  demo_flat(f);
  return 0;
}
