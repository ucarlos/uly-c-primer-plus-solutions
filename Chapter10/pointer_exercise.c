//
// Created by ulysses on 2/6/17.
//
#include<stdio.h>
void foo(int* pointer);

int main(void){
    int a = 1;
    int *pointer = &a;

    printf("Before: %d\tLocation: %p\n", *pointer, pointer);
    foo(pointer);
    pointer++;
    printf("After: %d \tLocation: %p\n", *pointer, pointer);
    return 0;
}
void foo(int* ptr){
    *ptr = ptr + 1;

}
