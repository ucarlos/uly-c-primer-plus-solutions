//
// Created by ulysses on 5/27/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#define PRINT(...) printf(__VA_ARGS__)
double sum(int num, ...);
int main(void){
    double s, t;
    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("s value: %d\n", s);
    printf("t value: %d\n", t);
    return 0;
}
double sum(int num, ...){
    va_list object;
    double total = 0;
    va_start(object, num);
    for (int i = 0; i < num; i++)
        total += va_arg(object, double);
    va_end(object);

    return total;
}
