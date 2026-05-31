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
    // your code here
    node* new_Node = (node*)malloc(sizeof(node));
    if (new_Node == NULL) {
        printf("Malloc error occured \n");
        exit(EXIT_FAILURE);
    }
    new_Node->next = head;
    new_Node->key = strdup(key);
    new_Node->value = strdup(value);

    return new_Node; 
}

/* 
 * checks if there is a node in the linked list with the given key
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: value if the key is found, NULL otherwise
 */
char* getNode(node* head, char* key){
    // your code from proj02 here
    node* curr = head;

    while(curr != NULL){
        if(strcmp(curr->key, key)==0){
            return curr->value;
        }
        curr = curr->next;
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
    // your code here
        node*curr = head;
    node *prev = NULL;
    node *nextnode = NULL;
    int *n = num;

    while(curr != NULL){
        if(strcmp(curr->key, key) ==0){
            if(prev !=NULL){
                prev->next = curr->next;
            }else{
                head = curr->next;
            }
            free(curr->key);     
            free(curr->value);      
            free(curr); 
            *n = 1;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    *n=0;
    return head;
}

void printList(node* head) {
    // your code from proj02 here
    node*curr = head;
    printf("[");
    while (curr != NULL) {
       printf("[%s,%s]", curr->key, curr->value);
       if (curr->next != NULL) {
           printf(",");
        }
           curr = curr->next; 
    }
    printf("]\n");
} 
