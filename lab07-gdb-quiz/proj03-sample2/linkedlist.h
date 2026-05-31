typedef struct node {
    char* key;
    char* value;
    struct node* next;
} node;

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 * @return: a pointer to the new head of the linked list
 */
node* addNode(node* head, char* key, char* value);

/* 
 * checks if there is a node in the linked list with the given key
 * @param: key is a string in the (key, value) pair
 * @return: 1 if the key is found, 0 otherwise
 */
char* getNode(node* head, char* key);

/* 
 * looks for a node with the given key, and if found, remove the node and return the corresponding value.
 * @param: key is a string in the (key, value) pair
 * @return: value if the key is found, NULL otherwise
 */
node* deleteNode(node* head, char* key, int* num);

void printList();
