//
// Created by ulysses on 6/10/17.
//
#include "LinkedList.h"



inline static clear_buffer(void){
    while (getchar() != '\n')
        continue;
}

bool DeleteNode (LinkedList *plist, Item item){ //Thanks Linus
	LNode **ppoint = &plist->head; //Points to head pointer
	LNode *entry = plist->head;
    LNode *temp;
	
	while (entry){ //while entry != NULL
		if (entry->item.data == item.data){
			temp = *ppoint;
			*ppoint = entry->next;
			free(temp);
            plist->list_size--;
            return true;
		}
		ppoint = &entry->next;
		entry = entry->next;
	}
    return false;
}

/*int delete(LinkedList *list, int value){ //Cormen's implementation
    Node *pointer = search(list, value);
    if(pointer == NULL)
        return 0;
    else if (pointer == list->head){ //Fix
        //free(list->head);
        pointer->next = NULL;
    }
    else{
        Node *previous = list->head;
        while (previous->next != NULL && previous->next != pointer)
            previous = previous->next;

        previous->next = (pointer->next == NULL)? NULL : pointer->next;

    }
    free(pointer);
    return 1; //No error
}
*/
LNode * Search(LinkedList *list, int value){
    LNode *pointer = list->head;
    while (pointer->next != NULL && pointer->item.data != value)
        pointer = pointer->next;
    return pointer;
}
bool InsertNode(LinkedList *list, int value){
    LNode *temp = malloc(sizeof(LNode));
    LNode **ppoint = &list->head;
    if (!temp){
        fprintf(stderr, "Error: Node cannot be created.");
        return false;
    }
    else temp->item.data = value, temp->next = NULL;

    while (*ppoint != NULL)
        ppoint = &((*ppoint)->next);

    *ppoint = temp;

    /*if (list->head == NULL) //Less Elegant
        list->head = temp;
    else{
        LNode *current = list->head;
        //while (current->next != NULL)
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
    } */
    list->list_size++;
    return true;
}



void InitializeList(LinkedList *list){
    printf("Enter a value for the first node in this list? [y/n]\n");
    char c = getchar();

    if(tolower(c) == 'y'){
        printf("Input a value :");
        scanf("%d", &list->head->item.data);
        list->list_size++;
        list->head->next = NULL;
    }
    else {list->head = NULL; return;}


    //clear_buffer();
}
void Clear_List(LinkedList *plist){
    LNode *current = plist->head, *swap;

    while (current != NULL){
        swap = current;
        current = current->next;
        free(swap);
    }
}
bool ListIsEmpty(LinkedList *plist){
    return (plist->list_size <= 0);
}
