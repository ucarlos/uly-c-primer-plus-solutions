//
// Created by ulysses on 1/30/17.
//
#include<stdio.h>
int main(void){
    int input, sum = 0;
    printf("Enter some values. To exit, input \"-1\".\n");
    scanf("%d", &input);
    while (input != -1){
        sum += input;
        scanf("%d", &input);
    }
    printf("Your sum is %d", sum);
    return 0;
}