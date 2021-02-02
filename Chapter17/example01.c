//
// Created by ulysses on 6/10/17.
//
// films2.c -- using a linked list of structures
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film{
    char title[TSIZE];
    int rating;
    struct film *next, *previous;
};
char * s_gets(char *string, int n);

inline static clear_buffer(void){
    while (getchar() != '\n')
        continue;
}

int main(void){
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0'){
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else {
            prev->next = current;
            current->previous = prev;
        }

        strncpy(current->title, input, TSIZE);
        puts("Now enter your rating <0 - 10>");
        scanf("%d", &current->rating);
        clear_buffer();
        puts("Enter the next movie title. To stop, input an empty line.");
        prev = current;
    }
    //Display movies
    if (head == NULL)
        printf("No data entered.");
    else printf("Here is the movie list :\n");

    current = head;

    while (current != NULL){
        printf("Title: %s\tRating: %d\n", current->title, current->rating);
        current = current->next;
        prev = current;
    }

    printf("Now, the same list again, but in reverse!\n");

    while (prev != NULL){
        printf("Title :%s\tRating: %d\n", current->title, current->rating);
        prev = prev->previous;
    }

    //Free allocated memory
    current = head;
    while(current != NULL){
        free(current);
        current = current->next;
    }
    printf("Good bye.\n");
    return 0;
}

char * s_gets(char *string, int n) {
    char *return_value, *find;
    return_value = fgets(string, n, stdin);
    if (return_value) {
        find = strchr(string, '\n');
        if (find) *find = '\0';
        else clear_buffer();
    }
    return return_value;
}
