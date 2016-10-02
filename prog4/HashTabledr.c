/* HashTabledr.c
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: 
 */

#include "HashTable.h"
#include <stdio.h>

int main(void){
    HashTable thisTable = newTable(10);
    insert(thisTable, "Harry Potter", 1241);
    insert(thisTable, "Harry Potter", 2436);
    insert(thisTable, "Harry Potter", 35658);
    insert(thisTable, "Harry Potter", 474523);
    
    insert(thisTable, "Introduction to Algorithms", 1241);
    insert(thisTable, "Introduction to Algorithms", 2579);
    insert(thisTable, "Introduction to Algorithms", 35658);
    insert(thisTable, "Introduction to Algorithms", 4754);
    
    printTable(thisTable);
    
    deleteListNode(thisTable, "Harry Potter", 1241);
    deleteListNode(thisTable, "Harry Potter", 9);
    
    printTable(thisTable);
    
    deleteHashNode(thisTable, "Introduction to Algorithms");
    deleteHashNode(thisTable, "Walmart Effect");
    
    printTable(thisTable);
    
    FILE *out = fopen("out.out", "w");
    printList(out, lookup(thisTable, "Harry Potter"));
    
    freeTable(&thisTable);
    fclose(out);
    return 0;
}