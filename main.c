#include <stdio.h>
#include <stdlib.h>

typedef struct equ {
    int a;
    int b;
    int r;
    int q;
    int val;
} EA;

int euclidean(int* a, int* b, int* r, int* q, int* val)
{
    while (*r != 0){
        *r = *b % *a;
        if (*r == 0){
            *val = *a;
            return *val;
        } else {
            *q = *b / *a;
            *b = *a;
            *a = *r;
            euclidean(a, b, r, q, val);
        };

    };

    return *val;
}

int main(void)
{
    EA gcd;
    gcd.a = 239238;
    gcd.b = 372843;
    gcd.r = -1;
    gcd.q = 0;
    gcd.val = 0;

    printf("GCD: %d\n", euclidean(&gcd.a, &gcd.b, &gcd.r, &gcd.q, &gcd.val));
    return EXIT_SUCCESS;
}