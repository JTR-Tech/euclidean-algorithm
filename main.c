#include <stdio.h>
#include <stdlib.h>

typedef struct equ {
    int smallest;
    int largest;
    int remainder;
    int quotient;
    int val;
} EA;

void argHandler(int* args)
{
    //sort our cmdline args smallest to largest
    if (args[0] >= args[1]) {
        int tmp = args[0];
        args[0] = args[1];
        args[1] = tmp;
    };
}

int euclidean(int* smallest, int* largest, int* remainder, int* quotient, int* val)
{
    //Recursive function implementing the Euclidean Algorithm to find the GCD
    while (*remainder != 0){
        *remainder = *largest % *smallest;
        if (*remainder == 0){
            *val = *smallest;
            return *val;
        } else {
            *quotient = *largest / *smallest;
            *largest = *smallest;
            *smallest = *remainder;
            euclidean(smallest, largest, remainder, quotient, val);
        };

    };

    return *val;
}

int main(int argc, char *argv[])
{
    //Convert command line arguments to ints, then sort smallest to largest
    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);
    int args[2] = {arg1, arg2};
    argHandler(args);

    EA gcd;
    gcd.smallest = args[0];
    gcd.largest = args[1];
    gcd.remainder = -1;
    gcd.quotient = 0;
    gcd.val = 0;

    printf("GCD: %d\n", euclidean(&gcd.smallest, &gcd.largest, &gcd.remainder, &gcd.quotient, &gcd.val));
    return EXIT_SUCCESS;
}