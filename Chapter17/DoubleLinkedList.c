#include "DoubleLinkedList.h"

bool InsertNode(DList *plist, int value){ //Inserts in Front of Node
	DNode *temp = malloc(sizeof(DNode));
	if (temp == NULL){
		fprintf(stderr, "Error: Cannot create node.");
		return false;
	}
	temp->next = plist->head, temp->prev = NULL;
	if (plist->head == NULL){
		plist->head->prev = temp;
	plist->head = temp;		
}

bool RemoveNode(DList *plist, Item item){
	DNode *check = SearchDList(plist, item);
	if (!check){
		fprintf(stdout, "Node cannot be found.\n");
		return false;
	}
	if (check->prev != NULL)
		check->prev->next = check->next;
	else plist->head = check->next;
	
	if (check->next != NULL)
		check->next->prev = check->prev;
		
	free(check);
	return true;			
}
DNode * SearchDList(DList *plist, Item item){
	DNode *temp = plist->head;
	while (temp != NULL && temp->item.data != item.data)
		temp = temp->next;
	return temp;	
}

bool DListIsEmpty(DList *plist){
	return (plist->length == 0);
}


}

void InitializeDList(DList *plist){
	plist->head = NULL;
	plist->length = 0;
	plist->tail = NULL;
}

void InitializeCircularDList(CDList *plist){
	plist->null->item = {-1};
	plist->null->next = NULL;
	plist->null->prev = NULL;
	plist->tail = NULL;
	plist->length = 0;
}

DNode * SearchCDList(CDList *plist, Item item){
	DNode *temp = plist->null->next;
	while (temp != plist->null && temp->item.data != item.data)
		temp = temp->next;
	return temp;
}

bool DeleteCDNode(CDList *plist, Item item){
	DNode *find = SearchCDList(plist, item);
	if (find == NULL){
		fprintf(stdout, "Node not found\n");
		return false;
	}
	find->prev->next = find->next;
	find->next->prev = find->prev;
	return true;
}

bool InsertCDNode(CDList *plist, int key){
	DNode *insert = malloc(sizeof(DNode));
	if (insert == NULL){
		fprintf(stderr, "Error: Cannot create node.\n");
		return false;
	}
	insert->prev = plist->null;
	insert->next = plist->null->next;
	plist->null->next->prev = insert;
	plist->null->next = insert;
	return true;
}

