//
// Created by ulysses on 2/18/17.
//

/*
 * REMEMBER: DO NOT USE SCANF AND FGETS IN THE SAME PROGRAM TOGETHER. UNDEFINED
 * SHIT HAPPENS WHEN YOU DO SO. USE SSCANF INSTEAD>
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sort(char *stringlist[], int string_amount);
char* s_gets(char *string, int length);
const int size = 50;
int main(void){
    //pointer amount
    char string_amount_input[2], c;
    int string_amount;
    printf("Please specify the amount of strings in this array:\n");
    fgets(string_amount_input, 2, stdin);
    string_amount = atoi(string_amount_input);

    while ((c = getchar()) != '\n' && c != EOF) // fixes issues with buffer
        ;

    char list[string_amount][size];
    char *stringpoint[string_amount];


    printf("Now, initialize these strings.\n");

    for (int p = 0; p < string_amount ; p++) {
        char *check_input = s_gets(list[p], size);
        if (check_input /*&& list[p][0] != '\0' */)
            stringpoint[p] = list[p];
    }


    sort(stringpoint, string_amount);

    puts("In order, the strings are as follows:");
        for (int i = 0; i < string_amount; i++)
            puts(stringpoint[i]);
    return 0;
}
void sort(char *list[], int string_amount){ //Insertion Sort
    for (int i = 1; i < string_amount; i++){
        char *key = list[i];
        int j = i - 1;
        while (strcmp(list[j], key) > 0 && j >= 0)
            list[j + 1] = list[j--];

        list[j + 1] = key;
    }
}
char* s_gets(char *string, int length){
    char *input = fgets(string,length, stdin);
    int i = 0;

    if (input) {//is defined
        while (string[i] != '\0' && string[i] != '\n')
            i++;
        if(string[i] == '\n')
            string[i] = '\0';
        else while (getchar() != '\n') //Input some shit you faggot
                continue;
    }
    return input;
}
