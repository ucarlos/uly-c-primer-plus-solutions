//
// Created by ulysses on 7/1/17.
//
#include "queue.h"
int main(void){
    Queue line;
    Item temp;
    char ch;
    InitializeQueue(&line);
    puts("Testing the Queue interface. Type \"a\" to add a value.");
    puts("Type \"d\" to delete a value and type \"q\" to quit.");
    while ((ch = getchar()) != 'q'){
        if (ch != 'a' && ch != 'd') continue;
        if (ch == 'a'){
            printf("Enter integer to add.");
            scanf("%d", &temp);
            if (!QueueIsFull(&line)){
                printf("Putting %d into queue\n", temp);
                EnQueue(temp, &line);
            }
            else puts("Queue is full.");
        }
        else{
            if (QueueIsEmpty(&line))
                puts("Error: Queue is Empty.");
            else{
                DeQueue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("Current Queue Size: %d/%d\n", QueueItemCount(&line), MAXQUEUE);
        puts("Type \"a\" to add, \"d\" to delete and \"q\" to quit.");
    }
    EmptyTheQueue(&line);
    puts("Exiting.");
    return 0;
}
