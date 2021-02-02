//
// Created by ulysses on 6/3/17.
//
#include "common_header.h"
#define SIZE 100
void random_pick(int list[], int length, unsigned int n_picks);
int main(void){
    srand(time(NULL));
    int list[SIZE];
    for (int i = 0; i < SIZE; i++)
        list[i] = i + 1;
    int n;
    printf("How many numbers do you want?");
    scanf("%d", &n);
    random_pick(list, SIZE, n);

    return 0;
}
void random_pick(int list[], int length, unsigned int n_picks){
    if (n_picks >= length ){
        printf("Invalid number of choices. Aborting.");
        return;
    }
    printf("Here are your choices:\n");
    int temp, counter = 0;
    while (counter < n_picks){
        temp = rand() % (SIZE - 1);
        if (!list[temp]) continue;
        printf(!((counter + 1) % 10)? "%d\n" : "%d ", list[temp]);
        list[temp] = 0;
        counter++;
    }
}