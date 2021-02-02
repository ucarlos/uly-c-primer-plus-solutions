//
// Created by ulysses on 7/17/17.
//
#include "common_header.h"
#include "Tree_problem07.h"
void InsertIntoTree(Tree *ptree, FILE *fp);
void Menu(Tree *ptree, FILE *fp);
static void PrintWord(const Item item);
static void SearchWord(const Tree *ptree);
static void StrtoLower(char *str);

inline static clear_buffer(void){
    while (getchar() != '\n')
        continue;
}
int main(void){
    Tree *tree1;
    FILE *filepoint;
    if ((filepoint = fopen("../sample1.txt", "r")) == NULL){
        fprintf(stderr, "Error: File either does not exist or cannot be opened.\n");
        exit(EXIT_FAILURE);
    }
    InitializeTree(tree1);
    InsertIntoTree(tree1, filepoint);




    fclose(filepoint);
}
void InsertIntoTree(Tree *ptree, FILE *fp) {
    char tempstr[SLEN];
    while (getc(fp) != EOF) {
        fscanf(fp, "%s", tempstr);
        StrtoLower(tempstr);
        Item item = {tempstr, 0};
        Pair search = SearchItem(&item, ptree);
        if ((search.child) != NULL)//Node exists
            search.child->item.occurrences++;
        else
            AddItem(&item, ptree); //Search again...
    }
}
void Menu(Tree *ptree, FILE *fp){
    char input;
    printf("Please make a selection from the following Choices:");
    printf("a)Print all words\tb)Search for a specific word\nq)Quit");
    while ((input = tolower(getchar()) != EOF)){
        clear_buffer();
        switch(input){
            case 'a':
                Traverse(ptree,PrintWord);break;
            default:
                printf("Invalid input.");break;

        }
    }
}

static void PrintWord(Item item){
    printf("Word: %s\tOccurances: %d\n",item.word, item.occurrences);
}
static void SearchWord(const Tree *ptree){
    clear_buffer();
    char input[SLEN];
    printf("Enter word:");
    scanf("%s", input);
    Item item = {input};
    Pair temp = SearchItem(&item, ptree);
    if (temp.child != NULL){
        printf("Word found. Displaying Contents:");
        PrintWord(temp.child->item);
    }
    else printf("Word not found.\n");
}
static void StrtoLower(char *str){
    for (char *ptr = str; *ptr; ptr++){
        if (isalpha(*ptr))
            *ptr = tolower(*ptr);
    }
}
