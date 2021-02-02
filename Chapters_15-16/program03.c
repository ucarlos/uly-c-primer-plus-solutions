//
// Created by ulysses on 5/19/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int check_set_bits(int number);
char * itobs(int number, char *spointer);
int main(void){
    int number;

    printf("Enter a number:");
    scanf("%d", &number);
    printf("The number of set bits in %d is %d", number, check_set_bits(number));
}
int check_set_bits(int number){
    char bin_str[CHAR_MAX * sizeof(int) + 1];
    itobs(number & INT_MAX, bin_str);
    int count = 0;
    for (char *p = bin_str; *p; p++){
        if (*p == '1')
            count++;
    }
    return count;
}
char * itobs(int number, char *spointer){
    const static size = CHAR_MAX * sizeof(int);
    for (int i = size - 1; i>= 0; i--, number >> 1)
        spointer[i] = (01 & number) +'0';

    return spointer;
}