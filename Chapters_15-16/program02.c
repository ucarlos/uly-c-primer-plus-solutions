//
// Created by ulysses on 5/19/17.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include "example.h"

int main(int argc, char *argv[]){
    //Check for errors first
    printf("%d\n%s%s\n", argc, argv[1], argv[2]);
    if (!check_string(argv[1]) || !check_string(argv[2])){
        printf("An error has occurred. Aborting.\n");
        exit(EXIT_FAILURE);
    }


    char *string1 = argv[1], *string2 = argv[2];
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    printf("Decimal Values: %ld\t%ld\n", bstoi(string1), bstoi(string2));
    printf("Negated Decimal Values: %ld\t%ld\n", ~bstoi(string1), ~bstoi(string2));
    printf("%s AND %s: %s\n", string1, string2, itobs(bstoi(string1) & bstoi(string2), bin_str));
    printf("%s OR %s: %s\n", string1, string2, itobs(bstoi(string1) | bstoi(string2), bin_str));
    printf("%s XOR %s: %s\n", string1, string2, itobs(bstoi(string1) ^ bstoi(string2), bin_str));

    return 0;


}
int check_string(char *string){
    for (char *p = string; *p; p++){
        int temp = *p - '0';
        if (!(0 <= temp && temp <= 1)) return 0;
    }

    return 1; // No problem
}
long bstoi(char *string){
    long value = 0;
    int strlength = strlen(string) - 1;
    for (int i = 0; i <= strlength; i++)
        value += (string[i] - '0') * (1 << (strlength - i)); // Left shift 1 by i (i.e 1 * 2 ^ i)

    return value;
}
char * itobs(int n, char *spointer){
    const static int size = CHAR_BIT * sizeof(int);

    for (int i = size - 1;i >= 0; i--, n >>= 1)
        spointer[i] = (01 & n) + '0';
    spointer[size] = '\0';

    return spointer;
}
void print_string(char *string){
    char *pointer;
    int temp;
    for (pointer = string; *pointer; pointer++){
        temp = pointer - string;
        printf((temp != 0 && ((temp + 1) % 4 == 0))? "%c ": "%c", *pointer);
    }

}
