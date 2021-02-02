//
// Created by ulysses on 2/6/17.
//
#include<stdio.h>

double factorial(int value);

int main(void){
    int index;
    printf("Enter the index limit(i) for the infinite series 1/n! :");
    int check_input = scanf("%d", &index);
    double e_value = 1;
    for (int i = 1; i <= index; i++)
        e_value += 1.0 / factorial(i);

    printf((index < 0 || !check_input)? "Invalid Input.\n" : "After %d indices, the value of e is %f.\n", index, e_value);
    return 0;
}

double factorial(int value){
    if (value < 0) return -1;//impossible
    double temp = 1;
    for (int i = value; i > 1; i--)
        temp *= i;
    return temp;
}