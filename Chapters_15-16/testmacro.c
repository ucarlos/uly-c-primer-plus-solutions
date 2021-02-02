//
// Created by ulysses on 5/31/17.
//
#include<stdio.h>
#include<stdlib.h>
int main(void){
    printf("At this moment, the number of lines in this file is %d...\n", __LINE__);
    printf("%s\t%s", __DATE__, __TIME__);
    return 0;
}
