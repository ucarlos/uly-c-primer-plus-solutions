//
// Created by ulysses on 4/3/17.
//
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(void){
    int list[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(list) / sizeof(list[0]);
    printf("Displaying input:");
    for (int i = 0; i < length; i++) {
        printf("%d\r", list[i]);
        sleep(1);
        fflush(stdout);
    }
    printf("\n");
    return 0;

}
