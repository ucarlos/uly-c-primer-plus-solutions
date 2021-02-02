//
// Created by ulysses on 5/4/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/poll.h>
struct phonebook {
    char name[100];
    unsigned long phone_number;
};
void search(char *name, struct phonebook list[], int length);
int compare(const struct phonebook *pointer1, const struct phonebook *pointer2);

int main(void){
    int plength;
    scanf("%d", &plength);

    struct phonebook list[plength];
    for (int i = 0; i < plength; i++)
        scanf("%s %lu", list[i].name, &list[i].phone_number);
    qsort(list, (size_t)plength, sizeof(struct phonebook), compare);

    char input[100];
    struct pollfd fds;
    fds.fd = 0, fds.events = POLLIN;

    scanf("%s", input);
    while (poll(&fds, 1, 0) == 1){ // I have no idea how to terminate input.
        struct phonebook *result = bsearch(input, list, (size_t)plength, sizeof(struct phonebook), compare);
        if(result == NULL)
            printf("Not found\n");
        else
            printf("%s=%lu\n", result->name, result->phone_number);
        scanf("%s", input);

    }


    return 0;
}

int compare(const struct phonebook *pointer1, const struct phonebook *pointer2){
    return strcasecmp(pointer1->name, pointer2->name);
}