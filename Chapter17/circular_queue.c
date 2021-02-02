//
// Created by ulysses on 6/24/17.
//
//Dynamic Array will be written later.


/* Consider when read and write point to the same index */
#include "circular_queue.h"
int main(void){
    srand(time(NULL));
    Queue *aqueue;
    InitializeQueue(&aqueue);

    Enqueue(aqueue, (Item){2,0});
    Enqueue(aqueue, (Item){5,0});
    printQueue(aqueue);
    Dequeue(aqueue);
    printQueue(aqueue);
}
void InitializeQueue(Queue **pQueue){
    //pQueue->array = malloc(sizeof(Item) * QUEUE_MAX_LENGTH);
    *pQueue = calloc(1, sizeof(Queue));
    (*pQueue)->read = rand() % QUEUE_MAX_LENGTH;
    (*pQueue)->item_count = 0;

    puts("Would you like to input an item at this time? [y/n]");
    char c = getchar();
    if (tolower(c) == 'y'){
        puts("Input the item.");
        scanf("%d", &(*pQueue)->array[(*pQueue)->read].data);
        (*pQueue)->array[(*pQueue)->read].NotNull = 1;
        (*pQueue)->write = ((*pQueue)->read + 1) % QUEUE_MAX_LENGTH;

        (*pQueue)->item_count++;
    }
    else (*pQueue)->write = (*pQueue)->read; // No item yet.
    clear_buffer();
}
bool Enqueue(Queue *pQueue, Item item){

    if (QueueIsFull(pQueue)){
        printf("Warning: Enqueuing this item will overwrite the contents in index %d"
                       " (Current value : %d). Continue? [y/n]", pQueue->write, pQueue->array[pQueue->write]);
        char c = getchar();
        if (tolower(c) == 'y')
            goto jump;
        else return false;
    }

    jump:
    pQueue->array[pQueue->write] = item;
    pQueue->array[pQueue->write].NotNull = 1; // Just in case

    pQueue->write = (pQueue->write + 1) % QUEUE_MAX_LENGTH;
    if(pQueue->item_count < QUEUE_MAX_LENGTH) pQueue->item_count++;
    return true;

}
Item Dequeue(Queue *pQueue){
    Item blank = {0, 0};
    if (QueueIsEmpty(pQueue)){
        puts("Queue is empty. Abort.");
        return blank;
    }

    Item temp = pQueue->array[pQueue->read];
    pQueue->array[pQueue->read] = blank;
    pQueue->read = (pQueue->read + 1) % QUEUE_MAX_LENGTH;
    --pQueue->item_count;
    return temp;
}
bool QueueIsEmpty(const Queue *q){
    return (!q->item_count);
}
bool QueueIsFull(const Queue *q){
    return (q->item_count >= QUEUE_MAX_LENGTH);
}
bool SearchQueue(const Queue *q, Item item){
    for (int i = 0; i < QUEUE_MAX_LENGTH; i++) {
        if (q->array[i].data == item.data) return true; //No other way?
    }
    return false;
}

void ClearQueue(Queue ** q){
    free(*q);

}
void printQueue(const Queue *q){
    for (int i = 0; i < QUEUE_MAX_LENGTH; i++) {
        printf("%d ", q->array[i].data);
        if (!((i + 1) % 10)) printf("\n");
    }
    printf("\n");

}
