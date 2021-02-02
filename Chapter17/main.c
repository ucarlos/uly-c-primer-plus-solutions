#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/ioctl.h>

typedef struct bog{
    int a;
    int b;
}Bog;

int main(void) {
    Bog *pb1;
    pb1->a = 1, pb1->b = 2;
    Bog *pb2 = NULL;

    printf("Contents of Pointer 1 are as follows: %d\t%d\n", pb1->a, pb1->b);
    printf("Contents of Pointer 2 are as follows: %d\t%d\n", pb2->a, pb2->b);

}