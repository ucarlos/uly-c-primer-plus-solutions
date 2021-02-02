//
// Created by ulysses on 6/1/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
void print_array(const int list[], int length);
//Remove following if C11 _Static_assert is not supported.
_Static_assert(sizeof(double) == 2 * sizeof(int), "Size of double type is not twice of int.");

int main(void){
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};

    puts("memcpy() used:");
    puts("Values (Original data):");
    print_array(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
    puts("Target (Now a copy of Values):");
    print_array(target, SIZE);

    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values + 2, values, 5 * sizeof(int));
    puts("Values: Elements 0-5 have been copied to Elements 2-7.");
    print_array(values, SIZE);

    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target, curious, (SIZE /2) * sizeof(double));
    puts("Target: (5 doubles into 10 int positions)");
    print_array(target, SIZE/2);
    print_array(target + 5, SIZE/2);

    return 0;

}
void print_array(const int list[], int length){
    for (int i = 0; i < length; i++)
        printf("%d ", list[i]);
    putchar("\n");
}