/* heapDriver.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: 
 */

#include "heap.h"
#include <stdio.h>

int main(void){
    heapHndl thisHeap = newHeap(256);
    if(isEmpty(thisHeap)) printf("EMPTY\n");
    else printf("NOT EMPTY\n");
    insert(thisHeap, 10);
    printHeap(thisHeap);
    insert(thisHeap, 3);
    printHeap(thisHeap);
    insert(thisHeap, 3);
    printHeap(thisHeap);
    insert(thisHeap, 17);
    printHeap(thisHeap);
    insert(thisHeap, 5);
    printHeap(thisHeap);
    insert(thisHeap, 13);
    printHeap(thisHeap);
    insert(thisHeap, 4);
    printHeap(thisHeap);
    insert(thisHeap, 11);
    printHeap(thisHeap);
    insert(thisHeap, 17);
    printHeap(thisHeap);
    insert(thisHeap, 7);
    printHeap(thisHeap);
    insert(thisHeap, 13);
    printHeap(thisHeap);
    printf("max: %d\n", maxValue(thisHeap));
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    deleteMax(thisHeap);
    printHeap(thisHeap);
    if(isFull(thisHeap)) printf("FULL\n");
    else printf("NOT FULL\n");
    freeHeap(&thisHeap);
    return 0;
}