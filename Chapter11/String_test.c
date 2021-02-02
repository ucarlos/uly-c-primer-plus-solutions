//
// Created by ulysses on 2/18/17.
//
#include<stdio.h>
int main(void){
    char string1[50], string2[30], string3[60];
    puts("Enter two strings:");
    fgets(string1, 20, stdin);
    fgets(string2, 20, stdin);
    puts("Now these strings will be printed inside string1.");
    sprintf(string1, "\nThe Next string is %s",string2);
    puts(string1);
    return 0;
}