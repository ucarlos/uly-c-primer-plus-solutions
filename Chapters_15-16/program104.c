//
// Created by ulysses on 6/3/17.
//
#include "common_header.h"
#include <time.h>
#define CHECK(X, Y) (double)((X) - (Y)) / (CLOCKS_PER_SEC)
void delay(double time);
int main(void){
    double time_delay;
    printf("Enter the desired time delay:");
    scanf("%lf", &time_delay);
    delay(time_delay);
    return 0;

}
void delay(double time){
    double check, time_start = clock();
    while ((check = CHECK(clock(),time_start)) < time){
        printf("Continuing onwards!\n");
    }
    printf("...And I'm done!");
}
