//
// Created by ulysses on 6/29/17.
//

#ifndef CHAPTER17_QUEUE_H
#define CHAPTER17_QUEUE_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//Place Item type here:
//typedef int Item; //Use for queue.c and use_queue.c
//Or create a structure HERE:
typedef struct item {long arrive; int processtime;} Item; // Use for mail.c
#define MAXQUEUE 10
typedef struct node{
    Item item;
    struct node *next;
}Node;

typedef struct queue{
    Node *front, *rear;
    int item_count;
}Queue;

//function declarations:
void InitializeQueue(Queue *pg);
bool QueueIsFull(const Queue *pg);
bool QueueIsEmpty(const Queue *pg);
int QueueItemCount(const Queue *pg);
bool EnQueue(Item item, Queue *pg);
bool DeQueue(Item *pitem, Queue *pg);
void EmptyTheQueue(Queue *pg);

#endif //CHAPTER17_QUEUE_H
