//
// Created by ulysses on 6/24/17.
//

#ifndef CHAPTER17_CIRCULAR_QUEUE_H
#define CHAPTER17_CIRCULAR_QUEUE_H
#include "common_header.h"
#define QUEUE_MAX_LENGTH 100
typedef struct item_struct{
    int data;
    unsigned int NotNull : 1;
    //NotNull : 0(False), 1(True)
}Item;
typedef struct queuestruct{
    Item array[QUEUE_MAX_LENGTH];
    unsigned int read, write, item_count;
}Queue;

Item  Dequeue(Queue *pQueue);
bool Enqueue(Queue *pQueue, Item item);
bool QueueIsEmpty(const Queue *q);
bool QueueIsFull(const Queue  *q);
bool SearchQueue(const Queue *q, Item item);
bool expandMaxQueueLength(Queue *q); // Planned
void printQueue(const Queue *q);
void  InitializeQueue(Queue **pQueue);
void ClearQueue(Queue **q);

inline static clear_buffer(void){
    while(getchar() != '\n')
        continue;
}
#endif //CHAPTER17_CIRCULAR_QUEUE_H
