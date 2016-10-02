/* sortComp.c
 * Brian Lin bjlin@ucsc.edu
 * Yunyi Ding yding13@ucsc.edu
 * Description: 
 */

#include <stdio.h> /* printf */
#include <time.h> /* clock_t, clock, CLOCKS_PER_SEC */

int main(){
    clock_t startTime, duration;
    // read your data and initialize array of unsorted keys
    startTime = clock();
    // run the sorting algorithm
    duration = clock() - startTime;
    printf ("sorting algorithm took %f seconds.\n", ((float) duration ) / CLOCKS_PER_SEC);
    return 0;
}
