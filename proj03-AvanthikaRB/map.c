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
/*	char hash[DIG_STR_LEN]; 
    sha256(hash, key); // compute SHA256 hash of the key
    //convert the last character of the hash digest to an integer
    int len = strlen(hash);
    char last = hash[len - 1];
    char indexStr[2];
    indexStr[1] = '\0'; // null-terminate
    indexStr[0] = last; 
    int index = strtol(indexStr, NULL, 16); // convert hexadecimal string to integer

    return index % length;
    
}*/
    char hash[DIG_STR_LEN];
    sha256(hash, key);
    //last character
    char lastChar = hash[strlen(hash) - 1];
    int last;
    sscanf(&lastChar, "%1x", &last);
    int index = last % length;
    return index;
} 

/* 
 * adds a new node with a given (key, value) in the beginning of the linked list. increase the count in the map.
 * @param: m is a pointer to the map
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 */
void add(map* m, char* key, char* value) {
	m->count++;
	int index = mapIndex(key, m->size);
	m->list[index]=addNode(m->list[index],key,value);
	
}

/* 
 * find a corresponding value for the given key
 * @param: m is a pointer to the map
 * @param: key is a string in the (key, value) pair
 * @return: value if the key is found, NULL otherwise
 */
char* get(map* m, char* key){
	int index = mapIndex(key, m->size);
	return getNode(m->list[index], key);
}


/* 
 * looks for a node with the given key, and if found, remove the (key, value) pair in the map
 * @param: m is a pointer to the map
 * @param: key is a string in the (key, value) pair
 */
void delete(map* m, char* key) {
	int num = 0;
	int index = mapIndex(key, m->size);
	m->list[index] = deleteNode(m->list[index], key, &num);
	m->count--;
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

