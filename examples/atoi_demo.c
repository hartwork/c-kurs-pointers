#include <stdio.h>
#include <stdlib.h>

void show(const char * s) {
	printf("atoi(\"%s\") == %d\n", s, atoi(s));
}

void main() {
	show("0002");
	show("2");
	show("2Hallo");
	show("+2");
	show("  2");
}
