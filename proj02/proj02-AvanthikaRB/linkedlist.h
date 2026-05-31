#include "node.h"

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
node* add(node* head, char* key, char* value);

/* 
 * gets a value for the given key 
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: the corresponding value if the key is found, NULL otherwise
 */
char* get(node* head, char* key);

/* 
 * delete the node with the given key if found
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
node* delete(node* head, char* key);

/* 
 * prints the linked list
 * @param: head is the pointer to the first node in the linked list
 */
void printList(node* head);
