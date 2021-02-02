#include <stdio.h>

int main(void) {
    int index = 0,check_input;
    double variance_1 = 0, total = 0, input;
    printf("Enter some numbers. To exit, enter \"-1\".\n");


    while((check_input = scanf("%lf", &input) == 1) && (input != -1)){
        index++;
        variance_1 += input * input;
        total += input;
    }
    double average = total / index;
    double variance = (variance_1 / index);
    printf("The average of these numbers is %.3f, while the variance is %.3f.",
           average, variance - (average * average));

    return 0;
}