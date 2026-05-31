#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

void add_print_test() {
    node* head = NULL;
    char key[] = "k";
    char value[] = "v";

    for (int i=9; i>=0; i--) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
	snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
	snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        head = add(head, newKey, newValue);
    }
    printList(head);
}
void get_found_test() {
    node* head = NULL;
    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<10; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        head = add(head, newKey, newValue);
    }

    char* returnValue = NULL;
    returnValue = get(head, "k3");
    if (returnValue == NULL) {
        printf("k3 is not found\n");
    } else {
        printf("k3's value is %s\n", returnValue);
    }
    returnValue = get(head, "k7");
    if (returnValue == NULL) {
        printf("k7 is not found\n");
    } else {
        printf("k7's value is %s\n", returnValue);
    }
}

void get_edge_test() {
    node* head = NULL;
    char key[] = "k";
    char value[] = "v";
    
    for (int i=0; i<10; i++) { 
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        head = add(head, newKey, newValue);
    }
    
    char* returnValue = NULL;
    returnValue = get(head, "k0");
    if (returnValue == NULL) {
        printf("k0 is not found\n");
    } else {
        printf("k0's value is %s\n", returnValue);
    }
    returnValue = get(head, "k9");
    if (returnValue == NULL) {
        printf("k9 is not found\n");
    } else {
        printf("k9's value is %s\n", returnValue);
    }
}

void get_fail_test() {
    node* head = NULL;
    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<10; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        head = add(head, newKey, newValue);
    }

    char* returnValue = get(head, "k11");
    if (returnValue == NULL) {
        printf("k11 is not found\n");
    } else {
        printf("k11's value is %s\n", returnValue);
    }
}

void delete_get_test() {
    node* head = NULL;
    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<10; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        head = add(head, newKey, newValue);
    }

    char* returnValue = get(head, "k4");
    if (returnValue == NULL) {
        printf("k4 is not found\n");
    } else {
        printf("k4's value is %s\n", returnValue);
    }
    head = delete(head, "k4");
    returnValue = get(head, "k4");
    if (returnValue == NULL) {
        printf("k4 is not found\n");
    } else {
        printf("k4's value is %s\n", returnValue);
    }
}

void delete_edge_test() {
    node* head = NULL;
    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<10; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        head = add(head, newKey, newValue);
    }
    head = delete(head, "k0");
    printList(head);
    head = delete(head, "k9");
    printList(head);
}

void delete_add_test() {
    node* head = NULL;
    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<10; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        head = add(head, newKey, newValue);
    }

    head = delete(head, "k4");
    printList(head);
    head = add(head, "k4", "v4");
    char* returnValue = get(head, "k4");
    if (returnValue == NULL) {
        printf("k4 is not found\n");
    } else {
        printf("k4's value is %s\n", returnValue);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argv[1][0] > '6' || argv[1][0] < '0') {
	   printf("Usage: ./proj02 [0..6]\n");
	   exit(-1);
    }
    void (*tests[10])();
    tests[0] = &add_print_test; //10 points
    tests[1] = &get_found_test; //10 points
    tests[2] = &get_fail_test; //10 points
    tests[3] = &get_edge_test; //10 points
    tests[4] = &delete_get_test;  //20 points
    tests[5] = &delete_edge_test; //20 points
    tests[6] = &delete_add_test; //20 points

    (*tests[(int) (argv[1][0]-'0')])();
}
