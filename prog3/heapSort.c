/* heapSort.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: 
 */

#include "heap.h"

void heapSort(int keys[], int numKeys){
    heapHndl H = newHeap(numKeys);
    for(int i = 0; i < numKeys; i++) insert(H, keys[i]);
    for(int i = numKeys; i > 0; i--){
        keys[i] = maxValue(H);
        deleteMax(H);
    }
    /*freeHeap(&H);*/
}
