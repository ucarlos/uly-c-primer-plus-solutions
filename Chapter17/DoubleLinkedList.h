#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "common_header.h"
typedef struct item{
	int data;
}Item;

typedef struct dlnode{
	Item item;
	struct dlnode *next, *prev;
}DNode;


typedef struct dlist{
	DNode *head, *tail;
	unsigned int length;
}DList;

typedef struct cdlist{//Circular Double LinkedList
	DNode *null, *tail;
	unsigned int length;
}CDList;
//functions:
//Insert, Remove, Search, IsEmpty, Traverse;
bool InsertNode(DList *plist, int value);
bool RemoveNode(DList *plist, Item item);
DNode * SearchDList(DList *plist, Item item);
bool DListIsEmpty(DList *plist);
void InitializeDList(DList *plist);

//For Circular Double LinkedLists
void InitializeCircularDList(CDList *plist);
bool InsertCDNode(CDList *plist, int value);
bool RemoveCDNode(CDList *plist, Item item);
DNode * SearchCDList(CDList *plist, Item item);
			
#endif //CHAPTER17_DOUBLELINKEDLIST_H
