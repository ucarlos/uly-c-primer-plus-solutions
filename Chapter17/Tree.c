//
// Created by ulysses on 7/12/17.
//
// tree.c -- tree support functions
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

//Local data type:
typedef struct pair{
    Trnode *parent;
    Trnode *child;
}Pair;

//Prototypes for Local functions:
static Trnode * MakeNode(const Item *pi);
static bool ToLeft(const Item *itemp1, const Item *itemp2);
static bool ToRight(const Item *itemp1, const Item *itemp2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfunction)(Item item));
static Pair SearchItem(const Item *pi, const Tree *ptree); //Originally SeekItem
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

//function defintions:
void InitializeTree(Tree *ptree){
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree){
    return (ptree->root == NULL);
}

bool TreeIsFull(const Tree *ptree){
    return (ptree->size == MAXITEMS);
}

int TreeItemCount(const Tree *ptree){
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree){
    Trnode *new_node;
    if (TreeIsFull(ptree)){
        fprintf(stderr, "Tree is Full. \n");
        return false;
    }
    if (SearchItem(pi, ptree).child != NULL){
        fprintf(stderr, "Error: Attempted to add duplicate item.");
        return false;
    }

    new_node = MakeNode(pi);
    if (new_node == NULL){
        fprintf(stderr, "Error: Could not create node.");
        return false;
    }

    //Successful at creating new node:
    ptree->size++;
    if (ptree->root == NULL) //Case 1: Tree is empty
        ptree->root = new_node;
    else //Add node to tree
        AddNode(new_node, ptree->root);
    return true;
}

bool InTree(const Item *pi, const Tree *ptree){
    return (SearchItem(pi, ptree).child == NULL)? false : true;

}

bool DeleteItem(const Item *pi, Tree *ptree){
    Pair look = SearchItem(pi, ptree);

    if (look.child == NULL) //If item not found
        return false;

    if (look.parent == NULL) //Delete root item
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)//If Node is its Parent's left Node
        DeleteNode(&look.parent->left);
    else DeleteNode(&look.parent->right);

    ptree->size--;
    return true;
}

void Traverse(const Tree *ptree, void (*pointerfunct)(Item item)){
    if (ptree != NULL)
       InOrder(ptree->root, pointerfunct);
}

void DeleteAll(Tree *ptree){
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

//Local functions
static void InOrder(const Trnode *root, void (*pfunction)(Item item)){
    if (root != NULL){
        InOrder(root->left, pfunction);
        (*pfunction)(root->item);
        InOrder(root->right, pfunction);
    }
}

static void DeleteAllNodes(Trnode *root){
    Trnode *pright;
    if (root != NULL){
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Trnode *new_node, Trnode *root){
    if (ToLeft(&new_node->item, &root->item)) {
        if (root->left == NULL) //Empty Subtree
            root->left = new_node; //So add node here
        else AddNode(new_node, root->left); //Else, process subtree.
    }
    else if (ToRight(&new_node->item, &root->item)){
        if (root->right == NULL)
            root->right = new_node;
        else AddNode(new_node, root->right);
    }
    else{
        fprintf(stderr, "Error: An node with the same properties is already "
                "in the tree. Aborting.\n");
        exit(EXIT_FAILURE);
    }
}

static bool ToLeft(const Item *pointer1, const Item *pointer2){
    int compare;

    if ((compare = strcmp(pointer1->petname, pointer2->petname)) < 0)
        return true;//pointer1 < pointer2 ?
    else //If petnames are identical, compare pet_kinds, otherwise return false.
        return ((compare == 0 &&
                strcmp(pointer1->petkind, pointer2->petkind) < 0));

}

static bool ToRight(const Item *pointer1, const Item *pointer2){
    int compare;

    if ((compare = strcmp(pointer1->petname, pointer2->petname)) > 0)
        return true;
    else return (compare == 0 &&
                strcmp(pointer1->petkind, pointer2->petkind) > 0);

}

static Trnode *MakeNode(const Item *pi){
    Trnode *new_node = (Trnode *) malloc(sizeof(Trnode));

    if (new_node != NULL){
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SearchItem(const Item *pi, const Tree *ptree){
    Pair look = {NULL, ptree->root};
    if (look.child == NULL)
        return look;

    while (look.child != NULL){
        if (ToLeft(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item))){
            look.parent = look.child;
            look.child = look.child->right;
        }
        else //Must be the same if not left or right,
            break; // so look.child is address of node w/ item
    }
    return look;
}

static void DeleteNode(Trnode **ptr){
    Trnode *temp;

    if ((*ptr)->left == NULL){
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else{ //Deleted Node has two children
        //Find where to reattach right subtree
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }

}