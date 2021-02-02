//
// Created by ulysses on 5/19/17.
//
#include<stdio.h>
#include<string.h>
#include<limits.h>
char * itobs(int number, char *pointer);
int search(int number, int bit_position);
int main(void){
    int value, bit_position;

    printf("Enter a value and the bit position you want to search:");
    scanf("%d %d", &value, &bit_position);

}
int search(int number, int bit_position){
    char b_string[CHAR_MAX * sizeof(int) + 1];
    itobs(number, b_string);
    return (bit_position > strlen(b_string))? -1 : (b_string[bit_position]);
}
char * itobs(int number, char *pointer){
    int value = CHAR_MAX * sizeof(int);
    for (int i = value - 1; i >= 0; i--, number >> 1)
        pointer[i] = (01 & number) + '0';
    return pointer;
}