//
// Created by ulysses on 6/2/17.
//
#include "common_header.h"
#define PRINT(...) printf(__VA_ARGS__)

#define isBOOL(x) _Generic((x), _Bool : "Boolean", default : "Not a Boolean")

#define PBOOL(x) puts((isBOOL(x)))
int main(void){
    _Bool boolean = 1;
    int faggot = 20;
    PBOOL(boolean);
    PBOOL(faggot);

    return 0;
}
