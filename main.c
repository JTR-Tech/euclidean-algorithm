#include <stdio.h>
#include <stdlib.h>

typedef struct equ {
    int a;
    int b;
    int r;
    int q;
    int val;
} EA;

void argHandler(int* args)
{
    if (args[0] >= args[1]) {
        int tmp = args[0];
        args[0] = args[1];
        args[1] = tmp;
    };
}

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

int main(int argc, char *argv[])
{
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);

    int args[2] = {arg1, arg2};
    argHandler(args);
    
    EA gcd;
    gcd.a = args[0];
    gcd.b = args[1];
    gcd.r = -1;
    gcd.q = 0;
    gcd.val = 0;

    printf("GCD: %d\n", euclidean(&gcd.a, &gcd.b, &gcd.r, &gcd.q, &gcd.val));
    return EXIT_SUCCESS;
}