//
// Created by ulysses on 2/22/17.
//
#include<stdio.h>
#include<ctype.h>
int main(void){
    printf("Input character:");
    char input = getchar();
    if(isalpha(input)){
        char temp = toupper(input);
        if(input == temp)
            putchar(tolower(input));//Correct method: Input
        else putchar(temp);// Temph
    }
    return 0;
}
