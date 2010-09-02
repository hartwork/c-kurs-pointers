#include <errno.h> /* for errno */
#include <stdlib.h> /* for strtod */
#include <string.h> /* for strlen */
#include <stdio.h> /* for printf */

int string_to_double(char const *text, double *output) {
    char * after_last;
    double number;

    errno = 0;
    number = strtod(text, &after_last);

    if ((number == 0.0)
            && ((after_last == text)
                || (errno == EINVAL))) {
        return 1;
    }

    if (errno == ERANGE) {
        return 2;
    }

    if (after_last != text + strlen(text)) {
        return 3;
    }

    *output = number;
    return 0;
}

int main() {
    double d;
    int const error = string_to_double("4.567", &d);

    printf("Error: %s\n"
        "Result: %f\n",
        error ? "yes" : "no",
        d);
    return 0;
}
