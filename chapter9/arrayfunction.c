//
// Created by ulysses on 1/17/17.
//
#include<stdio.h>
void function(int list[]);
int main(void){
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("The value of list[0] is %d\n", list[0]);
    function(list);
    printf("After running this function, it is now %d \n", list[0]);

}
void function(int list[]){

}
