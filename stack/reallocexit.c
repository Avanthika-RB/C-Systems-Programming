#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printList(int* list, int length) {
	for (int i=0; i<length; i++) {
		printf("%d ",list[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./resize [filename]\n");
        exit(-1);
    }

    FILE* fs = fopen(argv[1], "r");
    if (fs == NULL) {
        printf("invalid file %s\n", argv[1]);
        exit(-1);
    }
    int size = 10;
	int* nums = (int*) malloc(sizeof(int)*size);
    memset(nums, 0, sizeof(int)*size);
    
    int num = 0;
    int index = 0;

    while(fscanf(fs, "%d", &num)==1) {
        if (index >= size) {
            size *= 2;
            nums = (int*) realloc(nums, sizeof(int)*size);
        }
        nums[index] = num;
        index++;
    }
    printList(nums, index);
    free(nums);
    fclose(fs);
}
