//
// Created by ulysses on 1/16/17.
//
#include<stdio.h>
void swap(int *x, int *y);
int main(void){
    int x = 10, y = 15;

    printf("The values of x and y are %d and %d respectively.\n", x, y);
    swap(&x, &y);
    printf("Now their values are %d and %d.\n", x, y);
    return 0;
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}
