//
// Created by ulysses on 1/31/17.
//
#include<stdio.h>
int main(void){
    int input, sum = 0;
    printf("Enter some values. To exit, input \"-1\".\n");
    int check = scanf("%d", &input); //prevents garbage input

    while (check == 1 && (input != -1)){
        sum += input;
        check = scanf("%d", &input);
    }
    //!check is equivalent to (check != 0). C checks if the value is false(or zero).
    printf((!check)? "Your last input was invalid, so the sum is %d.\n" : "The sum is %d.\n", sum);
    return 0;
}
