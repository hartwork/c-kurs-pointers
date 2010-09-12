#include <stdio.h>

int my_strlen(const char * str) {
  char const * const begin = str;
  while (*str) {
    str++;
  }
  return (str - begin);
}

int main() {
  printf("my_strlen(\"ABC\") == %d\n",
      my_strlen("ABC"));
  return 0;
}
