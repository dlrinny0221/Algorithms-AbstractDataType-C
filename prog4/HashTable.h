/* HashTable.h
 * Yunyi Ding yding13@ucsc.edu
 * Brian Lin bjlin@ucsc.edu
 * Description: header file for the HashTable ADT 
 */

#include "List.h"

/* define the node and list structures */
typedef struct HashNodeStruct * HashNode;
typedef struct ListNodeStruct * ListNode;
typedef struct HashTableStruct * HashTable;

/*** Constructors-Destructors ***/
HashTable newTable(int tableSize);
void freeTable(HashTable* H); /* Pre: H has been created with newTable.*/

/* NOTE: all Access functions and Manipulation procedures also have the
   precondition that H has been initialized by newHeap().
 */

/*** Access functions ***/
/* returns the List of the HashNode corresponding to the key
 * returns NULL if doesn't exist */
ListHndl lookup(HashTable H, char* key);

/*** Manipulation procedures ***/
/* returns true if heap is full, else return false
 * Pre: !isFull()
 */
void insert(HashTable H, char* name, int num);

/* delete the (book) HashNode from the table
 * If book does not exist, nothing happens */
void deleteHashNode(HashTable H, char* name);

/* delete the ListNode (library number) from a HashNode's list
 * if the list is empty after operation, HashNode is also deleted
 * If library does not exist, nothing happens */
void deleteListNode(HashTable H, char* name, int num);

/* prints the HashTable */
void printTable(HashTable H);
