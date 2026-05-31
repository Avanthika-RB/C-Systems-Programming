#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

#define DEFAULT_SIZE 16

map *m;

map *createMap()
{
    map *m = (map *)malloc(sizeof(map));
    m->size = DEFAULT_SIZE;
    m->count = 0;
    m->LF_high_thres = 0.75;
    m->LF_low_thres = 0.25;
    m->list = (node **)malloc(sizeof(node *) * m->size);
    memset(m->list, 0, sizeof(node *) * m->size);

    return m;
}

void mapIndex_test()
{
    printf("%d\n", mapIndex("k0", 16));
    printf("%d\n", mapIndex("k0", 32));
    printf("%d\n", mapIndex("k0", 64));
    printf("%d\n", mapIndex("k0", 128));
    printf("%d\n", mapIndex("k0", 1024));
    printf("%d\n", mapIndex("k0", 16384));
    printf("%d\n", mapIndex("k0", 131072));
    printf("%d\n", mapIndex("k0", 1048576));
    printf("%d\n", mapIndex("k0", 16777216));
}

void mapIndex_test2()
{
    printf("%d\n", mapIndex("k0", 10));
    printf("%d\n", mapIndex("k0", 20));
    printf("%d\n", mapIndex("k0", 50));
    printf("%d\n", mapIndex("k0", 100));
    printf("%d\n", mapIndex("k0", 1000));
    printf("%d\n", mapIndex("k0", 10000));
    printf("%d\n", mapIndex("k0", 100000));
    printf("%d\n", mapIndex("k0", 1000000));
    printf("%d\n", mapIndex("k0", 10000000));
}

void delete_edge_test()
{
    printf("%d\n", m->count);
    delete (m, "k7");
    printf("%d\n", m->count);
    printMap(*m);
}

void delete_fail_test()
{
    printf("%d\n", m->count);
    delete (m, "k20");
    printf("%d\n", m->count);
    printMap(*m);
}

void add_rehash_test()
{
    for (int i = 20; i < 24; i++)
    {
        char *newKey = (char *)malloc(sizeof(char) * 5);
        char *newValue = (char *)malloc(sizeof(char) * 5);
        snprintf(newKey, 5, "k%d\0", i);
        snprintf(newValue, 5, "v%d\0", i);
        add(m, newKey, newValue);
    }
    printMap(*m);
    char *newKey = (char *)malloc(sizeof(char) * 5);
    char *newValue = (char *)malloc(sizeof(char) * 5);
    snprintf(newKey, 5, "k24\0");
    snprintf(newValue, 5, "v24\0");
    add(m, newKey, newValue);
    printMap(*m);
}

void add_rehash_test2()
{
    for (int i = 20; i < 48; i++)
    {
        char *newKey = (char *)malloc(sizeof(char) * 5);
        char *newValue = (char *)malloc(sizeof(char) * 5);
        snprintf(newKey, 5, "k%d\0", i);
        snprintf(newValue, 5, "v%d\0", i);
        add(m, newKey, newValue);
    }
    printMap(*m);
    char *newKey = (char *)malloc(sizeof(char) * 5);
    char *newValue = (char *)malloc(sizeof(char) * 5);
    snprintf(newKey, 5, "k48\0");
    snprintf(newValue, 5, "v48\0");
    add(m, newKey, newValue);
    printMap(*m);
}

void delete_rehash_test()
{
    char *newKey = (char *)malloc(sizeof(char) * 5);
    for (int i = 19; i > 8; i--)
    {
        snprintf(newKey, 5, "k%d\0", i);
        delete (m, newKey);
    }
    printMap(*m);
    delete (m, "k8");
    printMap(*m);
    free(newKey);
}

void delete_rehash_test2()
{
    for (int i = 20; i <= 24; i++)
    {
        char *newKey = (char *)malloc(sizeof(char) * 5);
        char *newValue = (char *)malloc(sizeof(char) * 5);
        snprintf(newKey, 5, "k%d\0", i);
        snprintf(newValue, 5, "v%d\0", i);
        add(m, newKey, newValue);
    }
    char *newKey = (char *)malloc(sizeof(char) * 5);
    for (int i = 24; i > 16; i--)
    {
        snprintf(newKey, 5, "k%d\0", i);
        delete (m, newKey);
    }
    printMap(*m);
    delete (m, "k16");
    printMap(*m);
    free(newKey);
}

void delete_alt_test()
{
    for (int i = 20; i < 50; i += 2)
    {
        char *newKey = (char *)malloc(sizeof(char) * 5);
        char *newValue = (char *)malloc(sizeof(char) * 5);
        snprintf(newKey, 5, "k%d\0", i);
        snprintf(newValue, 5, "v%d\0", i);
        add(m, newKey, newValue);
    }

    char *newKey = (char *)malloc(sizeof(char) * 5);
    for (int i = 0; i < 50; i++)
    {
        snprintf(newKey, 5, "k%d\0", i);
        delete (m, newKey);
        printf("%d ", m->count);
    }
    printf("\n");
    free(newKey);
}

void delete_alt_test2()
{
    for (int i = 20; i < 50; i++)
    {
        char *newKey = (char *)malloc(sizeof(char) * 5);
        char *newValue = (char *)malloc(sizeof(char) * 5);
        snprintf(newKey, 5, "k%d\0", i);
        snprintf(newValue, 5, "v%d\0", i);
        add(m, newKey, newValue);
    }

    char *newKey = (char *)malloc(sizeof(char) * 5);
    for (int i = 0; i < 50; i += 2)
    {
        snprintf(newKey, 5, "k%d\0", i);
        delete (m, newKey);
    }

    for (int i = 0; i < 50; i += 3)
    {
        snprintf(newKey, 5, "k%d\0", i);
        char *res = get(m, newKey);
        if (res != NULL)
        {
            printf("%s ", res);
        }
    }
    printf("\n");
    free(newKey);
}

int main(int argc, char *argv[])
{
    if (argc < 2 || argv[1][0] > '9' || argv[1][0] < '0')
    {
        printf("Usage: ./proj045 [0..9]\n");
        exit(-1);
    }

    m = createMap();

    for (int i = 0; i <= 19; i++)
    {
        char *newKey = (char *)malloc(sizeof(char) * 4);
        char *newValue = (char *)malloc(sizeof(char) * 4);
        snprintf(newKey, 4, "k%d\0", i);
        snprintf(newValue, 4, "v%d\0", i);
        add(m, newKey, newValue);
    }
    void (*tests[9])();
    tests[0] = &mapIndex_test;       // 10 points
    tests[1] = &mapIndex_test2;      // 10 points
    tests[2] = &add_rehash_test;     // 10 points
    tests[3] = &add_rehash_test2;    // 10 points
    tests[4] = &delete_rehash_test;  // 10 points
    tests[5] = &delete_rehash_test2; // 10 points
    tests[6] = &delete_edge_test;    // 10 points
    tests[7] = &delete_fail_test;    // 10 points
    tests[8] = &delete_alt_test;     // 10 points
    tests[9] = &delete_alt_test2;    // 10 points

    (*tests[(int)(argv[1][0] - '0')])();
}
