//
// Created by ulysses on 5/26/17.
//
#include<stdio.h>
#include<math.h>
#include<assert.h>
int main(void){
    double x, y, z;
    puts("Enter a pair of numbers (0 0 to quit):");
    while ((scanf("%lf%lf", &x, &y) == 2) && (x != 0 || y != 0)){
        z = x * x - y * y;
        assert(z >= 0);
        printf("The answer is %f\n", sqrt(z));
        puts("Next pair of numbers:");
    }
    puts("Done.");

    return 0;
}
