//
// Created by ulysses on 5/26/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
void show_array(const int list[], int n);
_Static_assert(sizeof(double) == 2 * sizeof(int), "Double not twice int size");

int main(void){
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};

    printf("memcpy() used:\n");
    printf("Values (Original Data):");
    show_array(values, SIZE);

    printf("\nUsing memcpy() with overlapping ranges:");
    memmove(values + 2, values, 5 * sizeof(int));
    printf("\nValues -- elements 0-5 copied to 2-7:");
    show_array(values, SIZE);

    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target, curious, (SIZE / 2) * sizeof(double));
    puts("target --5 doubles into 10 int positions:");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);

    return 0;
}
void show_array(const int list[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf((i + 1) == n? "%d\n" : "%d ", list[i]);

}
