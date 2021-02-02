//
// Created by ulysses on 1/23/17.
//
#include<stdio.h>
void toString(int list[], int list_length);
void swap(int list[], int* end_list_pointer, int list_length);

int main(void){
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int list_length = (sizeof(list) / sizeof(list[0]));
    // Accidentally sent the pointer of end_list_pointer instead of list[9]
    int *end_list_pointer = &list[list_length - 1];
    toString(list, list_length);
    swap(list, end_list_pointer, list_length);
    toString(list, list_length);
    return 0;

}
void toString(int list[], int list_length ){
    printf("[");
    for (int i = 0; i < list_length; i++)
        printf( (i != list_length - 1)? "%d," : "%d]\n",list[i]);

}
void swap(int list[], int* end_list_pointer, int list_length){
    for (int i = 0; i < list_length / 2; i++){
        int temp = list[i];
        list[i] = *(end_list_pointer - i);
        *(end_list_pointer - i) = temp;
    }
}
