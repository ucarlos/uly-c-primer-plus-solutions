//
// Created by ulysses on 7/2/17.
//
#include "common_header.h"
bool isCapital(char x);
int main(void){
    char input[100];
    unsigned int shift;
    puts("Enter the phase in capital letters and the desired shift index:");
    fgets(input, 100, stdin);
    fscanf(stdin, "%u",&shift);
    printf("Current Phrase:\n %s\n", input);
    int check;

    for (char *p = input; *p; p++) {
        if(!isalpha(*p)) continue;
        char temp = toupper(*p);
        temp = ((temp + shift) > 'Z')? ((temp + shift - 1) % 'Z') + 'A' : (temp + shift);

        *p = (char)(isCapital(*p)? temp : tolower(temp));

    }

    printf("Phase is now:\n %s\n", input);

}
bool isCapital(char x){
    return ('A' <= x && x <= 'Z');
}
