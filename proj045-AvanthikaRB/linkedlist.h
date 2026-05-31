typedef struct node {
    char* key;
    char* value;
    struct node* next;
} node;

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 * @return: if successful, a pointer to the new head of the linked list. otherwise, the current head
 */
node* addNode(node* head, char* key, char* value);

/* 
 * checks if there is a node in the linked list with the given key
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @return: value if the key is found, NULL otherwise
 */
char* getNode(node* head, char* key);

/* 
 * looks for a node with the given key, and if found, remove the node
 * @param: head is the pointer to the first node in the linked list
 * @param: key is a string in the (key, value) pair
 * @param: num is the pointer to a variable that indicates if delete happened. The variable should be set to 1 if delete happened, 0 otherwise
 * @return: head of the linked list
 */
node* deleteNode(node* head, char* key, int* num);

/*
 * prints the content of the linked list of (key, value) pairs. should print [] if the list is empty
 * @param: head is the pointer to the first node of the linked list
 */
void printList();
