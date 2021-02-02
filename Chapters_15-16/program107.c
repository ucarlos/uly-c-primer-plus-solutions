//
// Created by ulysses on 6/3/17.
//
#include "common_header.h"
void print_array(const double list[], int length);
double * new_d_array(int length, ...);
int main(void){
    double *pointer1 = new_d_array(5e1, 6e1, 7e1 ,8e1, 9e1, 10e2);
    double *pointer2 = new_d_array(4, 1.5, 2.5, 3.2, 4.5);

    print_array(pointer1, 5);
    print_array(pointer2, 4);
    free(pointer1);
    free(pointer2);
}
void print_array(const double list[], int length){
    for (int i = 0; i < length; i++)
        printf("%.2f ", list[i]);
    printf("\n");

}
double * new_d_array(int length, ...){
    va_list object;
    va_start(object, length);
    double *temp = calloc(length, sizeof(double));
    for (int i = 0; i < length; i++){
        temp[i] = (double)va_arg(object, double);
    }
    va_end(object);
    return temp;
}
