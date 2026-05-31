#include <limits.h>
#include <stdio.h>
#include <math.h>
#include "mymod.h"

/*
 * Sets the bit at the specified index in the file's permission bitmap.
 * @param index: An integer between 0 and 15 representing the bit index to set.
 * @param f: Pointer to the file structure.
 */
void grantPermission(int index, struct file *f) {
    if (index >= 0 && index < 16) {
        unsigned short var = 1 << (15-index);
        f->permissions |= var;
    }
}

/*
 * Clears the bit at the specified index in the file's permission bitmap.
 * @param index: An integer between 0 and 15 representing the bit index to clear.
 * @param f: Pointer to the file structure.
 */
void revokePermission(int index, struct file *f) {
    if (index >= 0 && index < 16) {
        unsigned short var = ~(1 << (15-index));
        f->permissions &= var;
    }
}

/*
 * Checks if the bit at the specified index is set in the file's permissions bitmap.
 * @param index: An integer between 0 and 15 representing the bit index to check.
 * @param f: Pointer to the file structure.
 * @return: Returns 1 if the bit is set, 0 otherwise.
 */
int checkPermission(int index, struct file *f) {
    if (index >= 0 && index < 16) {
        unsigned short var = 1 << (15-index);
        return (f->permissions & var) != 0;
    }
    return 0;
}

/*
 * Prints the permission bitmap in binary format.
 * @param f: Pointer to the file structure.
 */
void printPermissions(struct file *f) {
    for (int i = 0; i < 16; i++) {
        unsigned short var = 1 << (15-i);
        printf("%d", (f->permissions & var) != 0);
    }
    printf("\n");
}
