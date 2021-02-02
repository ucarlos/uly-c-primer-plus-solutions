//
// Created by ulysses on 1/16/17.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int search(char ch);

int main(void){
    printf("Please enter some characters. Use CTRL-Z or CTRL-D to terminate input.\n");

    char input;
    while ((input = (char)getchar()) != EOF){
        if (isalpha(input))
            printf("%c is a letter and its location in the alphabet is %d\n", input, search(toupper(input)));
    }
    return 0;
}
int search(char ch){
    char list[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J','K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int low = 0, high = 26;
    while (low <= high){
        int mid = (low + high) / 2;
        if (list[mid] == ch) return mid + 1;
        else if (list[mid] > ch)
           high = mid - 1;
        else low = mid + 1;
    }
    return -1; // Not found
}

