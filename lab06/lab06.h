typedef struct dynamicList {
    int size; 
    int count;
    int* list;
} dynamicList;

void add(dynamicList* dlist, int num);

void printList(dynamicList* dlist);
