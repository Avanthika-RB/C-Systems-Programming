#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "sha256.h"

#define DIG_BIN_LEN 32
#define DIG_STR_LEN ((DIG_BIN_LEN * 2) + 1)

void sha256(char *dest, char *src)
{
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
    for (int i = 0; i < DIG_BIN_LEN; i++)
    {
        snprintf(dest, 3, "%02x", dig_bin[i]);
        dest += 2;
    }
}

/*
 * takes a key, hashes it, converts only the necessary bytes to a decimal, and compute the index to the internal array
 * in map
 * @param: key is a string in the (key, value) pair
 * @param: length is the size of the internal array in map
 * @return: index of an array for this key
 */
int mapIndex(char *key, int length) {
    char hash[DIG_STR_LEN];
    sha256(hash, key);
    int bytes = ceil(log(length)/log(16));  
    char arr[bytes + 1];
    arr[bytes] = '\0';
    strncpy(arr, &hash[strlen(hash) - bytes], bytes);   
    int index = strtol(arr, NULL, 16); //hexadecimal string to integer
    return index % length;
 }

/*
 * adds a given (key, value) pair to the hash map
 * @param: m is the map to add this pair
 * @param: key is a string in the (key, value) pair
 * @param: value is a string in the (key, value) pair
 */
void add(map *m, char *key, char *value) {
// old code from proj04:
//     int index = mapIndex(key, m->size);
//     m->list[index] = addNode(m->list[index], key, value);
//     m->count++;   
//     //resizing 
//     double load = ((double)(m->count) / (double)(m->size));
//     if (load > m->LF_high_thres) {
//         int newSize = m->size * 2;
//         // reallocate memory for new array
//         node** newList = (node**)calloc(newSize, sizeof(node*));
//         if (m->list == NULL) {		//memory management
//             printf("memory allocation failed.\n");
//             exit(0);
//         }
//         //rehash 
//         if(newList){
//         	for (int i = 0; i < m->size; i++) {
//            		node* current = m->list[i]; //current is head at the beginning of for loop
//             	while (current != NULL) {
//             		//put node in new hash map
//             		int newIndex = mapIndex(current->key, newSize);
//                 	node* temp = current->next;
//                 	current->next = newList[newIndex];
//                 	newList[newIndex] = current;
//                 	current = temp;
//            		}
//         	}
//         	//free(m->list);
//         	m->list = newList;
//         	m->size = newSize;
//     	} 
// 	} 
// }
	//proj045 without addNode:
    int index = mapIndex(key, m->size);
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {	//memory management
        printf("memory allocation error\n");
        exit(0);
    }
    newNode->key = strdup(key);//strdup duplicates and stores key and value.
    newNode->value = strdup(value);
    newNode->next = m->list[index];
    m->list[index] = newNode;
    m->count++;
    //resize
    double load = (double)m->count / m->size;
    if (load > m->LF_high_thres) {
        int newSize = m->size * 2;
        node** newList = (node**)calloc(newSize, sizeof(node*));
        if (!newList) {
            printf("memory allocation error\n");
            exit(0);
        }
        //rehash
        for (int i = 0; i < m->size; i++) {
            node* currentNode = m->list[i];
            while (currentNode != NULL) {
                node* nextNode = currentNode->next;
                int newIndex = mapIndex(currentNode->key, newSize);
                currentNode->next = newList[newIndex];
                newList[newIndex] = currentNode;
                currentNode = nextNode;
            }
        }
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
    return getNode(m->list[index],key);
}

/*
 * delete a (key, value) pair with the given key if found
 * @param: m is the map to delete this pair
 * @param: key is a string in the (key, value) pair
 */
void delete(map *m, char *key) {
// old code from proj04:
//     int index = mapIndex(key, m->size);
//     int deleted = 0;  
//     m->list[index] = deleteNode(m->list[index], key, &deleted);
//     if (deleted) {
//         m->count--;
//         //resize
//         if ((double)m->count / m->size <= m->LF_low_thres && m->size >= 16) { 
//             int newSize = m->size / 2;
//             //reallocate memory to put values into newList
//             node** newList = (node**)malloc(newSize * sizeof(node*));
//             if (newList == NULL) {
//                 printf("memory allocation failed.\n");
//                 exit(0);
//             }
//             //set newList values to NULL
//             for (int i = 0; i < newSize; i++) {
//                 newList[i] = NULL;
//             }
//             //rehash
//             for (int i = 0; i < m->size; i++) {
//                 node* currentNode = m->list[i];
//                 while (currentNode != NULL) {
//                     int newIndex = mapIndex(currentNode->key, newSize);
//                     node* temp = currentNode->next;
//                     currentNode->next = newList[newIndex];
//                     newList[newIndex] = currentNode;
//                     currentNode = temp;
//                 }
//             }
//             m->list = newList;
//             m->size = newSize;
//         }
//     }
// }
// new code without deleteNode:
    int index = mapIndex(key, m->size);
    node* current = m->list[index];
    node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            //remove node
            if (prev == NULL) {
                m->list[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current->value);
            free(current);
            m->count--;
            break;
        }
        prev = current;
        current = current->next;
    }
    //resize
    double load = (double)m->count / (double)m->size;
    if (load <= m->LF_low_thres && m->size > 16) {
        int newSize = m->size / 2;
        for (int i = 0; i < newSize; i++) {
            if (m->list[i + newSize] != NULL) {
                node* currentList = m->list[i];
                if (currentList == NULL) {
                    m->list[i] = m->list[i + newSize];
                } else {
                    while (currentList->next != NULL) {
                        currentList = currentList->next;
                    }
                    currentList->next = m->list[i + newSize];
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
void printMap(map m)
{
    for (int i = 0; i < m.size; i++)
    {
        if (m.list[i] != NULL)
        {
            printf("%d, ", i);
            printList(m.list[i]);
        }
    }
}
