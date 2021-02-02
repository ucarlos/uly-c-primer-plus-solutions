//
// Created by ulysses on 2/20/17.
//
#include<stdio.h>
#include<stdlib.h>
int main(void){
    int input;
    scanf("%d", &input);
    if (!input){
        puts("Failure!"); exit(EXIT_FAILURE);
    }
    else exit(EXIT_SUCCESS);

}
