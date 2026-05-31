#include "linkedlist.h"

typedef struct map {
    int size;
    int count; 
    float LF_high_thres;
    float LF_low_thres;
    node** list;
} map;

/*
 * takes a key, hashes it, converts only the necessary bytes to a decimal, and compute the index to the internal array in map
 * @param: key is a string in the (key, value) pair
 * @param: length is the size of the internal array in map
 * @return: index of an array for this key
 */
int mapIndex(char* key, int length);

/* 
 * adds a given (key, value) pair to the hash map
 * @param: m is the map to add this pair
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 */
void add(map* m, char* key, char* value);

/* 
 * gets a value for the given key 
 * @param: m is the map to get the value for the given key
 * @param: key is a string in the (key, value) pair
 * @return: the corresponding value if the key is found, NULL otherwise
 */
char* get(map* m, char* key);

/* 
 * delete a (key, value) pair with the given key if found
 * @param: m is the map to delete this pair
 * @param: key is a string in the (key, value) pair
 */
void delete(map* m, char* key);

/* 
 * prints the linked list
 * @param: m is the map to print
 */
void printMap(map m);

