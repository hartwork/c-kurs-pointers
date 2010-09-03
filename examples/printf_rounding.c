#include <stdio.h>

int main() {
    float const f = 3.141592653f;
    printf("%%.10f -> %.10f\n"
           "   %%f -> %f\n"
           " %%.4f -> %.4f\n", f, f, f);
    return 0;
}
