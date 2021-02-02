//
// Created by ulysses on 1/16/17.
//
#include<stdio.h>
int main(void){
	int value = 10, box = 1000;
    int *point = &box - 1;


	printf("Location of value :%p\tLocation of box: %p\tLocation of point:%d\n", &value, &box, *point);
	return 0;
}
