//
// Created by ulysses on 5/8/17.
//
#include<stdio.h>
#include<stdlib.h>
struct month{
    char month_name[12];
    char month_abr[3];
    int number_of_days;
    int month_num;
};
int num_days(const struct month *point);
int main(void){

}
int num_days(const struct month *point){
    int sum = 0;
    for (int i = 0; i < point->month_num; i++){
        /*if (i > 9)
            sum += (i % 2 == 0)? 30: 31;
        else
            sum += (i == 2)? 28 :
                   (i % 2 == 0) ? 30: 31; */ //Same code as below

        sum += (i > 9)? ((i % 2 == 0)? 30: 31) :
               (i == 2) ? 28 :
               (i % 2 == 0)? 30: 31;
    }
    return sum + point->number_of_days;
}


