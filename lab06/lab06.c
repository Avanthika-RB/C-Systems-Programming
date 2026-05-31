#include <stdio.h>
#include <stdlib.h>

#include "lab06.h"

#define DEFAULT_SIZE 10

void test(int numAdd) {

    dynamicList dlist;
    dlist.size = DEFAULT_SIZE;
    dlist.count = 0;
    dlist.list  = (int*) malloc (DEFAULT_SIZE * sizeof(int));

    if (numAdd > 0) {
        int currentSize = dlist.size;
        for (int i=0; i<numAdd; i++) {
            add(&dlist, i);
            if (dlist.size != currentSize) {
                printf("size: %d, count: %d\n", dlist.size, dlist.count);
                currentSize = dlist.size;
            }
        }
    }
    printf("size: %d, count: %d\n", dlist.size, dlist.count);
    free(dlist.list);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./lab06 [number of items to add]\n");
        exit(-1);
    }

    test(atoi(argv[1]));
}

