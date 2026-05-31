#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "map.h"

#define DEFAULT_SIZE 16

map* createMap() {
    map* m = (map*) malloc(sizeof(map)); 
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->LF_high_thres = 0.75;
    m->LF_low_thres = 0.25;
    m->list = (node**) malloc(sizeof(node*)*m->size);
    memset(m->list, 0, sizeof(node*)*m->size);

    return m;
}

void add_limit_test() {
    map* m = createMap();

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<=1048576; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+8));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+8));
        snprintf(newKey, sizeof(key)+8, "%s%d\0", key, i);
        snprintf(newValue, sizeof(value)+8, "%s%d\0", value, i);
        int oldSize = m->size;
        add(m, newKey, newValue);
        if (oldSize != m->size) {
            printf("Map has %d items in size %d.\n", m->count, m->size);
        }
    }
    printf("Map has %d items in size %d.\n", m->count, m->size);
}

void delete_limit_test() {
    map* m = createMap();

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<=1048576; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+8));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+8));
        snprintf(newKey, sizeof(key)+8, "%s%d\0", key, i);
        snprintf(newValue, sizeof(value)+8, "%s%d\0", value, i);
        int oldSize = m->size;
        add(m, newKey, newValue);
    }
    printf("Map has %d items in size %d.\n", m->count, m->size);
    for (int i=0; i<=1048572; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+8));
        snprintf(newKey, sizeof(key)+8, "%s%d\0", key, i);
        int oldSize = m->size;
        delete(m, newKey);
        if (oldSize != m->size) {
            printf("Map has %d items in size %d.\n", m->count, m->size);
        }
    }
    printf("Map has %d items in size %d.\n", m->count, m->size);
    printMap(*m);
}

void add_delete_test() {
    map* m = createMap();

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<=19; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+3));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+3));
        snprintf(newKey, sizeof(key)+3, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+3, "%s%d", value, i);
        int oldSize = m->size;
        add(m, newKey, newValue);
        if (oldSize != m->size) {
            printf("Map has %d items in size %d.\n", m->count, m->size);
        }
    }
    printf("Map has %d items in size %d.\n", m->count, m->size);
    printMap(*m);
    printf("\n");

    for (int i=0; i<=15; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+3));
        snprintf(newKey, sizeof(key)+3, "%s%d", key, i);
        int oldSize = m->size;
        delete(m, newKey);
        if (oldSize != m->size) {
            printf("Map has %d items in size %d.\n", m->count, m->size);
            printMap(*m);
        }
    }
    printf("Map has %d items in size %d.\n", m->count, m->size);
    printMap(*m);
}

void get_found_test() {
    map* m = createMap();

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<100; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+3));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+3));
        snprintf(newKey, sizeof(key)+3, "%s%d\0", key, i);
        snprintf(newValue, sizeof(value)+3, "%s%d\0", value, i);
        add(m, newKey, newValue);
    }

    char* returnValue = NULL;
    returnValue = get(m, "k33");
    if (returnValue == NULL) {
        printf("k33 is not found\n");
    } else {
        printf("k33's value is %s\n", returnValue);
    }
    returnValue = get(m, "k97");
    if (returnValue == NULL) {
        printf("k97 is not found\n");
    } else {
        printf("k97's value is %s\n", returnValue);
    }
}

void get_edge_test() {
    map* m = createMap();

    char key[] = "k";
    char value[] = "v";
    
    for (int i=0; i<20; i++) { 
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+3));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+3));
        snprintf(newKey, sizeof(key)+3, "%s%d\0", key, i);
        snprintf(newValue, sizeof(value)+3, "%s%d\0", value, i);
        add(m, newKey, newValue);
    }
    printMap(*m);
    char* returnValue = NULL;
    returnValue = get(m, "k10");
    if (returnValue == NULL) {
        printf("k10 is not found\n");
    } else {
        printf("k10's value is %s\n", returnValue);
    }
    returnValue = get(m, "k13");
    if (returnValue == NULL) {
        printf("k13 is not found\n");
    } else {
        printf("k13's value is %s\n", returnValue);
    }
}

void get_fail_test() {
    map* m = createMap();

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
    map* m = createMap();

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<256; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+3));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+3));
        snprintf(newKey, sizeof(key)+3, "%s%d", key, i);
        snprintf(newValue, sizeof(value)+3, "%s%d", value, i);
        add(m, newKey, newValue);
    }

    char* returnValue = NULL;
    returnValue = get(m, "k124");
    if (returnValue == NULL) {
        printf("k124 is not found\n");
    } else {
        printf("k124's value is %s\n", returnValue);
    }
    printf("Map has %d items.\n", m->count);
    delete(m, "k124");
    printf("Map has %d items.\n", m->count);
    returnValue = get(m, "k124");
    if (returnValue == NULL) {
        printf("k124 is not found\n");
    } else {
        printf("k124's value is %s\n", returnValue);
    }
}

void delete_edge_test() {
    map* m = createMap();

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
    map* m = createMap();

    char key[] = "k";
    char value[] = "v";

    for (int i=0; i<20; i++) {
        char* newKey = (char*) malloc(sizeof(char)*(sizeof(key)+3));
        char* newValue = (char*) malloc(sizeof(char)*(sizeof(value)+3));
        snprintf(newKey, sizeof(key)+3, "%s%d\0", key, i);
        snprintf(newValue, sizeof(value)+3, "%s%d\0", value, i);
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

    if (argc < 2 || argv[1][0] > '8' || argv[1][0] < '0') {
	   printf("Usage: ./proj04 [0..8]\n");
	   exit(-1);
    }
    void (*tests[9])();
    tests[0] = &add_delete_test; // 10 points
    tests[1] = &get_found_test; // 10 points
    tests[2] = &get_fail_test; // 10 points
    tests[3] = &get_edge_test; // 10 points
    tests[4] = &delete_get_test;  // 10 points
    tests[5] = &delete_edge_test; // 10 points
    tests[6] = &delete_add_test; // 10 points
    tests[7] = &add_limit_test; // 10 points
    tests[8] = &delete_limit_test; // 20 points

    (*tests[(int) (argv[1][0]-'0')])();
}
