//
// Created by ulysses on 2/9/17.
//
#include<stdio.h>
void display(int row_len, int column_len,double matrix[row_len][column_len]);
void copy(int row, int column, double copy[row][column], double origin[row][column]);
void initalize(int row, int column, double matrix[row][column]);

int main(void){
    int row_length = 3, column_length = 5;
    double matrix_1[row_length][column_length],
            copy[row_length][column_length];

    printf("Please initalize this 3 * 5 Matrix:\n");
    initalize(row_length, column_length, matrix_1);
    display(row_length, column_length, matrix_1);



    return 0;
}

void display(int row_len, int column_len, double matrix[row_len][column_len]){
        for (int i = 0; i < row_len; i++){
            printf("[");
            for (int j = 0; j < column_len; j++)
                printf((j == column_len - 1)? "%4.2f]\n": "%4.2f, ", matrix[i][j]);
        }
}
void copy(int row, int column, double copy[row][column], double origin[row][column]){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
                copy[i][j] = origin[i][j];
}
void initalize(int row, int column, double matrix[row][column]){
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
                scanf("%lf", &matrix[i][j]);
}
