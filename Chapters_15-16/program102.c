//
// Created by ulysses on 6/2/17.
//
#include "common_header.h"
#define HMEAN(x, y) 2.0 / ((1.0 / (x)) + (1.0 / (y)))
int main(void){
    double x, y;
    scanf("%lf%lf", &x, &y);
    printf("The harmonic mean of %.2f and %.2f is %.3f\n", x, y, HMEAN(x, y));

    return 0;
}
