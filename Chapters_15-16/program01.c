//
// Created by ulysses on 5/19/17.
//
#include<stdio.h>
#include<string.h>
int check_string(char *string);
unsigned int bstoi(char *string);
int main(void){
    int check_error;
    char string[32];
    puts("Please enter a binary string.");
    scanf("%s", string);
    while(!(check_error = check_string(string))){
        printf("Invalid String. Try again.\n");
        scanf("%s", string);
    }

    printf("Binary String: %s\nDecimal Value:%u", string, bstoi(string));
    return 0;
}
unsigned int bstoi(char *string){
    unsigned int value = 0;
    int strlength = strlen(string) - 1;
    for (int i = 0; i <= strlength; i++)
        value += (string[i] - '0') * (1 << (strlength - i)); // Left shift 1 by i (i.e 1 * 2 ^ i)

    return value;
}

int check_string(char *string){
    for (char *p = string; *p; p++){
        int temp = *p - '0';
        if (!(0 <= temp && temp <= 1)) return 0;
    }

    return 1; // No problem
}