/* HashTable.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: 
 */

#include "HashTable.h"
#include <assert.h>
#include <tgmath.h>
#include <string.h>
#include <stdlib.h>

typedef struct HashNodeStruct{
    char* name;
    ListHndl L;
}HashNodeStruct;

typedef struct HashTableStruct{
    int tableSize;
    ListHndl* array;
} HashTableStruct;

HashTable newTable(int tableSize){
    HashTable tempTable = malloc(sizeof(HashTableStruct));
    tempTable->tableSize = tableSize;
    tempTable->array = calloc((tableSize),sizeof(ListHndl));
    for(int i = 0; i < tableSize; i++) tempTable->array[i] = newList();
    return tempTable;
}

HashNode newHashNode(char* name){
    HashNode tempNode = malloc(sizeof(HashNode));
    tempNode->name = name;
    tempNode->L = newList();
    return tempNode;
}

void freeNode(HashNode* N){
    assert((*N) != NULL);
    freeList(&((*N)->L));
    free(*N);
    (*N) = NULL;
}

void freeTable(HashTable* H){
    assert ((*H) != NULL);
    for(int i = 0; i < (*H)->tableSize; i++){
        if(isEmpty((*H)->array[i])){
            freeList(&((*H)->array[i]));
            continue;
        }
        moveFirst((*H)->array[i]);
        while(!offEnd((*H)->array[i])){
            HashNode N = getCurrent((*H)->array[i]);
            freeNode(&N);
            moveNext((*H)->array[i]);
        }
        freeList(&((*H)->array[i]));
    }
    free((*H)->array);
    free(*H);
    (*H) = NULL;
}

long hash(unsigned char* key){
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return abs(hash);
}

ListHndl lookup(HashTable H, char* key){
    assert (H != NULL);
    ListHndl slot = H->array[hash((unsigned char*)key) % H->tableSize];
    if(isEmpty(slot)) return NULL;
    else moveFirst(slot);
    while(!offEnd(slot)){
        HashNode temp = getCurrent(slot);
        if(strcmp(key,temp->name) == 0) return temp->L;
        else moveNext(slot);
    }
    return NULL;
}

void insert(HashTable H, char* name, int num){
    assert (H != NULL);
    ListHndl L = lookup(H, name);
    if(L == NULL){
        ListHndl slot = H->array[hash((unsigned char*)name) % H->tableSize];
        HashNode N = newHashNode(name);
        L = N->L;
        insertAtBack(slot,N);
    }
    insertAtBack(L,&num);
}

void deleteHashNode(HashTable H, char* name){
    assert (H != NULL);
    ListHndl slot = H->array[hash((unsigned char*)name) % H->tableSize];
    if(isEmpty(slot)) return;
    moveFirst(slot);
    while(!offEnd(slot)){
        HashNode temp = getCurrent(slot);
        if(strcmp(name, temp->name) == 0){
            freeNode(&temp);
            deleteCurrent(slot);
        }else moveNext(slot);
    }
}

void deleteListNode(HashTable H, char* name, int num){
    assert (H != NULL);
    ListHndl L = lookup(H, name);
    if(L == NULL) return;
    moveFirst(L);
    while(!offEnd(L)){
        int* temp = getCurrent(L);
        if(*temp == num){
            deleteCurrent(L);
            break;
        }
        moveNext(L);
    }
    if(isEmpty(L)){
        ListHndl slot = H->array[hash((unsigned char*)name) % H->tableSize];
        freeNode(getCurrent(slot));
        deleteCurrent(slot);
    }
}

void printTable(HashTable H){
    assert (H != NULL);
	printf("HashTable: Size %d\n", H->tableSize);
    for(int i = 0; i < H->tableSize; i++){
        printf("%d:\n",i);
        if(isEmpty(H->array[i])) continue;
        moveFirst(H->array[i]);
        while(!offEnd(H->array[i])){
            HashNode N = getCurrent(H->array[i]);
            printf("-%s\n",N->name);
            moveFirst(N->L);
            while(!offEnd(N->L)){
                printf("--%p\n",getCurrent(N->L));
                moveNext(N->L);
            }
            moveNext(H->array[i]);
        }
    }
}
