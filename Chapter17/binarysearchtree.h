//
// Created by ulysses on 7/16/17.
//

#ifndef CHAPTER17_BINARYSEARCHTREE_H
#define CHAPTER17_BINARYSEARCHTREE_H
#include "common_header.h"

typedef struct item{
  int data;
}Item;

typedef struct tree_node{
    Item item;
    struct tree_node *parent, *left, *right;
}TNode;

typedef struct tree{
    TNode *root;
    int tree_size;
}Tree;

//Function declarations
#endif //CHAPTER17_BINARYSEARCHTREE_H
