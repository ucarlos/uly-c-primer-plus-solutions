//
// Created by ulysses on 5/14/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
int main(void){
    int value = CHAR_BIT;
    printf("The number was first %d, but after one right shift, it became %d", value, value << 1);
    return 0;
}
