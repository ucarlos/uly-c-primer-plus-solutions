//
// Created by ulysses on 7/13/17.
//
//petclub.c -- Uses a binary search tree
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Tree.h"

char menu(void);
void addpets(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *string);
char * s_gets(char *string, int n);

int main(void){
    Tree pets;
    char choice;
    InitializeTree(&pets);
    while ((choice = menu()) != 'q'){
        switch(choice){
            case 'a': addpets(&pets);
                break;
            case 'l' : showpets(&pets);
                break;
            case 'f' : findpet(&pets);
                break;
            case 'n' : printf("%d pets in club\n",TreeItemCount(&pets));
                break;
            case 'd' : droppet(&pets);
                break;
            default  : puts("Invalid Character. Try again.");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");

    return 0;
}

char menu(void){
    int ch;
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    printf("a) Add a pet \t\t\tl) Show list of pets\n");
    printf("n) Number of pets\t\tf) Find pets\n");
    printf("d) Delete a pet\t\t\tq) Quit\n");
    while ((ch = getchar()) != EOF){
        while (getchar() != '\n')
            continue;
        ch = tolower(ch);
        if (strchr("alrfdq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q :");
        else break;
    }
    if (ch == EOF)
        ch = 'q';
    return ch;
}

void addpets(Tree *pt){
    Item temp;
    if (TreeIsFull(pt))
        puts("No room in the club!");
    else{
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind, SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        AddItem(&temp, pt);
    }
}

void showpets(const Tree *pt){
    if (TreeIsEmpty(pt))
        puts("There are no pets in the club.");
    else Traverse(pt, printitem);
}

void printitem(Item item){
    printf("Pet: %s\tKind: %s\n", item.petname, item.petkind);
}

void findpet(const Tree *pt){
    Item temp;
    if (TreeIsEmpty(pt)){
        puts("There are no pets in the club.");
        return;
    }


    puts("Enter the name of the pet to look up:");
    s_gets(temp.petname, SLEN);
    puts("Enter pet kind:");
    s_gets(temp.petname, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (InTree(&temp, pt))
        printf("is a member of the club.\n");
    else printf("is not a member.\n");
}

void droppet(Tree *pt){
    Item temp;
    if (TreeIsEmpty(pt)){
        puts("There are no pets in the club.");
        return;
    }
    puts("Enter the name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (DeleteItem(&temp, pt))
        printf("is dropped from the club.\n");
    else printf("is not a member.\n");
}

void uppercase(char *string){
    for (char *ptr = string; *ptr; ptr++)
        *ptr = toupper(*ptr);
}

char * s_gets(char *string, int n){
    char *return_value, *find;
    return_value = fgets(string, n, stdin);
    if (return_value){
        find = strchr(string, "\n");
        if (find)
            *find = '\0';
        else while (getchar() != '\n')
                continue;
    }
    return return_value;
}
