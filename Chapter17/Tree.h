//
// Created by ulysses on 7/2/17.
//

#ifndef CHAPTER17_TREE_H
#define CHAPTER17_TREE_H
#include <stdbool.h>
#define SLEN 50

typedef struct item{ //Used for TestTree.c and petclub.c
    char petname[SLEN], petkind[SLEN];
}Item;



#define MAXITEMS 20
typedef struct trnnode{
    Item item;
    //Pointers to left and right branches respectively
    struct trnode *left, *right;
}Trnode;

typedef struct tree{
    Trnode *root; //Pointer to root of tree
    int size;
}Tree;

typedef struct pair{
    Trnode *parent;
    Trnode *child;
}Pair;
//function prototypes:
void InitializeTree(Tree *ptree);
bool TreeIsEmpty(const Tree *ptree);
bool TreeIsFull(const Tree *ptree);
int TreeItemCount(const Tree *ptree);
bool AddItem(const Item *pi, Tree *ptree);
bool InTree(const Item *pi, const Tree *ptree);
bool DeleteItem(const Item *pi, Tree *ptree);
void Traverse(const Tree *ptree, void(* pfun)(Item item));
Pair SearchItem(const Item *pi, const Tree *ptree);
void DeleteAll(Tree *ptree);

#endif //CHAPTER17_TREE_H
