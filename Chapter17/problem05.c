//
// Created by ulysses on 7/16/17.
//
#include "array_stack.h"
#define SLEN 100
char * s_gets(char *string, int len);
/*inline static clear_buffer(void){
    while (getchar() != '\n')
        continue;
} */
int main(void){
    char *string = calloc(SLEN, sizeof(Item));
    puts("Enter a string:");
    s_gets(string, SLEN);

    Stack *stack;
    InitializeStack(&stack);
    for (char *temp = string; *temp; temp++)
        Insert((Item){*temp}, stack);

    for (int i = stack->stack_size; i >= 0; i--){
        Item temp;
        if (Pop(&temp, stack))
            printf("%c ", temp);
    }
    return 0;
}

char * s_gets(char *string, int len) {
    char *return_val, *find;
    return_val = fgets(string, len, stdin);
    if (return_val) {
        find = strchr(string, '\n'); //Look for newline
        if (find) //if the address is not NULL
            *find = '\0';// place a null character there
        else
            while (getchar() != '\n')
                continue; //dispose of rest of line-- clear buffer
    }
    return return_val;
}
