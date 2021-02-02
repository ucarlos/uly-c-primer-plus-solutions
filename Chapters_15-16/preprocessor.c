//
// Created by ulysses on 5/23/17.
//
#include<stdio.h>
#include<stdlib.h>
#define SQUARE(x) ((x*x))
#define PR(x) printf("The result is %d.\n", x)


int main(void){
    int x = 25, z;
    printf("x = %x\n", x);
    printf("Evaluating SQUARE(x):");
    PR(x);
    z = SQUARE(2);
    printf("Evaluating SQUARE(2):");
    PR(z);
    printf("Evalutating SQUARE(x+2):");
    PR(SQUARE((x+2)));
    return 0;
}
