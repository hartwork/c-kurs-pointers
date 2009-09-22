#include <stdio.h>

#include <assert.h>
#include <string.h>

void
write_and_advance(char **write, const char *text) {
    strcpy(*write, text);
    *write += strlen(text);
}

int
copy_escape_xml(char *output, const char *input) {
    const char *read = input;
    char *write = output;

    assert(input != NULL);
    assert(output != NULL);

    for (;;) {
        switch (read[0]) {
        case '\0':
            write[0] = '\0';
            return write - output;  /* == strlen(output) */
        case '&':
            write_and_advance(&write, "&amp;");
            break;
        case '<':
            write_and_advance(&write, "&lt;");
            break;
        case '>':
            write_and_advance(&write, "&gt;");
            break;
        case '\'':
            write_and_advance(&write, "&apos;");
            break;
        case '"':
            write_and_advance(&write, "&quot;");
            break;
        default:
            *(write++) = read[0];
        }
        read++;
    }
}

void
single_slashes(char *input_output) {
    const char *read = input_output;
    char *write = input_output;

    assert(input_output != NULL);

    for (;;) {
        switch (read[0]) {
        case '\0':
            write[0] = '\0';
            return;
        case '/':
            {
                /* Advance after last slash in sequence */
                read++;
                while (read[0] == '/') {
                    read++;
                }
                write[0] = '/';
                write++;
                break;
            }
        default:
            *(write++) = read[0];
            read++;
        }
    }
}


int
main() {
    char escape_input[] = "Kernighan & Ritchie";
    char escape_output[255];
    char slash_input_output[] = "/usr//bin///env";
    copy_escape_xml(escape_output, escape_input);
    single_slashes(slash_input_output);

    printf("copy_escape_xml --> \"%s\"\n", escape_output);
    printf("single_slashes --> \"%s\"\n", slash_input_output);

    return 0;
}
