#include <assert.h>
#include <stdlib.h>  /* for NULL */
#include <stdio.h>

unsigned int
my_strlen(const char *str) {
  const char *walker = str;
  assert(str != NULL);
  while (*walker) {
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
