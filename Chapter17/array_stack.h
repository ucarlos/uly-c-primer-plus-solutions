//
// Created by ulysses on 7/14/17.
//

#ifndef CHAPTER17_ARRAY_STACK_H
#define CHAPTER17_ARRAY_STACK_H
#include "common_header.h"

#define STACKLEN 100
#define SIZE 1000

typedef struct item{ //Expand
    char data;
}Item;

typedef struct stack{
    unsigned int top_stack,
            stack_size, max_size;
    Item list[];//Dynamic array member
}Stack;

//functions:

void InitializeStack(Stack **ppstack);
bool Insert(Item item, Stack *pstack);
bool Pop(Item *item, Stack *pstack);
void PrintStack(Stack *pstack);
bool StackIsEmpty(Stack *pstack);
bool StackIsFull(Stack *pstack);
bool ExtendStack(Stack **pstack); //TO DO
void ClearStack(Stack **pstack);
//Look at item at top of stack
Item * Peek(Stack *pstack);


#endif //CHAPTER17_ARRAY_STACK_H
