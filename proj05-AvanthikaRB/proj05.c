#include <stdio.h>
#include <limits.h>
#include "mymod.h"

void grant_test() {

    struct file f;

    f.filename = "file0";
    f.permissions = 0;
	
    grantPermission(0, &f);
    printf("%hu\n", f.permissions);
    grantPermission(10, &f);
    printf("%hu\n", f.permissions);
}

void print_test() {

    struct file f;

    f.filename = "file1";
    f.permissions = 0;

    grantPermission(0, &f);
    printPermissions(&f);
    grantPermission(15, &f);
    printPermissions(&f);
    grantPermission(5, &f);
    printPermissions(&f);
}

void revoke_test() {

    struct file f;

    f.filename = "file2";
    f.permissions = 0;

    grantPermission(0, &f);
    printPermissions(&f);
    grantPermission(15, &f);
    printPermissions(&f);
    revokePermission(0, &f);
    printPermissions(&f);
}

void check_test() {

    struct file f;

    f.filename = "file3";
    f.permissions = 0;

    grantPermission(0, &f);

    if (checkPermission(0, &f)) {
        printf("%s has permission %d set\n", f.filename, 0);
    } else {
        printf("%s doesn't have permission %d set\n", f.filename, 0);
    }
    grantPermission(2, &f);
    if (checkPermission(3, &f)) {
        printf("%s has permission %d set\n", f.filename, 3);
    } else {
        printf("%s doesn't have permission %d set\n", f.filename, 3);
    }
}

void all_test() {
    struct file f;

    f.filename = "file4";
    f.permissions = 0;

    for (int i=0; i<16; i+=2) {
        grantPermission(i, &f);
        printPermissions(&f);
    }

    for (int i=15; i>0; i-=3) {
        revokePermission(i, &f);
        printPermissions(&f);
    }
}

int main(int argc, char *argv[])
{
    void (*tests[5])();
    tests[0] = &grant_test; // 10 points
    tests[1] = &print_test; // 10 points
    tests[2] = &revoke_test;// 10 points
    tests[3] = &check_test; // 10 points
    tests[4] = &all_test;   // 10 points

    (*tests[(int)(argv[1][0] - '0')])();
}
