//
// Created by ulysses on 6/24/17.
//
#include "queue.h"
//Local Functions
static void CopyToNode(Item item, Node *pointer);
static void CopyToItem(Node *pn, Item *pi);

void InitializeQueue(Queue *pg){
    pg->front = pg->rear = NULL;
    pg->item_count = 0;
}

bool QueueIsFull(const Queue *pg){
    return pg->item_count == MAXQUEUE;
}
bool QueueIsEmpty(const Queue *pg){
    return (!pg->item_count); //pg->item_count == 0
}
int QueueItemCount(const Queue *pg){
    return pg->item_count;
}

bool EnQueue(Item item, Queue *pg){
    Node *pnew;
    if (QueueIsFull(pg))
        return false;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL) { //Memory allocation failure
        fprintf(stderr, "Error: Unable to allocate memory.");
        exit(EXIT_FAILURE);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pg))
        pg->front = pnew;
    else
        pg->rear->next = pnew;
    pg->rear = pnew;
    pg->item_count++;

    return true;
}

bool DeQueue(Item *pitem, Queue *pg){
    Node *pt;

    if (QueueIsEmpty(pg))
        return false;
    CopyToItem(pg->front, pitem);
    pt = pg->front;
    pg->front = pg->front->next;
    free(pt);
    pg->item_count--;
    if(pg->item_count == 0)
        pg->rear = NULL;

    return true;
}

void EmptyTheQueue(Queue *pg){
    Item dummy;
    while(!QueueIsEmpty(pg))
        DeQueue(&dummy, pg);
}

// Local Functions:
static void CopyToNode(Item item, Node *pn){
    pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi){
    *pi = pn->item;
}