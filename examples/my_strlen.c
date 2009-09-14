#include <stdio.h>

unsigned int
my_strlen(const char *str) {
  const char *walker = str;
  while ('\0' != *walker) {
    walker++;
  }
  return (walker - str);
}

int
main() {
  printf("my_strlen(\"ABC\") == %d\n",
      my_strlen("ABC"));
  return 0;
}
