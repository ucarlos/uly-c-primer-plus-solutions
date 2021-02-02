//
// Created by ulysses on 2/6/17.
//
#include<stdio.h>
void swap(int *a, int*b);
int main(void){
    int a = 5, b = 6;
    printf("Before a change, a is %d and b is %d.", a , b);
    swap(&a, &b);
    printf("Now a is %d and b is %d.", a, b);
}
void swap(int *a , int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}