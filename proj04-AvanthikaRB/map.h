#include "linkedlist.h"

typedef struct map {
    int size;
    int count; 
    float LF_high_thres;
    float LF_low_thres;
    node** list;
} map;

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 */
void add(map* m, char* key, char* value);

/* 
 * gets a value for the given key 
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: the corresponding value if the key is found, NULL otherwise
 */
char* get(map* m, char* key);

/* 
 * delete the node with the given key if found
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
void delete(map* m, char* key);

/* 
 * prints the linked list
 * @param: head is the pointer to the first node in the linked list
 */
void printMap(map m);
