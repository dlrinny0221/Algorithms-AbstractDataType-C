/* heap.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: 
 */

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct HeapStruct{
    int maxSize;
    int currentSize;
    int* array;
} HeapStruct;

void swim(heapHndl H, int pos){
    assert(H != NULL);
    assert(pos < H->currentSize+1 && pos > 0);
    while(H->array[pos/2] < H->array[pos] && pos > 1){
        int temp = H->array[pos/2];
        H->array[pos/2] = H->array[pos];
        H->array[pos] = temp;
        pos = pos/2;
    }
}

void sink(heapHndl H, int pos){
    assert(H != NULL);
    assert(pos < H->currentSize+1 && pos > 0);
    for(;;){
        int newpos = pos*2;
        if(newpos > H->maxSize) break;
        if(newpos > H->currentSize) break;
        if(H->array[pos] > H->array[newpos]){
            newpos++;
            if(newpos > H->maxSize) break;
            if(newpos > H->currentSize) break;
            if(H->array[pos] > H->array[newpos]) break;
        }
        int temp = H->array[pos];
        H->array[pos] = H->array[newpos];
        H->array[newpos] = temp;
        pos = newpos;
    }
}

heapHndl newHeap(int maxSize){
    heapHndl tempHeap = malloc(sizeof(HeapStruct));
    tempHeap->maxSize = maxSize;
    tempHeap->currentSize = 0;
    tempHeap->array = malloc((maxSize+1)*sizeof(int));
    return tempHeap;
}

void freeHeap(heapHndl* H){
    assert ((*H) != NULL);
    free((*H)->array);
    free(*H);
    (*H) = NULL;
}

Boolean isFull(heapHndl H){
    assert (H != NULL);
    if(H->currentSize == H->maxSize) return TRUE;
    else return FALSE;
}

Boolean isEmpty(heapHndl H){
    assert(H != NULL);
    if(H->currentSize == 0) return TRUE;
    else return FALSE;
}

int maxValue(heapHndl H){
    assert(H != NULL);
    return H->array[1];
}

void deleteMax(heapHndl H){
    assert(H != NULL);
    assert(!isEmpty(H));
    H->array[1] = H->array[H->currentSize];
    sink(H,1);
    H->currentSize--;
}

void insert(heapHndl H, int priority){
    assert(H != NULL);
    assert(!isFull(H));
    H->currentSize++;
    H->array[H->currentSize] = priority;
    swim(H,H->currentSize);
}

void printHeap(heapHndl H){
    assert(H != NULL);
    printf("currentSize: %d\n", H->currentSize);
    printf("maxSize: %d\n", H->maxSize);
    int skipLine = 1;
    int height = 1;
    for(int i = 1; i < H->currentSize+1; i++){
        printf("%d ", H->array[i]);
        if(i == skipLine){
            printf("\n");
            int power = 1;
            for(int j = 0; j < height; j++) power *= 2;
            skipLine+=power;
            height++;
        }
    }
    printf("\n");
}
