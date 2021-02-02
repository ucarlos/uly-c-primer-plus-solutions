//
// Created by ulysses on 2/16/17.
//
#include<stdio.h>
#include<string.h>
int main(void){
    char string1[20], string2[20];
    puts("Please input two strings.");
    fgets(string1, 20, stdin);
    fgets(string2, 20, stdin);

    printf("The concatenated string is %s", strncat(string1, string2, 20));
    return 0;
}
