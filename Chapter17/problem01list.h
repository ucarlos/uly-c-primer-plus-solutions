//
// Created by ulysses on 7/15/17.
//

#ifndef CHAPTER17_PROBLEM01LIST_H
#define CHAPTER17_PROBLEM01LIST_H
#include "common_header.h"
#define TSIZE 100
typedef struct film{
    char title[TSIZE];
    int rating;
}Item;

typedef struct node{
    Item item;
    struct node *next, *previous;
}Node;

typedef struct List{
    Node *head;
    unsigned int list_size;
};

//functions:
void InitializeList(List *plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
void Traverse(const List *plist, void(*pfunction)(Item Item));
void EmptyList(List *plist);
#endif //CHAPTER17_PROBLEM01LIST_H
