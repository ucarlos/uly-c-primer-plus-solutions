u//
// Created by ulysses on 6/17/17.
//
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
void showmovies(Item item);
char * s_gets(char *string, int n);
inline static clear_buffer(void){
    while(getchar() != '\n')
        continue;
}
int main(void){
    List movies;
    Item temp;

    //initialize List:
    InitializeList(&movies);
    if (ListIsFull(&movies)){
        fprintf(stderr, "This list is full. Aborting.");
        exit(EXIT_FAILURE);
    }
    printf("Enter the first movie title:");
    while(s_gets(temp.title, TSIZE) != NULL &&
          temp.title[0] != '\0'){
        printf("\nEnter an rating <0-10>:");
        scanf("%d", &temp.rating);
        clear_buffer();
        if (!AddItem(temp, &movies)){
            fprintf(stderr, "Problem allocating memory.");
            break;
        }
        if (ListIsFull(&movies)){
            puts("List is now full. Exiting.");
            break;
        }
        puts("Enter next movie title (empty line to stop)");
    }
    //display:
    if (ListIsEmpty(&movies))
        printf("No data entered.");
    else {printf("Displaying movie List:\n"); Traverse(&movies, showmovies);}

    EmptyList(&movies);
    return 0;

}

void showmovies(Item item){
    printf("Title: %s\tRating: %d\n", item.title, item.rating);
}

char * s_gets(char *string, int n){
    char *return_value, *find;
    return_value = fgets(string, n, stdin);
    if (return_value){
        find = strchr(string, '\n');
        if(find)
            *find = '\0';
        else clear_buffer();
    }
    return return_value;
}
