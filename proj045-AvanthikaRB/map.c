#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "sha256.h"

#define DIG_BIN_LEN 32
#define DIG_STR_LEN ((DIG_BIN_LEN * 2) + 1)

void sha256(char *dest, char *src) {
    // zero out the sha256 context
    struct sha256_ctx ctx;
    memset(&ctx, 0, sizeof(ctx));

    // zero out the binary version of the hash digest
    unsigned char dig_bin[DIG_BIN_LEN];
    memset(dig_bin, 0, DIG_BIN_LEN);

    // zero out the string version of the hash digest
    memset(dest, 0, DIG_STR_LEN);

    // compute the binary hash digest
    __sha256_init_ctx(&ctx);
    __sha256_process_bytes(src, strlen(src), &ctx);
    __sha256_finish_ctx(&ctx, dig_bin);

    // convert it into a string of hexadecimal digits
    for (int i = 0; i < DIG_BIN_LEN; i++) {
        snprintf(dest, 3, "%02x", dig_bin[i]);
        dest += 2;
    }
}

/*
 * takes a key, hashes it, converts only the necessary bytes to a decimal, and
 * compute the index to the internal array in map
 * @param: key is a string in the (key, value) pair
 * @param: length is the size of the internal array in map
 * @return: index of an array for this key
 */
int mapIndex(char *key, int length) {
    char hash[DIG_STR_LEN];
    sha256(hash, key);
    int bytes = ceil(log(length) / log(16));
    char arr[bytes + 1];
    arr[bytes] = '\0';
    strncpy(arr, &hash[strlen(hash) - bytes], bytes);
    int index = strtol(arr, NULL, 16); // hexadecimal string to integer
    return index % length;
}


/*
 * adds a given (key, value) pair to the hash map
 * @param: m is the map to add this pair
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 */
void add(map *m, char *key, char *value) {
    int index = mapIndex(key, m->size);
    node *newNode = addNode(m->list[index], key, value);
    if(newNode != NULL){
    	m->list[index] = newNode;
    	m->count++; //increments count only if addNode is successful
    }else{
    	printf("error handling\n"); //if not successful, exit
    	exit(0);
    }
    //resize
    double load = ((double)m->count/(double)m->size);
    if (load > m->LF_high_thres) {
        int newSize = m->size * 2;
        node **newList = (node**)calloc(newSize, sizeof(node*));
        if (!newList) { //memory management
            printf("memory allocation error\n");
            exit(0);
        } 
        //rehash only when load is larger than high thres
        if(newList){
        for (int i = 0; i < m->size; i++) {
            node *current = m->list[i];
            while (current != NULL) {
                int newIndex = mapIndex(current->key, newSize);
                node *temp = current->next; 
                current->next = newList[newIndex]; //puts current node at the head with new index/list
                newList[newIndex] = current;
                current = temp; //node is now in list, not new list
                }
            }
        }
        free(m->list); //free list
        m->list = newList;
        m->size = newSize;
    }
}

/*
 * gets a value for the given key
 * @param: m is the map to get the value for the given key
 * @param: key is a string in the (key, value) pair
 * @return: the corresponding value if the key is found, NULL otherwise
 */
char *get(map *m, char *key) {
    int index = mapIndex(key, m->size);
    return getNode(m->list[index], key);
}

/*
 * delete a (key, value) pair with the given key if found
 * @param: m is the map to delete this pair
 * @param: key is a string in the (key, value) pair
 */
void delete(map *m, char *key) {
    int index = mapIndex(key, m->size);
    node *current = m->list[index];
    node *prev = NULL;
    while (current != NULL) {
        if (strncmp(current->key, key, strlen(key)) == 0) {
            // remove node
            if (prev == NULL) {
                m->list[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key); //free allocated memory
            free(current->value);
            free(current);
            m->count--; //decrements count only when node was found and deleted
            break; //break when node is deleted
        }
        prev = current; //next node in list
        current = current->next;
    }
    // resize
    double load = (double)m->count / (double)m->size;
    if (load <= m->LF_low_thres && m->size > 16) {
        int newSize = m->size / 2;
        for (int i = 0; i < newSize; i++) { //merge list
            if (m->list[i + newSize] != NULL) {
                node *newList = m->list[i];
                if (newList == NULL) {
                    m->list[i] = m->list[i + newSize];
                } else {
                    while (newList->next != NULL) {
                        newList = newList->next;
                    }
                    newList->next = m->list[i + newSize];
                }
            }
        }
        m->size = newSize;
    }
}

/*
 * prints the linked list
 * @param: m is the map to print
 */
void printMap(map m) {
    for (int i = 0; i < m.size; i++) {
        if (m.list[i] != NULL) {
            printf("%d, ", i);
            printList(m.list[i]);
        }
    }
}
