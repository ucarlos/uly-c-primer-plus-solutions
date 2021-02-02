//
// Created by ulysses on 5/24/17.
//
#include<stdio.h>
#if __STDC_VERSION__ == 199901L
#error

#define PRINTD(x) printf(x " died in the hellhole. Oh Vey!")


int main(void){
    PRINTD(__FILE__);
    return 0;
}
