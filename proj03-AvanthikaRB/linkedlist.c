#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list. If malloc fails, print the error message and terminate the program with return code -1. 
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 * @return: a pointer to the head of the updated linked list
 */
node* addNode(node* head, char* key, char* value) {
    node* newnode = (node*)malloc(sizeof(node)); 
    if (newnode == NULL) {
        printf("memory allocation failed\n");
        exit(0);
    }
	newnode->key = key;
	newnode->value = value;
	newnode->next = head; 
	return newnode;
}

/* 
 * checks if there is a node in the linked list with the given key
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: value if the key is found, NULL otherwise
 */
char* getNode(node* head, char* key){
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
 * looks for a node with the given key, and if found, remove the node and return the corresponding value.
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: num is a pointer to an int variable to store the result. num should store 1 if a node was deleted, 0 otherwise. 
 * @return: a pointer to the head of the updated linked list
 */
node* deleteNode(node* head, char* key, int* num) {
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
            *num = 1; 
            return head; 
        }
        prev = current; 
        current = current->next;
    }
    *num = 0; //store num with 0 if node was not deleted
    return head; 
}


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
