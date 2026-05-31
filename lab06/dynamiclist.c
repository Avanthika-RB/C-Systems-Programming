#include <stdio.h>
#include <stdlib.h>

#include "lab06.h"

/*
 * adds num to the dynamicList dlist
 * @param dlist a pointer to a dynamicList
 * @param num an int number to add
 */
void add(dynamicList* dlist, int num) {
    if (dlist->count >= dlist->size) {
        //double the size
        int newSize = dlist->size * 2;
        //reallocate memory for the new list
        int* newList = (int*)realloc(dlist->list, newSize * sizeof(int));
        if (newList == NULL) {
            printf("memory allocation error.\n");
            exit(0);
        }
        // updates list and size
        dlist->list = newList;
        dlist->size = newSize;
    }
    // Add the number to the end of the list
    dlist->list[dlist->count] = num;
    dlist->count++;
}

void printList(dynamicList* dlist) {
    int length = dlist->count;
    printf("size: %d, count %d\n", dlist->size, dlist->count);
    for (int i=0; i<length; i++) {
        printf("%d ", dlist->list[i]);
    }
    printf("\n");
}
