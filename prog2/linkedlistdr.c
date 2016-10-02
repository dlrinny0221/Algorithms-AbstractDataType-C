#include "linkedlist.h"
#include "stdio.h"

int main(){
    ListHndl TheList = newList();
    FILE *out = fopen("out.out", "w");
    
    /*test empty in empty case*/
    if(isEmpty(TheList)) printf("Empty");
    else printf("not Empty");
    
    //testing insert one number
    insertAtFront(TheList,35728);
    printf("%lu\n",getFirst(TheList));
    printf("%lu\n",getLast(TheList));
    //should have same value
    
    
    
    printList(out, TheList);
    return 0;
}
