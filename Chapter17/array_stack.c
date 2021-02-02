//
// Created by ulysses on 7/16/17.
//
#include "array_stack.h"

void InitializeStack(Stack **pstack){
    (*pstack) = malloc(sizeof(*pstack) + SIZE * sizeof(Item));
    (*pstack)->stack_size = 0;
    (*pstack)->top_stack = 0;
    (*pstack)->max_size = SIZE;
}

bool Insert(Item item, Stack *pstack){
    if (StackIsFull(pstack))
        return false;
    pstack->list[pstack->top_stack++] = item;
    pstack->stack_size++;
    return true;
}

bool Pop(Item *item, Stack *pstack){
    if (pstack->top_stack <= 0 || pstack->top_stack >= pstack->max_size)
        return false;
    *item = pstack->list[--pstack->top_stack];
    pstack->list[pstack->top_stack + 1] = (Item){NULL};
    pstack->stack_size--;
    return true;

}

bool StackIsEmpty(Stack *pstack){
    return (pstack->stack_size == 0);
}

bool StackIsFull(Stack *pstack){
    return pstack->stack_size >= pstack->max_size;
}

void PrintStack(Stack *pstack){
    puts("The contents of the stack are as follows:");
    for (int i = 0; i < pstack->stack_size; i++) {
        //Change for the type of item:
        printf("%c ", pstack->list[i]);
    }
}

Item * Peek(Stack *pstack){
    return &pstack->list[pstack->top_stack];
}

void ClearStack(Stack **pstack){
    free(*pstack);
}

bool ExtendStack(Stack **pstack){
    (*pstack)->max_size *= 1.5; //Doubles max size;
    Item *temp = realloc((*pstack)->list, (*pstack)->max_size * sizeof(Item)); //FIX
    if (temp == NULL){
        fprintf(stderr, "Error: Cannot allocate any more memory for the array.");
        return false;
    }else return true;

}

