//
// Created by ulysses on 2/22/17.
//
#include<stdio.h>
void pointerswap(int *a, int *b);
int main(void){
    int a = 10, b = 15;
    printf("Before: %d, %d\n", a, b);
    pointerswap(&a, &b);
    printf("After: %d, %d\n", a, b);
    return 0;
}
void pointerswap(int *a, int *b){ // Will do absolutely nothing.
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}