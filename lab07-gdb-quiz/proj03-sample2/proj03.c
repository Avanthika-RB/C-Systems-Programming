#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "map.h"

#define DEFAULT_SIZE 16

void add_print_test() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    char key[] = "k";
    char value[] = "v";

    for (int i=9; i>=0; i--) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        add(m, newKey, newValue);
    }
    printf("Map has %d (key, value) pairs.\n", m->count);
    printMap(*m);
}

void get_found_test() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<10; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+1));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+1));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        add(m, newKey, newValue);
    }

    char* returnValue = NULL;
    returnValue = get(m, "k3");
    if (returnValue == NULL) {
        printf("k3 is not found\n");
    } else {
        printf("k3's value is %s\n", returnValue);
    }
    returnValue = get(m, "k7");
    if (returnValue == NULL) {
        printf("k7 is not found\n");
    } else {
        printf("k7's value is %s\n", returnValue);
    }
}

void get_edge_test() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    char key[] = "k";
    char value[] = "v";
    
    for (int i=0; i<20; i++) { 
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+2));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+2));
        snprintf(newKey, sizeof(key)+2, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+2, "%s%d", value, i);
        add(m, newKey, newValue);
    }
    
    char* returnValue = NULL;
    returnValue = get(m, "k1");
    if (returnValue == NULL) {
        printf("k1 is not found\n");
    } else {
        printf("k1's value is %s\n", returnValue);
    }
    returnValue = get(m, "k11");
    if (returnValue == NULL) {
        printf("k11 is not found\n");
    } else {
        printf("k11's value is %s\n", returnValue);
    }
}

void get_fail_test() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<20; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+2));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+2));
        snprintf(newKey, sizeof(key)+2, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+2, "%s%d", value, i);
        add(m, newKey, newValue);
    }

    char* returnValue = NULL;
    returnValue = get(m, "k21");
    if (returnValue == NULL) {
        printf("k21 is not found\n");
    } else {
        printf("k21's value is %s\n", returnValue);
    }
}

void delete_get_test() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<20; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+2));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+2));
        snprintf(newKey, sizeof(key)+1, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+1, "%s%d", value, i);
        add(m, newKey, newValue);
    }

    char* returnValue = NULL;
    returnValue = get(m, "k4");
    if (returnValue == NULL) {
        printf("k4 is not found\n");
    } else {
        printf("k4's value is %s\n", returnValue);
    }
    printf("Map has %d (key, value) pairs.\n", m->count);
    delete(m, "k4");
    printf("Map has %d (key, value) pairs.\n", m->count);
    returnValue = get(m, "k4");
    if (returnValue == NULL) {
        printf("k4 is not found\n");
    } else {
        printf("k4's value is %s\n", returnValue);
    }
}

void delete_edge_test() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<20; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+2));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+2));
        snprintf(newKey, sizeof(key)+2, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+2, "%s%d", value, i);
        add(m, newKey, newValue);
    }
    printMap(*m);
    delete(m, "k10");
    printf("\nafter deleting k10\n");
    printMap(*m);
    delete(m, "k11");
    printf("\nafter deleting k11\n");
    printMap(*m);
}

void delete_add_test() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<20; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+3));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+3));
        snprintf(newKey, sizeof(key)+2, "%s%d\0", key, i);
        snprintf(newValue, sizeof(value)+2, "%s%d\0", value, i);
        add(m, newKey, newValue);
    }

    delete(m, "k4");
    char* returnValue = NULL;
    returnValue = get(m, "k4");
    if (returnValue == NULL) {
        printf("k4 is not found\n");
    } else {
        printf("k4's value is %s\n", returnValue);
    }
    add(m, "k4", "v4");
    returnValue = get(m, "k4");
    if (returnValue == NULL) {
        printf("k4 is not found\n");
    } else {
        printf("k4's value is %s\n", returnValue);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argv[1][0] > '6' || argv[1][0] < '0') {
	   printf("Usage: ./proj03 [0..6]\n");
	   exit(-1);
    }
    void (*tests[7])();
    tests[0] = &add_print_test; //10 points
    tests[1] = &get_found_test; //10 points
    tests[2] = &get_fail_test; //10 points
    tests[3] = &get_edge_test; //10 points
    tests[4] = &delete_get_test;  //20 points
    tests[5] = &delete_edge_test; //20 points
    tests[6] = &delete_add_test; //20 points

    (*tests[(int) (argv[1][0]-'0')])();
}
