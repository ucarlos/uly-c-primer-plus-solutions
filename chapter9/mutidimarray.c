//
// Created by ulysses on 1/17/17.
//
#include<stdio.h>
int main(void){
    int matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    int row_length = sizeof(matrix) / sizeof(matrix[0]);
    for (int i = 0; i < row_length; i++)
        printf("This row has a size of %d bytes.\n", sizeof(matrix[i]));
    return 0;
}
