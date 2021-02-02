//
// Created by ulysses on 5/17/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
char * itobs(int n, char *spointer);
void printstring(char *string);
int main(void){
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;
    printf("Enter a number to convert to binary:");
    scanf("%d", &number);
    itobs(number, bin_str);
    printstring(bin_str);
    return 0;

}
char * itobs(int n, char *spointer){
    const static int size = CHAR_BIT * sizeof(int);

    for (int i = size - 1;i >= 0; i--, n >>= 1)
        spointer[i] = (01 & n) + '0'; // ANDs 01 and the number, and converts it to a char
    spointer[size] = '\0';//Add null character

    return spointer; //How to use?
}

void printstring(char *string){
    char *pointer;
    for (pointer = string; *pointer; pointer++){
        unsigned long temp = pointer - string;
        printf((temp != 0 && ((temp + 1) % 4 == 0))? "%c ": "%c", *pointer);
    }

}
