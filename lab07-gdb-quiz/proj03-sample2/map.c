#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "sha256.h"
#include "map.h"

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
 * takes a key, hashes it, and compute the index to the internal array in map
 * @param: key is a string in the (key, value) pair
 * @param: length is the size of the internal array in map
 * @return: index of an array for this key
 */
int mapIndex(char* key, int length) {
    // your code here
    char* h_string = (char*)malloc(DIG_STR_LEN);
    if (h_string == NULL){
        printf("Malloc error occured \n");
        exit(0);
    }

    sha256(h_string, key);
    long h_long = strtol(h_string, NULL, 16);
    unsigned int h_int = (unsigned int)h_long;
    free(h_string);

    return h_int % length;
   
}

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list. increase the count in the map.
 * @param: m is a pointer to the map
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 */
void add(map* m, char* key, char* value) {
    // your code here
    int ind =mapIndex(key, m->size);
    m->list[ind] = addNode(m->list[ind], key, value);
}

/* 
 * find a corresponding value for the given key
 * @param: m is a pointer to the map
 * @param: key is a string in the (key, value) pair
 * @return: value if the key is found, NULL otherwise
 */
char* get(map* m, char* key){
    // your code here  
    int ind = mapIndex(key, m->size);
    return getNode(m->list[ind], key);   

}         



/* 
 * looks for a node with the given key, and if found, remove the (key, value) pair in the map
 * @param: m is a pointer to the map
 * @param: key is a string in the (key, value) pair
 */
void delete(map* m, char* key) {
    // your code here
    int ind = mapIndex(key, m->size);
    m ->list[ind] = deleteNode(m->list[ind], key, &(m->count));
}

/*
 * prints the content of the internal array of linked lists
 * @param: m is a pointer to the map
 */
void printMap(map m) {
    for (int i=0; i<m.size; i++) {
        if (m.list[i]!=NULL) {
            printList(m.list[i]);
        }
    }
} 
