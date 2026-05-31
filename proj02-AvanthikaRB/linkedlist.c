#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"


/* 
 * adds a new node with a given (key, value) in the beginning of the linked list
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
 //add function returns pointer to the new head
node* add(node* head, char* key, char* value) {
    node* newnode = (node*)malloc(sizeof(node)); 
    if (newnode == NULL) {
        printf("memory allocation failed\n");
        return 0;
    }
	newnode->key = key;
	newnode->value = value;
	newnode->next = head; 
	return newnode;
}


/* 
 * gets a value for the given key 
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: the corresponding value if the key is found, NULL otherwise
 */
 //key is what to search for in linked list. 
char* get(node* head, char* key) {
    node* current = head; 
    while (current != NULL) {  
        if (strcmp(current->key, key) == 0) { //compares key of current node with the key.return 0 means 2 strings are equal.return 0 means 2 strings are equal.
            return current->value;	
        }
        current = current->next; 
    }
    return NULL;
}

/* 
 * delete the node with the given key if found
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
node* delete(node* head, char* key) {
    node* current = head; 
    node* prev = NULL; 
    while (current != NULL) { 
        if (strcmp(current->key, key) == 0) { //compares key in current node to the key. 0 means equal strings
			//function deletes current node from linked list if equal
            if (prev == NULL) { //if current node is the head, point to next node
                head = current->next;  
            } else { 	
                prev->next = current->next; //deletes from list
            }
            free(current->key); //memory deallocation/memory management
            free(current->value);
            free(current);
            return head; 
        }
        prev = current; 
        current = current->next;
    }
    return head; 
}

/* 
 * prints the linked list
 * @param: head is the pointer to the first node in the linked list
 */
void printList(node* head) {
    node* current = head;
    if(head == NULL){
        printf("[]\n");
        return;
    }
    printf("[");
    while (current->next != NULL) {
        printf("[%s,%s],", current->key, current->value); 
        current = current->next;
    }
    printf("[%s,%s]]\n", current->key, current->value);    
}
