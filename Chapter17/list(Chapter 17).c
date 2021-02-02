//
// Created by ulysses on 6/17/17.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//Local function prototype
static void CopyToNode(Item item, Node *pnode);

//Interface functions
//Empty List:

void InitializeList(List *plist){
    *plist = NULL;
}
bool ListIsEmpty(const List *plist){
    return (*plist == NULL);
}
bool ListIsFull(const List *plist){
    Node *point;
    bool full;
    point = malloc(sizeof(Node));
    full = (point == NULL)? true : false;
    free(point);
    return full;
}
unsigned int ListItemCount(const List *plist){
    unsigned int count = 0;
    Node *pnode = *plist;
    while (pnode != NULL) {
        count++;
        pnode = pnode->next;
    }
    return count;
}
//Creates Node to hold item and adds it to end of list:
bool AddItem(Item item, List *plist){
    Node *pnew = (Node *) malloc(sizeof(Node)), *scan = *plist;

    if (pnew == NULL) return false; //quit function on failure.
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) //Empty List, so place pnew at head of list.
        *plist = pnew;
    else {
        while (scan->next != NULL)
            scan = scan->next;
        scan->next = pnew;
    }
    return true;
}
//Visits each node and executes function pointed to by pfunction.
void Traverse(const List *plist, void (*pfunction)(Item item)){
    Node *pnode = *plist;
    while (pnode !=NULL){
        (*pfunction)(pnode->item); //Apply function to item.
        pnode = pnode->next;
    }
}
//Free memory allocated by malloc() and set list pointer to NULL.
void EmptyList(List *plist){
    Node *psave;
    while (*plist != NULL){
        psave = (*plist)->next; //Save address of next node.
        free(*plist);
        *plist = psave;
    }
}
//Local function definition: Copies an item into a node.
static void CopyToNode(Item item, Node *pnode){
    pnode->item = item; //Copies structure
}
