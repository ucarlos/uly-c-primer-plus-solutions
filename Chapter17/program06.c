//
// Created by ulysses on 7/19/17.
//
#include "common_header.h"
int BinarySearch(int *list, int length, int key);
int main(void){ //Binary Search
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

}
int BinarySearch(int *list, int length, int key){
    int low = 0, high = length, mid;
    while (low < high){
        mid = low + high / 2;
        if (list[mid] == key)
            return mid;
        else if (key > list[mid])
            low = mid + 1;
        else high = mid - 1;
    }


}