//
// Created by ulysses on 5/31/17.
//
#include <stdio.h>
#include<math.h>

#define MYTYPE(X) _Generic((X),\
int: "int",\
float : "float",\
double: "double",\
default: "other"\
)
// _Generic works on C99 because the compiler supports it.
// Normally, you should expect that only C11 supports this.

#define SQRT(X) _Generic((X),\
    float : sqrtf,\
    long double: sqrtl,\
    default: sqrt\
)(X)

int main(void)
{
    int d = 5;
    printf("%f\n", SQRT(3.14f));
    printf("%s\n", MYTYPE(d)); // d is type int
    printf("%s\n", MYTYPE(2.0*d)); // 2.0* d is type double
    printf("%s\n", MYTYPE(3L)); // 3L is type long
    printf("%s\n", MYTYPE(&d)); // &d is type int *
    //return 0;

    
}
