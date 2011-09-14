#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_to_long__strtol(const char * text, long * output) {
	if (! text) return 0;
	char * end;
	long number = strtol(text, &end, 10);
	if ((end != text) && (end[0] == '\0')) {
		*output = number;
		return 1;
	}
	return 0;
}

int str_to_long__sscanf(const char * text, long * output) {
	if (! text) return 0;
	long number;
	int count = sscanf(text, "%ld", &number);
	if (count == 1) {
		*output = number;
		return 1;
	}
	return 0;
}

void show(const char * s) {
	long number_strtol = -1;
	int success_strtol = str_to_long__strtol(s, &number_strtol);
	printf("str_to_long__strtol(\"%s\") --> %2ld, success = %d\n", s, number_strtol, success_strtol);

	long number_sscanf = -1;
	int success_sscanf = str_to_long__sscanf(s, &number_sscanf);
	printf("str_to_long__sscanf(\"%s\") --> %2ld, success = %d\n", s, number_sscanf, success_sscanf);
}

void main() {
	show("");
	show(NULL);
	show("0002");
	show("2");
	show("2Hallo");
	show("+2");
	show("  2");
}
