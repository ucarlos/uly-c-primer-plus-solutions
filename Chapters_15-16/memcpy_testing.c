//
// Created by ulysses on 5/26/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
    int source[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int dest[8] = {0};
    //USE MEMMOVE WHEN THERE'S A CHANCE OF OVERLAPPING DATA
    toString(source, sizeof(source)/sizeof(source[0]));
    memcpy(source , source + 2, 6);
    toString(source, sizeof(source)/sizeof(source[0]));
    return 0;
}
void toString(int list[], int length){
    for (int i = 0; i < length; i++)
        printf((i + 1) == length? "%d\n": "%d ", list[i]);

}
