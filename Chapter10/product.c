//
// Created by ulysses on 2/5/17.
//
#include<stdio.h>
int multiply(int a, int b);
int main(void){
    int a, b;
    printf("Input a * b:");
    scanf("%d %d", &a, &b);
    printf("The value is %d", multiply(a, b));
    return 0;
}
int multiply(int a, int b){
    if (b < 0){
        b = ~b + 1; a = ~a + 1;
    }
    int sum = 0;
    for (int i = b; i >= 1; i--)
        sum += a;
   return sum;
}

