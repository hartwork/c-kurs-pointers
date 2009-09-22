#include <stdio.h>
#include <assert.h>

void mult(
        const int * const *a,
        const int * const *b,
        int * const *result,
        int rows_a,
        int cols_a,
        int cols_b) {
    int row = 0;
    for (; row < rows_a; ++row) {
        int col = 0;
        for (; col < cols_b; ++col) {
            int i = 0;
            result[row][col] = 0;
            for (; i < cols_a; ++i) {
                result[row][col] += a[row][i] * b[i][col];
            }
        }
    }
}

int main() {
    const int a0[] = {1, 0};
    const int a1[] = {4, 3};
    const int a2[] = {2, 5};
    const int *a[] = {a0, a1, a2};

    const int b0[] = {6, 3, 4, 2};
    const int b1[] = {7, 1, 0, 5};
    const int *b[] = {b0, b1};

    int c0[4], c1[4], c2[4];
    int * const result[] = {c0, c1, c2};

    const int d0[] = { 6,  3,  4,  2};
    const int d1[] = {45, 15, 16, 23};
    const int d2[] = {47, 11,  8, 29};
    const int * const expected[] = {d0, d1, d2};

    int row = 0;


    mult(a, b, result,
            sizeof(a) / sizeof(int *),
            sizeof(a0) / sizeof(int),
            sizeof(b0) / sizeof(int));


    /* Print result, compare against expected values */
    for (; row < sizeof(result) / sizeof(int *); ++row) {
        int col = 0;
        for (; col < sizeof(c0) / sizeof(int); ++col) {
            printf("%2d ", result[row][col]);
            assert(result[row][col] == expected[row][col]);
        }
        printf("\n");
    }

    return 0;
}
