#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct NodeStruct {
    long data;
    NodePtr next;
    NodePtr prev;
} NodeStruct;


typedef struct ListStruct {
    NodePtr first;
    NodePtr last;
    NodePtr current;
} ListStruct;


ListHndl newList(void){
    ListHndl tempList = malloc ( sizeof(ListStruct) );
    tempList->first = tempList->last = tempList->current = NULL;
    return tempList;
}

void freeList (ListHndl* L){
    assert ((*L) != NULL); 
    if(isEmpty(*L)) makeEmpty(*L);
    free(*L);
    (*L) = NULL;
}

int isEmpty(ListHndl L){
    assert (L != NULL);
    return (L->first == NULL);
}

int offEnd(ListHndl L){
    assert (L != NULL);
    return (L->current == NULL);
}

int atFirst(ListHndl L){
    assert (L != NULL);
    return (L->current == L->first && !offEnd(L));
}

int atLast(ListHndl L){
    assert (L != NULL);
    return (L->current == L->last && !offEnd(L));
}

long getFirst(ListHndl L){
    assert(L != NULL && !isEmpty(L));
    return L->first->data;
}

long getLast(ListHndl L){
    assert(L != NULL && !isEmpty(L));
    return L->last->data;
}

long getCurrent(ListHndl L){
    assert(L != NULL && !offEnd(L));
    return L->current->data;
}

void makeEmpty(ListHndl L){
    assert (L != NULL);
    L->current = NULL;
    L->last = NULL;
    while(!isEmpty(L)) deleteFirst(L);
}

void moveFirst(ListHndl L){
    assert (L != NULL && !isEmpty(L));
    L->current = L->first;
}

void moveLast(ListHndl L){
    assert (L != NULL && !isEmpty(L));
    L->current = L->last;
}

void movePrev(ListHndl L){
    assert (L != NULL && !offEnd(L));
    L->current = L->current->prev;
}

void moveNext(ListHndl L){
    assert (L != NULL && !offEnd(L));
    L->current = L->current->next;
}

void insertAtFront(ListHndl L, long data){
    NodePtr temp;
    assert (L != NULL);
    temp = malloc(sizeof(NodeStruct));
    temp->data = data;
    temp->prev = NULL;
    temp->next = L->first;
    if(!isEmpty(L)) L->first->prev = temp;
    else L->last = temp;
    L->first = temp;
}

void insertAtBack(ListHndl L, long data){
    NodePtr temp;
    assert (L != NULL && !isEmpty(L));
    temp = malloc(sizeof(NodeStruct));
    temp->data = data;
    temp->next = NULL;
    temp->prev = L->last;
    if(!isEmpty(L)) L->last->next = temp;
    else L->first = temp;
    L->last = temp;
}

void insertBeforeCurrent(ListHndl L, long data){}

void deleteFirst(ListHndl L){}

void deleteLast(ListHndl L){}

void deleteCurrent(ListHndl L){}

void printList(FILE* out, ListHndl L){
    NodePtr currNode = L->first;
    assert(L != NULL);
    if (out == NULL) {
        fprintf(stderr, "Can't open output file!\n");
        exit(1);
    }
    if(L->first!=NULL) fprintf(out, "First:   %lu\n",L->first->data);
    else fprintf(out, "First:   NULL\n");
    if(L->last!=NULL) fprintf(out, "Last:    %lu\n",L->last->data);
    else fprintf(out, "Last:    NULL\n");
    if(L->current!=NULL) fprintf(out, "Current: %lu\n",L->current->data);
    else fprintf(out, "Current: NULL\n");
    fprintf(out, "Items in List:\n");
    while(currNode != NULL){
        fprintf(out, "%lu\n",currNode->data);
        currNode = currNode->next;
    }
}