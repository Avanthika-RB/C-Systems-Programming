#include <stdio.h>
#include <stdlib.h>

int* merge(int* listA, int lenA, int* listB, int lenB) {
	int i = 0;
	int j = 0;
	int m = 0;
	int size = lenA + lenB;
	int *merged = (int*)malloc((size) * sizeof(int));
	//int *listA = (int*)malloc((*lenA) * sizeof(int));
	//int *listB = (int*)malloc((*lenB) * sizeof(int));
	
	if(merged == NULL){
		printf("input failed");
		return 0;
	}
	while(i < lenA && j < lenB){
		if(listA[i] <= listB[j]){
			merged[m++] = listA[i++];
		}else{
			merged[m++] = listB[j++];
		}
	}

	while(i < lenA){
		merged[m++] = listA[i++];
	}
	while(j < lenB){
		merged[m++] = listB[j++];
	}
	return merged;

}

void printArray(int* list, int length) {
	for(int i = 0; i < length; i++){
		printf("%d ", *list++);
	}

}

int main(int argc, char* argv[]) {
	FILE *file, *file2;
	file = fopen(argv[1], "r");
	file2 = fopen(argv[2], "r");
	if (file == NULL || file2 == NULL){
		printf("no elements in file");
		return 0;
	}
	int lenA, lenB =0;
	fscanf(file, "%d", &lenA);
	fscanf(file2, "%d", &lenB);
	int listA[lenA];
	int listB[lenB];
	for(int i = 0;i < lenA; i++){
		if(fscanf(file, "%d", &listA[i]) != 1){
			printf("%s", "invalid input format\n");
			return 0;
		}
		if(feof(file)){
			printf("/nEnd of file");
			return 0;
		}
	}

	for(int i = 0; i< lenB; i++){
		if(fscanf(file2, "%d", &listB[i]) != 1){
			printf("%s", "invalid file format\n");
			return 0;
		}
		if(feof(file2)){
			printf("/nEnd of file");
		return 0;
		}
	}
	int *merged = merge(listA,lenA,listB,lenB);
	int size = lenA + lenB;
	printArray(merged, size);
	free(merged);
	fclose(file);
	fclose(file2);
	return 0;
	

// read from two files given as command-line arguments

// pass two arrays to merge function

// print the array returned from merge using printArray function
}
