//
// Created by ulysses on 7/21/17.
//

#ifndef CHAPTER17_LINKEDLIST_H
#define CHAPTER17_LINKEDLIST_H
#include "common_header.h"
typedef struct item{
    int data;
}Item;

typedef struct lnode{
    Item item;
    struct lnode *next;
}LNode;

typedef struct llist{
    LNode *head;
    int list_size;
}LinkedList;

void InitializeList(LinkedList *plist);
LNode * Search(LinkedList *plist, int item);
bool InsertNode(LinkedList *plist, int value);
bool DeleteNode(LinkedList *plist, Item item);
void Clear_List(LinkedList *plist);




#endif //CHAPTER17_LINKEDLIST_H
