//
// Created by ulysses on 6/17/17.
//

#ifndef CHAPTER17_LIST_H
#define CHAPTER17_LIST_H
#include <stdbool.h>
#include <string.h>

#define TSIZE 45
typedef struct film{
    char title[TSIZE];
    int rating;
}Item;

typedef struct node{
    Item item;
    struct node * next;
}Node;

#define MAXSIZE 100
typedef struct list{
    Item list[MAXSIZE];
    int items;
}List;
/*typedef struct list{
    Node *head, *end;
}List; */ //Problem 02

//typedef Node *List; //Normal

//functions:
void InitializeList(List * plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListItemCount(const List *plist);
bool AddItem(Item item, List *plist);
void Traverse(const List *plist, void (*pfunction)(Item Item));
void EmptyList(List *plist);
#endif //CHAPTER17_LIST_H
